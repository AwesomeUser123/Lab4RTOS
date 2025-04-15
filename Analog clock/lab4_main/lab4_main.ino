#include <scheduler.h>
#define LED_PIN 48
#define D3 6
#define D4 7

int led_status = 0;
void test_blinky(){
  led_status = 1 - led_status;
  digitalWrite(LED_PIN, led_status);
}


void TIMER_ISR(void *pvParameters) {
  
  while(1) {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // put your setup code here, to run once:
  for (int i=5;i<=22;i++)   {
    pinMode(i,OUTPUT);
  }
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);

  SCH_Init();
  SCH_Add_Task(Red1, 0 , 6000);
  SCH_Add_Task(Yellow1, 500, 6000);
  SCH_Add_Task(Green1, 1000, 6000);
  
  
  SCH_Add_Task(Red2, 1500, 6000);
  SCH_Add_Task(Yellow2, 2000, 6000);
  SCH_Add_Task(Green2, 2500, 6000);
  
  SCH_Add_Task(Red3, 3000, 6000);
  SCH_Add_Task(Yellow3, 3500, 6000);
  SCH_Add_Task(Green3, 4000, 6000);

  SCH_Add_Task(Red4, 4500, 6000);
  SCH_Add_Task(Yellow4, 5000, 6000);
  SCH_Add_Task(Green4, 5500, 6000);
}

void Red1()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
void Yellow1()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH); 
}
void Green1()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW); 
}
void Off1()   {
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
void Red2()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void Yellow2()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH); 
}
void Green2()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW); 
}
void Off2()   {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}


void Red3()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(10,HIGH);
  digitalWrite(17,HIGH);
}
void Yellow3()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(10,LOW);
  digitalWrite(17,HIGH); 
}
void Green3()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(10,HIGH);
  digitalWrite(17,LOW); 
}
void Off3()   {
  digitalWrite(10,LOW);
  digitalWrite(17,LOW);
}
void Red4()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(18,HIGH);
  digitalWrite(21,HIGH);
}
void Yellow4()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(18,LOW);
  digitalWrite(21,HIGH); 
}
void Green4()	{
  Off1(); Off2(); Off3(); Off4();
  digitalWrite(18,HIGH);
  digitalWrite(21,LOW); 
}
void Off4()   {
  digitalWrite(18,LOW);
  digitalWrite(21,LOW);
}
void loop() {
  SCH_Dispatch_Tasks();
}
