class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n1len=num1.size();
        int n2len=num2.size();
        vector<int>num(n1len+n2len,0);
        int i=n1len-1;
        int pf=0;
        while(i>=0){
            int ival=num1[i]-'0';
            i--;
            int k=num.size()-1-pf;
            int carry =0;
            int j=n2len-1;
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
        string ans="";
        bool flag = false;
        for(auto it:num){
            if(it==0 and !flag) continue;
            else{
                flag=true;
                ans+=(it+'0');
            }
        }
        return ans;
    }
};