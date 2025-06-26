#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 4);
const int led_vermelho = 2;
const int led_verde = 6;
const int led_amarelo = 5;
int comando = -1;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available() > 0) {
    comando = BTSerial.read();
    Serial.println(comando);
    if (comando == 1) {
      for (int i = 0; i < 2; i++) {
        digitalWrite(led_verde, HIGH);
        delay(500);
        digitalWrite(led_verde, LOW);
        delay(500);
      }
    }

    if (comando == 2) {
      for (int i = 0; i < 2; i++) {
        digitalWrite(led_amarelo, HIGH);
        delay(500);
        digitalWrite(led_amarelo, LOW);
        delay(500);
      }
    }



    if (comando == 3) {
      for (int i = 0; i < 2; i++) {
        digitalWrite(led_vermelho, HIGH);
        delay(500);
        digitalWrite(led_vermelho, LOW);
        delay(500);
      }
    }
  }
}
