class Solution {
public:
    int allUnique(vector<int> &arr) {
        set<int> s;
        int n=arr.size();
        
        for (int i=0; i<n; i++) {
            int val=arr[i];
            if (s.count(val)) return false;
            s.insert(val);
        }
        
        return true;
    }
    
    string toString(vector<int> &arr) {
        string res="";
        int n=arr.size();
        
        for (int i=0; i<n; i++) res+= (to_string(arr[i]) + " ");
        return res;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        deque<vector<int>> tRes;
        int n=nums.size();
        
        for (int i=0; i<n; i++) {
            vector<int> v(1, nums[i]);
            tRes.push_back(v);
        }
        
        for (int idx=1; idx<n; idx++) {
            int size=tRes.size();
            
            for (int i=0; i<size; i++) {
                vector<int> arr(tRes.front());
                
                for (int j=0; j<n; j++) {
                    vector<int> curr(arr);
                    int val=nums[j];
                    
                    curr.push_back(val);
                    tRes.push_back(curr);
                }
                
                tRes.pop_front();
            }
        }
        
        vector<vector<int>> res;
        set<string> s;
        
        for (int i=0; i<tRes.size(); i++) {    
            if (allUnique(tRes[i]) && s.count(toString(tRes[i])) == 0) {
                res.push_back(tRes[i]);
                s.insert(toString(tRes[i]));
            }
        }
            
        return res;
    }
};Q
