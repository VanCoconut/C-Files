
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct array {
char character[100];
};



void* fun1(void* p){
    struct array* a =(struct array*) p;
    struct array* stringa1;

    printf("la somma degli indici pari e':");
    return (void*) &(stringa1->character);
}
void* fun2(void* p){
    struct array* b =(struct array*) p;
    struct array* stringa2;

    printf("la somma degli indici pari e': %d");
    return (void*) &(stringa2->character);
}

int main(){
    pthread_t t1,t2;
    struct array stringa;
    scanf("%s", &stringa.character);

    pthread_create(&t1,NULL,&fun1, stringa.character);
    pthread_create(&t2,NULL,&fun2, stringa.character);

    pthread_join(&t1,NULL);
    pthread_join(&t2,NULL);
    return 0;
}
