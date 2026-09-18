void delayUs(uint32_t tempo){
    for(volatile uint32_t i = 0; i < tempo * 10; i++);
}
void questao14() {

    Pin pwm, horario, antihorario;

    pinStart(&pwm, GPIOA, 8, OUTPUT);
    pinStart(&horario, GPIOA, 9, OUTPUT);
    pinStart(&antihorario, GPIOA, 10, OUTPUT);

    writeHigh(&horario);
    writeLow(&antihorario);

    uint32_t acelerador = 0;
    int8_t toIncrement = 1;

    while (1){
        if (acelerador == 0) writeLow(&pwm);
        writeHigh(&pwm);
        delayUs(acelerador);
        writeLow(&pwm);
        delayUs(500 - acelerador / 50);
        if (acelerador == 25000) writeHigh(&pwm);
        if (acelerador >= 25000 || acelerador < 0){
            togglePin(&horario);
            togglePin(&antihorario);
            toIncrement *= -1;
        }
        acelerador += toIncrement;
    }
}