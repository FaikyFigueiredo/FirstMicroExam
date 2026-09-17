void questao17(void){
    Pin buttons[2], leds[2], buttonReset;
    uint8_t state = 0;
    pinStart(&buttonReset,GPIOE, 3, INPUT);
    setPullDown(&buttonReset);
    for(uint8_t i = 0; i < 2; i++){
        pinStart(&leds[i],GPIOA, 6 + i, OUTPUT);
        pinStart(&buttons[i],GPIOE, 5 + i, INPUT);
        setPullDown(&buttons[i]);
    }
    while(1){
        if(state == 0){
            if(readPin(&buttons[0])){
                writeHigh(&leds[0]);
                state = 1;
            }else if(readPin(&buttons[1])){
                writeHigh(&leds[1]);
                state = 1;
            }
        }else if(readPin(&buttonReset)) state = 0;
    }
}