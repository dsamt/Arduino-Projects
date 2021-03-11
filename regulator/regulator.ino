#define In A1
#define pulse 5
uint8_t duty_cycle = 148;
float desiredVoltage = 12.0;
uint8_t max_duty_cycle = 250;
uint8_t min_duty_cycle = 0;
int Vi;
int divider = 3;
float voltage;
int Aref = 5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pulse, OUTPUT);
pinMode(In, INPUT);
TCCR0B = TCCR0B & 0b11111000 | 0x02;
analogWrite(pulse, duty_cycle);
}

void loop() {
  // put your main code here, to run repeatedly:
Vi = analogRead(In);
voltage = float(Vi) * 15 / 1023;
if (voltage < desiredVoltage && duty_cycle < max_duty_cycle){
  duty_cycle++;
}

if (voltage > desiredVoltage && duty_cycle > min_duty_cycle){
  duty_cycle--;
}
analogWrite(pulse, duty_cycle);
Serial.print("Vi: ");Serial.println(Vi);
Serial.print("voltage: ");Serial.println(voltage);
Serial.print("duty cycle: ");Serial.println(duty_cycle);
}
