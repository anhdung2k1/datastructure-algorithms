public class Solution {
    public boolean lemonadeChange(int[] bills) {
        int collected_5b = 0;
        int collected_10b = 0;
        for (int x : bills) {
            if (x == 5) {
                collected_5b++;
            }
            else if(x == 10) {
                if(collected_5b <= 0) return false;
                collected_5b--;
                collected_10b++;
            }
            else if(x == 20){
                if(collected_10b > 0 && collected_5b > 0) {
                    collected_10b--;
                    collected_5b--;
                }
                else if(collected_5b > 2) {
                    collected_5b-=3;
                }
                else {
                    return false;
                }
            }
            if (collected_5b < 0 && collected_10b < 0) return false;
        }
        System.out.printf("Collected 5b: %s, 10b: %s", collected_5b, collected_10b);
        return true;
    }
}
