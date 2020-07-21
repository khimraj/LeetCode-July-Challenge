/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3 */


/* Approach - DFS */

// Time Complexity - O(m*n*(4^l)), where m*n is size of bard and l is length of word
// Space Complexity - O(1)

class Solution {
private:
    bool search(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[index] != board[i][j]) {
            return false;
        }
        char c = board[i][j];
        board[i][j] = '*';
        bool res =  search(board, word, index + 1, i + 1, j) || search(board, word, index + 1, i - 1, j) || search(board, word, index + 1, i, j + 1) || search(board, word, index + 1, i, j - 1);
        board[i][j] = c;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && search(board, word, 0, i, j)) {
                    return true;
                } 
            }
        }
        return false;
    }
};