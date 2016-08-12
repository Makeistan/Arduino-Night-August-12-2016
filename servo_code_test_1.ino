#include <Servo.h>

Servo big;
int directin = 90; // direction variable 

int left_move = 9;    // pin defined
int right_move = 10;

int left;   // variable for left and right input defined
int right;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
big.attach(4);

pinMode( left_move , INPUT);
pinMode( right_move ,INPUT );

big.write( directin ); // inital direction of servo is selected

}


void loop() {
  // put your main code here, to run repeatedly:

left =digitalRead (left_move);      // taking input every time from user
right =digitalRead (right_move);
  

  if ( left == HIGH && directin > 0 ){

    directin -= 2;
    big.write( directin );
    Serial.println("I am going left")   ;
  }

  
  if ( right == HIGH && directin < 180 ){

    directin += 2;
    big.write( directin );
    Serial.println("Weeeeeeee Right");
  }
  delay(15);
 
}
