# ESP32 Web OTA using ElegantOTA

## Overview

This project demonstrates how to perform **Over-the-Air (OTA) firmware updates** on an ESP32 using **ElegantOTA**. The ESP32 hosts a local web server, allowing firmware updates through a web browser without requiring the Arduino IDE after the initial firmware upload.

Once the ESP32 is connected to the same Wi-Fi network, users can access the OTA webpage using the ESP32's IP address, upload a compiled firmware (`.bin`) file, and update the device wirelessly.

This method is commonly used for local maintenance, customer deployments, and IoT prototypes.

---

# Features

* Wireless firmware update through a web browser
* No USB cable required after initial setup
* User-friendly web interface
* Simple firmware upload process
* Automatic firmware flashing
* Automatic device reboot after successful update
* Supports repeated OTA updates

---

# Hardware Required

* ESP32 Development Board
* USB Cable (only for initial firmware upload)
* Wi-Fi Router
* Computer connected to the same Wi-Fi network

---

# Software Requirements

* Arduino IDE 2.x
* ESP32 Board Package
* ElegantOTA Library
* WebServer Library (ESP32 Core)

---

# Project Structure

```text
ESP32_ElegantOTA/
│
├── ESP32_ElegantOTA.ino
├── credentials.h
├── README.md
└── images/
```

---

# How Web OTA Works

```text
                USB Upload (Only Once)
                        │
                        ▼
                 ESP32 Firmware
                        │
                Connect to Wi-Fi
                        │
                        ▼
              Start Web Server
                        │
                        ▼
             ElegantOTA Web Page
                        │
                        ▼
      User Opens Browser (ESP32 IP)
                        │
                        ▼
             Select firmware.bin
                        │
                        ▼
               Upload Firmware
                        │
                        ▼
          Firmware Written to Flash
                        │
                        ▼
              Automatic Restart
                        │
                        ▼
               New Firmware Running
```

---

# Workflow

### Step 1

Upload the Web OTA firmware using a USB cable.

---

### Step 2

ESP32 connects to the configured Wi-Fi network.

---

### Step 3

The ESP32 starts a web server.

---

### Step 4

Open the Serial Monitor.

Example output:

```text
WiFi Connected
IP Address: 192.168.1.105

HTTP Server Started
OTA Page:
http://192.168.1.105/update
```

---

### Step 5

Open a web browser.

Navigate to:

```text
http://<ESP32_IP>/update
```

Example:

```text
http://192.168.1.105/update
```

---

### Step 6

ElegantOTA displays a firmware upload page.

---

### Step 7

Compile your modified project.

Export the compiled binary:

```
Sketch → Export Compiled Binary
```

This generates:

```text
firmware.bin
```

---

### Step 8

Click **Choose File**.

Select the exported `.bin` file.

---

### Step 9

Click **Update**.

The ESP32 receives the firmware, writes it to flash memory, and automatically restarts.

---

### Step 10

The new firmware starts running.

---

# ElegantOTA Update Process

```text
Developer
     │
Modify Code
     │
     ▼
Compile Firmware
     │
     ▼
Export firmware.bin
     │
     ▼
Open Browser
     │
     ▼
http://ESP32_IP/update
     │
     ▼
Choose firmware.bin
     │
     ▼
Upload
     │
     ▼
ESP32 Receives Firmware
     │
     ▼
Write Firmware to Flash
     │
     ▼
Restart ESP32
     │
     ▼
Run Updated Firmware
```

---

# Advantages

* Very simple to use
* No Arduino IDE required after deployment
* Browser-based firmware upload
* User-friendly interface
* Ideal for demonstrations
* Perfect for local maintenance
* Faster than reconnecting USB repeatedly

---

# Limitations

* ESP32 and computer must be on the same Wi-Fi network.
* Firmware upload is manual.
* Not suitable for unattended remote deployments.
* Requires access to the device's local IP address.

---

# Typical Development Cycle

```text
Modify Code
      │
      ▼
Compile
      │
      ▼
Export firmware.bin
      │
      ▼
Open OTA Page
      │
      ▼
Upload Firmware
      │
      ▼
ESP32 Restarts
      │
      ▼
Verify Changes
      │
      ▼
Repeat
```

---

# Applications

* Embedded system development
* IoT prototype testing
* Classroom demonstrations
* Robotics projects
* Industrial maintenance
* Customer firmware updates over a local network

---

# Comparison with Arduino OTA

| Arduino OTA              | Web OTA (ElegantOTA)                     |
| ------------------------ | ---------------------------------------- |
| Uses Arduino IDE         | Uses any web browser                     |
| Upload directly from IDE | Upload compiled `.bin` file              |
| Developer-oriented       | User-friendly                            |
| Requires Arduino IDE     | No IDE required after deployment         |
| Best for development     | Best for local maintenance and end users |

---

# Comparison with HTTP OTA

| Web OTA                | HTTP OTA                            |
| ---------------------- | ----------------------------------- |
| Manual firmware upload | Automatic firmware download         |
| User initiates update  | Device initiates update             |
| Local network          | Local or cloud server               |
| Browser required       | No browser required                 |
| Suitable for testing   | Suitable for production deployments |

---

# Learning Outcomes

After completing this project, you will understand:

* ESP32 Web Server
* ElegantOTA
* Browser-based firmware updates
* Flash memory concepts
* OTA firmware upload process
* Local network communication
* Embedded firmware deployment

---

# Future Enhancements

* HTTP OTA
* HTTPS OTA
* MQTT-triggered OTA
* AWS IoT Core Integration
* Amazon S3 Firmware Hosting
* Automatic Version Checking
* Firmware Authentication
* Secure Boot
* Rollback Mechanism

---

# Author

**Ashok Kadagala**

Embedded Systems | IoT | ESP32 | MQTT | AWS IoT | OTA Firmware Updates

---

# License

This project is intended for educational and learning purposes. You are free to modify, improve, and use the code for personal, academic, or research projects.
