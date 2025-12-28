# Fuel Level Conversion Logic  
Ultrasonic Sensor → Fuel Percentage Mapping

---

## Overview

The ultrasonic sensor measures the **distance between the sensor and fuel surface**.
This distance value is transmitted over CAN and converted into a **fuel percentage**
at the dashboard node.

> Conversion logic is implemented in `dashboard.c` under **CAN ID = 0x02**

---

## Input Parameter

| Parameter | Description                          |
|----------:|--------------------------------------|
| byteA     | Distance from ultrasonic sensor (cm) |

---

## Fuel Percentage Mapping Table

| Distance Range (cm) | Fuel Percentage Displayed |
|--------------------:|--------------------------:|
| 0  – 5              | 95 %                      |
| >5 – 10             | 75 %                      |
| >10 – 15            | 50 %                      |
| >15 – 20            | 25 %                      |
| >20 – 25            | 10 %                      |
| >25                 | 0 %                       |

---

## Conversion Logic (Code Reference)

```c
if((D>=0)&&(D<=5))
        D=95;
else if((D>5)&&(D<=10))
        D=75;
else if((D>10)&&(D<=15))
        D=50;
else if((D>15)&&(D<=20))
        D=25;
else if((D>20)&&(D<=25))
        D=10;
else
        D=0;

