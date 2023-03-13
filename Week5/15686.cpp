#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int* selected_chicken;
int left_chicken, min_distance = 100000;
vector< pair<int, int> > house, chicken;


void DFS(int cnt, int chicken_cnt, int start){
    if(cnt == left_chicken){
        int temp_distance = 0; // 도시 치킨거리 temp
        for(int i = 0; i < house.size(); i++){
            int temp = 0;
            int min_chicken_distance = 10000;   // 집 기준 / 선택된 치킨집 중 가장 짧은 치킨집과의 거리
            for(int j = 0; j < cnt; j++){
                temp = 0;
                temp += abs(house[i].first - chicken[ selected_chicken[j]].first);
                temp += abs(house[i].second - chicken[ selected_chicken[j]].second);
                if( temp < min_chicken_distance) min_chicken_distance = temp;
            }
            temp_distance += min_chicken_distance;
            if(temp_distance > min_distance) return;
        }
        min_distance = temp_distance;
        return;
    }
    else{
        for(int i = start; i < chicken_cnt; i++){
            selected_chicken[cnt] = i;
            DFS(cnt + 1, chicken_cnt, i + 1);
        }
    }

}

int main(){

    int N;
    vector<int> Distance;
    
    cin >> N >> left_chicken;
    selected_chicken = (int*)malloc(sizeof(int) * left_chicken);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            if(temp == 1) house.push_back(make_pair(i, j));
            if(temp == 2) chicken.push_back(make_pair(i, j));
        }
    }
    DFS(0, chicken.size(), 0);
    cout << min_distance;
    return 0;
}