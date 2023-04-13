int delaylegnth = 10;


//sens anti-horaire


void setup(){
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B

}






void loop(){
      digitalWrite(12, HIGH);   //Sets direction of CH A
      analogWrite(3, 255);   //Moves CH A
  
      delay(delaylegnth);
  

      digitalWrite(13, HIGH);   //Sets direction of CH B
      analogWrite(11, 255);   //Moves CH B
  
      delay(delaylegnth);
  
  
      digitalWrite(12, LOW);   //Sets direction of CH A
      analogWrite(3, 255);   //Moves CH A
  
      delay(delaylegnth);
    
      digitalWrite(13, LOW);   //Sets direction of CH B
      analogWrite(11, 255);   //Moves CH B
  
      delay(delaylegnth);
}
