#include <string.h>
#include <stdio.h>

int main(){

    /*
        If you are using just a char or other type but arrays, you can use a temporary variable to store one value    
    */
    char x ='X';
    char y = 'Y';
    char temp;

    temp = x;
    x= y;
    y=temp;

    printf("%c\n",x);
    printf("%c\n",y);


    char water[] ="water";
    char lemonade[] = "lemonade";
    char tempo[15];

    strcpy(tempo,water);
    // the second argument of the string coppy must be a longer word or you can occure in some unespectide behavior
    strcpy(water,lemonade);  
    strcpy(lemonade,tempo);

    printf("%s\n",water);
    printf("%s\n",lemonade);

    return 0;
}