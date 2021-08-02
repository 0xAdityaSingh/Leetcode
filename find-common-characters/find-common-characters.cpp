class Solution {
public:
    string common(string s1,string s2){
        unordered_map<char,int> mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        string ans="";
        for(int i=0;i<s2.size();i++){
            if(mp.find(s2[i])!=mp.end()){
                if(mp[s2[i]]>0){
                    ans+=s2[i];
                    mp[s2[i]]--;
                }
            }
        }
        return ans;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string>vec;
        if(words.size()==0){
            return vec;
        }
        string ans=words[0];
        for(int i=1;i<words.size();i++){
            ans=common(ans,words[i]);
        }

        for(int i=0;i<ans.size();i++){
            string str;
            str.append(1, ans[i]);
            vec.push_back(str);
        }
        return vec;
        
    }
};