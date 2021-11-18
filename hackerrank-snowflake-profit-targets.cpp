#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int stockPairs_Optimal(vector<int> stockPairs, int targetProfit) {
    map<int, int> profits;
    set<pair<int, int> > pairSet;
    for (int i = 0;i<stockPairs.size();i++) {
        if(profits.find(stockPairs[i]) == profits.end()) {
            profits[stockPairs[i]] = 1;
        } else {
            profits[stockPairs[i]]++;
        }
    }

    for (int i = 0;i<stockPairs.size();i++) {
        if(profits.find(targetProfit-stockPairs[i])==profits.end())
            continue;
        if(profits[targetProfit-stockPairs[i]]<=0 || profits[stockPairs[i]]<=0)
            continue;
        if(stockPairs[i]==targetProfit-stockPairs[i] && profits[stockPairs[i]]<=1)
            continue;
        if(pairSet.find({stockPairs[i],targetProfit-stockPairs[i]})!=pairSet.end() || pairSet.find({targetProfit-stockPairs[i],stockPairs[i]})!=pairSet.end())
            continue;
        profits[stockPairs[i]] -= 1;
        profits[target - stockPairs[i]] -= 1;
        pairSet.insert({stockPairs[i], target - stockPairs[i]});
    }
    return pairSet.size();
}

int stockPairs_BruteForce(vector<int> stockProfits, int targetProfit) {

    int numPairs = 0;
    for (int i = 0; i < stockProfits.size(); i++) {
        for (int j = i + 1; j < stockProfits.size(); j++) {
            if (stockProfits[i] + stockProfits[j] == targetProfit) {
                numPairs++;
            }
        }
    }
    return numPairs;
}

int main() {
    vector<int> stocksProfits = {5, 7, 9, 13, 11, 6, 6, 3, 3};
    int targetProfit = 12;


}