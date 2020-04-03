


int E2 = 6;                      
int M2 = 7;                        

void setup_gache() 
{ 
       pinMode(E2, OUTPUT);       
       pinMode(M2, OUTPUT);    
} 

void gache() 
{  

   int value = 255; 
if (psd == true)
  { 
    digitalWrite(M2, LOW);       
    analogWrite(E2, value);   //PWM Speed Control
    date2 = millis();
    dateM = millis();
  }  

if (millis() - date2 > date_gache){
  digitalWrite(M2, LOW);       
    analogWrite(E2, 0);
}
}
