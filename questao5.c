void questao5(void){
    Pin led1, led2, led3;
    pinStart(&led1, GPIOA, 6, OUTPUT);
    pinStart(&led2, GPIOA, 7, OUTPUT);
    pinStart(&led3, GPIOA, 8, OUTPUT);
    writeHigh(&led1);
    writeHigh(&led2);
    writeHigh(&led3);

    while(1){
        togglePin(&led1);
        if(getPinStatus(&led1)){
            togglePin(&led2);
            if(getPinStatus(&led2)) togglePin(&led3);
        }
        delay(1000); // delay de 1 segundo pra ficar bão
    }
}