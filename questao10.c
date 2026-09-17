static Pin carSemaphore[3];
static uint8_t buttonFlag = 0;
static uint8_t count = 0;

void buttonHandler(void){
    if(!getPinStatus(&carSemaphore[1]) && !getPinStatus(&carSemaphore[2])) buttonFlag = 1;
    delay(50);
}

void openWalker(Pin* semaphore){
    writeHigh(&semaphore[0]);
    writeLow(&semaphore[1]);
}

void closeWalker(Pin* semaphore){
    for(uint8_t i = 0 ; i < 4 ; i++){
        writeHigh(&semaphore[1]);
        delay(250);
        writeLow(&semaphore[1]);
        delay(250);
    }
    writeHigh(&semaphore[1]);
    writeLow(&semaphore[0]);
}

void closeAndOpenWalker(Pin* walkerSemaphore){
    close(carSemaphore);
    delay(2000);
    openWalker(walkerSemaphore);
    delay(3000);
    closeWalker(walkerSemaphore);
    open(carSemaphore);
    buttonFlag = 0;
    count = 0;
}

void questao10(void){
    Pin walkerSemaphore[2], button;
    interruptiOn();
    for(uint8_t i = 0; i < 3; i++) pinStart(&carSemaphore[i], GPIOC, 6+i, OUTPUT);
    for(uint8_t i = 0; i < 2; i++) pinStart(&walkerSemaphore[i], GPIOD, 6+i, OUTPUT);
    pinStart(&button, GPIOE, 3, INPUT);
    setPullDown(&button);
    interruptPin(&button, 0, 0, buttonHandler);
    writeHigh(&walkerSemaphore[1]);
    open(carSemaphore);
    while(1){
        if(buttonFlag){
            closeAndOpenWalker(walkerSemaphore);
        }else{
            delay(500);
            count++;
            if(count == 10){
                closeAndOpenWalker(walkerSemaphore);
            }
        }
    }
}