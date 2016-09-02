
int switchState = 0;
int currentLevel = 1;
int x = 0;
int timer = 0;
int maxLight = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  //INITIALIZE LOOP
  delay(250);
  int currentLight = currentLevel + 3;
  for(int i = 3; i < currentLight; i++){
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
    delay(10);
  }while(timer <= 50);
  timer = 0;
  delay(250);
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
    delay(5);
  }while(timer <= 50);
  timer = 0;
}
