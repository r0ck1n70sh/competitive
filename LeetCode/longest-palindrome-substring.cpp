class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<pair<int,int>> pre(n);
        
        for (int i=0; i<n; i++) {
            pre[i] = make_pair(i,i);
        }
        
        pair<int, int> max1 = pre[0];
        for (int len=3; len<=n; len+=2) {
            vector<pair<int,int>> nxt;
            
            for (int i=0; i<pre.size(); i++) {
                int l = pre[i].first;
                int r = pre[i].second;

                if (l==0 || r==n-1) continue;
                char c1 = s[l-1];
                char c2 = s[r+1];

                if (c1==c2) nxt.push_back(make_pair(l-1, r+1));
            }
            
            pre=nxt;
            max1=pre[0];
        }
        string s1=s.substr(max1.first, max1.second-max1.first+1);
        
        pre.clear();
        for (int i=1; i<n; i++) {
            if (s[i] == s[i-1]) pre.push_back(make_pair(i-1, i));
        }
        
        if (pre.size() < 1) return s1;
        
        pair<int, int> max2 = pre[0];
         for (int len=4; len<=n; len+=2) {
            vector<pair<int,int>> nxt;
            
            for (int i=0; i<pre.size(); i++) {
                int l = pre[i].first;
                int r = pre[i].second;

                if (l==0 || r==n-1) continue;
                char c1 = s[l-1];
                char c2 = s[r+1];

                if (c1==c2) nxt.push_back(make_pair(l-1, r+1));
            }
            
            pre=nxt;
            max2=pre[0];
        }
        string s2=s.substr(max2.first, max2.second-max2.first+1);
        
        return s1.length() > s2.length() ? s1 : s2;
    }
};
