#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<pair<int, vector<int>>> pr;

    pr.push_back({10, {}});
    pr.push_back({20, {10, 20}});
    pr.push_back({30, {10, 20 , 40}});
    pr.push_back({20, {10, 20}});

    for(int i = 0;  i< pr.size(); i++) {
        cout << pr[i].first << " -> ";
        for(int j = 0; j < pr[i].second.size(); j++) {
            cout << pr[i].second[j] << " ";
        }
        cout << endl;
    }

    // for(auto vec: pr) {
    //     cout << vec.first << " => ";
    //     for(auto vec2: vec.second) {
    //         cout << vec2 << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}