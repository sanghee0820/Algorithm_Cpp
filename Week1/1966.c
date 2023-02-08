#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Data{
    int index;
    int importance;
}Data;
Data* Queue = NULL;
int front = 0;
int rear = 0;

void push(Data data, int N);
Data pop(int N);
void print(int N, int M);
int importancy();

int main(){
    int test;
    int N, M;

    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        scanf("%d %d", &N, &M);
        Queue = (Data*)malloc(sizeof(Data) * N + 1);
        front = 0;
        rear = N;
        for(int j = 0; j < N; j++){
            scanf("%d", &Queue[j].importance);
            Queue[j].index = j;
        }
        print(N, M);
        free(Queue);
    }

    return 0;
}
void print(int N, int M){
    int count = 0;
    int MAX_importance;
    int Queue_Size;
    
    while( count < N + 1){
        if (front > rear) Queue_Size = N + 1 - (front - rear);
        else Queue_Size = rear - front;

        MAX_importance = Queue[front % (N + 1)].importance;
        for( int i = 1; i < Queue_Size; i ++){
            if (Queue[(front + i) % (N + 1)].importance > MAX_importance) MAX_importance = Queue[(front + i) % (N + 1)].importance;
        }


        for( int i = 0; i < Queue_Size; i ++){
            Data temp = pop(N);
            if( temp.importance != MAX_importance){
                push(temp, N);
            }
            else{
                if(temp.index == M){
                    printf("%d\n", count + 1);
                    return;
                }
                break;
            }
        }
        count++;
    }
}
void push(Data data, int N){

    Queue[(rear++) % (N+1)] = data;
}

Data pop(int N){
    return Queue[(front++) % (N + 1)];
}