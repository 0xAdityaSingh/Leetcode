// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
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
        for(int i=0;i<n;i++)sum1+=A[i];
        for(int i=0;i<m;i++)sum2+=B[i];
        if ((sum1 - sum2) % 2 != 0)
	        return -1;
        int diff=(sum1-sum2)/2;
        for(int i=0;i<m;i++){
            int temp=(diff+B[i]);
            // cout<<diff<<" "<<temp<<endl;
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