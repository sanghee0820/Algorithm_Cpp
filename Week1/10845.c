#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 10005


int Queue[QUEUE_SIZE];
int front = 0;
int rear = 0;

void push(int data);
void pop();
void size();
void empty();
void front_();
void back();

int main(){

    int N, data;
    char operator[7];
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", operator);
        if(!strcmp(operator, "push")){
            scanf("%d", &data);
            push(data);
        }
        else if(!strcmp(operator, "pop")) pop();
        else if(!strcmp(operator, "size")) size();
        else if(!strcmp(operator, "empty")) empty();
        else if(!strcmp(operator, "front")) front_();
        else back();
    }
    return 0;
}

void push(int data){
    Queue[rear] = data;
    rear = rear + 1 % (QUEUE_SIZE);
}
void pop(){
    if(front == rear){
        printf("-1\n");
    }
    else{
        printf("%d\n", Queue[front]);
        front = (front + 1) % (QUEUE_SIZE);
    }
}
void size(){
    if (front > rear) printf("%d\n",QUEUE_SIZE - (front - rear));
    else printf("%d\n",rear - front) ;
}
void empty(){
    if(front == rear) printf("1\n");
    else printf("0\n");
}
void front_(){

    if(front == rear) printf("-1\n");
    else printf("%d\n",Queue[front]);
}
void back(){
    if(front == rear) printf("-1\n");
    else printf("%d\n", Queue[rear-1]);
}