String selection = "null"; // User selection String

int green = 8; // Pin for green LED
int yellow = 9; // Pin for yellow LED
int blue = 10; // Pin for blue LED
int red = 11; // Pin for red LED

String ledStatus() { // Display status of all LEDs
  String gstat;
  String ystat;
  String bstat;
  String rstat;
  
  digitalRead(green) == HIGH ? gstat = "ON" : gstat = "OFF";
  digitalRead(yellow) == HIGH ? ystat = "ON" : ystat = "OFF";
  digitalRead(blue) == HIGH ? bstat = "ON" : bstat = "OFF";
  digitalRead(red) == HIGH ? rstat = "ON" : rstat = "OFF";
  
  String output = "Green = " + gstat + " | Yellow = " + ystat + " | Blue = " + bstat + " | Red = " + rstat;
  return output;
}

void toggleOff() {
  Serial.println("All set to OFF");
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}

void toggleOn() {
  Serial.println("All set to ON");
  digitalWrite(green, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
}

void invert() { // Invert all LEDs
  String output;
  
  digitalWrite(green, !digitalRead(green));
  digitalWrite(yellow, !digitalRead(yellow));
  digitalWrite(blue, !digitalRead(blue));
  digitalWrite(red, !digitalRead(red));
  
  digitalRead(green) == HIGH ? output += "Green set to ON | " : output += "Green set to OFF | ";
  digitalRead(yellow) == HIGH ? output += "Yellow set to ON | " : output += "Yellow set to OFF | ";
  digitalRead(blue) == HIGH ? output += "Blue set to ON | " : output += "Blue set to OFF | ";
  digitalRead(red) == HIGH ? output += "Red set to ON" : output += "Red set to OFF";
  
  Serial.println(output);
}

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  
  Serial.begin(9600);
  
  delay(5000);
}

void loop() {
  if(Serial.available()) {
    selection = Serial.readString();
    if(selection.equalsIgnoreCase("green")) {
      digitalWrite(green, !digitalRead(green));
      digitalRead(green) == HIGH ? Serial.println("Green set to ON") : Serial.println("Green set to OFF");
    }
    else if(selection.equalsIgnoreCase("yellow")) {
      digitalWrite(yellow, !digitalRead(yellow));
      digitalRead(yellow) == HIGH ? Serial.println("Yellow set to ON") : Serial.println("Yellow set to OFF");
    }
    else if(selection.equalsIgnoreCase("blue")) {
      digitalWrite(blue, !digitalRead(blue));
      digitalRead(blue) == HIGH ? Serial.println("Blue set to ON") : Serial.println("Blue set to OFF");
    }
    else if(selection.equalsIgnoreCase("red")) {
      digitalWrite(red, !digitalRead(red));
      digitalRead(red) == HIGH ? Serial.println("Red set to ON") : Serial.println("Red set to OFF");
    }
    else if(selection.equalsIgnoreCase("status")) {
      Serial.println(ledStatus());
    }
    else if(selection.equalsIgnoreCase("off")) {
      toggleOff();
    }
    else if(selection.equalsIgnoreCase("on")) {
      toggleOn();
    }
    else if(selection.equalsIgnoreCase("invert")) {
      invert();
    }
    else {
      Serial.println("Bad selection!");
    }
  }
}
