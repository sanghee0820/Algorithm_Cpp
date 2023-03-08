#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j){
    return i > j;
}

int main(){
    int topping, dough_price, topping_price, dough_kal;

    int total_price, total_kal;

    vector<int> topping_kal;

    cin >> topping >> dough_price >> topping_price >> dough_kal;
    
    total_price = dough_price;
    total_kal = dough_kal;
    
    for(int i = 0; i < topping; i++){
        int temp;
        cin >> temp;
        topping_kal.push_back(temp);
    }
    sort(topping_kal.begin(), topping_kal.end(),compare);

    for(int i = 0; i < topping; i++){
        if( (total_kal/total_price) <= ((total_kal + topping_kal[i])/(total_price+topping_price))) {
            total_kal += topping_kal[i];
            total_price += topping_price;
        }
        else{
            break;
        }
    }

    cout << (int)total_kal / total_price;

    return 0;
}