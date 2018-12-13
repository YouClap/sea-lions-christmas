int pins[] = {1, 3, 15, 13, 12, 14};
int actual_pin = 0;

int status_c = 0;

void setup() {
  for(int i = 0; i < 6; i++) {
    pinMode(pins[i], OUTPUT);
  }
}
 
void loop() {
  digitalWrite(pins[actual_pin], HIGH);
  delay(500);
  digitalWrite(pins[actual_pin], LOW);
  actual_pin++;
  status_c++;
  if(actual_pin >= 6){
    actual_pin = 0;
  }
  if(status_c >= 30){
    status_c = 0;
    for(int i = 0; i <= 200; i++){
      actual_pin = random(0, 6);
      digitalWrite(pins[actual_pin], HIGH);
      delay(50);
      digitalWrite(pins[actual_pin], LOW);
    }

    for(int delay_ = 500; delay_ >= 0; delay_-=20){
      for(int i = 0; i < 6; i+=2){
        digitalWrite(pins[i], HIGH);
        digitalWrite(pins[i+1], HIGH);
        delay(delay_);
        digitalWrite(pins[i], LOW);
        digitalWrite(pins[i+1], LOW);
      }
      if (delay_ < 250){
        delay_ += 15;
      }
    }

    for(int x = 0; x < 10; x+=1){
      for(int i = 0; i < 6; i+=1){
          digitalWrite(pins[i], HIGH);
      }
      delay(500);
      for(int i = 0; i < 6; i+=1){
          digitalWrite(pins[i], LOW);
      }
      delay(500);
    }
    actual_pin=0;
  }
}
