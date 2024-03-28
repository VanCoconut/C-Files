#include <stdio.h>
#include <string.h>

typedef enum {Sun=1,Mon,Tue,Web,Thu,Fri,Sat} Day;

int main(){

    Day today = Mon;

    //enums are not STRINGS, they are rapresented as INTEGERS
    printf("\nEnum value is: %d",today);

    //However, apart from the printing, we can use it as the valeu we assignet it at the definition so...

    if (today==Sat || today==Sun)
    {
        printf("\nIt's the weekend");
    }
    else
    {
        printf("\nIt's not the weekend");
    }
    

    return 0;
}