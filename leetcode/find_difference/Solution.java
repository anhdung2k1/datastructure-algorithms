package leetcode.find_difference;

import java.util.*;

public class Solution {
    public static char findTheDifference(String s, String t) {
        char c = 0;
        for (char c_s : s.toCharArray()) {
            c ^= c_s;
        }
        for (char c_t : t.toCharArray()) {
            c ^= c_t;
        }
        return c;
    }
    public static void main(String[] args) {
        Map<String, String> testcases = new HashMap<>() {{
            put("abcd", "abcde");
            put("", "y");
        }};
        for (Map.Entry<String, String> entry : testcases.entrySet()) {
            System.out.println("Diff: "+ findTheDifference(entry.getKey(), entry.getValue()));
        }
    }
}