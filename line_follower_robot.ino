

//const int left_for = D0;  // gnd 1st pin  l293d  
//const int left_back =D1;   // power 2nd pin
//const int right_for = D2; //power 3rd pin
//const int right_back = D3; // gnd 4th pin
int left_for = D0;  // gnd 1st pin  l293d  
int left_back =D1;   // power 2nd pin
int right_for = D2; //power 3rd pin
int right_back = D3; // gnd 4th pin

int IR1=D7;
int IR2=D8;

void  forward()
{
  digitalWrite(right_for, HIGH);
  digitalWrite(right_back, LOW);
  digitalWrite(left_back, LOW);
  digitalWrite(left_for, HIGH);
  delay(200);
}

void backward()
{

  digitalWrite(right_for, LOW);
  digitalWrite(right_back, HIGH);
  digitalWrite(left_back, HIGH);
  digitalWrite(left_for, LOW);
  delay(200);
  digitalWrite(left_back, LOW);
  digitalWrite(right_back, LOW);
  delay(200);
}

void right()
{
  //  Serial.println("RIGHT");
  digitalWrite(right_for, LOW);
  digitalWrite(right_back, HIGH);
  digitalWrite(left_back, LOW);
  digitalWrite(left_for, HIGH);

  delay(200);
  digitalWrite(left_for, LOW);
  digitalWrite(right_back, LOW);
  delay(200);
}

void left()
{
  digitalWrite(right_for, HIGH);
  digitalWrite(right_back, LOW);
  digitalWrite(left_back, HIGH);
  digitalWrite(left_for, LOW);
  delay(200);
  digitalWrite(left_back, LOW);
  digitalWrite(right_for, LOW); delay(200);
}

void stopfn()
{
  digitalWrite(left_for, LOW);
  digitalWrite(left_back, LOW);
  digitalWrite(right_for, LOW);
  digitalWrite(right_back, LOW);
  Serial.print("STOP");

}
void setup() {
  Serial.begin(9600);
  pinMode(left_for, OUTPUT);
  pinMode(left_back, OUTPUT);
  pinMode(right_for, OUTPUT);
  pinMode(right_back, OUTPUT);
 
 
  stopfn();
}

void loop() {
  
    if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH) //black
    {
      
      stopfn();
    }

    else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW) //white
    {
         //Move both the Motors
      forward();
      
    }

    else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH)
    {
      
      right();
      delay(100);
    }

    else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW)
    {
      left();
      delay(100);
    }

    else
    {
      stopfn();

    }
  }
 
