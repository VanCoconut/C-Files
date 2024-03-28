#include <stdio.h>
#include <string.h>

int main()
{

  /*
      scanf not allow white space therefore it will affect following scans

      fgets avoid this inconvinient but remeber that it will ad \n ad the end of the scanned line

  */

  int age;
  int x, y;
  char name[10];
  const char *cosa;
  const char *scarto;
  //senza lo scarto non si possono immagazzinare 2 stringhe diverse se si inserisce una prima strigna più lunga di 2
  //scanf("%2s%s%2s",name,scarto,cosa); 
  //printf("nome = %s ,scarto = %s cosa = %s ",name,scarto,cosa);
  //in questo caso essendo 20>"name" viene consideratp lo spazio di separazione
  //scanf("%9s%s %10s",name,scarto,cosa); 

  fscanf(stdin,"%9s%s %10s",name,scarto,cosa);
  printf("nome = %s,scarto = %s, cosa = %s ",name,scarto,cosa);

  //scanf("%d %d",&x,&y);
  //printf("x = %d y = %d", x, y);
  //  printf("How old are you?\n");
  // printf("What's your name?\n");
  //  scanf("%d",&age);
  // scanf("%s",&name);
  // fgets(name,25,stdin);
  // name[strlen(name)-1]= '\0';
  // printf("You are %d years old",age);
  // printf("Hello %s ",name);
  return 0;
}
