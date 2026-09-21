void questao20{
    distances[3] = {20,40,50};
    Pin ultrasonic[2], buzzer;
    pinStart(&ultrasonic[0], GPIOA, 6, OUTPUT);
    pinStart(&ultrasonic[1], GPIOA, 7, INPUT);
    pinStart(&buzzer, GPIOC, 10, OUTPUT);
    while(1){
        uint32_t distance = getDistance(&ultrasonic[0], &ultrasonic[1]);
        if(distance < distance[0]) writeHigh(&buzzer);
        else if (distance < distance[1]){
            writeHigh(&buzzer);
            delay(2);
            writeLow(&buzzer);
            delay(2);
        }else if (distance < distance[2]){
            writeHigh(&buzzer);
            delay(10);
            writeLow(&buzzer);
            delay(10);
        }
        
    }
}
