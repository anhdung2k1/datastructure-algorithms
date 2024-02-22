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
};
int main() {
   string str1 = "abcd";
   string str2 = "abcde";
   
   Solution *solv = new Solution();
   char res = solv->findTheDifference(str1, str2);
   cout << "Output: " << res << endl;
}