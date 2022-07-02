// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int res = -1;
        res = findOn(arr, 0, n);
        return res;
    }
    
    int findOn(int arr[], int low, int high){
        
        if(low == high) return arr[low];
        
        else {
            
            int mid = low + (high - low)/2;
            
            if(mid % 2 == 0)
                if(arr[mid] == arr[mid+1])
                    return findOn(arr, mid+2, high);
                else
                    return findOn(arr, low, mid);
            
            else {
                if(arr[mid] == arr[mid-1])
                    return findOn(arr, mid+1, high);
                else
                    return findOn(arr, low, mid-1);
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends