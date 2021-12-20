// You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

// You can return the answer in any order.

 

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
// Example 3:

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lower-case English letters.
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] consists of lower-case English letters.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> mp;
        for(auto &w : words) mp[w]++;
        for(int i = 0; i < len; i++){
            int left = i, count = 0;
            unordered_map<string, int> tp;
            for(int j = i; j <= n - len; j += len){
                string w = s.substr(j, len);
                if(mp.count(w)){
                    tp[w]++;
                    if(tp[w] <= mp[w]) count++;
                    else{
                        while(tp[w] > mp[w]){
                            string lw = s.substr(left, len);
                            if(mp.count(lw)){
                                tp[lw]--;
                                if(tp[lw] < mp[lw]) count--;
                                left += len;
                            }
                        }
                    }
                    if(count == m) res.push_back(left);
                }
                else{
                    left = j + len;
                    count = 0;
                    tp.clear();
                }
            }
        }
        return res;
        
    }
};