class Solution {
unordered_map<float, int> um;
public:
    int maxPoints(vector<vector<int>>& ps) {
        int n = ps.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                float s = (float) (ps[i][1] - ps[j][1]) / (ps[i][0] - ps[j][0]);
                ans = max(ans, ++um[s] + 1);
            }
            um.clear();
        }
        return ans;
    }
};