#include <bits/stdc++.h>
using namespace std;
struct MyCalendar {
    vector<pair<int,int>> ivals; 
    bool book(int s, int e) {
        int n = (int)ivals.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ivals[mid].first < s) lo = mid + 1;
            else hi = mid;
        }
if (lo > 0 && ivals[lo-1].second > s) return false;
        if (lo < n && ivals[lo].first < e) return false;
        ivals.insert(ivals.begin() + lo, {s, e});
        return true;
    }
};

int main() {
    MyCalendar cal;
    cout << boolalpha;
    cout << cal.book(10,20) << "\n";  


