// Question Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Question Link :- https://leetcode.com/problems/delete-operation-for-two-strings/
// Minimum number of deletions and insertions


// MEMOIZATION
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int LCS(string text1, string text2, int n, int m, vector<vector<int>> &t) {
        if (n == 0 || m == 0) {
		    return 0;
		}
	    if (t[n][m] != -1) {
		    return t[n][m];
		}
	    if (text1[n - 1] == text2[m - 1]) {
		    t[n][m] = 1 + LCS(text1, text2, n - 1, m - 1, t);
		} else {
		    t[n][m] = max(LCS(text1, text2, n - 1, m, t), LCS(text1, text2, n, m - 1, t)); 
		}
	    return t[n][m];
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

	    int deletions = m - LCS(word1, word2, m, n, t);
	    int insertions = n - LCS(word1, word2, m, n, t);
	    
	    return deletions + insertions;
    }
};



// TABULATION
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int LCS(string X, string Y, int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (Y[i - 1] == X[j - 1]) { 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string X, string Y) {
        int m = X.length(), n = Y.length();
	    int deletions = m - LCS(X, Y, m, n);
	    int insertions = n - LCS(X, Y, m, n);
	    
	    return deletions + insertions;
    }
};


// Input :-
// heap
// pea

// Output :-
// 3 (deletions = 2 + insertions = 1)