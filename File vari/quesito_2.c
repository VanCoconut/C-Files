#include <stdio.h> 
#include <stdlib.h>

#define ALFABETO 26

void read_char_by_char_fgetc(FILE *fp, int* frequenze){
	char buf = fgetc(fp);
	while(buf != EOF){
		/*se il carattere è maiuscolo*/
		if('A' <= buf && buf <= 'Z'){
			frequenze[buf-'A']++;
		}
		/*se il carattere è minusolo*/ 
		else if('a' <= buf && buf <= 'z'){
			frequenze[buf-'a']++;
		}
		/*negli altri casi non faccio nulla*/
		buf = fgetc(fp);
	}
	return;
}

void read_char_by_char_fscanf(FILE *fp, int* frequenze){
	char buf;
	while(fscanf(fp, "%c", &buf) > 0){
		/*se il carattere è maiuscolo*/
		if('A' <= buf && buf <= 'Z'){
			frequenze[buf-'A']++;
		}
		/*se il carattere è minuscolo*/ 
		else if('a' <= buf && buf <= 'z'){
			frequenze[buf-'a']++;
		}
		/*negli altri casi non faccio nulla*/
	}
	return;
}

void printArray(int* array, size_t n){
	for (int i = 0; i < n; ++i){
		printf("[%d] ", array[i]);
	}
	printf("\n");
}

int main(){ 
	char pathToFile[100];
	printf("Inserire path: ");
	scanf("%s", pathToFile);

	FILE *fp = fopen(pathToFile, "r");
	
	if (fp != NULL){
		int *frequenze = (int*) calloc(ALFABETO, sizeof(int));
		read_char_by_char_fscanf(fp, frequenze);
		printArray(frequenze, ALFABETO);

		read_char_by_char_fgetc(fp, frequenze);
		printArray(frequenze, ALFABETO);

		free(frequenze);
		fclose(fp);
	} else
		printf("%s\n", "Path non valido");
	return 0;
}
