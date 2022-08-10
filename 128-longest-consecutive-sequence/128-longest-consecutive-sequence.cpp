class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]] = 1;
    for(int i = 0; i < n; i++){
        if(mp.find(arr[i] - 1) != mp.end()){
            mp[arr[i]] = 0;
        }
    }
    int mxLen = 0;
    for(int i = 0; i < n; i++){
        if(mp[arr[i]] == 1) {
            cout<<arr[i]<<endl;
            int length = 1; 
            while(mp.find(arr[i] + length) != mp.end()){
                length++;
            }

            mxLen = max(mxLen, length);
        }
    }
    return mxLen;
    }
};