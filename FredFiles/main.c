#include <stdio.h>
#include <stdlib.h>

int count_(char *word, int *wordSize, char *text, int *textSize);
int errorCheck(char *word, int wordSize);

int main(){
	FILE *fp;
	fp = fopen("arquivo","r");

	if(fp==NULL){
		printf("Can't open input file");
		return;	// 1;
	}
	
	char word[21];	
	int wordSize = 0;
	while((word[wordSize]=fgetc(fp))!=EOF){
		wordSize++;
		//Identifica erros
		if(errorCheck(word,wordSize)==1)
			return;
		
		//Identifica condicao de parada
		if(word[wordSize-1]=='\n')
			break;
	}

	int textSize = 0;
	char temp;
	while((temp = fgetc(fp)) != EOF)
		textSize++;		
	fseek(fp,wordSize,SEEK_SET); //wordSize+1 or +2 ?
	int size;
	char *text;
	text = (char*) malloc(sizeof(char)*textSize);
	for(size=0; size<textSize; size++){
		text[size]=fgetc(fp);
	}
	
	//Chama função Fortran
	int nTimes;
	nTimes = count_(word, &wordSize, text, &textSize);
		
	printf("\nThe first line string was found %d times in the text\n", nTimes);
	//printf("A string da primeira linha foi encontrada no texto %d vezes", nTimes);
	return;
}

int errorCheck(char *word, int wordSize){
	if(wordSize>=21){
		printf("\nWord is longer than the character limit\n");
		return 1;
	}
	if(!((word[wordSize-1]>='0' && word[wordSize-1]<='9')||(word[wordSize-1]>='A' && word[wordSize-1]<='Z')||(word[wordSize-1]>='a' && word[wordSize-1]<='z')||word[wordSize-1]=='\n')){
		printf("\nWord contains invalid characters\n");
		return 1;
	}
}
