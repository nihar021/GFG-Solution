//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int wt[], int val[], int capacity, int index, vector<vector<int>>& dp) {
        if (index < 0 || capacity <= 0) {
            return 0;
        }

        if (dp[index][capacity] != -1) {
            return dp[index][capacity];
        }

        int incl = 0;
        if (wt[index] <= capacity) {
            incl = val[index] + solve(wt, val, capacity - wt[index], index - 1, dp);
        }
        int excl = solve(wt, val, capacity, index - 1, dp);

        dp[index][capacity] = max(incl, excl);
        return dp[index][capacity];
    }

    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(wt, val, W, n - 1, dp);
    }
};



//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends