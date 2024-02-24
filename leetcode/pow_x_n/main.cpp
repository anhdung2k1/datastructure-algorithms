#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if (n < 0) {
                x = 1/x;
                n = -n;
            }
            double ans = 1;
            while(n != 0) {
                if (n & 1 != 0) {
                    ans *= x;
                }
                x *= x;
                n >>= 1;
            }
            return ans;
        }
};

int main() {
    double x = 82;
    int n = 45;
    Solution *solv = new Solution();
    cout << solv->myPow(x,n) << endl;
    return 1;
}