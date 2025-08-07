#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n; // Handle k > n

        // Step 1: Reverse the whole array
        reverse(nums, 0, n - 1);

        // Step 2: Reverse first k elements
        reverse(nums, 0, k - 1);

        // Step 3: Reverse the remaining n-k elements
        reverse(nums, k, n - 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution sol;
    sol.rotate(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
