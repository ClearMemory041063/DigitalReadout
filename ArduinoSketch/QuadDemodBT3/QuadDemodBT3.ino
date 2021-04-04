//4Jan2021
// 74LS86 quad xor gates chips arrived
// Quadrature Demodulator of digital signals
// pinXI=chipXOR(pinXA,pinXB)
// pinYI=chipXOR(pinYA,pinYB)
// pinZI=chipXOR(pinzA,pinZB)



// Pins for a Leonardo
//The interrupt pins are connected to the outputs of three XOR gates
int pinXI = 2;
int pinYI =3;
int pinZI = 7;
// The A and B pins from the encoder connect to the XOR gate inputs and the pins on the Arduino
int pinXA =4;
int pinXB=5;
int pinYA =6;
int pinYB=8;
int pinZA =9;
int pinZB=10;


volatile int oldx,oldy,oldz;
volatile int flag=1;
volatile int newvalx,newvaly,newvalz;
volatile long X=0;
volatile long Y=0;
volatile long Z=0;
int table[4][4]={ 0,-1, 1, 0,
                  1, 0, 0,-1, 
                 -1, 0, 0, 1,
                  0, 1,-1, 0};

char Incoming_value = 0;
void setup() {
    pinMode(pinXI, INPUT_PULLUP);
    pinMode(pinYI, INPUT_PULLUP);
    pinMode(pinZI, INPUT_PULLUP);
    pinMode(pinXA, INPUT_PULLUP);
    pinMode(pinXB, INPUT_PULLUP);
    pinMode(pinYA, INPUT_PULLUP);
    pinMode(pinYB, INPUT_PULLUP);
    pinMode(pinZA, INPUT_PULLUP);
    pinMode(pinZB, INPUT_PULLUP);
    
     oldx= digitalRead(pinXA)+2+digitalRead(pinXB);
     oldy= digitalRead(pinYA)+2+digitalRead(pinYB);
     oldz= digitalRead(pinZA)+2+digitalRead(pinZB);
    Serial.begin(115200);
    Serial1.begin(9600);         
    pinMode(13, OUTPUT);    //LED   
X=0;
Y=0;
Z=0;
    attachInterrupt(digitalPinToInterrupt(pinXI), countx, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pinYI), county, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pinZI), countz, CHANGE);

}

void loop() {

 if(flag){
    Serial.print("-100, ");
    Serial.print(X);
    Serial.print(", ");
    Serial.print(Y);
    Serial.print(", "); 
    Serial.print(", ");
    Serial.print(Z);
    Serial.print(", ");
    Serial.print(newvalx);
    Serial.print(", ");
    Serial.print(newvaly);
    Serial.print(", ");
    Serial.print(newvalz);
    Serial.print(", "); 
    Serial.println("100");
    //
    
  Serial1.print("{X:");
  Serial1.print(X); 
  Serial1.print(",Y:");
  Serial1.print(Y); 
  Serial1.print(",Z:");
  Serial1.print(Z);
  Serial1.println("}"); 
  
  //
    flag=0;
  }
  delay(50); // allows skipping of fast readings to Android Bluetooth APP// comment out when testing circuit with serial monitor to see all values

    // comment out RX section if no HC-05 Bluetooth connected
  if (Serial1.available() > 1) {
    
    Incoming_value=toUpperCase(Serial1.read());
    Serial.println(Incoming_value);
   // Serial1.println(Incoming_value);
   switch (Incoming_value){
    case 'X':
    // if(Serial1.read()=='0')X=0;
    // X=0;
     X=Serial1.parseInt();
    break;
    case 'Y':
     //if(Serial1.read()=='0')Y=0;
      Y=Serial1.parseInt();
   break;
    case 'Z':
     //if(Serial1.read()=='0')Z=0;
     Z=Serial1.parseInt();
    break;
    default:
    break;
   }//endswitch
   flag=1;
  }//endif 
  //*/
}


void countx() {
    newvalx=digitalRead(pinXA)*2+digitalRead(pinXB);
    X+=table[newvalx][oldx];
    oldx=newvalx;
    flag=1;
}

void county() {
    newvaly=digitalRead(pinYA)*2+digitalRead(pinYB);
    Y+=table[newvaly][oldy];
    oldy=newvaly;
    flag=1;
}

void countz() {
    newvalz=digitalRead(pinZA)*2+digitalRead(pinZB);
    Z+=table[newvalz][oldz];
    oldz=newvalz;
    flag=1;
}
