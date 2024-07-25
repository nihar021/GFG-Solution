//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> M) {
        // Create a 2D vector to store the maximum gold up to that cell
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Fill the table from right to left
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                // For the last column, the value is the same as in M
                if (j == m - 1) {
                    ans[i][j] = M[i][j];
                } else {
                    // If it's not the first row, consider the upper-right diagonal
                    int right_up = (i == 0) ? 0 : ans[i - 1][j + 1];
                    // Value from the cell to the right
                    int right = ans[i][j + 1];
                    // If it's not the last row, consider the lower-right diagonal
                    int right_down = (i == n - 1) ? 0 : ans[i + 1][j + 1];

                    // Current cell value is the current gold plus the maximum of the three possible moves
                    ans[i][j] = M[i][j] + max({right_up, right, right_down});
                }
            }
        }

        // The result is the maximum value in the first column
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, ans[i][0]);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends