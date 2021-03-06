#pragma config(Sensor, S1,     touchSensor,    sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int buttonTest;
int speed;
int encoderCount;


void measureRPM() 																							// Function to measure the rotation speed in rpm
{

	nMotorEncoder[motorC] = 0;																		// Initialize the rotation sensor of the servo
	wait1Msec(100);																								// Wait for 0,1 sec to measure the final angle
	encoderCount = nMotorEncoder [motorC];

	speed = 10 *((60* encoderCount / 360));												//Converting the units to rpm

	// We add limits to the possible speed values

	if (speed > 100)
	{
		speed = 100;
	}

	else if (speed < -100)
	{
		speed = -100;
	}

	else if (speed == -0)																					// Just in case as this is a reported bug of the NXT
	{
		speed = 0;
	}


	nxtDisplayTextLine(1,"Encoder=%d", nMotorEncoder[motorA]); 		//Displaying the result of the angle measured
	nxtDisplayTextLine (2, "speed %d rpm", speed);								//Displaying the result in rpm

}


task main()
{

	while (true)
	{
		wait1Msec(100);
		if(nNxtButtonPressed == 1)                        // if the current pressed button is 1 (the Right Arrow):
		{
	  	buttonTest = 1;  																	// We want to send 1
			nxtDisplayTextLine(4,"Button: %d",buttonTest);
  	}

  	else if (nNxtButtonPressed == 2)
		{
			buttonTest= 2;
			nxtDisplayTextLine(4,"Button: %d",buttonTest);
		}

		else if (nNxtButtonPressed == 3)
		{
	  	buttonTest = 3;  																	// We want to send 2
	  	nxtDisplayTextLine(4,"Button: %d",buttonTest);
		}

		else if (SensorValue [touchSensor] == 1)           	// if the SensorTouch is pressed
		{
  		buttonTest = 4;  																	// We want to send 4
			nxtDisplayTextLine(4,"Button: %d",buttonTest);
  	}

  	else 																		           	// If Nothing is pressed
		{
  		buttonTest = 0;  																	// We want to send 0
			nxtDisplayTextLine(4,"No Button Pressed");
  	}

  	measureRPM();																				// We call the function to measure the speed of dial (motorC)

  	sendMessageWithParm(buttonTest, speed);
  	wait1Msec(100);
  }

  	//int number_1 = 5;
  //int number_2 = -1;
  //int number_3 = 700;

	//This sends through three values: 5, -1 and 700


	//Let's wait a bit and send something else
	//wait1Msec(3000);
	//number_1 = 2;
	//number_2 = 4;
	//number_3 = 6;
	//sendMessageWithParm(number_1,number_2,number_3);

}
