//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int nCr(int n, int r) {
        const int MOD = 1e9 + 7;
        
        if (r > n) {
            return 0;
        }
        
        vector<vector<int>> pascals_triangle(n + 1, vector<int>(r + 1, 0));
        
        for (int row = 0; row <= n; row++) {
            pascals_triangle[row][0] = 1;
            for (int pos = 1; pos <= min(row, r); pos++) {
                if (row == pos) {
                    pascals_triangle[row][pos] = 1;
                } else {
                    pascals_triangle[row][pos] = (pascals_triangle[row-1][pos-1] + pascals_triangle[row-1][pos]) % MOD;
                }
            }
        }
        
        return pascals_triangle[n][r];
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends