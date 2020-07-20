/* Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order. */


/* Approach - Use hash map + bucket sorting */

// Time Complexity - O(n), where n is length of nums
// Space Complexity - O(1)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for (auto n : nums) {
            count[n]++;
        }
        vector<vector<int>> bucketsort(nums.size() + 1);
        for (auto itr : count) {
            bucketsort[itr.second].push_back(itr.first);
        }
        vector<int> res;
        for (int i = bucketsort.size() - 1; i >= 0; i--) {
            for (int j = 0; j < bucketsort[i].size(); j++){
                res.push_back(bucketsort[i][j]);
                k--;
                if (k == 0) {
                    break;
                }
            }
            if (k == 0) {
                break;
            }
        }
        return res;
    }
};