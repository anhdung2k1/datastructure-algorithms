#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        for (int i = 0;i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()) {
                ans[mp[temp]].push_back(strs[i]);
            } else {
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};

int main() {
   vector<string> str = {"eat","tea","tan","ate","nat","bat"};
   
   Solution *solv = new Solution();
   vector<vector<string>> strs = solv->groupAnagrams(str);
   for (auto p : strs) {
    cout << "[\"";
      for (auto s : p) {
        if (s != p.at(p.size()-1))
         cout << s << "\",";
        else
         cout << s << "\"";
      }
      cout << "],";
   }
}
