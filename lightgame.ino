int switchState = 0; //variable for the button press check
int currentLevel = 1; //current "level" of the game that begins at one
int maxLight = 9; //the max pin that is being used
int minLight = 3; //the minimum pin that is used. The levels progress from minLight to maxLight sequentially
int timer = 0;

void setup() {
  //PIN INITIATION
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  
  //INITIALIZE LOOP
  delay(250 / currentLevel);
  int currentLight = currentLevel + 3;
  for(int i = minLight; i < currentLight; i++){
    digitalWrite(i, HIGH);
  }
  
  //BEGIN NO LIGHT LOOP
   digitalWrite(currentLight, LOW);
      do{
    switchState = digitalRead(2);
    if(switchState == HIGH){
      if(currentLevel != 1){
        for(int i = maxLight; i > 3; i--){
          digitalWrite(i, LOW);
          delay(100);
        }
        currentLevel = 1;
        currentLight = currentLevel + 3;
      }
      break;
    }
    timer++;
    delay(10 / (currentLevel * 0.8));
  }while(timer <= 50);
  timer = 0;
  //END NO LIGHT LOOP
  
  delay(250 / currentLevel);
  
  //BEGIN LIGHT LOOP
  digitalWrite(currentLight, HIGH);
  do{
    switchState = digitalRead(2);
    if(switchState == HIGH){
      currentLevel++;
      digitalWrite(currentLight, HIGH);
      //CELEBRATION
      digitalWrite(3, LOW);
      delay(200);
      digitalWrite(3, HIGH);
      delay(200);
      digitalWrite(3, LOW);
      delay(200);
      digitalWrite(3, HIGH);
      delay(200);
      digitalWrite(3, LOW);
      delay(200);
      digitalWrite(3, HIGH);
      //END CELEBRATION
      break;
    }
    timer++;
    delay(5 / (currentLevel * 0.8));
  }while(timer <= 50);
  timer = 0;
  //END LIGHT LOOP
}
