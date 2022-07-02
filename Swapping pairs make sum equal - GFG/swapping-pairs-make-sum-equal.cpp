// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int getSum(int X[], int n)
	{
	    int sum = 0;
	    for (int i = 0; i < n; i++)
	        sum += X[i];
	    return sum;
	}
	 

	int getTarget(int A[], int n, int B[], int m){

	    int sum1 = getSum(A, n);
	    int sum2 = getSum(B, m);
	 

	    if ((sum1 - sum2) % 2 != 0)
	        return INT_MIN;
	    return ((sum1 - sum2) / 2);
	}
	bool binary_search(int v[],int s,int e,int val){
	    if(s>e) return false;
	    int mid=(s+e)/2;
	    if(v[mid]==val) return true;
	    else if(v[mid]>val){
	        return binary_search(v,s,mid-1,val);
	    }
	    else if(v[mid]<val){
	        return binary_search(v,mid+1,e,val);
	    }
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum1=0,sum2=0;
        sort(A,A+n);
        sort(B,B+m);
        int diff=getTarget(A,n,B,m);
        if(diff==INT_MIN) return -1;
        for(int i=0;i<m;i++){
            int temp=diff+B[i];
            if(binary_search(A,0,n-1,temp)) return 1;
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends