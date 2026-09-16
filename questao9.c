void open(Pin* semaphore){
    writeHigh(&semaphore[0]);
    writeLow(&semaphore[2]);
}

void close(Pin* semaphore){
    writeHigh(&semaphore[1]);
    writeLow(&semaphore[0]);
    delay(1000);
    writeHigh(&semaphore[2]);
    writeLow(&semaphore[1]);
}

void questao9(void){
    Pin semaphore1[3];
    Pin semaphore2[3];
    for(int i = 0; i < 3; i++){
        pinStart(&semaphore1[i], GPIOC, 6+i, OUTPUT);
        pinStart(&semaphore2[i], GPIOD, 6+i, OUTPUT);
    }
    writeHigh(&semaphore2[2]);
    while(1){
        open(semaphore1);
        delay(5000);
        close(semaphore1);
        delay(1000);
        open(semaphore2);
        delay(5000);
        close(semaphore2);
        delay(1000);
    }
}