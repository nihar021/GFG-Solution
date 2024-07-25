//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution {
public:
    int countFriendsPairings(int n) 
    { 
        const int MOD = 1'000'000'007;
        
        if (n == 0 || n == 1) return n;
        
        vector<long long> dp(n + 1);
        dp[0] = 1; // There is one way to pair 0 friends: do nothing.
        dp[1] = 1; // There is one way to pair 1 friend: the friend remains single.
        dp[2] = 2; // There are two ways to pair 2 friends: both single or pair them up.
        
        for (int i = 3; i <= n; i++) {
             // dp[i-1]: the i-th friend stays single.
            // (i-1) * dp[i-2]: the i-th friend pairs up with any of the (i-1) friends and the rest (i-2) friends can be paired in dp[i-2] ways.
            dp[i] = (dp[i-1] + (i - 1) * dp[i-2] % MOD) % MOD;
        }
        
        return dp[n] % MOD;
    }
};

 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends