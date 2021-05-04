// Output pin connected to 555 timer which drives the Tx
const int tx = 8;

// Input pin from the Rx
const int rx = 7;

int state = 0;


void setup() {
  // Set serial communication to display
  Serial.begin(9600);
  
  // Tx pin as output
  pinMode(tx, OUTPUT);

  // Rx pin as output
  pinMode(rx, INPUT);
}

void loop() {
  // Port mapping sets pin high
  PORTB &= B00000001;
  
  // Delay for burst of 10 ultrasonic pulses
  delayMicroseconds(250);

  // Port mapping sets pin low
  PORTB |= B00000001; 

  // Delay for Tx to swtich off
  delayMicroseconds(250);

  // Check state of pin
  state = digitalRead(rx);

  if(state == HIGH){
    Serial.println("Object detected");
  }
  if(state == LOW){
    Serial.println("No object");
  }
  delay(250);
}