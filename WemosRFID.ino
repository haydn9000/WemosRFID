
/* Pin layout used:
 * -----------------------------------------
 *             MFRC522      Wemos       
 *             Reader/PCD   D1 mini v2.2.0
 * Signal      Pin          Pin
 * -----------------------------------------
 * RST/Reset   RST          D0
 * SPI SS      SDA(SS)      D8
 * SPI MOSI    MOSI         D7
 * SPI MISO    MISO         D6
 * SPI SCK     SCK          D5
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         D0          // Configurable, see typical pin layout above
#define SS_PIN          D8         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() {
  Serial.begin(74880);   // Initialize serial communications with the PC
  delay(1000);
  Serial.println("Setup");
  
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  Serial.println("Setup done");
}

void loop() {
//  Serial.println("Loop...");
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    //delay(50);
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    //delay(50);
    return;
  }

  // Show some details of the PICC (that is: the tag/card)
  Serial.print(F("Card UID:"));
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  
  // Dump debug info about the card; PICC_HaltA() is automatically called
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  delay(1000);
}

// Helper routine to dump a byte array as hex values to Serial
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
} 
