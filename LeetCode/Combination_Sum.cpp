class Solution {
public:
    vector<vector<int>> dp[501];
    
    void init(vector<int> &arr) {
        for (int val: arr) {
            vector<vector<int>> x = {{val}};
            dp[val] = x;
        }
    }
    
    vector<vector<int>> unique(vector<vector<int>> &arr) {
        set<string> s;
        vector<vector<int>> res;
        
        for (auto v: arr) {
            sort(v.begin(), v.end());
            
            string str = "";
            for (int idx=0; idx<v.size(); idx++) str += (to_string(v[idx]) + " ");
            if (s.count(str)) continue;
            
            res.push_back(v);
            s.insert(str);
        }
        
        return res;
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        init(arr);
        
        auto u = upper_bound(arr.begin(), arr.end(), k);
        vector<int> a(arr.begin(), u);
        
        set<int> s;
        for (int idx=0; idx<a.size(); idx++) s.insert(a[idx]);
        
        for (int idx=2; idx<=k; idx++) {
            vector<vector<int>> res;
            
            for (int i=0; i<idx; i++) {
                int val = idx-i;
                
                vector<vector<int>> v = dp[i];
                vector<vector<int>> v1 = dp[val];
                if (v.size() < 1 || v1.size() < 1) continue;
                
                for (int j=0; j<v.size(); j++) {
                    vector<int> curr(dp[i][j].begin(), dp[i][j].end());
                    
                    curr.push_back(val);
                    res.push_back(curr);
                }
            }
            
            for (int j=0; j<res.size(); j++) {
                dp[idx].push_back(res[j]);
            }
            
            dp[idx]=unique(dp[idx]);
        }
        
        vector<vector<int>> res;
        for (int i=0; i<dp[k].size(); i++) {
            int f=1;
            for (auto val: dp[k][i]) {
                f = f && s.count(val);
            }
            
            if (f) res.push_back(dp[k][i]);
        }
        
        return res;
    }
};
