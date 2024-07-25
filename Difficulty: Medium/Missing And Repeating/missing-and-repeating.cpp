//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
      
    int repeating = -1, missing = -1;

    for (int i = 0; i < n; i++) {
        int abs_val = abs(arr[i]);

        if (arr[abs_val - 1] > 0) {
            arr[abs_val - 1] = -arr[abs_val - 1];
        } else {
            repeating = abs_val;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends