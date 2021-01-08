class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        // return climbStairs(n-1)+climbStairs(n-2);超出时间限制
        int fib[3] = {1,1,0};
        for(int i = 2; i <= n; i++) {
            fib[2] = fib[0]+fib[1];
            fib[0] = fib[1];
            fib[1] = fib[2];
        }
        return fib[2];
    }
};