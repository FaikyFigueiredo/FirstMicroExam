questao6(void){
    uint32_t count = 0;
    uint8_t toIncrement = 1;
    Pin led1, led2;
    pinStart(&led1, GPIOA, 6, OUTPUT);
    pinStart(&led2, GPIOA, 7, OUTPUT);
    while(1){
        writeHigh(&led1);
        if (count != 0) writeLow(&led2);
        delay(count/100);
        writeHigh(&led1);
        if (count != 10000) writeLow(&led2);
        delay((count - 10000)/100);
        count+= toIncrement;
        if(count == 10000 || count == 0) toIncrement *= -1;
    }
}