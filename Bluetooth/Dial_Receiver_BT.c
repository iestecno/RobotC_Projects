int button;
int power;
//int testMessage;


void readMessages()
{
  	//Read the messages to variables
	  button = messageParm[0];
	  power = messageParm[1];
	  //testMessage = messageParm[2]; I used this to check the conditional

	  nxtDisplayTextLine(2,"Button: %d", button);
		nxtDisplayTextLine(4,"Speed: %d", power);

		//Something got through if the signals are not all zero
		//I've tried this first maybe works now!!
	  //if(button != 0 || speed  != 0  || testMessage != 0)


		if (bQueuedMsgAvailable())  // If we reveived a message we have to erase it to keep using new ones
	  {
			//In the example BT program the used the following lines
	  	//If I use it in this case the variables are resetted constantly

	  	//display the values as stored in the variables
		  //nxtDisplayTextLine(2,"Button: %d", button);
		  //nxtDisplayTextLine(4,"Speed: %d rpm", speed);
		  //nxtDisplayBigTextLine(6,"3: %d",message_third);

	  	// This is the only line we need
		  //Clear the messages, set them to 0 So we can keep processing them
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

  	if(button == 0)                        							// We move in a straight way
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

	  //Checking for a message every half a second is
	  //fine for this simple test
	  wait1Msec(50);

	}



}
