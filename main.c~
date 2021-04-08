#include <stdio.h>
#include <stdlib.h>

int count(char *, int, char *, int);

void main(){
	FILE *fp;
	fp = fopen("teste","r");

	if(fp==NULL){
		printf("Can't open input file");
		return;	// 1;
	}
	
	char word[21];	
	int wordSize = 0;
	while((word[wordSize]=fgetc(fp))!=EOF){ // && wordSize<20
		wordSize++;
		//Identifica erros
		if(wordSize>=21){
			printf("Word is longer than the character limit");
			return;	// 1;
		}
		if(!((word[wordSize]>='0' && word[wordSize]<='9')||(word[wordSize]>='A' && word[wordSize]<='Z')||(word[wordSize]>='a' && word[wordSize]<='z')||word[wordSize]=='\n')){
			printf("Word contains invalid characters");
			return;	// 1;		
		}
		
		//Identifica condicao de parada
		if(word[wordSize-1]=='\n')
			break;
	}

	int textSize = 0;
	char temp;
	while((temp = fgetc(fp)) != EOF)
		textSize++;		
	fseek(fp,wordSize+1,SEEK_SET); //+2 ?
	int size;
	char *text;
	text = (char*) malloc(sizeof(char)*textSize);	//warning
	for(size=0; size<textSize; size++){
		text[size]=fgetc(fp);
	}
	
	//Chama função Fortran
	int nTimes;
	nTimes = count(word, wordSize, text, textSize);
		
	printf("The first line string was found %d times in the text", nTimes);	//error
	//printf("A string da primeira linha foi encontrada no texto %d vezes", nTimes);
	return;
}


//Tinha tentando nao armazenar o '\n', mas nao vale a pena
/*
	char word[20];	
	int wordSize = 0;
	while((word[wordSize]=fgetc(fp))!='\n' && word[wordSize]!=EOF){
		wordSize++;
		//Identifica erros
		if(wordSize>=21){
			printf("Word is longer than the character limit");
			return 1;
		}
		if(!((word[wordSize]>='0' && word[wordSize]<='9')||(word[wordSize]>='A' && word[wordSize]<='Z')||(word[wordSize]>='a' && word[wordSize]<='z'))){
			printf("Word contains invalid characters");
			return 1;		
		}
	}
*/
