#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_Index 101 /* 100 + 1*/

int is_end(char*);
void push(char*, char*);

int main(){
    char str[MAX_Index];
    char answer[100000];
    int len = 5000;

    while( is_end(str) ){
        push(str, answer);
    }

    printf("%s", answer);

    return 0;
}

int is_end(char* str){
    gets(str);
    char temp[100];
    if( !strcmp(str, ".") ){
        return 0;
    }

    else{
        while(str[strlen(str)-1] != '.'){
            gets(temp);
            strcat(str,temp);
        }
        return 1;
    }
}

void push(char* str, char* answer){

    char barket[MAX_Index];
    int top = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        switch(str[i]){
            case 91:{ 
                barket[top++] = 91;
                break;
            }
            case 40:{
                barket[top++] = 40;
                break;
            }
            case 93:{
                if(top == 0){
                    strcat(answer, "no\n");
                    return;
                }
                if(!(barket[--top] == 91)){
                    strcat(answer, "no\n");
                    return;
                }
                break;
            }
            case 41:{
                if(top == 0){
                    strcat(answer, "no\n");
                    return;
                }
                if(!(barket[--top] == 40)){
                    strcat(answer, "no\n");
                    return;
                }
                break;
            }
            default: break;
        }
    }
    if(top == 0){
        strcat(answer, "yes\n");
    }
    else{

        strcat(answer, "no\n");
    }
}