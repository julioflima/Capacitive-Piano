#include <CapacitiveSensor.h>
#include <TimerOne.h>

int buzzer = 10;
int sender = 7;
int receiver_0 = 8;
int receiver_1 = 14;
int receiver_2 = 2;
int receiver_3 = 3;
int receiver_4 = 4;
int receiver_5 = 5;
int receiver_6 = 6;

long total[7];

CapacitiveSensor cs[7]={
  CapacitiveSensor(sender,receiver_0),
  CapacitiveSensor(sender,receiver_1),
  CapacitiveSensor(sender,receiver_2),
  CapacitiveSensor(sender,receiver_3),
  CapacitiveSensor(sender,receiver_4),
  CapacitiveSensor(sender,receiver_5),
  CapacitiveSensor(sender,receiver_6)
};

void setup() {  

   cs[2].set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

   Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
   Timer1.initialize(100000);  //Set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
   Timer1.attachInterrupt(happen);  //Attach the service routine here

}  
   
 void loop() {  
  
    for(int r=0; r<7;r++)
    {
      
      while(total[r]>0)
      {
        nota(r);
      }
      
      noTone(buzzer);
    }
    
}

void happen()
{
  for(int r=0; r<7;r++)
  {
    total[r] =  cs[r].capacitiveSensor(10);
  }
}
 
void nota(int nota_r)
{
  switch (nota_r) {
     case 0:
      {
        tone(buzzer, 132);
        Serial.println("Passou 1");
      }
      break;
     case 1:
      {
        tone(buzzer, 148.5);
        Serial.println("Passou 2");
      }
      break;
     case 2:
      {
        tone(buzzer, 165);
        Serial.println("Passou 3");  
      }
      break;
     case 3:
      {
        tone(buzzer, 175.5);
        Serial.println("Passou 4 ");
      }
      break;
     case 4:
      {
        tone(buzzer, 198);
        Serial.println("Passou");
      }
      break;
      case 5:
      {
        tone(buzzer, 220);
        Serial.println("Passou 6");
      }
      break;
     case 6:
      {
        tone(buzzer, 247.5);
        Serial.println("Passou 7");
      }
      break;
     case 7:
      {
        tone(buzzer, 264);
        Serial.println("Passou 8");
      }
      break;
    default: 
      noTone(buzzer);
    break;
  }
}


