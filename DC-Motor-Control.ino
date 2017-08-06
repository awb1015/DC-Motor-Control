
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;
int onOffSwitchState = 0;
int previousOnOffSwitchState =0;
int directionSwitchState = 0;
int prevDirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeedTarget = 0;
int motorDirection = 1;
int currentSpeed = 0;
int previousSpeed = 0;

int pControl(int motorTargetSpeed, int currentSpeed){
  const int tauP = .5;
  const int error = 0;
  //Compute Error and Update
  error = currentSpeed - motorTargetSpeed;
  -error * tau;
  return 0;
}

int PDcontrol(int motorTargetSpeed, int previousSpeed, int currentSpeed){
  const int tauD = 3;
  //Place holder return statement

  //We'll need to call pControl
  pControl(motorTargetSpeed, currentSpeed);
  
  return 0;
}

int PIDcontrol(int motorTargetSpeed){
  int targetspeed = 0;
  
  //Place holder return statement
  return targetspeed;
}

int getSpeed(){
  int measuredSpeed = 0;
  //Some function to check our speed sensor of choice

  return measuredSpeed;
}


void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStatSwitchPin, INPUT);
  pinMode(controlPin1; OUTPUT);
  pinMode(controlPin2; OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);

void loop() {
  //Set values from user inputs
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  
  //Ensure we're happy with this
  motorSpeedTarget = analogRead(potPin)/4;
  currentSpeed = getSpeed();
  
  //If we've pressed the on/off then change motor state. This makes this a latching switch rather than momentary contact
  if((onOffSwitchState != previousOnOffSwitchState) && (onOffSwitchState == HIGH)){
    motorEnabled = !motorEnabled;
  }
  
  //If we've pressed to change direction then update, again this is created as a latching switch
  if((directionSwitchState != prevDirectionSwitchState) && (directionSwitchState == HIGH){
    motorDirection = !motorDirection;
  }
  
  //Set Direction
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else{
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  
  //Now actually run the motor, for now we write the targetSpeed, 
  if(motorEnabled == 1){
    //Now we'll call our control algorithm of choice here
    //Functions can be grouped in an array and we can select amongst them with a function pointer
    
    analogWrite(enablePin, motorSpeedTarget);
  }
  else{
    analogWrite(enablePin, 0);
  }
  
  //Set switch states
  prevDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  previousSpeed = currentSpeed;
  
}
