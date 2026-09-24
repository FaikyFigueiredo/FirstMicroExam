void questao19() {
    /*void valuesKey(Pin *pins, uint8_t i, uint8_t j) {
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
        }else {
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
    };*/
    uint8_t matrix[4][4] = {
        {ONE, TWO, THREE, HEX_A},
        {FOUR, FIVE, SIX, HEX_B},
        {SEVEN, EIGHT, NINE, HEX_C},
        {HEX_E, ZERO, HEX_F, HEX_D}
    };
    Pin pins[7];
    Pin keysOut[4];
    Pin keysIn[4];
    for (uint8_t i = 0; i < 4; i++) {
        pinStart(&keysOut[i], GPIOB, 4+i, OUTPUT);
        GPIO_Output_Type(GPIOB, &keysOut[i], OPEN_DRAIN); 
        setPullUp(&keysOut[i]);
    } 
    for (uint8_t i = 0; i < 4; i++) {
        pinStart(&keysIn[i], GPIOD, 4+i, INPUT);
        setPullUp(&keysIn[i]);
    } 
    startDisplayPins(pins);
    while(1){
        for(uint8_t i = 0; i<4; i++){
            writeLow(&keysOut[i]);
            for (uint8_t j = 0; j < 4; j++){
                if(!readPin(&keysIn[j])){
                    writeInDisplay(pins, matrix[i][j]);
                    delay(100);
                }
            }
        }
    }
}