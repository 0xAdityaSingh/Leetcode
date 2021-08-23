class Solution {
public:
    int numUniqueEmails(vector<string>& mails) {
        unordered_set<string> set;
        for(string mail:mails){
            bool istrue=false,isplus=false;
            string temp="";
            for(int i=0;i<mail.size();i++){
                if(mail[i]=='@'|| istrue){
                    temp+=mail[i];
                    istrue=true;
                }
                else{
                    if(mail[i]!='.' and mail[i]!='+' and !isplus){
                        temp+=mail[i];
                    }
                    if(mail[i]=='+'){
                        isplus=true;
                    }
                }
            }
            set.insert(temp);
        }
        return set.size();
    }
};