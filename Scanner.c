#include <stdio.h>
#include <string.h>

int main(){
 
/*
    scanf not allow white space therefore it will affect following scans

    fgets avoid this inconvinient but remeber that it will ad \n ad the end of the scanned line

*/
    
    int age;
    char name[25];
  //  printf("How old are you?\n");
    printf("What's your name?\n");
  //  scanf("%d",&age);
   // scanf("%s",&name);
   fgets(name,25,stdin);
   name[strlen(name)-1]= '\0';
   // printf("You are %d years old",age);
    printf("Hello %s ",name);
    return 0;
}
