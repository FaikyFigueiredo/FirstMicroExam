void questao19() {

      uint8_t values[16] = {
          ZERO,
          ONE,
          TWO,
          THREE,
          FOUR,
          FIVE,
          SIX,
          SEVEN,
          EIGHT,
          NINE,
          HEX_A,
          HEX_B,
          HEX_C,
          HEX_D,
          HEX_E,
          HEX_F
      };

      void valuesKey(Pin *pins, uint8_t i, uint8_t j) {
                if (j < 3 && i < 3){
                    writeInDisplay(pins, values[i * 3 + j + 1]);
                    return;
                }

                if (i == 3){
                    switch(j){
                      case(0):
                          writeInDisplay(pins, values[14]);
                          break;
                      case(1):
                          writeInDisplay(pins, values[0]);
                          break;
                      case(2):
                          writeInDisplay(pins, values[15]);
                          break;
                      case(3):
                          writeInDisplay(pins, values[13]);
                          break;
                    }
                }
                else if (j == 3){
                    switch (i){
                    case(0):
                        writeInDisplay(pins, values[10]);
                        break;
                    case(1):
                        writeInDisplay(pins, values[11]);
                        break;
                    case(2):
                        writeInDisplay(pins, values[12]);
                        break;
                    case(3):
                        writeInDisplay(pins, values[13]);
                        break;

                    }
                }

            }

      Pin pins[7];
      Pin keysOut[4];
      Pin keysIn[4];

      for (uint8_t i = 0; i < 4; i++) {    // LINHAS
          pinStart(&keysOut[i], GPIOB, 4+i, OUTPUT);
          GPIO_Output_Type(GPIOB, keysOut[i].index, OPEN_DRAIN);
          setPullUp(&keysOut[i]);
      }

      for (uint8_t i = 0; i < 4; i++) {  // COLUNAS
          pinStart(&keysIn[i], GPIOD, 4+i, INPUT);
          setPullUp(&keysIn[i]);
      }

      startDisplayPins(pins);
      while(1){
          for(uint8_t i = 0; i < 4; i++){
              writeLow(&keysOut[i]);
              for (uint8_t j = 0; j < 4; j++){
                  if(readPin(&keysIn[j])) {
                      valuesKey(pins, i, j);
                      delay(500);
                  }
              }
              writeHigh(&keysOut[i]);
          }

      }

  }