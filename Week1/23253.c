#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M;
    // Stack Top
    int* Top;
    // Book Group
    int** Books;


    scanf("%d %d", &N, &M);
    Books = (int**)malloc(sizeof(int*) * M);
    Top = (int*)malloc(sizeof(int) * M);

    //Data Scan
    for(int i = 0; i < M; i++){
        scanf("%d", Top + i);
        Books[i] = (int*)malloc(sizeof(int*) * Top[i]);
        for(int j = 0; j < Top[i]; j++) scanf("%d", &Books[i][j]);
    }



    for(int i = 0; i < M; i++){
        for(int j = 0; j < Top[i]-1; j++){
            if(Books[i][j] < Books[i][j+1]){
                printf("No");
                return 0;
            }
        }
    }
    
    printf("Yes");
    return 0;
}