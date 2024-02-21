package leetcode.Bitwise_AND_Numbers_Range;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right) {
            left >>=1;
            right >>=1;
            count++;
        }
        return (left << count);
    }
    
    public static void main(String[] args) {
        Map<Integer, Integer> testcases = new HashMap<>() {{
            put(5, 7);
            put(0, 0);
            put(1, 2147483647);
        }};
        for(Map.Entry<Integer, Integer> entry : testcases.entrySet()) {
            System.out.println("Input: left = " + entry.getKey() + ", right = " + entry.getValue());
            System.out.println("Output: " + rangeBitwiseAnd(entry.getKey(), entry.getValue()));
        }
    }
}