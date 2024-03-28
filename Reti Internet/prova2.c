#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                break;
            }
            printf("Ciao");
        }
        printf("Ciao2");
    }
    
    
    
}