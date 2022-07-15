// #include <PID_v1.h>
#include <AccelStepper.h>

// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 400;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);

// Pins
#define limitSwitchPin 2

// Global Variables
bool CW = true; // 1 = CW, 0 = CCW
unsigned long switchTimeStore = millis();
unsigned long switchTimeCurrent = millis();

void setup()
{
	// set the speed rpm:
    int speedRPM = 100;
	myStepper.setSpeed(speedRPM);

	// Pin setup
	pinMode(limitSwitchPin, INPUT_PULLUP);

	// Interrupts
	attachInterrupt(digitalPinToInterrupt(limitSwitchPin), limitSwitchHit, FALLING);

	// initialize the serial port:
	Serial.begin(9600);

	interrupts();

	//====================================================================================
	// PROGRAM BEGIN - Perform calibration (E-stop will cause program to start again here)
	Serial.println("cal 1");
	myStepper.step(durationSteps(100, 1));	// Just for testing turn 1s CW then 1s CCW
	delay(500);
	Serial.println("cal 2");
	myStepper.step(-durationSteps(100, 1));
	delay(1000);
	Serial.println("starting program");
}

void loop() 
{
	if (CW) {
		myStepper.step(1);
	} else {
		myStepper.step(-1);
	}


	// // step one revolution in one direction, wait 1s:
	// Serial.println("clockwise");
	// myStepper.step(durationSteps(100, 10));      // clockwise = +ve
	// delay(1000);

	// // step one revolution in the other direction, wait 1s:
	// Serial.println("counterclockwise");
	// myStepper.step(-durationSteps(100, 10));     // counter-clockwise = -ve
	// delay(1000);
}

float durationSteps(int speedRPM, int seconds) 			// For testing, set a duration (blocking function)
{
    myStepper.setSpeed(speedRPM);
    float RPS = speedRPM/60;         // rpm to rps
    float steps = seconds * RPS * stepsPerRevolution;   // how many steps motor must complete
    return steps;
}

void limitSwitchHit() {			// TODO: for now it just switches the direction
	switchTimeCurrent = millis();
	if ((switchTimeCurrent - switchTimeStore) > 200) {
		CW = !CW;
		switchTimeStore = switchTimeCurrent;
	}
}