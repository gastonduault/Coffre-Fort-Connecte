/*
  Software serial multple serial test

  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.

  The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

  created back in the mists of time
  modified 25 May 2012
  by Tom Igoe
  based on Mikal Hart's example

  This example code is in the public domain.
  a
*/


SoftwareSerial mySerial(A0, A0); // RX, TX


unsigned long date = 0;

void setup_badge() {
    // juste pour voir si la carte reboote
    Serial.println("Goodnight moon!");

    // set the data rate for the SoftwareSerial port
    mySerial.begin(9600);
}

void badge() { // run over and over
    char buffer_[20] = "";
    if (mySerial.available())
    {
        mySerial.readBytesUntil(3, buffer_, 20);
        Serial.println(buffer_ + 1);
    }

    if ((badge1 == 0) || (millis() - date > date_badge))
    {
        badge1 = 0;
        for (int i=0; i<NB_BADGE; i++)
        {
            if (strncmp(tab_badge[i], buffer_ + 1, 12) == 0) {
                Serial.println("Badge # VALIDE");
                badge1 = i;
                date = millis();
            }
        }
    }
    
}
