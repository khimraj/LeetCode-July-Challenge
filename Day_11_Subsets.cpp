/* Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
] */


/* Approach - Iterative */

// Time Complexity - O((2^n)*n), where n is length of nums
// Space Complexity - O(2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++){
                vector<int> v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};