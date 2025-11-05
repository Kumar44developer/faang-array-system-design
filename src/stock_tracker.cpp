#include <bits/stdc++.h>
using namespace std;

struct StockTracker {
    vector<long long> ring; 
    int K, head, count;
    long long ringSum, curPrice, globalMin, globalMax;
