#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N;
    int top = 0, pushed = 1;

    int* Sequence, * Ary;
    char* Answer;
    scanf("%d", &N);

    
    Sequence = (int*)malloc(sizeof(int) * N);
    Ary = (int*)malloc(sizeof(int) * N);
    Ary[0] = 0;
    
    Answer = (char*)malloc(N *4 + 1);
    for(int i = 0; i < N; i++){
        scanf("%d", Sequence + i);
    }


    Ary[top++] = pushed++;
    strcat(Answer, "+\n"); 

    for(int i = 0; i < N; i++){
        // Pushed index < 
        if( Sequence[i] < Ary[top-1]) break;

        while( Sequence[i] != Ary[ top - 1 ]){
            Ary[top++] = pushed++;
            strcat(Answer, "+\n"); 
        }
        strcat(Answer,"-\n");
        top--;

    }

    if(strlen(Answer) == N * 4){
        printf("%s", Answer);
    }
    else{
        printf("NO");
    }
    return 0;
}