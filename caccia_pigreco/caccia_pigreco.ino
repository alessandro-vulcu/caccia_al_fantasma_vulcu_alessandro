#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
int punteggio = 0;
int r;
int nrandom;
int i = 3;
int npenality;
int t = 0;
int tempo = 600;
//int difficoltà = 0;
byte heart[8] = { 0b00000, 0b01010,
                  0b11111, 0b11111,
                  0b11111, 0b01110,
                  0b00100, 0b00000
                };
byte enemy[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B11111,
  B10101,
  B00000
};
byte bomb[8] = {
  B00010,
  B00101,
  B01000,
  B00100,
  B01110,
  B11111,
  B11111,
  B01110
};

int dim = 600;
int k = 0;
int button1 = 10;
int button2 = 9;
int button3 = 8;
int button4 = 7;
int button5 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);

  lcd.begin (20, 4);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.createChar(1, heart);
  lcd.createChar(2, enemy);
  lcd.createChar(3, bomb);
  lcd.setCursor(0, 0);
  randomSeed(analogRead(0));
}
void vitapiu() {
  while (digitalRead(button1) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH || digitalRead(button4) == HIGH || digitalRead(button5) == HIGH );
  lcd.setCursor(17, 3);
  i++;
  lcd.print(i);
}
void vita1() {
  while (digitalRead(button1) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button1) == HIGH) {
      vitapiu();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void vita2() {
  while (digitalRead(button2) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button2) == HIGH) {
      vitapiu();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void vita3() {
  while (digitalRead(button3) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button3) == HIGH) {
      vitapiu();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void vita4() {
  while (digitalRead(button4) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button4) == HIGH) {
      vitapiu();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}

void vita5() {
  while (digitalRead(button5) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button5) == HIGH) {
      vitapiu();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}

void penality1() {
  while (digitalRead(button1) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button1) == HIGH) {
      vitameno();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void penality2() {
  while (digitalRead(button2) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button2) == HIGH) {
      vitameno();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void penality3() {
  while (digitalRead(button3) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button3) == HIGH) {
      vitameno();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void penality4() {
  while (digitalRead(button4) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button4) == HIGH) {
      vitameno();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void penality5() {
  while (digitalRead(button5) == LOW || tempo != 0) {
    lcd.setCursor(16, 0);
    lcd.print("s");
    lcd.setCursor(14, 0);
    delay(5);
    tempo--;
    lcd.print(tempo / 100);

    if (digitalRead(button5) == HIGH) {
      vitameno();
      break;
    }
    else if (tempo == 0) {
      return;
    }
  }
}
void score() {
  punteggio++;
  lcd.setCursor(7, 3);
  lcd.print(punteggio);
}

void vitameno() {
  while (digitalRead(button1) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH || digitalRead(button4) == HIGH || digitalRead(button5) == HIGH );
  lcd.setCursor(17, 3);
  i--;
  lcd.print(i);
  if (i == 0) {
    gameover();
  }

  delay(250);
}

void dif() {
  if (k == 10) {
    dim = dim / 2;
  }
}
void time1() {
  lcd.setCursor(16, 0);
  lcd.print("s");
  lcd.setCursor(14, 0);
  delay(5);
  tempo--;
  lcd.print(tempo / 100);
  if (tempo == 0) {
    i--;
    tempo = dim;
    lcd.setCursor(17, 3);
    lcd.print(i);
  }
  if (i == 0) {
      gameover();
    }
}

void gameover() {
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(0, 1);
  lcd.print("Vuoi giocare ancora?");
  lcd.setCursor(4, 2);
  lcd.print("Punteggio: " );
  lcd.print(punteggio);
  lcd.setCursor(3, 3);
  lcd.print("[Si]");
  lcd.setCursor(13, 3);
  lcd.print("[No]");
  while (1) {
    if (digitalRead(button1) == HIGH) {
      while (digitalRead(button1) == HIGH);
      punteggio = 0;
      i = 3;
      tempo = 1000;
      delay(100);
      lcd.clear();
      setGame();
    }
    else if (digitalRead(button5) == HIGH) {
      while (digitalRead(button5) == HIGH);
      punteggio = 0;
      i = 3;
      tempo = 1000;
      lcd.clear();
      delay(10);
      start();
    }
  }
}
void one() {
  lcd.setCursor(1, 2);
  r = random(0, 12);
  if (r == 1) {
    lcd.write(byte(3));
    penality1();
  }
  else if (r == 6) {
    lcd.write(byte(1));
    vita1();
  }
  else {
    lcd.write(byte(2));
    while (digitalRead(button1) == LOW) {
      time1();
      delay(1);
    }
  }

  while (digitalRead(button1) == HIGH);
  score();
  k++;
  dif();
  tempo = dim;
  lcd.setCursor(1, 2);
  lcd.print(" ");
  game();
}

void two() {
  lcd.setCursor(3, 2);
  r = random(0, 12);
  if (r == 1) {
    lcd.write(byte(3));
    penality2();
  }
  else if (r == 6) {
    lcd.write(byte(1));
    vita2();
  }
  else {
    lcd.write(byte(2));
    while (digitalRead(button2) == LOW) {
      time1();
      delay(3);
    }
  }

  while (digitalRead(button2) == HIGH);
  score();
  k++;
  dif();
  tempo = dim;
  lcd.setCursor(3, 2);
  lcd.print(" ");
  game();
}
void three() {
  lcd.setCursor(5, 2);
  r = random(0, 12);
  if (r == 1) {
    lcd.write(byte(3));
    penality3();
  }
  else if (r == 6) {
    lcd.write(byte(1));
    vita3();
  }
  else {
    lcd.write(byte(2));
    while (digitalRead(button3) == LOW) {
      time1();
      delay(3);
    }
  }
  while (digitalRead(button3) == HIGH);
  score();
  k++;
  dif();
  tempo = dim;
  lcd.setCursor(5, 2);
  lcd.print(" ");
  game();
}

void four() {
  lcd.setCursor(7, 2);
  r = random(0, 12);
  if (r == 1) {
    lcd.write(byte(3));
    penality4();
  }
  else if (r == 6) {
    lcd.write(byte(1));
    vita4();
  }
  else {
    lcd.write(byte(2));
    while (digitalRead(button4) == LOW) {
      time1();
      delay(3);
    }
  }

  while (digitalRead(button4) == HIGH);
  score();
  k++;
  dif();
  tempo = dim;
  lcd.setCursor(7, 2);
  lcd.print(" ");
  game();

}
void five() {
  lcd.setCursor(9, 2);
  r = random(0, 12);
  if (r == 1) {
    lcd.write(byte(3));
    penality5();
  }
  else if (r == 6) {
    lcd.write(byte(1));
    vita5();
  }
  else {
    lcd.write(byte(2));
    while (digitalRead(button5) == LOW) {
      time1();
      delay(3);
    }
  }

  while (digitalRead(button5) == HIGH);
  score();
  k++;
  dif();
  tempo = dim;
  lcd.setCursor(9, 2);
  lcd.print(" ");
  game();
}
void setGame() {
  lcd.clear();
  delay(100);
  lcd.setCursor(0, 3);
  lcd.print("score: ");
  lcd.setCursor(19, 3);
  lcd.write(byte(1));
  delay(100);
  lcd.setCursor(18, 3);
  lcd.print("x");
  delay(100);
  lcd.setCursor(17, 3);
  lcd.print(i);
  delay(1000);

  lcd.setCursor(1, 0);
  lcd.print("1");
  delay(75);
  lcd.setCursor(3, 0);
  lcd.print("2");
  delay(75);
  lcd.setCursor(5, 0);
  lcd.print("3");
  delay(75);
  lcd.setCursor(7, 0);
  lcd.print("4");
  delay(75);
  lcd.setCursor(9, 0);
  lcd.print("5");
  delay(1000);
  lcd.setCursor(14, 0);
  lcd.print(tempo / 1000);
  game();
}
void game() {

  nrandom = random(0, 5);
  if (nrandom == 0) {
    one();
  }
  else if (nrandom == 1) {
    two();
  }

  else if (nrandom == 2) {
    three();
  }

  else if (nrandom == 3) {
    four();
  }

  else if (nrandom == 4) {
    five();
  }
}
void opzioni() {
  lcd.clear();
  lcd.write(byte(1));
  lcd.print(": vite in piu';");
  lcd.setCursor(0, 1);
  lcd.write(byte(2));
  lcd.print(": nemici;");
  lcd.setCursor(0, 2);
  lcd.write(byte(3));
  lcd.print(": toglie vite;");
  lcd.setCursor(0, 3);
  lcd.print("Enjoy :)");
  while (digitalRead(button5) == LOW);
  lcd.clear();
}
void crediti() {
  lcd.clear();
  lcd.print("Caccia al fantasma");
  lcd.setCursor(0, 1);
  lcd.print("creato da Alessandro");
  lcd.setCursor(0, 2);
  lcd.print("Vulcu");
  while (digitalRead(button5) == LOW);
  lcd.clear();
}
void start() {
  if (digitalRead(button1) == HIGH ) {
    delay(10);
    setGame();
  }
  else if (digitalRead(button2) == HIGH ) {
    delay(10);
    opzioni();
  }
  else if (digitalRead(button3) == HIGH ) {
    delay(10);
    crediti();
  }

  else {
    lcd.setCursor(0, 0);
    lcd.print("1: Start");
    lcd.setCursor(0, 1);
    lcd.print("2: Opzioni");
    lcd.setCursor(0, 2);
    lcd.print("3: Crediti");
    lcd.setCursor(0, 3);
    lcd.print("--------------------");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  start();
}
