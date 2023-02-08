#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

char* Ary;
char* Alphabet;

void DFS(int cnt, int index, int Max_Count, int i){
    if( cnt == Max_Count){
        int count_vowel = 0;
        int count_consonant = 0;
        for(int i = 0; i < cnt; i++){
            if(Ary[i] == 'a') count_vowel ++;
            else if(Ary[i] == 'e') count_vowel ++;
            else if(Ary[i] == 'i') count_vowel ++;
            else if(Ary[i] == 'o') count_vowel ++;
            else if(Ary[i] == 'u')  count_vowel ++;
            else count_consonant++;
            if ((count_vowel > 0) && (count_consonant > 1)) break;
            
            if( i == cnt -1){
                return;
            }
        }
        for(int i = 0; i < cnt; i++){
            cout << Ary[i];
        }
        cout << "\n";
        return;
    }
    for(int j = i; j < index; j++){
        Ary[cnt] = Alphabet[j];
        DFS(cnt + 1, index, Max_Count, j + 1);
    }
}
int main(){
    int N, M;
    cin >> N >> M;

    Ary = (char*)malloc(sizeof(char) * N);
    Alphabet = (char*)malloc(sizeof(char) * M);
    for(int i = 0; i < M; i++){
        cin >> Alphabet[i];
    }
    sort(Alphabet, Alphabet + M);

    DFS(0, M, N, 0);

    return 0;
}