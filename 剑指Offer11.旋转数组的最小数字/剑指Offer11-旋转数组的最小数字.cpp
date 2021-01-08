class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;

        while (left < right) {
            mid = left + (right - left) / 2;
            //中间的值如果比最右边的值大，说明最小值在mid的右边，所以移动left
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            //中间的值如果比最右边的值小，说明最小值在mid的左边，所以移动right
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};