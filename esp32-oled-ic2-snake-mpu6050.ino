// ==========================================
// Libraries
// ==========================================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_tockn.h>

// ==========================================
// OLED Display Configuration
// ==========================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// ==========================================
// MPU6050 Motion Sensor
// ==========================================

MPU6050 mpu6050(Wire);

// ==========================================
// Game Configuration
// ==========================================

const int grid = 4;

// Snake body coordinates

int snakeX[200];
int snakeY[200];

// Initial snake length

int snakeLength = 5;

// Current movement direction

int dirX = 1;
int dirY = 0;

// Buffered next direction
// Prevents instant reverse movement

int nextDirX = 1;
int nextDirY = 0;

// Food position

int foodX;
int foodY;

// Game timing

unsigned long lastMove = 0;

// Dynamic game speed

int gameSpeed = 120;

// Game states

bool gameOver = false;
bool gameStarted = false;

// Score system

int score = 0;
int bestScore = 0;

// Tilt sensitivity

float threshold = 0.35;

// ==========================================
// Spawn Food
// ==========================================

void spawnFood() {

  foodX = random(0, SCREEN_WIDTH / grid) * grid;
  foodY = random(0, SCREEN_HEIGHT / grid) * grid;
}

// ==========================================
// Reset Game State
// ==========================================

void resetGame() {

  snakeLength = 5;

  score = 0;

  dirX = 1;
  dirY = 0;

  nextDirX = 1;
  nextDirY = 0;

  gameOver = false;

  // Create initial snake body

  for (int i = 0; i < snakeLength; i++) {

    snakeX[i] = 40 - i * grid;
    snakeY[i] = 20;
  }

  spawnFood();
}

// ==========================================
// Setup
// ==========================================

void setup() {

  Serial.begin(115200);

  // Initialize I2C

  Wire.begin();

  // Lower I2C speed for stability

  Wire.setClock(100000);

  // Initialize OLED display

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.display();

  // Initialize MPU6050

  mpu6050.begin();

  // Gyroscope calibration

  mpu6050.calcGyroOffsets(true);

  // Random seed for food spawning

  randomSeed(millis());

  resetGame();
}

// ==========================================
// Main Loop
// ==========================================

void loop() {

  // ==========================================
  // Start Screen
  // ==========================================

  if (!gameStarted) {

    mpu6050.update();

    float x = mpu6050.getAccX();
    float y = mpu6050.getAccY();

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);

    display.setCursor(30, 5);
    display.println("SNAKE");

    display.setTextSize(1);

    display.setCursor(10, 28);
    display.println("Tilt to play");

    display.display();

    // Start game when tilt is detected

    if (abs(x) > 0.5 || abs(y) > 0.5) {

      gameStarted = true;

      delay(300);
    }

    return;
  }

  // ==========================================
  // Game Over Screen
  // ==========================================

  if (gameOver) {

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);

    display.setCursor(10, 5);
    display.println("GAME");

    display.setCursor(15, 25);
    display.println("OVER");

    display.setTextSize(1);

    display.setCursor(30, 50);
    display.print("SCORE: ");
    display.println(score);

    display.display();

    delay(2500);

    gameStarted = false;

    resetGame();

    return;
  }

  // ==========================================
  // Read MPU6050 Sensor
  // ==========================================

  mpu6050.update();

  // Use accelerometer values
  // Better for responsive tilt controls

  float x = mpu6050.getAccX();
  float y = mpu6050.getAccY();

  // ==========================================
  // Dynamic Speed System
  // ==========================================

  float tilt = max(abs(x), abs(y));

  if (tilt > threshold) {

    gameSpeed = map(
      constrain(tilt * 100, 35, 100),
      35,
      100,
      150,
      60
    );

  } else {

    gameSpeed = 150;
  }

  // ==========================================
  // Tilt Controls
  // ==========================================

  if (abs(x) > abs(y)) {

    // Move Up

    if (x > threshold) {

      if (!(dirX == 0 && dirY == -1)) {

        nextDirX = 0;
        nextDirY = 1;
      }
    }

    // Move Down

    else if (x < -threshold) {

      if (!(dirX == 0 && dirY == 1)) {

        nextDirX = 0;
        nextDirY = -1;
      }
    }

  } else {

    // Move Right

    if (y > threshold) {

      if (!(dirX == -1 && dirY == 0)) {

        nextDirX = 1;
        nextDirY = 0;
      }
    }

    // Move Left

    else if (y < -threshold) {

      if (!(dirX == 1 && dirY == 0)) {

        nextDirX = -1;
        nextDirY = 0;
      }
    }
  }

  // ==========================================
  // Snake Movement
  // ==========================================

  if (millis() - lastMove > gameSpeed) {

    lastMove = millis();

    // Apply next direction

    dirX = nextDirX;
    dirY = nextDirY;

    // Move snake body

    for (int i = snakeLength; i > 0; i--) {

      snakeX[i] = snakeX[i - 1];
      snakeY[i] = snakeY[i - 1];
    }

    // Move snake head

    snakeX[0] += dirX * grid;
    snakeY[0] += dirY * grid;

    // ==========================================
    // Screen Wrapping
    // ==========================================

    if (snakeX[0] < 0)
      snakeX[0] = SCREEN_WIDTH - grid;

    if (snakeX[0] >= SCREEN_WIDTH)
      snakeX[0] = 0;

    if (snakeY[0] < 0)
      snakeY[0] = SCREEN_HEIGHT - grid;

    if (snakeY[0] >= SCREEN_HEIGHT)
      snakeY[0] = 0;

    // ==========================================
    // Self Collision Detection
    // ==========================================

    for (int i = 1; i < snakeLength; i++) {

      if (snakeX[0] == snakeX[i] &&
          snakeY[0] == snakeY[i]) {

        gameOver = true;
      }
    }

    // ==========================================
    // Food Collection
    // ==========================================

    if (snakeX[0] == foodX &&
        snakeY[0] == foodY) {

      snakeLength++;

      score++;

      // Save best score

      if (score > bestScore) {
        bestScore = score;
      }

      spawnFood();
    }
  }

  // ==========================================
  // Render Game
  // ==========================================

  display.clearDisplay();

  // Draw food

  display.fillRect(
    foodX,
    foodY,
    grid,
    grid,
    WHITE
  );

  // Draw snake

  for (int i = 0; i < snakeLength; i++) {

    display.fillRect(
      snakeX[i],
      snakeY[i],
      grid,
      grid,
      WHITE
    );
  }

  // Draw score

  display.setTextSize(1);

  display.setCursor(0, 0);

  display.print(score);

  display.display();
}
