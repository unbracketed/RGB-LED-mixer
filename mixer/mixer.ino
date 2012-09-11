/*
dev-lights
 
 Ambient feedback indicators for CI or test suite-related events
 */

int level_R = 0;
int level_G = 1;
int level_B = 2;

//int debug_led = 8;
int indicator_R = 9;
int indicator_G = 10;
int indicator_B = 11;


void setup() {                
  //  pinMode(debug_led, OUTPUT);   
  pinMode(indicator_R, OUTPUT);   
  pinMode(indicator_G, OUTPUT);   
  pinMode(indicator_B, OUTPUT);
  //  pinMode(level_R, INPUT);
  //  pinMode(level_G, INPUT);
  //  pinMode(level_B, INPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
}

int oldr = 0;
int oldg = 0;
int oldb = 0;


void loop() {  
  // read the input on analog pin 0:
  int cur_R = map(analogRead(level_R), 0, 1023, 0, 255);
  int cur_G = map(analogRead(level_G), 0, 1023, 0, 255);
  int cur_B = map(analogRead(level_B), 0, 1023, 0, 255);  

  if (abs(oldr - cur_R) > 1) {
    oldr = cur_R;
    Serial.println(String(cur_R) + " " + String(cur_G) + " " + String(cur_B));
    analogWrite(indicator_R, cur_R);
  }
  if (abs(oldg - cur_G) > 1) {
    oldg = cur_G;
    Serial.println(String(cur_R) + " " + String(cur_G) + " " + String(cur_B));
    analogWrite(indicator_G, cur_G);
  }
  if (abs(oldb - cur_B) > 1) {
    oldb = cur_B;
    Serial.println(String(cur_R) + " " + String(cur_G) + " " + String(cur_B));
    analogWrite(indicator_B, cur_B);
  }
  delay(1);        // delay in between reads for stability
}






