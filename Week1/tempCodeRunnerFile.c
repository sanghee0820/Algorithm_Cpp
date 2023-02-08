#include<stdio.h>
#include <stdlib.h>

int front = 0;
int rear = 0;
int* Queue;

void push(int data, int N);
int pop(int N);

int main(){
    int N, M;
    int count = 0;
    int data;
    scanf("%d %d", &N, &M);
    Queue = (int*)malloc(sizeof(int) * M + 1);
    for(int i = 0; i < N; i++){
        push(i + 1,N);
    }

    for(int i = 0; i < M - 1; i++){
        data = pop(N);
        push(data, N);
    }
    printf("<%d", pop(N));
    count ++;

    while( count < N ){
        for(int i = 0; i < M-1; i++){
            data = pop(N);
            push(data, N);
        }

        printf(", %d",pop(N));
        count ++;
    }
    printf(">");
    return 0;
}


void push(int data, int N){

    Queue[(rear++) % (N+1)] = data;
}

int pop(int N){
    return Queue[(front++) % (N + 1)];
}