#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_five = 0, bill_ten = 0;
        for(auto bill : bills) {
            if (bill == 5) bill_five++;
            else if(bill == 10) bill_five--, bill_ten++;
            else if(bill_ten > 0) bill_ten--, bill_five--;
            else bill_five-=3;
            if (bill_five < 0) return false;
        }
        return true;
    }
};