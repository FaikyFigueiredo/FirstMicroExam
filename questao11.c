void questao11(void){
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
    startDisplayPins(pins);
    while(1){
        for(uint8_t i = 0; i<16; i++){
            writeInDisplay(pins, values[i]);
            delay(10000);
        }
    }
}