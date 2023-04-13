const int capteur1 = A0;
const int capteur2 = A1;
int valeurLue1;
float tension1;
int valeurLue2;
float tension2;

void setup(){
  Serial.begin(9600);
}
void loop(){
  valeurLue1=analogRead(capteur1);
  tension1=map(valeurLue1,0,1023,0,5000);
  Serial.print("valeurLue1=");
  Serial.println(valeurLue1);
  Serial.print("Tension1=");
  Serial.print(tension1);
  Serial.println("mv");
  Serial.print(" ");
  delay(2000);
  valeurLue2=analogRead(capteur2);
  tension2=map(valeurLue2,0,1023,0,5000);
  Serial.print("valeurLue2=");
  Serial.println(valeurLue2);
  Serial.print("Tension2=");
  Serial.print(tension2);
  Serial.println("mv");
  Serial.print(" ");
  delay(2000);
}
