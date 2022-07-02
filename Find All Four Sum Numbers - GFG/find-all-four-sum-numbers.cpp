// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        if (arr.size() < 4) return {};
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j=i+1;j<n-2;j++){
                 if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                int s=j+1,e=n-1,diff=k-arr[i]-arr[j];
                while(s<e){
                    int l=s,r=e;
                    
                    if(arr[s]+arr[e]==diff){
                        ans.push_back({arr[i],arr[j],arr[s],arr[e]});
                        while (s < e && arr[s] == arr[l]) s++;
                        while (s < e && arr[e] == arr[r]) e--;
                    }
                    else if(arr[s]+arr[e]<diff){
                        s++;
                    }
                    else if(arr[s]+arr[e]>diff){
                        e--;
                    }
                }
            }
        }
        // set<vector<int>> s(ans.begin(), ans.end());
        // vector<vector<int>> fans(s.begin(), s.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends