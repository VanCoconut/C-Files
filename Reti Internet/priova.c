#include <stdio.h>
#include <time.h>  
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
    char str[80] = "Hello! My name is website";
    const char s[2] = " ";
    char *token,name[20],p1[20]="ciao!",p2[20]="ciao!";
    strcat(p1,p2); 
    //printf("%s",p1);
    for (size_t i = 0; i <10; i++)
    {
        if (i==1)
        {
            goto out;
        }
        
    }
    
    

    token = strtok(str, s);
    /*printf("%s\n",token);

    if (strcmp("Hello!", token) != 0)
    {
        printf("Wrong message 1\n");
    }

    token = strtok(NULL, s);

    if (strcmp("My", token) != 0)
    {
        printf("Wrong message 2\n");
    }

    token = strtok(NULL, s);

    if (strcmp("name", token) != 0)
    {
        printf("Wrong message 3\n");
    }
    token = strtok(NULL, s);

    if (strcmp("is", token) != 0)
    {
        printf("Wrong message 4\n");
    }
    token = strtok(NULL, s);

    strcpy(name, token);
    printf("%s\n", name);*/
    out:printf("ciao");
    return 0;
    
}