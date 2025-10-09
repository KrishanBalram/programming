#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If found, find just larger element on right
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse right part
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    cout << "Original array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    obj.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
