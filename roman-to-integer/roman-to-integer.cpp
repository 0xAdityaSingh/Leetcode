class Solution {
public:
    int to_int(char x){
    switch(x){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
    }
    return 0;
}

int romanToInt(string s) {
    int n=s.length();
    int sum=to_int(s[n-1]);
    int pre=to_int(s[n-1]);
    for(int i=n-2;i>=0;i--){
        if(to_int(s[i])<pre){
            sum-=to_int(s[i]);
        }
        else{
            sum+=to_int(s[i]);
        }
        pre=to_int(s[i]);
    }
    return sum;
}
};