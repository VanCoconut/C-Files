#include <stdio.h>

int main()
{
   // WRITE/APPEND A FILE "w" to overwrite and "a" append use only absolutre path
   FILE *pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\test.txt", "a");

   fprintf(pF, "Spongebob Squarepants");

   fclose(pF);
   
   // DELETE A FILE
   
  /* if(remove("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\test.txt") == 0)
   {
      printf("That file was deleted successfully!");
   }
   else
   {
      printf("That file was NOT deleted!");
   }*/
   
   return 0;
}