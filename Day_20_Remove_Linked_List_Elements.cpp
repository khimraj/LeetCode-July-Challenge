/* Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5 */


/* Approach - List traversal */

// Time Complexity - O(n), where n is total number of nodes in list
// Space Complexity - O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode *ptr = head, *prev = NULL;
        while (ptr) {
            while (ptr && ptr->val == val) {
                ptr = ptr->next;
                prev->next = ptr;
            }
            prev = ptr;
            if (ptr){
                ptr = ptr->next;
            }
        }
        return head;
    }
};