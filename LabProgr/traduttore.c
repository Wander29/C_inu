/*

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NMAX 300

char* en2pigLatin(char enword[]);
void pig(char* line);
void read(char* line);
void upper(char* line);
int readOption();

int main() {
    char* line= malloc(NMAX*sizeof(char));
    //array of pointers to functions to handle the first 3 options
    //Option 4 is handled directly by the while loop
    void (*f[])(char*)={read,upper,pig};
    int option=readOption();
    while(option!=4){
        f[option-1](line);
        option=readOption();
    }
    printf("Ciao!\n");
    return 0;
}

//reads the new option checking that input is correct
int readOption(){
    int option;
    printf("Scegliere l'operazione:\n");
        
    while(scanf("%d",&option)<1 || option<1 || option>4 ){
        printf("Scegliere l'operazione:\n");
        scanf("%*[^\n]%*c");
    }
    return option;

}

//translates a phrase from english to pig latin
void pig(char* line){
    //first split the phrase into words using strtok.
    //we create a copy of the phrase so that the phrase remains unchanged
    char* copy=malloc(sizeof(char)*(strlen(line)+1));
    strcpy(copy, line);
    //take the first word
    char* token;
    token=strtok(copy, " ");
    while (token!=NULL){
        //translate word using function
        char* translation=en2pigLatin(token);
        //print translation
        printf(" %s",translation);
        //free memory for translation
        free(translation);
        //take the next word
        token=strtok(NULL, " ");
    }
    printf("\n");
    //free memory for the copy
    free(copy);
    
}

//reads one line from standard input
void read(char* line){
    printf("Inserire stringa:\n");
    scanf(" %[^\n]%*c",line);
}

//prints capitalised phrase
void upper(char* line){
    for (int i=0; i<strlen(line); i++)
        printf("%c",toupper(line[i]));
    printf("\n");
}

//checks if a letter is a vowel.
int isVowel(char c, int pos ){
    switch(tolower(c)){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        case 'y'://the letter 'y' is a vowel only if it is not the first letter in the word
            if (pos>0)
                return 1;
    }
    return 0;
}

//translates one word into pig latin
char* en2pigLatin(char  enword[])
{
    char* result=malloc(sizeof(char)*(strlen(enword)+4)) ;
    int upper=isupper(enword[0]);
    int i;
    if (isVowel(enword[0],0)){
        strcpy(result,enword);
        strcpy(result+strlen(enword),"way");
        
    } else {
        i=0;
        while (enword[i]!='\0' && !isVowel(enword[i],i)){
            i++;
        }
        strcpy(result,enword+i);
        strncpy(result+strlen(enword+i),enword,i);
        strcpy(result+strlen(enword),"ay");
    }
    if (upper)
        result[0]=toupper(result[0]);
    for (i=1;i<strlen(result);i++){
        result[i]=tolower(result[i]);
    }
    
    
    return result;
    
        
    
}

