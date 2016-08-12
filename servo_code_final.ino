#include <Servo.h>

Servo sam;
Servo saf;
int directin = 90; // direction variable 
int directin1 = 90;

int left_move = 9;    // pin defined
int right_move = 10;

int left=0;   // variable for left and right input defined
int right=0;

int up_move = 11;    // pin defined
int down_move = 12;

int up = 0;   // variable for left and right input defined
int down = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
sam.attach(4);
saf.attach(5);

pinMode( left_move , INPUT);
pinMode( right_move ,INPUT );

pinMode( up_move , INPUT);
pinMode( down_move ,INPUT );

sam.write( directin ); // inital direction of servo is selected
saf.write( directin1 );
}


void loop() {
  // put your main code here, to run repeatedly:

left =digitalRead (left_move);      // taking input every time from user
right =digitalRead (right_move);


up =digitalRead (up_move);      // taking input every time from user
down =digitalRead (down_move);
//-------------------------------------------------------------------

  if ( left == HIGH && directin> 0  ){

    directin -= 2;
    sam.write( directin );
    Serial.println("I am going left")   ;
  }

  
  if ( right == HIGH && directin < 180 ){

    directin += 2;
    sam.write( directin );
    Serial.println("Weeeeeeee Right");
  }
//-----------------------------------------------------------------------

  if ( up == HIGH && directin1 > 0 ){

    directin1 += 2;
    saf.write( directin1 );
    Serial.println("-------------------------I up")   ;
  }

  
  if ( down == HIGH && directin1 < 180 ){

    directin1 -= 2;
    saf.write( directin1 );
    Serial.println("down------");
  }
  
  
delay(15);
 // left = 0 ;
 // right = 0 ;
}
