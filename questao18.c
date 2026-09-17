void questao18(void){
    Pin buttons[2], slave;
    for(uint8_t i = 0; i < 2; i++){
        pinStart(&buttons[i], GPIOE, 4 - i, INPUT);
        setPullDown(&buttons[i]);
    }
    pinStart(&slave, GPIOA, 6, OUTPUT);
    uint32_t degree = 0;
    while(1){
        writeHigh(&slave);
        for(uint32_t i = 0; i < 500 + degree/100; i++);
        writeLow(&slave);
        for(uint32_t i = 0; i < 2000 - degree/100; i++);
        if(readPin(&buttons[0]) && degree > 0) degree--;
        if(readPin(&buttons[0]) && degree < 200000) degree++;
    }
}