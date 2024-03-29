#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left = 0, right=col-1,top=0,bottom=row-1;

        while(top <= bottom && left <= right) {
            //left to right
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            //top to bottom
            for(int i=top;i<=bottom;i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom) {
                //right to left
                for(int i=right;i>=left;i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //bottom to top
            if(left <= right) {
                for(int i=bottom;i>=top;i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};