float operacion(char opcion, float num1, float num2);

float operacion(char opcion, float num1, float num2){
   float resultado=0;
   switch(opcion){
      case 's':
      resultado=num1+num2;
      break;
      case 'r':
      resultado=num1-num2;
      break;
      case 'm':
      resultado=num1*num2;
      break;
      case 'd':
      resultado=num1/num2;
      break;
   }
   return resultado;
}
