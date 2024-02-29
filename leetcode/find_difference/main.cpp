#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        char findTheDifference(string s, string t) {
            char c = 0;
            for (char c_s : s) {
                c ^= c_s;
            }
            for (char c_t : t) {
                c ^= c_t;
            }
            return c;
        }
        char findTheDifference2(string s, string t) {
            for(int i = 0;i < s.size(); i++) {
                t[i+1]+=t[i]-s[i];
            }
        return t[t.size()-1];
    }
};
int main() {
   string str1 = "abcd";
   string str2 = "abcde";
   
   Solution *solv = new Solution();
   char res = solv->findTheDifference2(str1, str2);
   cout << "Output: " << res << endl;
   char res = solv->findTheDifference1(str1, str2);
   cout << "Output2: " << res << endl;
}