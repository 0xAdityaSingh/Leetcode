// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int  solve(int n)
   {
       if(n==1)
       return 1;
       if(n%2==0)
       return 1+solve(n/2);
       return 2+solve(n/2);
   }
  public:
    int minOperation(int n)
    {
        return solve(n);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends