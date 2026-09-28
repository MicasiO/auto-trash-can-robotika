#include <Servo.h>

#define OPEN_TRIG_PIN 13
#define OPEN_ECHO_PIN 11

#define FULL_TRIG_PIN 7
#define FULL_ECHO_PIN 6

#define SERVO_PIN 4

#define FULL_LED_PIN 8
#define HALF_LED_PIN 2
#define EMPTY_LED_PIN 12

static Servo servo;
static bool is_open = false;

void setup()
{
  pinMode(OPEN_TRIG_PIN, OUTPUT);
  pinMode(OPEN_ECHO_PIN, INPUT);
  pinMode(FULL_TRIG_PIN, OUTPUT);
  pinMode(FULL_ECHO_PIN, INPUT);
  
  pinMode(FULL_LED_PIN, OUTPUT);
  pinMode(HALF_LED_PIN, OUTPUT);
  pinMode(EMPTY_LED_PIN, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0);

  Serial.begin(9600);
}

long get_sensor_dist(const int trig_pin, const int echo_pin) {
  digitalWrite(trig_pin, LOW);
  delay(2);

  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  long distance = duration / 29 / 2;
  
  return distance;
}

void rotate_servo(const int servo_pin, const bool open) {
  if (open) {
    for (int i = 0; i < 90; i++) {
      servo.write(i);
      delay(5);
    }
  } else {
    for (int i = 90; i >= 0; i--) {
      servo.write(i);
      delay(5);
    }
  }
}

void loop() {
  long distance_open = get_sensor_dist(OPEN_TRIG_PIN, OPEN_ECHO_PIN);
  delay(50);
  long distance_full = get_sensor_dist(FULL_TRIG_PIN, FULL_ECHO_PIN);

  if (distance_full < 10) {
  	digitalWrite(FULL_LED_PIN, HIGH);
    digitalWrite(HALF_LED_PIN, LOW);
    digitalWrite(EMPTY_LED_PIN, LOW);
  } else if (distance_full < 30) {
    digitalWrite(FULL_LED_PIN, LOW);
    digitalWrite(HALF_LED_PIN, HIGH);
    digitalWrite(EMPTY_LED_PIN, LOW);
  } else {
    digitalWrite(FULL_LED_PIN, LOW);
    digitalWrite(HALF_LED_PIN, LOW);
    digitalWrite(EMPTY_LED_PIN, HIGH);
  }
  
  if (distance_open <= 40) {
    if (!is_open) {
      rotate_servo(SERVO_PIN, true);
      is_open = true;
    }
  } else {
    if (is_open) {
      delay(2000);
      rotate_servo(SERVO_PIN, false);
      is_open = false;
    }
  }

  delay(500);
}
