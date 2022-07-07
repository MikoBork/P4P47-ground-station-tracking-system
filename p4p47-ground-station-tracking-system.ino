// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 400;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);


void setup()
{
	// set the speed rpm:
    int speedRPM = 100;
	myStepper.setSpeed(speedRPM);
	// initialize the serial port:
	Serial.begin(9600);
}

void loop() 
{
	// step one revolution in one direction, wait 1s:
	Serial.println("clockwise");
	myStepper.step(durationSteps(110, 10));      // clockwise = +ve
	delay(1000);

	// step one revolution in the other direction, wait 1s:
	Serial.println("counterclockwise");
	myStepper.step(-durationSteps(110, 10));     // counter-clockwise = -ve
	delay(1000);
}

int durationSteps(int speedRPM, int seconds) 
{
    myStepper.setSpeed(speedRPM);
    int revolutionPeriod = 1/(speedRPM/60);         // rpm to rps, then T = 1/rps
    int revolutions = seconds/revolutionPeriod;     // duration/period for total revs
    int steps = revolutions * stepsPerRevolution;   // how many steps motor must complete
    return steps;
}