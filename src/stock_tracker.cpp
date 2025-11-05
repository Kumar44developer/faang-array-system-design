#include <bits/stdc++.h>
using namespace std;

struct StockTracker {
    vector<long long> ring; 
    int K, head, count;
    long long ringSum, curPrice, globalMin, globalMax;

  explicit StockTracker(int k)
        : K(k), head(0), count(0), ringSum(0), curPrice(0),
          globalMin(LLONG_MAX), globalMax(LLONG_MIN) {
        ring.assign(max(1, K), 0);
    }


    void update(long long price) {          
        curPrice = price;
        globalMin = min(globalMin, price);
        globalMax = max(globalMax, price);

    if (K <= 0) return;
        if (count < K) {
            ringSum += price;
            ring[head] = price;
            head = (head + 1) % K;
            ++count;
        } else {
            long long old = ring[head];
            ringSum += price - old;
            ring[head] = price;
            head = (head + 1) % K;
        }
    }
