class Solution {
public:

    int maxProfit(vector<int>& arr) {
  int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 

        for (int i = n - 1; i >= 0; i--) { 
            for (int j = 1; j >= 0; j--) { 
                int profit = 0;
                if (j) { 
                    profit = max(-arr[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    profit = max(arr[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][1]; 
        
    }
};