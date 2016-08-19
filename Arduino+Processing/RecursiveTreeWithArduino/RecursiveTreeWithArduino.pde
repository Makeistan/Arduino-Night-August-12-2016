/*
* Recursive Tree
* by Daniel Shiffman 
*
* Renders a simple tree-like structure via recursion
* Branching angle calculated as a function of horizontal mouse  location
*/ 
import processing.serial.*; // reference the serial library

import cc.arduino.*; // reference the arduino library

Arduino arduino; // create a variable arduino of the Arduino data type

float theta;
float multiple;

void setup() 
{
  size(500,500);
  smooth();
  println(Serial.list()); // List all the available serial ports:
  arduino = new Arduino(this, "COM15", 57600);
}

void draw()
{
  color Quswar = color(100,200,150);
  color RGBColor = color(arduino.analogRead(0)*5, arduino.analogRead(0)*2, arduino.analogRead(0)/6);
  background(Quswar);
  frameRate(30);
  stroke(255);
  // Let's pick an angle 0 to 90 degrees based on the mouse position
/* float a = (mouseX / (float) width) * 90f; // original line */
float a = map(arduino.analogRead(0),0,1024,0,90);
//float a = (arduino.analogRead(0) / (float) width) * 90f;
println(a);
 // Convert it to radians
  theta = radians(a);
  // Start the tree from the bottom of the screen
  translate(width/2,height);
  // Draw a line 60 pixels
  line(0,0,0,-60);
  // Move to the end of that line
  translate(0,-60);
  // Start the recursive branching!
//  branch(arduino.analogRead(0));
  branch(a+a);
}

void branch(float h) 
{
  // Each branch will be 2/3rds the size of the previous one
  h *= 0.66f;

  // All recursive functions must have an exit condition!!!!
  // Here, ours is when the length of the branch is 2 pixels or less
  if (h > 2) {
    pushMatrix();    // Save the current state of transformation (i.e. where are we now)
    rotate(theta);   // Rotate by theta
    line(0,0,0,-h);  // Draw the branch
    translate(0,-h); // Move to the end of the branch
    branch(h);       // Ok, now call myself to draw two new branches!!
    popMatrix();     // Whenever we get back here, we "pop" in order to restore the previous matrix state

    // Repeat the same thing, only branch off to the "left" this time!
    pushMatrix();
    rotate(-theta);
    line(0,0,0,-h);
    translate(0,-h);
    branch(h);
    popMatrix();
  }
}