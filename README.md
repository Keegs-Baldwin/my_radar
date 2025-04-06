# 🛫 My Radar Project

A real-time 2D air traffic control simulation built in **C** using **CSFML**.

---

## 📌 Overview

This project simulates air traffic control in a 2D environment. It manages the movement and interactions of aircraft and control towers based on predefined rules and real-time physics.

The simulation includes graphical visualization and collision detection logic.  
All logic and rendering are handled using the **CSFML** graphics library (C binding of SFML).

---

## ✨ Features

- **🛩 Aircrafts**
  - Move from departure to arrival coordinates at a constant speed
  - Appear on takeoff and disappear upon landing or destruction

- **🗼 Control Towers**
  - Stationary entities with control zones
  - Prevent aircraft within their area from colliding

- **💥 Collision Detection**
  - Aircrafts collide if they cross paths outside tower coverage
  - Destroyed upon collision unless protected by a control zone

- **🖼 Visualization**
  - Displays:
    - Aircraft and tower sprites
    - Hitboxes
    - Control tower zones

- **🛑 Termination**
  - Simulation ends when all aircrafts have landed or been destroyed

---

## 🧰 Compilation

Use the provided `Makefile` to compile and manage the project:

```bash
make        # Compile the project
make re     # Recompile from scratch
make clean  # Remove object files
make fclean # Remove all binaries and object files
```

---

## ▶️ Usage

Run the simulation with a scenario file as input:

```bash
./my_radar scenario.txt
```

Where `scenario.txt` defines aircrafts and towers with their respective parameters.

Example input format:
```
A 10 10 100 100 5 3
T 50 50 10
```

---

## 🛠 Technologies Used

- **C Language**
- **CSFML (Simple and Fast Multimedia Library)**
- **Makefile**

---

## 🎯 Objective

This project aims to strengthen understanding of:
- Real-time simulation logic
- Graphics programming with CSFML
- Collision detection
- Object-oriented design in C

---
