void questao16(){
      Pin led, button1, button2;
      
      pinStart(&led, GPIOA, 6, OUTPUT);
      pinStart(&button1, GPIOE, 3, INPUT);
      pinStart(&button2, GPIOE, 4, INPUT);
      setPullDown(&button1);
      setPullDown(&button2);
      uint8_t flag = 1;
      
      while (1){
        if (readPin(&button2)){
            continue;
        }
        
        if (readPin(&button1)){
            if (flag){
                for (int i = 0; i < 10000000; i++){
                    if (readPin(&button2)){
                        writeLow(&led);
                    }
                    writeHigh(&led);
                }
                flag = !flag;
            }
            
        }
        flag = 1;
        writeHigh(&led);
    }
      
}