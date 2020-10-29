#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(13,2,4,9,10,11); 
SoftwareSerial nodemcu(2,3);

int parking1_slot1_ir_s = 5; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 6;

int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;

String sensor1="0"; 
String sensor2="0"; 
String sensor3="0"; 
String sensor4="0"; 

int LED1=A2;
int LED2=A3;
int LED3=A0;
int LED4=A1;


String cdata =""; // complete data, consisting of sensors values
void setup()
{ 
    lcd.begin(16,2);
    
//    Serial.begin(19200); 
    nodemcu.begin(9600);
    
    pinMode(parking1_slot1_ir_s, INPUT);
    pinMode(parking1_slot2_ir_s, INPUT);
    
    pinMode(parking2_slot1_ir_s, INPUT);
    pinMode(parking2_slot2_ir_s, INPUT);
    
//    pinMode(LED1,OUTPUT);
//    pinMode(LED2,OUTPUT);
//    pinMode(LED3,OUTPUT);
//    pinMode(LED4,OUTPUT);

}
String k="a";

void loop()
{   
    p1slot1(); 
    p1slot2();
    
    p2slot1();
    p2slot2();
    cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 ; 
    int space=(sensor1=="0"?0:1)+(sensor2=="0"?0:1)+(sensor3=="0"?0:1)+(sensor4=="0"?0:1);
    
    space=4-space;
    String s=String(space);
    
    lcd.print(s+" LEFT!!");
    for(int i=0;i<2;i++)
    {lcd.print("        ");}
        
    Serial.println(s+" LEFT!!"); 
    
    Serial.println(cdata); 
     nodemcu.println(cdata);
    delay(800); // 100 milli seconds
    cdata = ""; 
    
    digitalWrite(parking1_slot1_ir_s, HIGH); 
    digitalWrite(parking1_slot2_ir_s, HIGH); 
    
    digitalWrite(parking2_slot1_ir_s, HIGH);
    digitalWrite(parking2_slot2_ir_s, HIGH);

}

void p1slot1()
{
  if( digitalRead(parking1_slot1_ir_s) == LOW) 
  {
  sensor1 = "255";
  analogWrite(LED1,255);

  delay(100); 
  } 
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  sensor1 = "0";  
  analogWrite(LED1,0);
  delay(100);  
}
}

void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW) 
  {
  sensor2 = "255"; 
  analogWrite(LED2,255);
  delay(100); 
  }
if( digitalRead (parking1_slot2_ir_s) == HIGH)  
  {
  sensor2 = "0";  
  analogWrite(LED2,0);
  delay(100);
  } 
}
void p2slot1() // parking 1 slot3
{
  if( digitalRead(parking2_slot1_ir_s) == LOW) 
  {
  sensor3 = "255"; 
    analogWrite(LED3,255);

  delay(100); 
  }
if( digitalRead(parking2_slot1_ir_s) == HIGH)  
  {
  sensor3 = "0";
   analogWrite(LED3,0);

  delay(100);
  } 
}

void p2slot2() // parking 1 slot3
{
  if( digitalRead(parking2_slot2_ir_s) == LOW) 
  {
  sensor4 = "255";
    analogWrite(LED4,255);

  delay(100); 
  }
if( digitalRead(parking2_slot2_ir_s) == HIGH)  
  {
  sensor4 = "0";
    analogWrite(LED4,0);

  delay(100);
  } 
}
