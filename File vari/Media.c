#include <stdio.h>

int main(){

   int eof=999;
   int num;
   float media;
   int i;
   int sum;

   printf("Iserire i numeri con cui calcolare la media\n");

   for(i=0;;i++)
   {     
      
      scanf("%d",&num);
      
      if (num == eof)
      {
         break;
      }

      sum+=num;
   }

   media=sum/i;

   printf("La media e': %.2f\n",media);
}