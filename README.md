# Atari 2600 Joystick to Bluetooth Keyboard (ESP32)

This project converts a classic **Atari 2600 Joystick** (or any compatible DB9 controller) into a wireless Bluetooth keyboard using an **ESP32**. 

By using the `BleKeyboard` library, the joystick is recognized as a standard HID input device, making it natively compatible with Windows, Android, and iOS emulators without the need for additional drivers.

## 🚀 Features

* **Wireless Retro Gaming:** Turns any original DB9 Atari joystick into a Bluetooth controller.
* **Plug & Play:** Recognized as a keyboard, ensuring high compatibility across different operating systems.
* **Debounced Input:** Uses a state machine logic (`IDLE`, `PRESSED`, `RELEASED`) to handle button presses cleanly.
* **Energy Efficient:** Built on Bluetooth Low Energy (BLE) standards.



## 🕹️ Key Mapping

| Atari Function | Keyboard Key | ESP32 Pin (GPIO) |
| :--- | :--- | :--- |
| **UP** | Up Arrow | GPIO 12 |
| **DOWN** | Down Arrow | GPIO 13 |
| **LEFT** | Left Arrow | GPIO 27 |
| **RIGHT** | Right Arrow | GPIO 14 |
| **FIRE** | Right Control | GPIO 26 |

## 🛠️ Hardware Setup

The Atari joystick uses a simple "switch-to-ground" mechanism. The ESP32 pins are configured with internal `INPUT_PULLUP`, so you only need to connect the joystick pins to the corresponding GPIOs and the common pin to GND.

### DB9 Connector Pinout (Male - Looking at the controller plug):

| Pin | Function | ESP32 Connection |
| :--- | :--- | :--- |
| 1 | Up | GPIO 12 |
| 2 | Down | GPIO 13 |
| 3 | Left | GPIO 27 |
| 4 | Right | GPIO 14 |
| 6 | Fire | GPIO 26 |
| 8 | Ground | GND |

*Note: Pins 5, 7, and 9 are not used for standard Atari joysticks.*

## 💻 Prerequisites

1.  **Arduino IDE** with ESP32 board support installed.
2.  **Library:** [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) (install via Library Manager or GitHub).

## 📝 How to Use

1.  Flash the provided code to your ESP32 Lite (or standard ESP32).
2.  Once powered, the device will advertise as **"Atari BLE Keyboard"**.
3.  Open Bluetooth settings on your PC or Mobile and pair with the device.
4.  Launch your favorite emulator (e.g., Stella, RetroArch) and map the controls using the keyboard keys listed above.

## 📑 Changelog

* **v2.0:** Switched input method from Gamepad to Keyboard for better OS compatibility.
* **v2.1:** Adjusted polling delays and confirmed compatibility with Windows/Android. Fixed arrow key behavior for Windows environments using `bleKeyboard.press/release`.

---
**Developed by:** Paulo
