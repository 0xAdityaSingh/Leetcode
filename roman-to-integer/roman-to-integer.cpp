class Solution {
public:
    int to_int(char x){
    switch(x){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
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