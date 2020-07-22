/* Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
] */


/* Approach - bfs traversal */

// Time Complexity - O(n), where n is total numbers of node in tree
// Space Complexity - O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        int level = 0;
        while (!bfs.empty()) {
            vector<int> v;
            int size = bfs.size();
            for (int i = 0; i < size; i++){
                TreeNode *ptr = bfs.front();
                if (level % 2) {
                    v.insert(v.begin(), ptr->val);
                }
                else {
                    v.push_back(ptr->val);
                }
                if (ptr->left) {
                    bfs.push(ptr->left);
                }
                if (ptr->right) {
                    bfs.push(ptr->right);
                }
                bfs.pop();
            }
            level++;
            res.push_back(v);  
        }
        return res;
    }
};