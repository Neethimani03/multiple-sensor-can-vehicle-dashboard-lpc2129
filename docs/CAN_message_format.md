# CAN Message Format  
Multiple Sensor CAN Vehicle Dashboard using LPC2129

---

## CAN Configuration

| Parameter              | Value                     |
|------------------------|---------------------------|
| CAN Controller         | CAN2                      |
| Frame Type             | Standard Data Frame       |
| Bit Rate               | 125 kbps                  |
| Acceptance Filter      | Disabled (Accept All)     |
| Data Length Code (DLC) | 4 Bytes                   |

---

## CAN Frame Structure

| Field  | Description                         |
|--------|-------------------------------------|
| ID     | Message Identifier (Standard)       |
| RTR    | 0 – Data Frame                      |
| DLC    | 4                                   |
| DATA   | ByteA (Lower 4 bytes used)          |

---

## CAN Message ID Mapping

| CAN ID | Source Node           | Byte Used | Description                |
|-------:|-----------------------|-----------|----------------------------|
| 0x01   | LDR / Headlight Node  | byteA     | Headlight ON/OFF status    |
| 0x02   | Ultrasonic Sensor     | byteA     | Fuel level distance (cm)   |
| 0x03   | Speed PWM Node        | byteA     | Vehicle speed (km/hr)      |

---

## Message Definitions

### CAN ID: 0x01 — Headlight Status

| Parameter | Value                    |
|-----------|--------------------------|
| Source    | LDR Interrupt Node       |
| byteA     | `1` → Light ON           |
|           | `0` → Light OFF          |

---

### CAN ID: 0x02 — Fuel Level (Ultrasonic)

| Parameter | Value                            |
|-----------|----------------------------------|
| Source    | Ultrasonic Sensor Node           |
| byteA     | Distance from fuel surface (cm)  |
| Usage     | Converted to percentage in LCD   |

---

### CAN ID: 0x03 — Vehicle Speed

| Parameter | Value                   |
|-----------|-------------------------|
| Source    | PWM Speed Node          |
| byteA     | Speed value (km/hr)     |

---

## Example CAN Frames

### Headlight ON

