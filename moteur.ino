//https://www.dfrobot.com/wiki/index.php/Arduino_Motor_Shield_(L298N)_(SKU:DRI0009)


 
 int E1 = 5;   
 int M1 = 4; 


void setup_moteur()  
{      
   pinMode(E1, OUTPUT);       
   pinMode(M1, OUTPUT);       
   
} 
  void moteur()   
   { 
   int value = 1; 
  
   if (millis() - dateM > date_moteur){
      value = 100;
      digitalWrite(M1,LOW);       
      analogWrite(E1, value);   //PWM Speed Control    
      dateM2 = millis();
      digitalWrite(LED_V, LOW);
      digitalWrite(LED_R, LOW); 
    }

  if(millis() - dateM2 > date_moteur2){
       
       value = 1;
      analogWrite(E1, value);
  }
   else {
      value = 1;
      analogWrite(E1, value);
   }       
 }
