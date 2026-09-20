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

    int acelerador = 0;
    int toIncrement = 1;

    while (1){
        if (acelerador == 0) writeLow(&pwm);
        writeHigh(&pwm);
        delayUs(acelerador);
        writeLow(&pwm);
        delayUs(5000 - acelerador / 5);
        if (acelerador >= 2500){
            writeHigh(&pwm);
            toIncrement *= -1;
        }

        if (acelerador < 0){
            togglePin(&horario);
            togglePin(&antihorario);
            toIncrement *= -1;
            
        }

        acelerador += toIncrement;
    }
}