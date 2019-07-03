
#use delay(clock=16000000)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #define RX_232        PIN_C7
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1, UART1, RCV=RX_232)
   #use fast_io(c)
#endif

int ContadorBuffer=0;
int flagSerial=0,flagEcho=0,flagEnter=0;

char BufferNum1[10]={""};
char BufferNum2[10]={""};

void DeteccionPosiciones(int &flagEnter, int Posicion[], int tamano, char buffer[], int TotalCaracteres);
void AgregandoCaracteres(int bufferNum1 [],int TamanoBuffer1, int bufferNum2 [],int TamanoBuffer2, int buffer[], int TamanoBuffer, int PosicionComa[], int TamanoPosicion);

void DeteccionPosiciones(int &flagEnter, int Posicion[], int tamano, char buffer[], int TotalCaracteres){
   int RepeticionComas=0;
   for(int PosicionBuffer=0;PosicionBuffer<TotalCaracteres;PosicionBuffer++){
      if(buffer[PosicionBuffer]==','){
         Posicion[RepeticionComas]=PosicionBuffer;
         RepeticionComas++;
      }
      if(buffer[PosicionBuffer]==0x08){
         buffer[ContadorBuffer-1]=0;
         buffer[ContadorBuffer-2]=0;
         ContadorBuffer-=2;
      }  
      }   
}
void AgregandoCaracteres(int bufferNum1 [],int TamanoBuffer1, int bufferNum2 [],int TamanoBuffer2, int buffer[], int TamanoBuffer, int PosicionComa[], int TamanoPosicion){
      for(int Posicion=0;Posicion<=PosicionComa[0];Posicion++){
         bufferNum1[Posicion]=buffer[Posicion];
         bufferNum1[PosicionComa[0]]=0x00;       
      }
      for(int Posicion2=PosicionComa[0]+1;Posicion2<=PosicionComa[1];Posicion2++){
         bufferNum2[(Posicion2-PosicionComa[0])-1]=buffer[Posicion2];
         bufferNum2[(PosicionComa[1]-PosicionComa[0])-1]=0x00;
      }
}
      
