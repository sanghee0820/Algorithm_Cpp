#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

int* non_breaked_chanel;
void DFS(int* min_difference_chanel, int* min_difference, int chanel, int cnt, int* Ary, int digits, int number, int index){
    
    // cnt = 숫자 개수, index = 사용가능한 숫자(Ary)탐색 digits = 채널 숫자 개수, number 결과값, 
    if( cnt == digits){
        if(abs(chanel - number) + digits < *min_difference){
            *min_difference = abs(chanel - number) + digits;
            *min_difference_chanel = number;
        }
        return;
    }
    for(int i = 0; i < index; i++){
        number += pow(10,digits - cnt - 1) * Ary[i];
        DFS(min_difference_chanel,min_difference, chanel, cnt + 1, Ary, digits, number, index);
        number -= pow(10,digits - cnt - 1) * Ary[i];
    }
}

int main(){

    int chanel, breaked;
    int* breaked_chanel;
    int cnt = 0;
    
    cin >> chanel >> breaked;
    for(int i = 1; ; i++){ // count chanel digits
        cnt++;
        if((int)(chanel / (pow(10,i))) == 0) break;
    }

    breaked_chanel = (int*)malloc(sizeof(int) *  breaked);
    non_breaked_chanel = (int*)malloc(sizeof(int) * 10 - breaked);

    for(int i = 0; i < breaked; i++){
        cin >> breaked_chanel[i];
    }

    stack<int> temp ;
    for( int i = 0; i < 10; i++){
        
        temp.push(i);
        for(int j = 0; j < breaked; j++){
            if(breaked_chanel[j] == temp.top()){
                temp.pop();
                break;
            }
        }
    }
    for(int i = 0; i < 10-breaked; i++){
        non_breaked_chanel[i] = temp.top();
        temp.pop();
    }
    sort(non_breaked_chanel, non_breaked_chanel + 10 - breaked);

    int min_difference_chanel = 100, min_difference = abs(chanel - min_difference_chanel);
    int temp_chanel = 100;

    // Number of digits - 1
    if( cnt != 1 ){
        temp_chanel = 0;
        for(int i = 0; i < cnt - 1; i++ ){
            temp_chanel += pow(10,i) * non_breaked_chanel[9 - breaked];
        }
        if( abs(chanel - temp_chanel) + cnt - 1 < min_difference){
            min_difference_chanel = temp_chanel;
            min_difference = abs(chanel - temp_chanel) + cnt - 1;
        }
    }
    else{
        for( int i = 0; i < 10-breaked; i++){
            temp_chanel = non_breaked_chanel[i];
            if( abs(chanel - temp_chanel) + 1 < min_difference){
                min_difference_chanel = temp_chanel;
                min_difference = abs(chanel - temp_chanel) + 1;
            }
        }
    }

    // Number of digits + 1
    temp_chanel = 0;
    if( non_breaked_chanel[0] == 0){
        temp_chanel += pow(10,cnt) * non_breaked_chanel[1];
    }
    else{
        for(int i = 0; i < cnt + 1; i++ ) temp_chanel += pow(10,i) * non_breaked_chanel[0];
    }
    if( abs(chanel - temp_chanel) + cnt + 1 < min_difference){
        min_difference_chanel = temp_chanel;
        min_difference = abs(chanel - temp_chanel) + cnt + 1;
    }

    DFS(&min_difference_chanel, & min_difference, chanel, 0, non_breaked_chanel, cnt, 0, 10 - breaked);

    if( breaked != 10) cout << min_difference;
    else cout<< abs(chanel-100);

    return 0;
}