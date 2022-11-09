class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<string> res, prev;
    
    for (char c='a'; c<'a'+n; c++) {
      string curr = "";
      curr += c;
      prev.push_back(curr);
    }
    
    for (int idx=1; idx<k; idx++) {
      int size=prev.size();
      res.clear();

      for (int i=0; i<size; i++) {
        string curr=prev[i];

        for (char p=curr[curr.size()-1]+1; p<'a'+n; p++) {
          string str=curr;
          str+=p;
          res.push_back(str);
        }
      }
      
      prev=res;
    }
    
    vector<vector<int>> res1;
    for (int i=0; i<prev.size(); i++) {
      string curr=prev[i];
      vector<int> curr1(k);
      for (int p=0; p<curr.size(); p++) {
        curr1[p]=curr[p]-'a'+1; 
      }
      res1.push_back(curr1);
    }
    
   return res1;
  }
};
