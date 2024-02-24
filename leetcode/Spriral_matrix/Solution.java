package leetcode.Spriral_matrix;
import java.util.*;

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int top = 0;
        int bottom = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;
        while (top <= bottom && left <= right) {
            // Left to right
            for(int i = left; i <= right; i++) {
                ans.add(matrix[top][i]);
            }
            top++;
            // Top to bottom
            for(int i = top; i <= bottom; i++) {
                ans.add(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                // Right to left
                for(int i = right;i >= left;i--) {
                    ans.add(matrix[bottom][i]);
                }
                bottom--;
            }
            // Bottom to top
            if (left <= right) {
                for(int i = bottom;i >= top;i--) {
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
}
