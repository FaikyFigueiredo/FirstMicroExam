void questao8(void){
    static Pin pins[8];
    for(uint8_t i = 0; i < 8; i++)pinStart(&pins[i], GPIOC, 6+i, OUTPUT);
    uint8_t actualLed = 0;
    uint8_t toIncrement = 1;
    while(1){
        writeLow(&pins[(actualLed + 8 - 1) % 8]);
        writeHigh(&pins[actualLed]);
        actualLed += toIncrement;
        if(actualLed == 8 || actualLed == 0) toIncrement *= -1;
        delay(250);
    }
}