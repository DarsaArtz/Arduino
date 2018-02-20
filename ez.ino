// Optical Sensors
int oSen_F = xx;
int oSen_B = xx;

// Light Sensors
int lSen_FR = xx;
int lSen_FL = xx;
int lSen_BR = xx;
int lSen_BL = xx;

//Motors
int mRF = xx;
int mRB = xx;
int mLF = xx;
int mLB = xx;

void sense_Move() {
// Sensing 
  
  int _lSen_FR = digitalRead (lSen_FR);
  int _lSen_FL = digitalRead (lSen_FL);
  int _lSen_BR = digitalRead (lSen_BR);
  int _lSen_BL = digitalRead (lSen_BL);
  int _oSen_F = digitalRead (oSen_F);
  int _oSen_B = digitalRead (oSen_B);
  
  if (_lSen_FR == 1 && _lSen_FL == 0 && _lSen_BR == 0 && _lSen_BL == 0) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);
  }
    
  else if (_lSen_FR == 0 && _lSen_FL == 1 && _lSen_BR == 0 && _lSen_BL == 0) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);
  }
  
  else if (_lSen_FR == 0 && _lSen_FL == 0 && _lSen_BR == 1 && _lSen_BL == 0) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);
  }
  
  else if (_lSen_FR == 0 && _lSen_FL == 0 && _lSen_BR == 0 && _lSen_BL == 1) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);
  }
  else {
    
  if (_oSen_F == 1 && _oSen_B  == 0) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);      
  }
  
  else if (_oSen_F == 0 && _oSen_B  == 1) {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);      
  }
  else {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);    
    }
  }
}
void boost() {
  analogWrite (mRF , xxx);
  analogWrite (mRB , xxx);
  analogWrite (mLF , xxx);
  analogWrite (mLB , xxx);
  delay (2000);
  }


void setup() {
// Sensors mode :
pinMode (oSen_F , INPUT);
pinMode (oSen_B , INPUT);  
//-----------------------//
pinMode (lSen_FR , INPUT);
pinMode (lSen_FL , INPUT);
pinMode (lSen_BR , INPUT);
pinMode (lSen_BL , INPUT);
// Motors mode :
pinMode (mRF , OUTPUT);
pinMode (mRB , OUTPUT);
pinMode (mLF , OUTPUT);
pinMode (mLB , OUTPUT);
// Boost
boost();
}

void loop() {
sense_Move();
}
