/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
] */


/* Approach - BFS */

// Time Complexity - O(n), where n is total number of nodes in tree
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> traversalList;
        if (root == NULL) {
            return traversalList;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            int nodesCount = nodesQueue.size();
            vector<int> levelNodes;
            TreeNode *currNode;
            for (int index = 0; index < nodesCount; index++) {
                currNode = nodesQueue.front();
                levelNodes.push_back(currNode->val);
                if (currNode->left) {
                    nodesQueue.push(currNode->left);
                }
                if (currNode->right) {
                    nodesQueue.push(currNode->right);
                }
                nodesQueue.pop();
            }
            traversalList.insert(traversalList.begin(), levelNodes);
        }
        return traversalList;
    }
};