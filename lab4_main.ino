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
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);

  SCH_Init();
  SCH_Add_Task(Red1, 0 , 1000);
  SCH_Add_Task(Yellow1, 800 , 1000);
  SCH_Add_Task(Green1, 500 , 1000);
  
  
  SCH_Add_Task(Red2, 500 , 1000);
  SCH_Add_Task(Yellow2, 300 , 1000);
  SCH_Add_Task(Green2, 0 , 1000);
  
}

void Red1()	{
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}

void Yellow1()	{
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH); 
}
void Green1()	{
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW); 
}

void Red2()	{
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}

void Yellow2()	{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH); 
}
void Green2()	{
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW); 
}

void loop() {
  SCH_Dispatch_Tasks();
}
