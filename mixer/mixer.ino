/*
RGB-LED-mixer
 
Tools for mixing and tuning RGB LEDs 
*/


/*
RGB level inputs
*/
const int level_R = 0;
const int level_G = 1;
const int level_B = 2;

/*
RGB output channels
*/
const int chan_R = 9;
const int chan_G = 10;
const int chan_B = 11;


void setup() {                

  pinMode(chan_R, OUTPUT);   
  pinMode(chan_G, OUTPUT);   
  pinMode(chan_B, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
}

//values to hold last input readings
int oldr = 0;
int oldg = 0;
int oldb = 0;

/*
check an input and if the reading has changed since the
last check, update the PWM output channel
*/
void check_channel(int input, int &last_val, int output){
  int cur_val = map(analogRead(input), 0, 1023, 0, 255);
  if (abs(cur_val - last_val) > 1){
    last_val = cur_val;
    Serial.println(cur_val);
    analogWrite(output, cur_val);
  }

}

void loop() {  
  //read input levels for RGB channels
  check_channel(level_R, oldr, chan_R);
  check_channel(level_G, oldb, chan_G);
  check_channel(level_B, oldg, chan_B);
  delay(1);        // delay in between reads for stability
}







