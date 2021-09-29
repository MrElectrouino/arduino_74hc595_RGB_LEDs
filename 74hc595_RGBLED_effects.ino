int dataPin = 12;
int enablePin = 11;
int latchPin = 10;
int clockPin = 9;

#define number_of_74hc595s 5
#define numOfRegisterPins number_of_74hc595s * 8
#define numRGBLeds 12

boolean registers[numOfRegisterPins];

int redPin[]   = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33 };
int greenPin[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
int bluePin[]  = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };

void setup() {
  Serial.begin(9600);

  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  digitalWrite(enablePin, LOW);
  for (int i = numOfRegisterPins - 1; i >=  0; i--) {
    registers[i] = LOW;   
  }
  ledOff(0); 
}

void loop() {
//  effect_1(1);//effect_X(how many time you want to repeat the effect.)
//  ledOff(0);  //ledOff(leds off time )
//  effect_2(1);
//  ledOff(0);
 effect_3(1);
//  ledOff(0);
//  effect_4(4);
//  ledOff(0);
//  effect_5(2);
//  ledOff(0);
//  effect_6(1);
//  ledOff(0);
//  effect_7(3);
//  ledOff(0);
//  effect_8(1);
//  ledOff(0);
//  effect_9(1);
//  ledOff(0);
//  effect_10(1);
//  ledOff(0);
//  effect_11(1);
//  ledOff(0);
//  effect_12(2);
//  ledOff(0);
//  effect_13(1);
//  ledOff(0);
//  effect_14(1);
//  ledOff(0);
//  effect_15(3);
//  ledOff(0);
//  effect_16(1);
//  ledOff(0);
//  effect_17(1);
//  ledOff(0);
//  effect_18(1);
//  ledOff(0);
//  effect_19(2);
//  ledOff(0);
//  effect_20(5);
//  ledOff(0);
//  delay(1000);
}
//////////////////////////////////////////////////////EFFECT 1
void effect_1(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    Red(0, 11, 0);
    brigtness();
    ledOff(0);

    Yellow(0, 11, 0);
    brigtness();
    ledOff(0);

    Green(0, 11, 0);
    brigtness();
    ledOff(0);

    White(0, 11, 0);
    brigtness();
    ledOff(0);

    Cyan(0, 11, 0);
    brigtness();
    ledOff(0);

    Blue(0, 11, 0);
    brigtness();
    ledOff(0);

    Pink(0, 11, 0);
    brigtness();
    ledOff(0);
  }
}
//////////////////////////////////////////////////////effect_2
void effect_2(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++ ) {
      Red(0, i, 0);
      delay(50);
      ledOff(0);

      Yellow(0, i, 0);
      delay(50);
      ledOff(0);

      Green(0, i, 0);
      delay(50);
      ledOff(0);

      White(0, i, 0);
      delay(50);
      ledOff(0);

      Cyan(0, i, 0);
      delay(50);
      ledOff(0);

      Blue(0, i, 0);
      delay(50);
      ledOff(0);

      Pink(0, i, 0);
      delay(50);
      ledOff(0);
    }
  }
}
//////////////////////////////////////////////////////effect_3
void effect_3(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      registersWrite(redPin[i], HIGH);
      delay(100);
    } ledOff(30);
    for (int i = 11; i >= 0; i--) {
      registersWrite(redPin[i], HIGH);
      registersWrite(bluePin[i], HIGH);
      delay(100);
    } ledOffR(30);

    for (int i = 0; i <= 11; i++) {
      registersWrite(greenPin[i], HIGH);
      delay(100);
    } ledOff(30);

    for (int i = 11; i >= 0; i--) {
      registersWrite(redPin[i], HIGH);
      registersWrite(greenPin[i], HIGH);
      delay(100);
    } ledOffR(30);

    for (int i = 0; i <= 11; i++) {
      registersWrite(bluePin[i], HIGH);
      delay(100);
    } ledOff(30);

    for (int i = 11; i >= 0; i--) {
      registersWrite(bluePin[i], HIGH);
      registersWrite(greenPin[i], HIGH);
      delay(100);
    } ledOffR(30);

    for (int i = 0; i <= 11; i++) {
      registersWrite(bluePin[i], HIGH);
      registersWrite(redPin[i], HIGH);
      registersWrite(greenPin[i], HIGH);
      delay(100);
    } ledOff(30);
  }
}
//////////////////////////////////////////////////////effect_4
void effect_4(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    byte led = 0b10101010;
    byte led1 = 0b10101010;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, led);
    shiftOut(dataPin, clockPin, LSBFIRST, led1);
    digitalWrite(latchPin, HIGH);
    delay(100);
    brigtnessNodelay();
    byte led2 = 0b01010101;
    byte led3 = 0b01010101;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, led2);
    shiftOut(dataPin, clockPin, LSBFIRST, led3);
    digitalWrite(latchPin, HIGH);
    delay(100);
  }
}
//////////////////////////////////////////////////////effect_5
void effect_5(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    Red(0, 1, 0);
    Yellow(2, 3, 0);
    Green(4, 5, 0);
    White(6, 6, 0);
    Cyan(7, 7, 0);
    Blue(8, 9, 0);
    Pink(10, 11, 0);
    brigtness();
    for (int i = 1; i <= 5; i++) {
      turnOutputsOn();
      delay(50);
      turnOutputsOff();
      delay(50);
    }
  }
}
//////////////////////////////////////////////////////effect_6
void effect_6(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    int count = 12;
    for (int i = 0; i < 12; i++) {
      ledOff(5);
      registersWrite(redPin[i], HIGH);  // chaser 1
      registersWrite(bluePin[count], HIGH); // chaser 2
      delay(10);
      count--;
    }
    count = 12;
    for (int i = 0; i < 12; i++) {
      ledOff(5);
      registersWrite(redPin[i], HIGH);  // chaser 1
      registersWrite(greenPin[i], HIGH);
      registersWrite(bluePin[count], HIGH); // chaser 2
      delay(10);
      count--;
    }
    count = 12;
    for (int i = 0; i < 12; i++) {
      ledOff(5);
      registersWrite(redPin[i], HIGH);  // chaser 1
      registersWrite(bluePin[i], HIGH);
      registersWrite(greenPin[count], HIGH); // chaser 2
      delay(10);
      count--;
    }
  }
}
//////////////////////////////////////////////////////effect_7
void effect_7(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    int count = 11;
    for (int i = 0; i <= 11; i++) {
      ledOff(0);
      registersWrite(redPin[i], HIGH);  // chaser 1
      registersWrite(redPin[i - 1], HIGH);
      brigtnessNodelay();
      registersWrite(bluePin[count], HIGH); // chaser 2
      registersWrite(bluePin[count - 1], HIGH); // chaser 2
      count--;
      delay(100);
    }
  }
}
//////////////////////////////////////////////////////effect_8
void effect_8(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    int count = 11;
    for (int i = 0; i <= 11; i++) {
      Cyan(0, i, 0);
      Cyan(0, i - count, 0);
      brigtnessNodelay();
      Pink(0, count, 0);
      Pink(0, count - i, 0);
      count--;
      delay(100);
    }
    brigtnessNodelay();
    count = 11;
    for (int i = 0; i <= 11; i++) {
      Red(0, i, 0);
      Red(0, i - count, 0);
      brigtnessNodelay();
      Yellow(0, count, 0);
      Yellow(0, count - i, 0);
      count--;
      delay(100);
    }
    brigtnessNodelay();
    count = 11;
    for (int i = 0; i <= 11; i++) {
      Blue(0, i, 0);
      Blue(0, i - count, 0);
      brigtnessNodelay();
      Green(0, count, 0);
      Green(0, count - i, 0);
      count--;
      delay(100);
    }
  }
}
//////////////////////////////////////////////////////effect_9
void effect_9(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i < 12; i++) {
      for (int k = i; k < 12; k++) {
        registersWrite(greenPin[k], HIGH);
        delay(50);
        registersWrite(greenPin[k], LOW);
        delay(30);
      }
      //registersWrite(redPin[i], HIGH);
      if (i < 2) {
        Red(0, i, 0);
      }
      if (i < 4) {
        Yellow(2, i, 0);
      }
      if (i < 6) {
        Green(4, i, 0);
      }
      if (i < 7) {
        White(6, i, 0);
      }
      if (i < 8) {
        Cyan(7, i, 0);
      }
      if (i < 10) {
        Blue(8, i, 0);
      }
      if (i < 12) {
        Pink(10, i, 0);
        delay(20);
      }
    }
  }
}
/////////////////////////////////////////////////////Effect_10
void effect_10(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 11; i >= 0; i--) {
      for (int k = 0; k < i; k++) {
        registersWrite(redPin[k], HIGH);
        registersWrite(greenPin[k], HIGH);
        delay(50);
        registersWrite(redPin[k], LOW);
        registersWrite(greenPin[k], LOW);
        delay(30);
      }

      registersWrite(bluePin[i], HIGH);
      delay(20);
    }
  }
}
/////////////////////////////////////////////////////Effect 11
void effect_11(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      registersWrite(redPin[i], HIGH);
      delay(30);
      registersWrite(redPin[i - 4], LOW);
      delay(10);
    } ledOff(0);
    for (int i = 11; i >= 0; i--) {
      registersWrite(bluePin[i], HIGH);
      delay(30);
      registersWrite(bluePin[i + 4], LOW);
      delay(10);
    } ledOff(0);
    for (int i = 0; i <= 11; i++) {
      registersWrite(greenPin[i], HIGH);
      delay(30);
      registersWrite(greenPin[i - 4], LOW);
      delay(10);
    } ledOff(0);
    for (int i = 11; i >= 0; i--) {
      registersWrite(bluePin[i], HIGH);
      registersWrite(greenPin[i], HIGH);
      registersWrite(redPin[i], HIGH);
      delay(30);
      registersWrite(bluePin[i + 4], LOW);
      registersWrite(greenPin[i + 4], LOW);
      registersWrite(redPin[i + 4], LOW);
      delay(10);
    }
  }
}

/////////////////////////////////////////////////////effect_12
void effect_12(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    int count = 11;
    for (int i = 0; i <= 11; i++) {
      registersWrite(bluePin[i], HIGH);  // chaser 1
      registersWrite(bluePin[i - 1], HIGH);
      registersWrite(bluePin[count], HIGH); // chaser 2
      registersWrite(bluePin[count - 1], HIGH); // chaser 2
      count--;
      delay(100);
    }
    ledOff(0);
    count = 6;
    for (int i = 6; i >= 0; i--) {
      registersWrite(redPin[i], HIGH);  // chaser 1
      registersWrite(redPin[i - 1], HIGH);
      registersWrite(redPin[count], HIGH); // chaser 2
      registersWrite(redPin[count - 1], HIGH); // chaser 2
      count++;
      delay(100);
    }
    ledOff(0);
    count = 11;
    for (int i = 0; i <= 11; i++) {
      registersWrite(greenPin[i], HIGH);  // chaser 1
      registersWrite(greenPin[i - 1], HIGH);
      registersWrite(greenPin[count], HIGH); // chaser 2
      registersWrite(greenPin[count - 1], HIGH); // chaser 2
      count--;
      delay(100);
    }
    ledOff(0);
    count = 6;
    for (int i = 6; i >= 0; i--) {
      registersWrite(redPin[i], HIGH);
      registersWrite(bluePin[i], HIGH);
      registersWrite(greenPin[i], HIGH);
      brigtnessNodelay();
      registersWrite(redPin[i - 1], HIGH);
      registersWrite(bluePin[i - 1], HIGH);
      registersWrite(greenPin[i - 1], HIGH);
      brigtnessNodelay();
      registersWrite(redPin[count], HIGH);
      registersWrite(bluePin[count], HIGH);
      registersWrite(greenPin[count], HIGH);
      brigtnessNodelay();
      registersWrite(redPin[count - 1], HIGH);
      registersWrite(bluePin[count - 1], HIGH);
      registersWrite(greenPin[count - 1], HIGH);
      brigtnessNodelay();
      count++;
      delay(100);
    }
    ledOff(0);
  }
}
/////////////////////////////////////////////////////effect_13
void effect_13(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      for (int k = i; k <= 5; k++)
      {
        registersWrite(redPin[k], HIGH);
        registersWrite(bluePin[11 - k], HIGH);
        delay(100);
        registersWrite(redPin[k], LOW);
        registersWrite(bluePin[11 - k], LOW);
        delay(100);
      }
      registersWrite(greenPin[i], HIGH);
      registersWrite(bluePin[11 - i], HIGH);
      registersWrite(greenPin[11 - i], HIGH);
    }
  }
}

/////////////////////////////////////////////////////effect_14
void effect_14(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      i = i + 1;
      if (i >= 1) {
        registersWrite(redPin[i], HIGH);
      }
      if (i >= 3) {
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
      }
      if (i >= 5) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
        registersWrite(redPin[i], LOW);
      }
      if (i >= 7) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
      }
      if (i >= 9) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
        registersWrite(greenPin[i], LOW);
      }
      if (i >= 11) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], LOW);
      }
      delay(10);
    }
    ledOff(50);
    for (int i = 5; i >= 0; i--) {
      int  j = i * 2;
      if (j == 10) {
        registersWrite(redPin[j], HIGH);
      }
      if (j == 8) {
        registersWrite(redPin[j], HIGH);
        registersWrite(greenPin[j], HIGH);
        registersWrite(bluePin[j], LOW);
      }
      if (j == 6) {
        registersWrite(greenPin[j], HIGH);
        registersWrite(bluePin[j], LOW);
        registersWrite(redPin[j], LOW);
      }
      if (j == 4) {
        registersWrite(greenPin[j], HIGH);
        registersWrite(bluePin[j], HIGH);
        registersWrite(redPin[j], LOW);
      }
      if (j == 2) {
        registersWrite(bluePin[j], HIGH);
        registersWrite(redPin[j], LOW);
        registersWrite(greenPin[j], LOW);
      }
      if (j == 0) {
        registersWrite(bluePin[j], HIGH);
        registersWrite(redPin[j], HIGH);
        registersWrite(greenPin[j], LOW);
      }
      delay(10);
    }
    ledOffR(50);
  }
}
/////////////////////////////////////////////////////effect_15
void effect_15(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 11; i >= 0; i--) {
      if (i <= 11) {
        registersWrite(redPin[i], HIGH);
      }
      if (i <= 9) {
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
      }
      if (i <= 7) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
        registersWrite(redPin[i], LOW);
      }
      if (i <= 5) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
      }
      if (i <= 3) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
        registersWrite(greenPin[i], LOW);
      }
      if (i <= 0) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], LOW);
      }
      delay(10);
    }
    ledOffR(10);
    for (int i = 0; i <= 11; i++) {
      if (i >= 0) {
        registersWrite(redPin[i], HIGH);
      }
      if (i >= 2) {
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
      }
      if (i >= 4) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], LOW);
        registersWrite(redPin[i], LOW);
      }
      if (i >= 6) {
        registersWrite(greenPin[i], HIGH);
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
      }
      if (i >= 8) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], LOW);
        registersWrite(greenPin[i], LOW);
      }
      if (i >= 11) {
        registersWrite(bluePin[i], HIGH);
        registersWrite(redPin[i], HIGH);
        registersWrite(greenPin[i], LOW);
      }
      delay(10);
    }
    ledOff(10);
  }
}
/////////////////////////////////////////////////////effect_16
void effect_16(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int k = 0; k <= 11; k++) {
      for (int i = 0; i <= k; i++) {
        Red(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        Yellow(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        Green(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        White(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        Cyan(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        Blue(0, i, 0);
        brigtnessNodelay();
      }
      for (int i = 0; i <= k; i++) {
        Pink(0, i, 0);
        brigtnessNodelay();
      }
    }
  }
}
/////////////////////////////////////////////////////effect_17
void effect_17(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      registersWrite(redPin[i], HIGH);
      brigtnessNodelay();
      if (1 <= i) {
        registersWrite(redPin[i - 1], HIGH);
        registersWrite(greenPin[i - 1], HIGH);
        registersWrite(bluePin[i - 1], LOW);
        brigtnessNodelay();
      }
      if (2 <= i) {
        registersWrite(greenPin[i - 2], HIGH);
        brigtnessNodelay();
      }
      if (3 <= i) {
        registersWrite(redPin[i - 3], HIGH);
        registersWrite(greenPin[i - 3], HIGH);
        registersWrite(bluePin[i - 3], HIGH);
        brigtnessNodelay();
      }
      if (4 <= i) {
        registersWrite(greenPin[i - 4], HIGH);
        registersWrite(bluePin[i - 4], HIGH);
        brigtnessNodelay();
      }
      if (5 <= i) {
        registersWrite(bluePin[i - 5], HIGH);
        brigtnessNodelay();
      }
      if (6 <= i) {
        registersWrite(redPin[i - 6], HIGH);
        registersWrite(bluePin[i - 6], HIGH);
        brigtnessNodelay();
      }
      registersWrite(redPin[i], LOW);

      registersWrite(greenPin[i - 1], LOW);
      registersWrite(redPin[i - 1], LOW);

      registersWrite(greenPin[i - 2], LOW);

      registersWrite(redPin[i - 3], LOW);
      registersWrite(greenPin[i - 3], LOW);
      registersWrite(bluePin[i - 3], LOW);

      registersWrite(greenPin[i - 4], LOW);
      registersWrite(bluePin[i - 4], LOW);

      registersWrite(bluePin[i - 5], LOW);

      registersWrite(redPin[i - 6], LOW);
      registersWrite(bluePin[i - 6], LOW);
    }

    for (int i = 11; i >= 0; i--) {
      registersWrite(redPin[i], HIGH);
      brigtnessNodelay();
      if (10 >= i) {
        registersWrite(redPin[i + 1], HIGH);
        registersWrite(greenPin[i + 1], HIGH);
        registersWrite(bluePin[i + 1], LOW);
        brigtnessNodelay();
      }
      if (9 >= i) {
        registersWrite(greenPin[i + 2], HIGH);
        brigtnessNodelay();
      }
      if (8 >= i) {
        registersWrite(redPin[i + 3], HIGH);
        registersWrite(greenPin[i + 3], HIGH);
        registersWrite(bluePin[i + 3], HIGH);
        brigtnessNodelay();
      }
      if (7 >= i) {
        registersWrite(greenPin[i + 4], HIGH);
        registersWrite(bluePin[i + 4], HIGH);
        brigtnessNodelay();
      }
      if (6 >= i) {
        registersWrite(bluePin[i + 5], HIGH);
        brigtnessNodelay();
      }
      if (5 >= i) {
        registersWrite(redPin[i + 6], HIGH);
        registersWrite(bluePin[i + 6], HIGH);
        brigtnessNodelay();
      }
      registersWrite(redPin[i], LOW);

      registersWrite(greenPin[i + 1], LOW);
      registersWrite(redPin[i + 1], LOW);

      registersWrite(greenPin[i + 2], LOW);

      registersWrite(redPin[i + 3], LOW);
      registersWrite(greenPin[i + 3], LOW);
      registersWrite(bluePin[i + 3], LOW);

      registersWrite(greenPin[i + 4], LOW);
      registersWrite(bluePin[i + 4], LOW);

      registersWrite(bluePin[i + 5], LOW);

      registersWrite(redPin[i + 6], LOW);
      registersWrite(bluePin[i + 6], LOW);
    }
  }
}
//////////////////////////////////////////////////////effect_18
void effect_18(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      registersWrite(redPin[i], HIGH);
      i++;
      registersWrite(greenPin[i], HIGH);
      delay(100);
      registersWrite(redPin[i - 4], LOW);
      delay(50);
    } ledOff(0);
    for (int i = 11; i >= 0; i--) {
      registersWrite(bluePin[i], HIGH);
      i--;
      registersWrite(redPin[i], HIGH);
      delay(100);
      registersWrite(bluePin[i + 4], LOW);
      delay(50);
    }
  }
}
/////////////////////////////////////////////////////effect_19
void effect_19(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    Red(0, 1, 0);
    Yellow(2, 3, 0);
    Green(4, 5, 0);
    White(6, 6, 0);
    Cyan(7, 7, 0);
    Blue(8, 9, 0);
    Pink(10, 11, 0);
    //brigtness();
  }
}
/////////////////////////////////////////////////////effect_20
void effect_20(int repeatEffect) {
  for (int i = 1; i <= repeatEffect; i++) {
    for (int i = 0; i <= 11; i++) {
      registersWrite(redPin[i], HIGH);
      brigtnessNodelay();
      if (1 <= i) {
        registersWrite(redPin[i - 1], HIGH);
        registersWrite(greenPin[i - 1], HIGH);
        registersWrite(bluePin[i - 1], LOW);
        brigtnessNodelay();
      }
      if (2 <= i) {
        registersWrite(greenPin[i - 2], HIGH);
        brigtnessNodelay();
      }
      if (3 <= i) {
        registersWrite(redPin[i - 3], HIGH);
        registersWrite(greenPin[i - 3], HIGH);
        registersWrite(bluePin[i - 3], HIGH);
        brigtnessNodelay();
      }
      if (4 <= i) {
        registersWrite(greenPin[i - 4], HIGH);
        registersWrite(bluePin[i - 4], HIGH);
        brigtnessNodelay();
      }
      if (5 <= i) {
        registersWrite(bluePin[i - 5], HIGH);
        brigtnessNodelay();
      }
      if (6 <= i) {
        registersWrite(redPin[i - 6], HIGH);
        registersWrite(bluePin[i - 6], HIGH);
        brigtnessNodelay();
      }
      registersWrite(redPin[i], LOW);

      registersWrite(greenPin[i - 1], LOW);
      registersWrite(redPin[i - 1], LOW);

      registersWrite(greenPin[i - 2], LOW);

      registersWrite(redPin[i - 3], LOW);
      registersWrite(greenPin[i - 3], LOW);
      registersWrite(bluePin[i - 3], LOW);

      registersWrite(greenPin[i - 4], LOW);
      registersWrite(bluePin[i - 4], LOW);

      registersWrite(bluePin[i - 5], LOW);

      registersWrite(redPin[i - 6], LOW);
      registersWrite(bluePin[i - 6], LOW);
    }
  }
}

//////////////////////Functions/////////////////////
void brigtnessNodelay() {
  for (int i = 255; i >= 0; i--) {
    analogWrite(enablePin, i);
  }
}
void brigtness() {
  for (int i = 255; i >= 0; i--) {
    analogWrite(enablePin, i);
    delay(5);
  }
}

void ledOff(int clearSpeed) {
  for (int i = 0; i <= 35; i++) {
    registersWrite(i, LOW);
    delay(clearSpeed);
  }
}
void ledOffR(int clearSpeed) {
  for (int i = 35; i >= 0; i--) {
    registersWrite(i, LOW);
    delay(clearSpeed);
  }
}

void turnOutputsOn() {
  digitalWrite(enablePin, LOW);
}
void turnOutputsOff() {
  digitalWrite(enablePin, HIGH);
}

void registersWrite(int index, int value) {
  digitalWrite(enablePin, LOW);
  digitalWrite(latchPin, LOW);
  for (int i = numOfRegisterPins - 1; i >=  0; i--) {
    digitalWrite(clockPin, LOW);
    int val = registers[i];
    digitalWrite(dataPin, val);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
  registers[index] = value;
}

void Red(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(redPin[count], HIGH);
    registersWrite(bluePin[count], LOW);
    registersWrite(greenPin[count], LOW);
  }
}

void Pink(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(redPin[count], HIGH);
    registersWrite(bluePin[count], HIGH);
    registersWrite(greenPin[count], LOW);
    delay(ledBT);
  }
}

void Green(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(greenPin[count], HIGH);
    registersWrite(redPin[count], LOW);
    registersWrite(bluePin[count], LOW);
    delay(ledBT);
  }
}

void Yellow(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(redPin[count], HIGH);
    registersWrite(greenPin[count], HIGH);
    registersWrite(bluePin[count], LOW);
    delay(ledBT);
  }
}

void Blue(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(bluePin[count], HIGH);
    registersWrite(redPin[count], LOW);
    registersWrite(greenPin[count], LOW);
    delay(ledBT);
  }
}
void Cyan(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(greenPin[count], HIGH);
    registersWrite(bluePin[count], HIGH);
    registersWrite(redPin[count], LOW);
    delay(ledBT);
  }
}

void White(int startPin, int endPin, int ledBT) {
  for (byte count = startPin; count <= endPin; count++) {
    registersWrite(redPin[count], HIGH);
    registersWrite(greenPin[count], HIGH);
    registersWrite(bluePin[count], HIGH);
    delay(ledBT);
  }
}
