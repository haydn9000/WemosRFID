# WemosRFID
RFID reader using the RC522 RFID Module and Wemos D1 mini v2.2.0

The RC522 RFID Module creates a 13.56MHz electromagnetic field to communicate with the RFID tags (ISO 14443A standard tags). 

Pin Layout
----------

|           | MFRC522 | Wemos D1 mini v2.2.0 (ESP8266) |
|-----------|---------|---------------|
| Signal    | Pin     | Pin           |
| RST/Reset | RST     | D0            |
| SPI SS    | SDA(SS) | D8            |
| SPI MOSI  | MOSI    | D7            |
| SPI MISO  | MISO    | D6            |
| SPI SCK   | SCK     | D5            |


![Device Assembled](https://github.com/haydnady/WemosRFID/blob/main/img/housing_top_1.jpg)

![Electronics](https://github.com/haydnady/WemosRFID/blob/main/img/wiring_job.jpg)