  
const char* MorseTable[] = {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        // space, !, ", #, $, %, &, '
        "....--", "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
        // ( ) * + , - . /
        "-.--.", "-.--.-", NULL, ".-.-.", "--..--", "-....-", ".-.-.-", "-..-.",
        // 0 1 2 3 4 5 6 7
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
        // 8 9 : ; < = > ?
        "---..", "----.", "---...", "-.-.-.", NULL, "-...-", NULL, "..--..",
        // @ A B C D E F G
        ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        // H I J K L M N O
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
        // P Q R S T U V W
        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
        // X Y Z [ \ ] ^ _
        "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
        // ' a b c d e f g
        NULL, ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        // h i j k l m n o
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
        // p q r s t u v w
        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
        // x y z { | } ~ DEL
        "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, NULL,
        };

int dotLength = 5;
int dashLength = dotLength*3;

int laser = 7;

String str = "";
void setup() {
  // put your setup code here, to run once:
  pinMode(laser, OUTPUT);
  Serial.begin(9600);  

//str = "100 200 300 400 500 600 700 800 900";

str = "237 30 84 255 205 30 237 30 84 255 84 30 237 30 84 255 84 30 237 30 205 255 84 30 237 28 230 135 242 85 230 28 230 135 242 135 230 28 230 135 242 135 230 28 230 85 242 135 230 28 36 86 255 0 207 86 36 86 255 0 255 86 36 86 255 0 255 86 36 86 207 0 255 86 36";
//str = "118 118 118 118 118 118 118 118 118 118 118 49 49 49 49 49 49 49 49 118 118 49 118 118 118 118 118 118 49 118 118 49 118 49 49 49 49 118 49 118 118 49 118 49 118 118 49 118 49 118 118 49 118 49 118 118 49 118 49 118 118 49 118 49 49 49 49 118 49 118 118 49 118 118 118 118 118 118 49 118 118 49 49 49 49 49 49 49 49 118 118 118 118 118 118 118 118 118 118 118 255 255 255 255 255 255 255 255 255 255 255 27 27 27 27 27 27 27 27 255 255 27 255 255 255 255 255 255 27 255 255 27 255 27 27 27 27 255 27 255 255 27 255 27 255 255 27 255 27 255 255 27 255 27 255 255 27 255 27 255 255 27 255 27 27 27 27 255 27 255 255 27 255 255 255 255 255 255 27 255 255 27 27 27 27 27 27 27 27 255 255 255 255 255 255 255 255 255 255 255 3 3 3 3 3 3 3 3 3 3 3 146 146 146 146 146 146 146 146 3 3 146 3 3 3 3 3 3 146 3 3 146 3 146 146 146 146 3 146 3 3 146 3 146 3 3 146 3 146 3 3 146 3 146 3 3 146 3 146 3 3 146 3 146 146 146 146 3 146 3 3 146 3 3 3 3 3 3 146 3 3 146 146 146 146 146 146 146 146 3 3 3 3 3 3 3 3 3 3 3";
  for (int i=0;i<str.length();i++)
      {
    flashDashDot(MorseTable[str[i]]);
    delay(dotLength*2);
      }


}

void loop() {

  if(Serial.available()){
    
      str = Serial.read();
      for (int i=0;i<str.length();i++)
      {
    flashDashDot(MorseTable[str[i]]);
    delay(dotLength*2);
      }
  }
  
}

void flashDashDot(const char * morseCode)
{
  int i = 0;
  while(morseCode[i] != 0)
  {
    if(morseCode[i] == '.'){
      dot();
    } else if (morseCode[i] == '-'){
      dash();
    }
    i++;
  }
}

void dot()
{
  digitalWrite(laser, HIGH);
  delay(dotLength);
  digitalWrite(laser, LOW);
  delay(dotLength);
}

void dash()
{
  digitalWrite(laser, HIGH);
  delay(dashLength);
  digitalWrite(laser, LOW);
  delay(dotLength);
}
