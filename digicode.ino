void keypadEvent(KeypadEvent eKey);

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {12, 11, 10, 9};// Connecter le keypad ROW0, ROW1, ROW2 and ROW3 sur les pins 8.7.6.5
byte colPins[COLS] = {3, 2, 13};// Connecter le keypad COL0, COL1 and COL2 sur les pins 4.3


//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char buffer_[7] = {0};
char passwd[7] = {0};

void setup_digicode() {

  wdt_enable (WDTO_8S);
}


//----------------------------------------------------------


int compteur = 0;

void gererClavier()
{
  wdt_reset ();  // remet à zéro le timeout du watchdog
      Serial.print("---");
      Serial.print(buffer_);
      Serial.println("---");

  char customKey = keypad.getKey();

  if (customKey != NO_KEY) {
    
    if (customKey == '#') {
      compteur = 0;
      buffer_[compteur] = 0;
      //passwd[compteur] = 0;
    }

    if (customKey == '*') {
      Serial.println("---");
      Serial.println(buffer_);
      Serial.println("---");
      Serial.println();
      Serial.println();
      Serial.println();

      if (strncmp(tab_code[badge1], buffer_, 6) == 0) {
        Serial.println("mot de passe VALIDE:");
        Serial.println(buffer_);
        compteur = 0;
        buffer_[compteur] = 0;
        psd = true;
        digitalWrite(LED_V ,HIGH);
        digitalWrite(LED_R ,LOW);
      }

      else if (strncmp(tab_code[badge1], buffer_, 6) != 0) {
        Serial.println("mot de pas NON valide");
        compteur = 0;
        buffer_[compteur] = 0;
        psd = false;
        digitalWrite(LED_V ,LOW);
        digitalWrite(LED_R ,HIGH);
      }
    }
  
    else
    {
      buffer_[compteur] = customKey;
      compteur++;
      buffer_[compteur] = 0;
  
    }
  Serial.println(buffer_);
}
}
