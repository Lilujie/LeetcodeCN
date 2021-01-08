class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;

        int i = 0, j = height.size()-1;
        int max = 0;
        while(i<j) {
            int product = (height[i] > height[j] ? height[j] : height[i] ) * (j - i);
            if (product > max) max = product;
            if (height[i] > height[j])  j--;
            else i++;
        }
       
        return max;

    }
};