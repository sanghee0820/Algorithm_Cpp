#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int* house, *house_distance;
    int house_cnt;
    int min_distance, min_index;

    cin >> house_cnt;
    house = (int*)malloc(sizeof(int) * house_cnt);
    house_distance = (int*)malloc(sizeof(int) * house_cnt);
    for(int i = 0; i < house_cnt; i++) cin >> house[i];
    sort(house, house + house_cnt);
    cout << house[((house_cnt-1)/2)];
    
    // for(int i = 0; i < house_cnt; i++){
    //     for(int j = i + 1; j < house_cnt; j++){
    //         house_distance[i] += house[j] - house[i];
    //         house_distance[j] += house[j] - house[i];
    //     }
    // }

    // min_distance = house_distance[0];
    // min_index = house[0];

    // for(int i = 1; i < house_cnt; i++){
    //     if( min_distance > house_distance[i]){
    //         min_distance = house_distance[i];
    //         min_index = i;
    //     }
    // }

    // cout << house[min_index];


    return 0;
}