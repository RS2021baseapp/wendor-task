 #define MOTOR_IN1        PD0             // Motor direction pin 1
 #define MOTOR_IN2        PD1            // Motor direction pin 2
 #define STATUS           PA3           // Led Status
 #define SENSOR_PIN       PB6
 #define UART_TX          PA9           // UART TX pin
 #define UART_RX          PA10         // UART RX pin

bool item_dispensed = false;  // Track if the item was dispensed successfully


void motor_start()
{
  digitalWrite(MOTOR_IN2, HIGH);   
  digitalWrite(MOTOR_IN2, LOW);    
  digitalWrite(STATUS, LOW);   // LED HIGH During motor run
  Serial.println("motor running forward");  
}

void motor_stop() 
{
  digitalWrite(MOTOR_IN2, LOW);   
  digitalWrite(MOTOR_IN2, LOW);    
  digitalWrite(STATUS, HIGH);    //// LED Low when there is no operation running
}


void sensor_isr() {
  item_dispensed = true;
  motor_stop();
}

void setup() {
    pinMode(MOTOR_IN2,OUTPUT);
    pinMode(MOTOR_IN2,OUTPUT);
    pinMode(STATUS,OUTPUT);
    pinMode(SENSOR_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), sensor_isr, FALLING);
    Serial.begin(115200);    // UART communication setup

     // Initial motor direction (stop)
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
      char command = Serial.read();
       if (command == 'D') {
          item_dispensed = false;
           motor_start();
           while (!item_dispensed) {
        delay(100);
      }

       Serial.println("S");
       Serial.println("Item Dispensed Successfully");
    }
  }
}
