/* Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string. */


/* Approach - String Traversal */

// Time Complexity - O(n), where n is length of string s
// Space Complexity - O(n)

class Solution {
private:
    string appendWord(string sentence, string word) {
        return sentence.size() ? (word + ' ' + sentence) : word;
    }
public:
    string reverseWords(string s) {
        string reverse = "", word = "";
        for (char c : s) {
            if (c == ' ' && word.size() != 0) {
                reverse = appendWord(reverse, word);
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
        }
        if (word.size()) {
            reverse = appendWord(reverse, word);
        }
        return reverse;
    }
};