// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
// Accepted
// 392.6K
// Submissions
// 686.4K
// Seen this question in a real interview before?


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partitionHelper(s, 0, path, res);
        return res;
        
    }

    void partitionHelper(string s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                partitionHelper(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};