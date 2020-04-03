  //badge
#include <SoftwareSerial.h>

//digicode
#include <Keypad.h>
#include <WatchDog.h>
#include <Key.h>
#include <avr/wdt.h>

//LED
#define LED_V 0
#define LED_R 8

const int NB_BADGE = 4;
char tab_badge[NB_BADGE][20] = {"000000000000", "050080891F13", "070081B6F9C9", "08002526474C"};
char tab_code[NB_BADGE][20] = {"......", "123456", "654321", "000000"};

int badge1 = 0;
bool psd = false;
int date_gache = 15000;
int date_badge = 15000;
int date_moteur = 2000;
int date_moteur2 = 5000;
int date2;
int dateM;
int dateM2;


void setup() {
    Serial.begin(9600);
    pinMode(LED_V, OUTPUT);
    pinMode(LED_R, OUTPUT);
    digitalWrite(LED_V, LOW);
    digitalWrite(LED_R, LOW);
  setup_accelerometre();
  setup_badge();
  setup_digicode();
  setup_gache();
  //setup_moteur();
}

void loop() {
 
  
  badge();
  
  if(badge1 != 0){
    Serial.println(badge1);
    gererClavier();   
 
    if(psd == true){
      Serial.println("VALIDE");
      gache();
    }

    else {
      Serial.println("NON VALIDE");
    }
  }
    moteur();
    accelerometre();
}
