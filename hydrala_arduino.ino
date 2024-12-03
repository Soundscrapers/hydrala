const int TrigPin1 = 22;
const int TrigPin2 = 24;
const int TrigPin3 = 26;
const int TrigPin4 = 28;

const int EchoPin1 = 2;
const int EchoPin2 = 3;
const int EchoPin3 = 4;
const int EchoPin4 = 5;

const int TRIGGER_DELAY_IN_MICROSECONDS = 30000;

int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;

// the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  Serial.begin(57600);
  pinMode(TrigPin1, OUTPUT);
  pinMode(TrigPin2, OUTPUT);
  pinMode(TrigPin3, OUTPUT);
  pinMode(TrigPin4, OUTPUT);

  pinMode(EchoPin1, INPUT);
  pinMode(EchoPin2, INPUT);
  pinMode(EchoPin3, INPUT);
  pinMode(EchoPin4, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

int trigger(char* name, int trigger_pin, int echo_pin, int led_pin) {
  int brightness = 0;
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  int distance_in_cm = pulseIn(echo_pin, HIGH, TRIGGER_DELAY_IN_MICROSECONDS) / 58;
  if (distance_in_cm >= 1 && distance_in_cm <= 150) {
    float d = distance_in_cm * 1.5;
    brightness = 255 - d;
  }

  analogWrite(led_pin, brightness);

  Serial.print(name);
  Serial.println(distance_in_cm);
  Serial.println();
  return 0;
}


void loop() {
  trigger("a", TrigPin1, EchoPin1, led1);
  trigger("b", TrigPin2, EchoPin2, led2);
  trigger("c", TrigPin3, EchoPin3, led3);
  trigger("d", TrigPin4, EchoPin4, led4);


  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  //  Serial.println();

  delay(100);
}
