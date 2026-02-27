# ❤️ Portable ECG Monitoring and Heart Disease Detection System

A low-cost, portable **ECG monitoring and heart disease detection
system** built using **Arduino** and a **MIT App Inventor GUI-based
Android application**.

The system captures real-time ECG signals, processes heart parameters,
and sends data wirelessly to a mobile application for visualization,
storage, and basic heart disease analysis.

------------------------------------------------------------------------

## 📌 Project Overview

This project is designed to:

-   Acquire real-time ECG signals using ECG sensor module\
-   Monitor heart rate continuously\
-   Detect abnormal heart patterns\
-   Send ECG data to an Android application\
-   Store patient ECG records for later analysis\
-   Provide a portable and affordable cardiac monitoring solution

------------------------------------------------------------------------

## 🛠️ Hardware Components

-   Arduino (UNO / Nano / ESP32)
-   ECG Sensor Module (e.g., AD8232)
-   Bluetooth Module (HC-05 / HC-06) or WiFi (ESP32)
-   LCD (optional)
-   Power Supply / Battery
-   Electrodes
-   Connecting Wires

------------------------------------------------------------------------

## 💻 Software Used

-   Arduino IDE\
-   MIT App Inventor (for Android GUI application)\
-   Serial Monitor (for debugging)

------------------------------------------------------------------------

## 📱 Mobile Application (MIT App Inventor)

The Android application:

-   Receives ECG data via Bluetooth/WiFi\
-   Displays ECG waveform in real-time\
-   Shows heart rate (BPM)\
-   Stores patient records\
-   Provides basic heart condition indication

------------------------------------------------------------------------

## ⚙️ System Architecture

ECG Electrodes → ECG Sensor → Arduino → Bluetooth/WiFi → Android App\
                                              ↓\
                                       Data Storage

------------------------------------------------------------------------

## 🔌 Arduino Code Features

-   Serial ECG data acquisition\
-   Heart rate (BPM) calculation\
-   Noise filtering\
-   Data transmission to mobile app\
-   Real-time monitoring

------------------------------------------------------------------------

## 🚀 How to Run the Project

### 1️⃣ Hardware Setup

-   Connect ECG sensor to Arduino\
-   Connect Bluetooth module (TX/RX properly configured)\
-   Attach ECG electrodes correctly

### 2️⃣ Upload Arduino Code

-   Open Arduino IDE\
-   Select correct board and COM port\
-   Upload the provided `.ino` file

### 3️⃣ Install Android App

-   Build or install the MIT App Inventor APK\
-   Enable Bluetooth\
-   Connect to Arduino Bluetooth module

### 4️⃣ Start Monitoring

-   Wear ECG electrodes\
-   Open app\
-   Connect device\
-   View real-time ECG waveform

------------------------------------------------------------------------

## 📊 Heart Disease Detection Logic

The system performs basic detection based on:

-   Abnormal heart rate (Bradycardia / Tachycardia)
-   Irregular ECG waveform patterns
-   RR interval variations

⚠️ This system is for educational and prototype purposes only and not a
replacement for professional medical diagnosis.

------------------------------------------------------------------------

## 📂 Project Structure

PPortable-ECG-Monitoring/
│
├──  Portable_ECG_and_Heart_Rate_Monitoring.ino
│   
│
├── ECG_App.aia
│    
│
├── Images/
│   └── PCB_Design.jpeg
|   └──  PCB_Design_3D.jpeg
|   └── ECG Monitor.jpg
|   └── Real-time_check_1.jpg
|   └── Real-time-check_2.jpg
|   └── Real-time-check_3.jpeg 
|   └── Aleart_message.jpeg
│
└── README.md

------------------------------------------------------------------------

## 📈 Future Improvements

-   Integration with TensorFlow Lite model for heart disease prediction\
-   Cloud data storage (IoT integration)\
-   GPS-based emergency alert system\
-   Advanced ECG signal filtering\
-   Multi-lead ECG support

------------------------------------------------------------------------

## 🎯 Applications

-   Remote patient monitoring\
-   Rural healthcare systems\
-   Educational biomedical projects\
-   Portable heart monitoring device

------------------------------------------------------------------------

## 👨‍💻 Author

**Bipronath Saha**\
B.Sc. in Electrical & Electronic Engineering\


------------------------------------------------------------------------

## 📜 License

This project is Licensed in MIT 