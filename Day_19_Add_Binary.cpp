/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero. */


/* Approach - String Traversal from right to left */

// Time Complexity - O(max(m,n)), where m is length of string a and n is length of string b
// Space Complexity - O(max(m,n))

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        int i = a.size() - 1, j = b.size() - 1;
        for (; i >= 0 && j >=0; i--, j--) {
            if (carry) {
                if (a[i] == '1' && b[j] == '1') {
                    res = '1' + res;
                    carry = true;
                }
                else if (a[i] == '1' || b[j] == '1') {
                    res = '0' + res;
                    carry = true;
                }
                else {
                    res = '1' + res;
                    carry = false;
                }
            }
            else {
                if (a[i] == '1' && b[j] == '1') {
                    res = '0' + res;
                    carry = true;
                }
                else if (a[i] == '1' || b[j] == '1') {
                    res = '1' + res;
                    carry = false;
                }
                else {
                    res = '0' + res;
                    carry = false;
                }
            }
        }
        while (i >= 0) {
            if (a[i] == '1' && carry) {
                res = '0' + res;
                carry = true;
            }
            else if (a[i] == '1' || carry) {
                res = '1' + res;
                carry = false;
            }
            else {
                res = '0' + res;
                carry = false;
            }
            i--;
        }
        while (j >= 0) {
            if (b[j] == '1' && carry) {
                res = '0' + res;
                carry = true;
            }
            else if (b[j] == '1' || carry) {
                res = '1' + res;
                carry = false;
            }
            else {
                res = '0' + res;
                carry = false;
            }
            j--;
        }
        if (carry) {
            res = '1' + res;
        }
        return res;
    }
};