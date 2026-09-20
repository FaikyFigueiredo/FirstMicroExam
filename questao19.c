void questao19() {
      void valuesKey(Pin *pins, uint8_t i, uint8_t j) {
          if (j < 3 && i < 3){
              writeInDisplay(pins, values[i * 3 + j + 1]);
              return;
          }
          
          if (i == 3){
              switch(i){
                case(0):
                    writeInDisplay(pins, values[HEX_A]);
                    break;
                case(1):
                    writeInDisplay(pins, values[HEX_B]);
                    break;
                case(2):
                    writeInDisplay(pins, values[HEX_C]);
                    break;
              }
          }
          else {
              switch (j){
              case(0):
                  writeInDisplay(pins, values[HEX_E]);
                  break;
              case(1):
                  writeInDisplay(pins, values[0]);
                  break;
              case(2):
                  writeInDisplay(pins, values[HEX_F]);
                  break;
              case(3):
                  writeInDisplay(pins, values[HEX_D]);
                  break;
              
              }
          }
          
      }
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
      
      Pin pins[7];
      Pin keysOut[4];
      Pin keysIn[4];
      
      for (uint8_t i = 0; i < 4; i++) {    // LINHAS
          pinStart(&keysOut[i], GPIOB, 4+i, OUTPUT);
          GPIO_Output_Type(GPIOB, &keysOut[i], OPEN_DRAIN); 
          setPullUp(&keysOut[i]);
      } 
      
      for (uint8_t i = 0; i < 4; i++) {  // COLUNAS
          pinStart(&keysIn[i], GPIOD, 4+i, INPUT);
          setPullUp(&keysIn[i]);
      } 
      
      startDisplayPins(pins);
      while(1){
          for(uint8_t = 0; i<4; i++){
              for (uint8_t = 0; j < 4; j++){
                  if(getPinStatus(keysOut[i]) == 0 && getPinStatus(keysIn[j]) == 0) {
                      valuesKey(pins, i, j);
                      delay(500);
                  }
              }
          }
             
      }
}