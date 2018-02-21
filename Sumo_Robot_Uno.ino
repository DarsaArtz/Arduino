#include <ArduinoRobot.h>

//Motors
int mRB = xx; // pin
int mRF = xx; // pin
int mLB = xx; // pin
int mLF = xx; // pin

//IR
int oSen_F = xx; // pin
int oSen_B = xx; // pin

//Color
int lSen_FR = xx; // pin
int lSen_FL = xx; // pin
int lSen_BR = xx; // pin
int lSen_BL = xx; // pin

//neutral start
int _oSen_F; 
int _oSen_B;
  // Sensing
boolean border = false;
boolean border_FR = false;
boolean border_FL = false;
boolean border_BR = false;
boolean border_BL = false;

  // motive
float Speed;
boolean F = false;
boolean R = false;
boolean L = false;
boolean B = false;

void setup() {
    //oSen (Optical Sensor (Opponent))
  pinMode(oSen_F , INPUT); 
  pinMode(oSen_B  , INPUT);  
  
    //lSen (Light Sensor (Floor))
  pinMode(lSen_FR, INPUT);
  pinMode(lSen_FL, INPUT);
  pinMode(lSen_BR, INPUT);
  pinMode(lSen_BL, INPUT); 
}

////CHECK
  /*COLOR*/
void sense_floor() {
  if (digitalRead(lSen_FR) == LOW){
    border_FR == true;
    border == true;
  } else if (digitalRead(lSen_FL) == LOW) {
    border_FL == true;
    border == true;
  } else if (digitalRead(lSen_BR) == LOW) {
    border_BR == true;
    border == true;
  } else if (digitalRead(lSen_BL) == LOW) {
    border_BL == true;
    border == true;
  } 
  if (digitalRead(lSen_FR) == HIGH) {
      border_FR == false;
  } else if (digitalRead(lSen_FL) == HIGH) {
      border_FL == false;
  } else if (digitalRead(lSen_BR) == HIGH) {
      border_BR == false;
  } else if (digitalRead(lSen_BL) == HIGH) {
      border_BL == false;
  }

  
} //Out: `border` _FR _FL _BR _BL = `false` || `true` AND `border` = true || false

  /*Infrared*/
void sense_opponent() {
    _oSen_F = digitalRead(oSen_F); 
    _oSen_B = digitalRead(oSen_B); 
} //Out: `_oSen_F` && `_oSen_B` = `HIGH` || `LOW`
////


 //PRESETS
void Move(Speed, F, B, R, L) {

  /*//Opposite moves fix: (#1 || #2) = false
  if ((F && B) || (R && L)){
    if (F && B){
      if (random(1,2) == 2){
        F = false;
      } else {
        B = false;
     }
    }
    if (R && L){
      if (random(1,2) == 2){
        L = false;
      } else {
        R = false;
      }
    }*/
  
  // /
   
  if (Speed) { /* FAST Move */
    //Forwards
    if (F && !R && !L) {
      //fast F
      
    } else if (F && R) {
       //fast FR
    } else if (F & L) {
       //fast FL
    }
    
    //Backwards
    if (B && !R && !L) {
      //fast B
    } else if (B && R) {
       //fast BR
    } else if (B & L) {
       //fast BL
    }

  } else { /* normal Move */
    //Forwards
    if (F && !R && !L) {
      //F
    } else if (F && R) {
      //FR
    } else if (F & L) {
      //FL
    }
    
    //Backwards
    if (B && !R && !L) {
      //B
    } else if (B && R) {
      //BR
    } else if (B & L) {
      //BL
    }
  }
  loop();
}
}

void Stop() {
  //Stop
  loop();
}
////

////BRAIN
void Brain(){
  sense_floor();
  sense_opponent();
  if (border) { // BORDER! : fast BL || BR
    
    fast = true;
    F = false; B = true; 
    R = true; L = true;
    Move(fast,F,R,L,B);
  } else {
    if (IRL == HIGH && IRR == HIGH){ //not found: normal FR || FL
      fast = false;
      F = true; B = false; 
      R = true; L = true; 
      Move(fast,F,R,L,B);
    } else if (IRL == LOW && IRR == HIGH){ //found L: fast FL
      fast = true;
      F = true; B = false; 
      L = true; R = false;
      Move(fast,F,R,L,B);
    } else if (IRL == HIGH && IRR == LOW){ //found R: fast FR
      fast = true;
      F = true; B = false; 
      L = false; R = true;
      Move(fast,F,R,L,B);
    } else if (IRL == LOW && IRR == LOW){ //found RL (F): fast F
      fast = true;
      F = true; B = false; 
      L = false; R = false;
      Move(fast,F,R,L,B);
    }
  }
  
  loop();
}
////

////Repeat
void loop() {
  Brain();
}
////
