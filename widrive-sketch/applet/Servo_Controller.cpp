#include <MegaServo.h>

#include "WProgram.h"
void setup();
void loop();
MegaServo servo1; MegaServo servo2;

void setup() {

  Serial.begin(9600);
  Serial.println("Ready");
  servo1.attach(10);
  servo2.attach(9);
  // Reset the Servo's
  servo1.write(90);
  servo2.write(90);
}

void loop() {

  static int v = 0;

  if ( Serial.available()) {
    char ch = Serial.read();

    switch(ch) {
      case '0'...'9':
        v = v * 10 + ch - '0';
        break;
      case 'd':
        servo1.write(v);
        Serial.println(v);
        v = 0;
        break;
      case 's':
        servo2.write(v);
        Serial.println(v);
        v = 0;
        break;
    }
        
  }

} 

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

