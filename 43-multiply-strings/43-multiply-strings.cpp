class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>vec(n+m);
        int i=m-1;
        int pf=0;
        while(i>=0){
            int ival=num2[i]-'0';
            i--;
            int j=n-1;
            int carry=0;
            int k=vec.size()-1-pf;
            while(j>=0 || carry!=0){
                int jval=j>=0?num1[j]-'0':0;
                j--;
                int prod=ival*jval+carry+vec[k];
                vec[k]=prod%10;
                carry=prod/10;
                k--;
            }
            pf++;
        }
        string ans="";
        bool flag=false;
        for(auto it:vec){
            if(flag==false and it==0) continue;
            else{
                flag =true;
                ans+=it+'0';
            }
        }
        return ans;
    }
};