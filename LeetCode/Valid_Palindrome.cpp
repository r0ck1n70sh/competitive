class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string f = "";
        
        for (int i=0; i<n; i++) {
            char ch = s[i];
            
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <='9')) {
                f += ch;
                continue;
            }
            
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'a' + (ch - 'A');
                f += ch;
                continue;
            }
        }
        
        n = f.length();
        for (int i=0; i<n/2; i++) {
            char c1 = f[i];
            char c2 = f[n-i-1];
            
            if (c1 != c2) return false;
        }
        
        return true;
    }
};
