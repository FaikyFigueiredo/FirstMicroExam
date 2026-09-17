void questao15(void){
    Pin button, led;
    pinStart(&button, GPIOE, 3, INPUT);
    pinStart(&led, GPIOA, 6, OUTPUT);
    setPullDown(&button);
    while(1){
        if(!readPin(&button)){
            togglePin(&led);
            delay(100);
        }
    }
}