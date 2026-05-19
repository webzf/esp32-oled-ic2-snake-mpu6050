<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0f0f0f,100:1f6feb&height=180&section=header&text=ESP32%20OLED%20SNAKE&fontSize=42&fontColor=ffffff&animation=fadeIn"/>

# 🐍 ESP32 OLED Snake Game

### Motion-controlled Snake game running on ESP32 + SSD1306 OLED display + MPU6050

<br>

<img src="https://img.shields.io/badge/ESP32-Project-blue?style=for-the-badge">
<img src="https://img.shields.io/badge/OLED-SSD1306-black?style=for-the-badge">
<img src="https://img.shields.io/badge/MPU6050-Gyroscope-green?style=for-the-badge">

<br><br>

<img src="images/gameplay.gif" width="700"/>

<br><br>

🎮 Tilt Controls • 🐍 Smooth Gameplay • 📟 OLED Graphics • ⚡ ESP32 Powered

</div>

---

# 🚀 About the Project

This project is a modern tilt-controlled version of the classic Snake game made for **ESP32 + SSD1306 OLED** using an **MPU6050 gyroscope/accelerometer**.

Instead of buttons or a joystick, the snake is controlled by physically tilting the device using motion sensing.

The project features:

- Smooth gyroscope controls
- Dynamic movement speed
- Start screen
- Score and best score system
- Game over screen
- Retro arcade graphics
- Infinite edge wrapping gameplay

This project is also a great introduction to:

- Arduino accelerometer projects
- MPU6050 motion sensing
- I2C communication protocol
- Microcontroller sensor projects
- Real-time tilt controls using inertial sensors

---

# 🔗 Full Project

<div align="center">

<a href="https://www.youtube.com/@ztr0n1cs">
<img src="https://img.shields.io/badge/YouTube-ztr0n1cs-red?style=for-the-badge&logo=youtube">
</a>

<a href="https://beacons.ai/ztronics/">
<img src="https://img.shields.io/badge/Beacons-Full_Funnel-purple?style=for-the-badge">
</a>

<a href="https://www.instructables.com/member/ztr0nics/">
<img src="https://img.shields.io/badge/Instructables-Tutorial-orange?style=for-the-badge&logo=instructables">
</a>

<a href="https://www.pinterest.com/ztronics03/">
<img src="https://img.shields.io/badge/Pinterest-More_Projects-red?style=for-the-badge&logo=pinterest">
</a>

<a href="https://github.com/webzf/">
<img src="https://img.shields.io/badge/GitHub-webzf-black?style=for-the-badge&logo=github">
</a>

</div>

---

# ✨ Features

<table>
<tr>
<td>🎮 MPU6050 tilt controls</td>
<td>🐍 Smooth snake movement</td>
</tr>

<tr>
<td>⚡ Dynamic speed system</td>
<td>🍎 Food collection gameplay</td>
</tr>

<tr>
<td>🏆 Score & Best Score</td>
<td>📟 OLED retro graphics</td>
</tr>

<tr>
<td>🎬 Startup screen</td>
<td>💀 Game over screen</td>
</tr>
</table>

---

# 🛒 Exact Parts Used In This Build

<div align="center">
<img src="https://img.shields.io/badge/🎯%20MPU6050%20Used%20In%20This%20Project-View%20Part-green?style=for-the-badge">
<a href="https://beacons.ai/ztronics/">
<img src="https://img.shields.io/badge/🛒%20ESP32%20Dev%20Board-View%20Part-blue?style=for-the-badge">
</a>

<br><br>

<a href="https://beacons.ai/ztronics/">
<img src="https://img.shields.io/badge/📟%20SSD1306%20OLED-View%20Part-black?style=for-the-badge">
</a>



</div>

---

# 🔌 Wiring

## OLED Display

| OLED | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## MPU6050

| MPU6050 | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

# 📚 Libraries

Install these libraries from Arduino IDE Library Manager:

- Adafruit GFX
- Adafruit SSD1306
- MPU6050_tockn
- Wire

---

# 🎮 Controls

| Action | Motion |
|---|---|
| Move Up | Tilt Forward |
| Move Down | Tilt Backward |
| Move Left | Tilt Left |
| Move Right | Tilt Right |

---

# 🧠 Motion System

The MPU6050 accelerometer detects movement in real time.

The ESP32 reads tilt values and converts them into Snake movement directions.

Using the accelerometer instead of angle calculations provides:

- Faster response
- Smoother controls
- Lower latency
- Better arcade gameplay feel

This project also demonstrates practical usage of:

- I2C communication protocol
- Accelerometer-based motion sensing
- Microcontroller sensor projects
- Embedded gaming systems

---

# 🧪 Learn More About MPU6050

The MPU6050 is one of the most popular motion sensors used in:

- Arduino accelerometer projects
- Self-balancing robots
- Gesture control systems
- Motion-controlled games
- Drone stabilization systems
- DIY electronics projects

This project is also useful for learning:

- How to calibrate MPU6050
- I2C communication protocol
- Types of inertial measurement units
- Sensor fusion algorithms
- ESP32 motion sensing

Many makers also compare MPU6050 and MPU9250 when building advanced IMU projects with magnetometer support.

The same concepts can also be adapted for:

- Using MPU6050 with Raspberry Pi
- Robotics projects
- IoT sensor systems
- Motion tracking applications

---

# 📸 Preview

<div align="center">

<img src="https://i.pinimg.com/736x/97/2e/e4/972ee4bdbfe4bb0b01957db5f658e7d7.jpg" width="320"/>
<img src="https://i.pinimg.com/736x/4f/87/ca/4f87ca98e86b6776c31519cbb8cc5dc7.jpg" width="320"/>

</div>

---

# ⚡ Upload Guide

1. Open Arduino IDE  
2. Install ESP32 board package  
3. Install required libraries  
4. Select your ESP32 board  
5. Upload the code  
6. Tilt to play 🐍

---

# 📂 Repository Structure

esp32-oled-snake/

├── images/  
│   ├── gameplay.gif  
│   ├── gameplay.jpg  
│   └── wiring.png  

├── esp32-oled-snake.ino  
├── README.md  
└── LICENSE  

---

# ⭐ Support

If you liked this project:

⭐ Star the repository  
📺 Subscribe on YouTube  
🚀 Visit the full funnel  
💬 Share the project  

---

# 📜 License

MIT License

---

<div align="center">

# 🐍 Retro Snake on ESP32

Made with ❤️ using Arduino + ESP32 + MPU6050

<br><br>

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:1f6feb,100:0f0f0f&height=120&section=footer"/>

</div>
```
