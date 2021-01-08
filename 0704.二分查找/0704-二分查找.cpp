class Solution {
public:
    int search(vector<int>& nums, int target) {
        //套用模板
        // int left = -1, right = nums.size(), mid;
        // while (left + 1 != right) {
        //     mid = (left + right)/2;
        //     if(nums[mid] < target)
        //         left = mid;
        //     else
        //         right = mid;
        // }
        // if (right < nums.size() && nums[right] == target)
        //     return right;
        // else
        //     return -1;

        //递归
        return binary_search(nums, target, 0, nums.size()-1);
    }

    int binary_search(vector<int>& nums, int target, int left, int right) {
        if(left > right) return -1;

        int mid = (left + right)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return binary_search(nums, target, mid + 1, right);
        else return binary_search(nums, target, left, mid - 1);
    }
};