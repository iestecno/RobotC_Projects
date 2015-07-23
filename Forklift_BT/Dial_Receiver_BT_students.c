//Defining the variables

int button;
int power;
//int testMessage;


//Function to read messages
void readMessages()
{
  	//Read the messages to variables
	  button = messageParm[0];
	  power = messageParm[1];
	  //testMessage = messageParm[2]; I used this to check the conditional

	  nxtDisplayTextLine(2,"Button: %d", button);
		nxtDisplayTextLine(4,"Speed: %d", power);


		if (bQueuedMsgAvailable())  // If we received a message we have to erase it to keep using new ones
	  {

		   ClearMessage();

		}

	  else

		{

			wait1Msec (5);

		}
}


void setSpeed()
{
	// We use conditionals to control the Forklift

  	if(button == 0)                        								// We move in a straight way
		{
	  	//nSyncedMotors = synchBC; 													// We syncronize the motor to follow an straight line
	  	//nSyncedTurnRatio = 100;
	  	motor[motorB] = power;
	  	motor[motorC] = power;
	  	motor[motorA] = 0;
  	}

  	else if (button == 1)																// If we press the Right Arrow
		{
			motor[motorB] = power;
	  	motor[motorC] = 0;
	  	motor[motorA] = 0;
		}

		else if (button == 2)																// If we press the left Arrow
		{
	  	motor[motorB] = 0;
	  	motor[motorC] = power;
	  	motor[motorA] = 0;
		}

		else if (button == 3)										           	// If the Orange Button is pressed
		{
  		motor[motorB] = 0;
	  	motor[motorC] = 0;
	  	motor[motorA] = power;
		}

		else if (button == 4)										           	// If the Touch Sensor is pressed
		{
  		nxtDisplayTextLine(4,"Stop and Reset");
  	}

  	else 																		           	// If Nothing is pressed
		{

  	}

}

task main()
{

  while(true)
  {

  	readMessages();
		setSpeed();
		wait1Msec(50);																			//We check for a messages every 50ms

	}

}
