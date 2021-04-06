const int pinA = 8;
const int pinB = 9;
const int pinC = 10;
const int pinD = 11;

const uint8_t MAX_STEP = 7;

uint8_t steps[8] = {
  0b0111,
  0b0011,
  0b1011,
  0b1001,
  0b1101,
  0b1100,
  0b1110,
  0b0110};

uint8_t current_step=0;
uint8_t step_direction=1;

uint8_t get_next_step(){   
  if(step_direction == 0){
    if(current_step >= MAX_STEP){
      current_step = 0;
    }else{
      current_step++;
    }
  }else{
    if(current_step == 0 || current_step > MAX_STEP){
      current_step = MAX_STEP;
    }else{
      current_step--;
    }
  }
  return current_step;
}

void step_motor(uint8_t step){
  if((steps[step] & 0b0001) > 0){
    digitalWrite(pinA,HIGH);
  }else{
    digitalWrite(pinA,LOW);
  }
  if((steps[step] & 0b0010) > 0){
    digitalWrite(pinB,HIGH);
  }else{
    digitalWrite(pinB,LOW);
  }
  if((steps[step] & 0b0100) > 0){
    digitalWrite(pinC,HIGH);
  }else{
    digitalWrite(pinC,LOW);
  }
  if((steps[step] & 0b1000) > 0){
    digitalWrite(pinD,HIGH);
  }else{
    digitalWrite(pinD,LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
step_motor(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  step_motor(get_next_step());
  delay(1);
}
