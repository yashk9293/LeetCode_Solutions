// Question Link :- https://leetcode.com/problems/valid-palindrome/
// Valid Palindrome


// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end) {
            if(!isalnum(s[start])) {
                start++;
                continue;
            }
            if(!isalnum(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};