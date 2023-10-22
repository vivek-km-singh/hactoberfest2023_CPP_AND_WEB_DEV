#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(const string &text1, const string &text2) {
    int m = text1.size();
    int n = text2.size();

    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcs = dp[m][n];

    for (int i = 0; i <= m; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return lcs;
}

int main() {
    string text1, text2;
    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    int lcs_length = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence is " << lcs_length << endl;

    return 0;
}
