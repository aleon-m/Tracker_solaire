//-------------------Université de La Réunion----------------------------------------------------------------------------------------------
//-------------------------L3 Physique-----------------------------------------------------------------------------------------------------

//----------UE: Introduction aux projets scientifiques-------------------------------------------------------------------------------------


//programme réalisé par: Léo Atoui, Léon Andriambariarijaona, Olivier Lafuteur, Joseph Martin

//Ce programme permet de faire tourner un moteur pas à pas en fonction de l'ensoleillement reçu par 2 capteurs solaires, dans le but de réaliser un tracker solaire



const int capteur1 = A2;
const int capteur2 = A3;
int valeurLue1;
float tension1;
int valeurLue2;
float tension2;
int delai = 80; // délai de passage d'un pas à un autre

void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT); //stator A -> sens du courant: HIGH = +- et LOW = -+ 
  pinMode(13, OUTPUT); //stator B -> sens du courant: HIGH = +- et LOW = -+ 
  
}
void loop(){
  valeurLue1=analogRead(capteur1);
  tension1=map(valeurLue1,0,1023,0,5000);//convertit les valeurs analogique(plage de 0 à 5000) en valeur numérique(plage de 0 à 1023: 1024 valeurs)
  Serial.print("valeurLue1=");//permet d'afficher les valeurs numeriques correspondant à la tension
  Serial.println(valeurLue1);
  Serial.print("Tension1=");//permet d'afficher la tension
  Serial.print(tension1);
  Serial.println("mv");
  Serial.print(" ");
  delay(20);
  valeurLue2=analogRead(capteur2);
  tension2=map(valeurLue2,0,1023,0,5000);
  Serial.print("valeurLue2=");
  Serial.println(valeurLue2);
  Serial.print("Tension2=");
  Serial.print(tension2);
  Serial.println("mv");
  Serial.print(" ");
  delay(20);
  
  
  if (abs(valeurLue1-valeurLue2)>10){// critère: qui permet au moteur de ne pas tourner quand l'eclairement est le même pour les 2 cellules:34)
  
  if ( valeurLue1<valeurLue2) {
    
    //sens horaire
    digitalWrite(12, HIGH);   //stator A -> définit le sens du courant: +-
      analogWrite(3, 255);   //envoie l'inpulsion dans le stator A
  
      delay(delai);
  

      digitalWrite(13, LOW);   //stator B -> définit le sens du courant: -+
      analogWrite(11, 255);   //envoie l'inpulsion dans le stator B
  
      delay(delai);
  
  
      digitalWrite(12, LOW);   //stator A -> définit le sens du courant: -+
      analogWrite(3, 255);   //envoie l'inpulsion dans le stator A
  
      delay(delai);
    
      digitalWrite(13, HIGH);   //stator B -> définit le sens du courant: +-
      analogWrite(11, 255);   //envoie l'inpulsion dans le stator B
  
      delay(delai);
        }
        
  if ( valeurLue2<valeurLue1) {
  digitalWrite(12, HIGH);   //stator A -> définit le sens du courant: +-
      analogWrite(3, 255);   //envoie l'inpulsion dans le stator A
  
      delay(delai);
  

      digitalWrite(13, HIGH);   //stator B -> définit le sens du courant: +-
      analogWrite(11, 255);   //envoie l'inpulsion dans le stator B
  
      delay(delai);
  
  
      digitalWrite(12, LOW);   //stator A -> définit le sens du courant: -+
      analogWrite(3, 255);   //envoie l'inpulsion dans le stator A
  
      delay(delai);
    
      digitalWrite(13, LOW);   //stator B -> définit le sens du courant: -+
      analogWrite(11, 255);   //envoie l'inpulsion dans le stator B
  
      delay(delai);



    

        }  }    
}
