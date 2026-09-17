 #include "LCD_Blio.h"
 
 void questao12() {
      LCD_Init(4, 1);
      char texto[50];
      for (int i = 10; i >= 0; i--){
          sprintf(texto,"Guilherme\nHenriques\nCavalcante\n%d", i);
          LCD_Write_String(1, 1, texto);
          delay(3000);
          LCD_Clear();
      }

  }