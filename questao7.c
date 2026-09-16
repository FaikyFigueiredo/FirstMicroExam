static Pin pins[8];
void countRecursively(Pin* pin, uint8_t index){
    togglePin(pin);
    if(index < 7 && !getPinStatus(pin)) countRecursively(pin, index+1);
}
void questao7(void){
    for(uint8_t i = 0; i < 8; i++)pinStart(&pins[i], GPIOC, 6+i, OUTPUT);
    while(1){
        countRecursively(&pins[0], 0);
        delay(1000);
    }
}