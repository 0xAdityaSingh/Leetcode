class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int f(0),e(s.size()-1);
        while(f<=e){
            if(s[f]!=s[e]) return false;
            f++;e--;
        }
        return true;
    }
};