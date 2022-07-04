// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>vec;
       int top=0,left=0,bot=r-1,right=c-1;
       while(top<=bot&&left<=right)
       {
           //   Top - Row 
           for(int i=left;i<=right;i++)
           {
               vec.push_back(matrix[top][i]);
           }
           top++;
           //  Right Col
           for(int i=top;i<=bot;i++)
           {
               vec.push_back(matrix[i][right]);
           }
           right--;
           // Bottom Row REverse Order
           if(top<=bot)
           {
               for(int i=right;i>=left;i--)
               {
                   vec.push_back(matrix[bot][i]);
                   
               }
               bot--;
           }
           // left Col Reverse
           if(left<=right)
           {
               for(int i=bot;i>=top;i--)
               {
                   vec.push_back(matrix[i][left]);
               }
               left++;
           }
           
           
           
       }
       return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends