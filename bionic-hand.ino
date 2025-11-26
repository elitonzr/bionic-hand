/*
# -----------------------------------------------------------------
# Código   :  bionic-hand
# Descrição:  Projeto de uma mão biônica impressa em 3D, controlada por um Arduino através de cinco servo motores.
              Os movimentos (gestos) são acionados via comunicação serial/Bluetooth, permitindo controlar a mão remotamente por um aplicativo ou outro dispositivo.
# Versão   :  0.1
# Autor    :  Eliton Roberto Monteiro
# Data     :  22/11/2025
# Licença  :  MIT License
# Git      :  https://github.com/elitonzr/bionic-hand
# Tinkercad:  https://www.tinkercad.com/things/dSHOwrBsTty-bionic-hand
# -----------------------------------------------------------------

                        Índice Servo x Dedo

      aplicaGesto(indicador, médio, anelar, mínimo, polegar);

*/

#include <Servo.h>

Servo dedo[5];

int fecha = 180;
int abre = 0;

void setup() {
  Serial.begin(9600);
  dedo[0].attach(2);  // indicador
  dedo[1].attach(3);  // médio
  dedo[2].attach(4);  // anelar
  dedo[3].attach(5);  // mínimo
  dedo[4].attach(6);  // polegar

  gestoAbrir();
  delay(3000);

  gestoFechar();
  delay(3000);

  gestoAbrir();
  delay(3000);

  gestoApresentacao();
}

void loop() {

  if (Serial.available() > 0) {
    char bluetooth = Serial.read();

    if (bluetooth == ('T') || bluetooth == ('t')) {
      gestoApresentacao();
    }

    else if (bluetooth == ('F') || bluetooth == ('f')) {
      gestoFechar();
      delay(5000);
    }

    else if (bluetooth == ('A') || bluetooth == ('a')) {
      gestoAbrir();
      delay(5000);
    }

    else if (bluetooth == ('V') || bluetooth == ('v')) {
      gestoVitoria();
      delay(1000);
    }

    else if (bluetooth == ('R') || bluetooth == ('r')) {
      gestoRock();
      delay(1000);
    }

    else if (bluetooth == ('S') || bluetooth == ('s')) {
      gestoAranha();
      delay(1000);
    }

    else if (bluetooth == ('H') || bluetooth == ('h')) {
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

void aplicaGesto(int d0, int d1, int d2, int d3, int d4) {
  int valores[5] = { d0, d1, d2, d3, d4 };
  for (int i = 0; i < 5; i++) {
    dedo[i].write(valores[i]);
  }
}

void gestoApresentacao() {
  gestoFechar();
  delay(3000);

  gestoN1();
  delay(3000);

  gestoN2();
  delay(3000);

  gestoN3();
  delay(3000);

  gestoN4();
  delay(3000);

  gestoN5();
  delay(3000);

  gestoFechar();
  delay(3000);

  gestoVitoria();
  delay(3000);

  gestoRock();
  delay(3000);

  gestoAranha();
  delay(3000);

  gestoHangLoose();
  delay(3000);

  gestoAbrir();
  delay(3000);
}

void gestoFechar() {
  aplicaGesto(fecha, fecha, fecha, fecha, fecha);
  Serial.println("Mão Fechada!");
}

void gestoAbrir() {
  aplicaGesto(abre, abre, abre, abre, abre);
  Serial.println("Mão Aberta!");
}

void gestoVitoria() {
  aplicaGesto(abre, abre, fecha, fecha, fecha);
  Serial.println("Mão em gesto de Vitória!");
}

void gestoRock() {
  aplicaGesto(abre, fecha, fecha, abre, fecha);
  Serial.println("Mão em gesto de Rock!");
}

void gestoAranha() {
  aplicaGesto(abre, fecha, fecha, abre, abre);
  Serial.println("Mão em gesto do Aranha!");
}

void gestoHangLoose() {
  aplicaGesto(fecha, fecha, fecha, abre, abre);
  Serial.println("Mão em gesto de Hang Loose!");
}

void gestoN1() {
  aplicaGesto(abre, fecha, fecha, fecha, fecha);
  Serial.println("Mão em gesto número 1!");
}

void gestoN2() {
  aplicaGesto(abre, abre, fecha, fecha, fecha);
  Serial.println("Mão em gesto número 2!");
}

void gestoN3() {
  aplicaGesto(abre, abre, abre, fecha, fecha);
  Serial.println("Mão em gesto número 3!");
}

void gestoN4() {
  aplicaGesto(abre, abre, abre, abre, fecha);
  Serial.println("Mão em gesto número 4!");
}

void gestoN5() {
  aplicaGesto(abre, abre, abre, abre, abre);
  Serial.println("Mão em gesto número 5!");
}