#include <iostream>
#include <vector>
using namespace std;

int knap(vector<int> &weight, vector<int> &value, int capacity, int n){
    if (n == 0 || capacity == 0){
        return 0;
    }
    
    if (weight[n-1] > capacity){
        return knap(weight, value, capacity, n-1);
    }

    int choose = knap(weight, value, capacity - weight[n-1], n-1) + value[n-1];
    int nChoose = knap(weight, value, capacity, n-1);
    
    return max(choose, nChoose);
}


int main(){
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};   
    int capacity = 50;               
    int n = weights.size();               
    
    int maxValue = knap(weights, values, capacity, n);
    cout <<  maxValue << endl;
    return 0;
}
