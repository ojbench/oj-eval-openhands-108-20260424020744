#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> items; // (weight, value)
    
    for (int i = 0; i < n; i++) {
        int p, w, v;
        cin >> p >> w >> v;
        
        // Binary optimization
        int k = 1;
        while (k <= p) {
            items.push_back({k * w, k * v});
            p -= k;
            k *= 2;
        }
        if (p > 0) {
            items.push_back({p * w, p * v});
        }
    }
    
    // 0-1 knapsack DP
    vector<int> dp(m + 1, 0);
    
    for (const auto& item : items) {
        int weight = item.first;
        int value = item.second;
        
        for (int j = m; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    
    cout << dp[m] << endl;
    
    return 0;
}