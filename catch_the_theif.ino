int pir = 2;
int buzzer = 4;
int led = 7;
int motion = LOW; // 움직임 초기값

void setup(){
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int value = digitalRead(pir); // 센서값을 받음
 if(value == HIGH){ // 움직임이 있을 때
if(motion == HIGH){ 
      digitalWrite(led, HIGH); // 불 들어옴 
      tone(buzzer, 131); // 부저 소리남 
      delay(1000);
      noTone(buzzer);
      delay(1000);
      tone(buzzer, 262);
      delay(1000);
      Serial.println("Caught the motion!"); //움직임 포착 출력
      motion = LOW;
    }
  }
  else{
    if(motion == LOW){ // 움직임이 없을 때
      digitalWrite(led, LOW); // 불 꺼짐 
      noTone(buzzer); // 부저 소리 안 남 
      delay(1000);
      Serial.println("No motion!"); // 움직임 없음 출력 
      motion = HIGH;
    }
  }
  
}
