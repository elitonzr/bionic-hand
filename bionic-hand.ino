#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int dedo1 = 0;
int dedo2 = 0;
int dedo3 = 0;
int dedo4 = 0;
int dedo5 = 0;

int fecha = 180;
int abre = 0;

char bluetooth;

void setup() {
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);

  gestoAbrir();
  delay(3000);

  gestoFechar();
  delay(3000);


  gestoAbrir();
  delay(3000);
}

void loop() {

  if (Serial.available() > 0) {
    char bluetooth = Serial.read();

    if (bluetooth == ('t')) {
      gestoN1();
      delay(1000);

      gestoN2();
      delay(1000);

      gestoN3();
      delay(1000);

      gestoN4();
      delay(1000);

      gestoN5();
      delay(1000);

      gestoFechar();
      delay(3000);

      gestoAbrir();
      delay(1000);

      gestoVitoria();
      delay(3000);

      gestoRock();
      delay(3000);

      gestoAranha();
      delay(3000);

      gestoHangLoose();
      delay(3000);

      gestoAbrir();
      delay(1000);
    }

    else if (bluetooth == ('f')) {
      gestoFechar();
      delay(1000);
    }

    else if (bluetooth == ('a')) {
      gestoAbrir();
      delay(1000);
    }

    else if (bluetooth == ('v')) {
      gestoVitoria();
      delay(1000);
    }

    else if (bluetooth == ('r')) {
      gestoRock();
      delay(1000);
    }

    else if (bluetooth == ('s')) {
      gestoAranha();
      delay(1000);
    }

    else if (bluetooth == ('h')) {
      gestoHangLoose();
      delay(1000);
    }

    else if (bluetooth == ('1')) {
      gestoN1();
      delay(1000);
    }

    else if (bluetooth == ('2')) {
      gestoN2();
      delay(1000);
    }

    else if (bluetooth == ('3')) {
      gestoN3();
      delay(1000);
    }

    else if (bluetooth == ('4')) {
      gestoN4();
      delay(1000);
    }

    else if (bluetooth == ('5')) {
      gestoN5();
      delay(1000);
    }
  }

  delay(10);
}


void gestoFechar() {

  Serial.println("Mão Fechada!");

  dedo1 = fecha;
  servo1.write(dedo1);

  dedo2 = fecha;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = fecha;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoAbrir() {

  Serial.println("Mão Aberta!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = abre;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = abre;
  servo5.write(dedo5);
}

void gestoVitoria() {

  Serial.println("Mão em gesto de Vitória!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = fecha;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoRock() {

  Serial.println("Mão em gesto de Rock!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = fecha;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoAranha() {

  Serial.println("Mão em gesto do Aranha!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = fecha;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = abre;
  servo5.write(dedo5);
}

void gestoHangLoose() {

  Serial.println("Mão em gesto de Hang Loose!");

  dedo1 = fecha;
  servo1.write(dedo1);

  dedo2 = fecha;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = abre;
  servo5.write(dedo5);
}

void gestoN1() {

  Serial.println("Mão em gesto número 1!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = fecha;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = fecha;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoN2() {

  Serial.println("Mão em gesto número 2!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = fecha;
  servo3.write(dedo3);

  dedo4 = fecha;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoN3() {

  Serial.println("Mão em gesto número 3!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = abre;
  servo3.write(dedo3);

  dedo4 = fecha;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoN4() {

  Serial.println("Mão em gesto número 4!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = abre;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = fecha;
  servo5.write(dedo5);
}

void gestoN5() {

  Serial.println("Mão em gesto número 5!");

  dedo1 = abre;
  servo1.write(dedo1);

  dedo2 = abre;
  servo2.write(dedo2);

  dedo3 = abre;
  servo3.write(dedo3);

  dedo4 = abre;
  servo4.write(dedo4);

  dedo5 = abre;
  servo5.write(dedo5);
}