# 📡 Data Telemetry & Serial Protocol Specification

This document details the serial data transmission protocol, baud rates, packet structure, and telemetry specifications for data streaming between the hardware unit, mobile application, and future cloud/IoT integrations.

---

## 🎛️ Serial Interface Configuration

| Parameter | Value |
| :--- | :--- |
| **Baud Rate** | `57600 baud` |
| **Data Bits** | `8` |
| **Parity** | `None` |
| **Stop Bits** | `1` |
| **Flow Control** | `None` |

---

## 📦 Packet Structure Specification

The system transmits raw telemetry data, filtered amplitude levels, and heart rate parameters over serial / Bluetooth SPP interface.

### Data Frame Layout

```
+---------------+---------------+--------------------+------------------+----------------+
|  Header (0xA5) |  Heart Rate   | Filtered Sample MSB| Filtered Sample LSB| Status Flags   |
|   (1 Byte)    |   (1 Byte)    |      (1 Byte)      |     (1 Byte)     |    (1 Byte)    |
+---------------+---------------+--------------------+------------------+----------------+
```

### Field Definitions

1. **Header Byte (`0xA5`)**: Synchronization byte denoting packet start.
2. **Heart Rate (`uint8_t`)**: Calculated Heart Rate in Beats Per Minute (0 - 255 BPM).
3. **Filtered Sample MSB/LSB (`int16_t`)**: High and Low bytes of the 16-bit signed filtered ECG signal amplitude.
4. **Status Flags (`uint8_t`)**: Bitmask field encoding system alert state:
   - `Bit 0`: Lead-off status (`0` = Connected, `1` = Leads Off).
   - `Bit 1`: Arrhythmia flag (`0` = Normal, `1` = Abnormal rhythm).
   - `Bit 2-7`: Reserved for future sensor expansion.

---

## ☁️ Future IoT Payload Format (JSON Specification)

For future cloud telemetry (MQTT / HTTP REST API endpoint integration), the system formats cardiac sessions into structured JSON payloads:

```json
{
  "device_id": "ECG-MONITOR-001",
  "timestamp": "2026-09-24T23:35:00Z",
  "patient_id": "P-89210",
  "telemetry": {
    "heart_rate_bpm": 74,
    "respiration_rate_rpm": 16,
    "lead_status": "CONNECTED",
    "signal_quality": 98.5
  },
  "waveforms": {
    "ecg_channel_1": [12, 45, 120, 850, -420, 15, 8],
    "sample_rate_hz": 500
  },
  "diagnostic_alerts": {
    "bradycardia": false,
    "tachycardia": false,
    "arrhythmia_detected": false
  }
}
```
