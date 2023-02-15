#include <iostream>
#include <algorithm>
using namespace std;

bool possible = true;
int dooking = 0;
int max_possible = 0;

void greedy(int Gate_range, int* Gate, int Gate_max){

    int temp_Gate = Gate_range-1;
    if( max_possible < temp_Gate) temp_Gate = max_possible;

    while(temp_Gate > -1){
        if(!Gate[temp_Gate]){
            Gate[temp_Gate] = 1;
            dooking++;
        if( max_possible > temp_Gate && Gate_max == Gate_range) max_possible = temp_Gate;
            break;
        }
        temp_Gate--;
    }
    if(temp_Gate == -1) possible = false;
}

int main(){
    int* Gate;
    int Gate_count, Air_count;

    cin >> Gate_count >> Air_count;
    Gate = (int*)malloc(sizeof(int) * Gate_count);
    max_possible = Gate_count-1;

    for(int i = 0; i < Air_count; i++){
        int Gate_range;
        cin >> Gate_range;
        if(possible) greedy(Gate_range, Gate, Gate_count);
    }

    cout << dooking;
    return 0;
}