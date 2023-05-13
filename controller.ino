
// Line Follower Robot Using L298N Motor Driver

#define enA 6   //Enable1 L298 Pin enA 
#define in1 7   //Motor1 L298 Left Pin in1 
#define in2 8   //Motor1 L298 Left Pin in2 
#define in3 9   //Motor2 L298 Right Pin in3
#define in4 10  //Motor2 L298 Right Pin in4 
#define enB 11  //Enable2 L298 Pin enB 

#define IR_L 12 //IR sensor Left
#define IR_R 13 //IR sensor Right

void setup() {
  pinMode(in1,OUTPUT);  // declare as output for L298 Pin in1 
  pinMode(in2,OUTPUT);  // declare as output for L298 Pin in2 
  pinMode(in3,OUTPUT);  // declare as output for L298 Pin in3 
  pinMode(in4,OUTPUT);  // declare as output for L298 Pin in4
  pinMode(enA,OUTPUT);  // declare as output for L298 Pin enA 
  pinMode(enB,OUTPUT);  // declare as output for L298 Pin enB 

  pinMode(IR_L,INPUT);  // declare if sensor as input  
  pinMode(IR_R,INPUT);  // declare if sensor as input  

  analogWrite(enA,120); // Write The Duty Cycle 0 to 255 Enable Pin enA for Left Motor Speed 
  analogWrite(enB,120); // Write The Duty Cycle 0 to 255 Enable Pin enB for Right Motor Speed
}

void loop() {
  if(digitalRead(IR_L) == LOW && digitalRead(IR_R) == LOW)  forward(); //if Left Sensor and Right Sensor are at White color then it will call forword function
  if(digitalRead(IR_L) == HIGH && digitalRead(IR_R)== LOW)  left();    //if Left Sensor is Black and Right Sensor is White then it will call turn left function 
  if(digitalRead(IR_L) == LOW && digitalRead(IR_R) == HIGH) right();   //if Left Sensor is White and Right Sensor is Black then it will call turn right function 
  if(digitalRead(IR_L) == HIGH && digitalRead(IR_R)== HIGH) Stop();    //if Left Sensor and Right Sensor are at Black color then it will call Stop function
}

void forward() {  //forword
  digitalWrite(in1,HIGH); //Left Motor forword Pin 
  digitalWrite(in2,LOW);  //Left Motor backword Pin 
  digitalWrite(in3,HIGH); //Right Motor forword Pin 
  digitalWrite(in4,LOW);  //Right Motor backword Pin 
}

void left() { //left
  digitalWrite(in1,LOW);  //Left Motor forword Pin 
  digitalWrite(in2,HIGH); //Left Motor backword Pin 
  digitalWrite(in3,HIGH); //Right Motor forword Pin 
  digitalWrite(in4,LOW);  //Right Motor backword Pin 
}

void right() {  //right
  digitalWrite(in1,HIGH); //Left Motor forword Pin 
  digitalWrite(in2,LOW);  //Left Motor backword Pin 
  digitalWrite(in3,LOW);  //Right Motor forword Pin 
  digitalWrite(in4,HIGH); //Right Motor backword Pin 
}

void Stop() { //Stop
  digitalWrite(in1,LOW);  //Left Motor forword Pin 
  digitalWrite(in2,LOW);  //Left Motor backword Pin 
  digitalWrite(in3,LOW);  //Right Motor forword Pin 
  digitalWrite(in4,LOW);  //Right Motor backword Pin 
}
