package leetcode.pow_x_n;

import java.time.LocalTime;

public class Solution {
    public static double myPow_1(double x, int n) {
        //Approach 1: Time Limit Exceeded O(n)
        LocalTime beginTime = LocalTime.now();
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        double ans = 1;
        while (n != 0) {
            ans *= x;
            n--;
        }
        LocalTime endTime = LocalTime.now();
        System.out.printf("Execution: %s\n", (endTime.toNanoOfDay() - beginTime.toNanoOfDay()));
        return ans;
    }
    public static double myPow_2(double x, int n) {
        //Approach 2: Binary Exponentiation Olog2(N)
        LocalTime beginTime = LocalTime.now();
        if (n < 0) {
            x = 1/x;
            n = -n;
        }

        double pow = 1;
        while (n != 0) {
            if (n % 2 != 0) {
                pow *= x;
            }
            x *= x;
            n /= 2;
        }
        LocalTime endTime = LocalTime.now();
        System.out.printf("Execution: %s\n", (endTime.toNanoOfDay() - beginTime.toNanoOfDay()));
        return pow;
    }
    public static void main(String[] args) {
        double x = 24;
        int n = 100;
        // Appro 2 is much less time-consuming
        System.out.println("Appro 1: " + myPow_1(x, n));
        System.out.println("Appro 2: " + myPow_2(x, n));
    }
}
