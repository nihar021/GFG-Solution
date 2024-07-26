//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

// class Solution {
// public:
//     long long countWays(int n, int k) {
//         long long MOD = 1000000007;

//         // If there's only one fence, the number of ways to paint it is k
//         if (n == 1) return k % MOD;

//         // Same: Ways to paint fences such that last two fences are of the same color
//         // Diff: Ways to paint fences such that last two fences are of different colors
//         // Total: Total number of ways to paint fences up to the current fence
//         long long same = k % MOD;
//         long long diff = (k * (k - 1)) % MOD;
//         long long total = (same + diff) % MOD;

//         // Calculate the number of ways to paint fences from 3 to n
//         for (int i = 3; i <= n; i++) {
//             same = diff % MOD;                   // Update same to previous diff
//             diff = (total * (k - 1)) % MOD;      // Update diff to previous total times (k - 1)
//             total = (same + diff) % MOD;         // Update total to the sum of same and diff, modulo MOD
//         }

//         return total; // Return the total number of ways to paint the fence modulo MOD
//     }
// };


class Solution{
    public:
    long long countWays(int n,int k){
        long long dp[n+1],mod=1000000007;
        long long m=k;
        
        dp[1]=m;
        dp[2]=(m*m)%mod;
        
        for(int i=3;i<=n;i++){
            dp[i]=(((dp[i-1]+dp[i-2])%mod)*(m-1))%mod;
        }
        
        return dp[n];
    }
};













//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends