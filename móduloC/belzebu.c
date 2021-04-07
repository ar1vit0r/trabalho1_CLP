#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "belzebu.h"

int CheckTextOpen(FILE *TextFile){
    if(TextFile == NULL){
       printf("Can't Open File");
       return 0;
    }
return 1;
};

int GetCharacterQuantityF(FILE *TextFile){
    char write;
    int CharacterQuantityV = 0;

    if(CheckTextOpen(TextFile) == 0){
        return 0;
    }

    while((write = fgetc(TextFile)) != EOF){
        CharacterQuantityV++;
    }
return CharacterQuantityV;
};

char *GetTextFromFile(FILE *TextFile, char *Text, int CharacterQuantity){
    char write;
    int i=0;

    Text = (char*) malloc(sizeof(char)*CharacterQuantity);

    if(CheckTextOpen(TextFile) == 0){
        return NULL;
    }

    while((write = fgetc(TextFile)) != EOF){
       Text[i] = write;
       i++;
    };

return Text;
};

char *GetWordFromFile(FILE *TextFile, char *Word, int CharacterQuantity){
    char write;
    int i = 0;
    int c = 0;
    int z = 0;

    if(CheckTextOpen(TextFile) == 0){
        return NULL;
    }

    while((write = fgetc(TextFile)) != EOF){
       if(write == '\n' || c == 1){
            if(c == 0){
                rewind(TextFile);
                Word = (char*) malloc(sizeof(char)*i);
                z = i;
                i = 0;
                c = 1;
            }
            else if(c == 1 && i <= z ){
                    Word[i-1] = write;
            }
            else if(z == i){
                return Word;
            };
       }
       i++;
    };


return Word;
};

void PrintText(char *Text, int TextSize){
    for(int a=0; a<TextSize; a++){
        printf("%c", Text[a]);
    }
};
