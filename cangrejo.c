//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                Cangrejo gigante                                                                         //
//                                                                                                                                              //
//                                                Programa creado por: Julian Caro Linares                                                      //
//                                                                                                                                              //
//                                                         jcarolinares@gmail.com                                                               //
//                                                                                                                                              //
//                                                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

task sensores();

task main()
{
	SetSensorType(S1, sensorSoundDB);
SetSensorType(S3, sensorLightInactive);
SetSensorType(S4,sensorSONAR);

	StartTask(sensores);
nSyncedMotors=synchAB;
nSyncedTurnRatio=-100;
	while(true)
	{
	 motor[motorA]=25;
	 motor[motorB]=synchAB;
	 wait1Msec(5000);
	 motor[motorA]=0;
	 motor[motorB]=synchAB;
	 wait1Msec(1000);
	  motor[motorA]=-25;
	 motor[motorB]=synchAB;
	 wait1Msec(5000);
	 motor[motorA]=0;
	 motor[motorB]=synchAB;
	 wait1Msec(1000);
	}
}

task sensores()
{
  while(true)
  {
  	if(SensorValue(S1)<5)//luz//
   {
    SetSensorType(S1, sensorLightActive);
    wait1Msec(1000);
   }
   if(SensorValue(S4)<25)//sonar//
   {
   motor[motorA]=0;
	 motor[motorB]=synchAB;
   }
   if(SensorValue(S3)>80)//sonido//
   {
    PlaySound(soundBeepBeep);
    wait1Msec(1000);
   }

   SetSensorType(S1, sensorLightInactive);
  }
}
