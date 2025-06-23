# SmartDustbin1

##  Project Overview
SmartDustbin1 is an automated dustbin system built using an Arduino UNO, designed to improve hygiene and convenience. The system uses **two ultrasonic sensors** to detect:

- When a hand or object approaches to automatically open and close the lid.
- When the dustbin is full, triggering a notification through an LED indicator and a message on the Serial Monitor.

This smart system provides a touchless waste disposal experience and alerts users when the dustbin requires emptying.

---

##  Components Used

| Component                    | Quantity |
|:-----------------------------|:-----------|
| Arduino UNO                   | 1         |
| HC-SR04 Ultrasonic Sensor     | 2         |
| SG90 Servo Motor              | 1         |
| Red LED (standby indicator)   | 1         |
| White LED (bin full indicator)| 1         |
| 220Ω Resistor                 | 2         |
| Breadboard                    | 1         |
| Jumper Wires                  | As needed |

---

## 🔧 How It Works

- **Sensor 1 (Hand Detection)**:  
  Detects an approaching object within **30 cm**. When triggered:
  - The servo motor opens the lid.
  - After **8 seconds**, the lid closes automatically.

- **Sensor 2 (Bin Full Detection)**:  
  Detects the distance from the top of the bin to the trash surface. If the distance is less than **10 cm**:
  - A **White LED** turns on.
  - The message **"FULL"** is displayed on the **Arduino Serial Monitor**.

- **Standby Red LED**:  
  Blinks slowly to indicate the system is active.

---

##  Files

- `SmartDustbin_v2.ino` — Complete Arduino code with dual ultrasonic sensor support, LED indicators, and Serial Monitor feedback.
- `README.md` — Project overview, components, functionality explanation, and instructions.

---

##  Serial Monitor Output

- **"FULL"**: Displayed continuously when the bin is full.

*Open Serial Monitor via `Tools > Serial Monitor` in Arduino IDE at **9600 baud rate**.*

---

##  Pin Configuration

| Function               | Arduino UNO Pin |
|:------------------------|:----------------|
| Servo Motor Signal       | 6              |
| HC-SR04 #1 Trig (Hand)   | 5              |
| HC-SR04 #1 Echo (Hand)   | 4              |
| HC-SR04 #2 Trig (Bin Full)| 3             |
| HC-SR04 #2 Echo (Bin Full)| 2             |
| Red Standby LED          | 13             |
| White Bin Full LED       | 12             |

---

##  Future Improvements

- Integrate a Bluetooth module (HC-05) or Wi-Fi (ESP32) for mobile app notifications.
- Add an OLED display to show real-time bin status.
- Connect to Arduino IoT Cloud for remote monitoring (with Wi-Fi board).

---

##  Author

Eirfan Shah
- Student ID: 1191102014
- Course: ACE6263-EMBEDDED IoT SYSTEMS & APP
- Email: 1191102014@student.mmu.edu.my
- Project Group: 

---

##  License

This project is created for academic purposes. All rights reserved by Eirfan Shah.
