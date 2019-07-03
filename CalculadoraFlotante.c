#include <18F4620.h>
#include <stdlib.h>
#include <stdio.h>
#include <Operacion.c>
#include <Serial.c>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG

int Posicion[3];
char caracter;
char buffer[30]={""};
float num1,num2;
//Variables de Conversión
char opcion;
#define TamanoVectorNumerico 9
#define TamanoPosicionVector 3
#INT_RDA
void isrRDA(void){
   flagEcho=1;
   flagSerial=1;
   caracter=getc();
   if(ContadorBuffer<=30){
      buffer[ContadorBuffer]=caracter;
      ContadorBuffer++;
   }
   if(caracter==0x0D){
      flagEnter=1;
   } 
}
   
void main(void){
   set_tris_c(0x80);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   while(1){  
      DeteccionPosiciones(flagEnter, Posicion, 3, buffer, ContadorBuffer);
      AgregandoCaracteres(BufferNum1, TamanoVectorNumerico, BufferNum2, TamanoVectorNumerico, buffer, ContadorBuffer, Posicion, TamanoPosicionVector);
      opcion=buffer[ContadorBuffer-2];
      num1=atof(BufferNum1);
      num2=atof(BufferNum2);
      if(flagSerial==1){
         putc(caracter);
         flagSerial=0;
      }
      if(flagEnter==1){
         printf("%.2f\n", operacion(opcion, num1, num2));
         flagEnter=0;
      }
   }
}



