#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > class_time;

priority_queue< int, vector<int>, greater<int> > pq_endtime;

int greedy(int class_count){
    pq_endtime.push(class_time[0].second);

    for(int i=1; i<class_count; ++i){
        pq_endtime.push(class_time[i].second);

        if (pq_endtime.top() <= class_time[i].first){
            pq_endtime.pop();
        }
    }
    return pq_endtime.size();
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        int start, end;
        cin >> start >> end;

        class_time.push_back(make_pair(start, end));
    }

    sort(class_time.begin(), class_time.end());

    cout << greedy(n);

}