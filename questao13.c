void questao13(void){
    Pin slave;
    pinStart(&slave, GPIOA, 6, OUTPUT);
    uint32_t count = 0;
    uint8_t toIncrement = 1;
    while(1){
        writeHigh(&slave);
        for(uint32_t i = 0; i < 500 + count/100; i++);
        writeLow(&slave);
        for(uint32_t i = 0; i < 2500 - count/100; i++);
        count+= toIncrement;
        if(count == 0 || count == 200000) toIncrement *= -1;
    }
}