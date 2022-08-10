class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1=="0"|| num2=="0") return "0";
        
        int n=num1.size();// len of string num1
        int m=num2.size();// len of string num2
        vector<int> num(n+m,0);
        string ans;
        
        int i=n-1;
        int pf=0;
        while(i>=0){
            int ival=num1[i]-'0';
            i--;
            int carry=0;
            int j=m-1;
            int k=num.size()-1-pf;
            while(j>=0 || carry!=0){
                int jval=j>=0?num2[j]-'0':0;
                j--;
                int prod=ival*jval+carry+num[k];
                num[k]=prod%10;
                carry=prod/10;
                k--;
            }
            pf++;
        }
        bool flag=false;
        for(auto it: num){
            if(it==0 and !flag) continue;
            else{
                flag=true;
                ans+=(it+'0');
            }
        }
        return ans;
    }
};