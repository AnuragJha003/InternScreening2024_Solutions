#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // Initialization
    dp[0][0] = isupper(s[0]) ? 0 : 1;
    dp[0][1] = islower(s[0]) ? 0 : 1;

    for (int i = 1; i < n; ++i) {
        if (isupper(s[i])) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + 1;
        } else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
        }
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}