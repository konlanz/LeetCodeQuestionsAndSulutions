# You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

# You can return the answer in any order.

 

# Example 1:

# Input: s = "barfoothefoobarman", words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
# The output order does not matter, returning [9,0] is fine too.
# Example 2:

# Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
# Output: []
# Example 3:

# Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
# Output: [6,9,12]
 

# Constraints:

# 1 <= s.length <= 104
# s consists of lower-case English letters.
# 1 <= words.length <= 5000
# 1 <= words[i].length <= 30
# words[i] consists of lower-case English letters.

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
   
        if not s or not words:
            return []
        if len(words) == 1:
            return [i for i in range(len(s)) if s[i:i+len(words[0])] == words[0]]
        if len(words) == 0:
            return []
        if len(words) > len(s):
            return []
        if len(words) * len(words[0]) > len(s):
            return []
        word_len = len(words[0])
        word_num = len(words)
        word_dict = {}
        for word in words:
            if word in word_dict:
                word_dict[word] += 1
            else:
                word_dict[word] = 1
        res = []
        for i in range(len(s) - word_len * word_num + 1):
            if s[i:i+word_len] in word_dict:
                word_dict[s[i:i+word_len]] -= 1
                if word_dict[s[i:i+word_len]] < 0:
                    word_dict[s[i:i+word_len]] += 1
                    i += word_len
                    continue
                for j in range(i+word_len, len(s) - word_len * word_num + 1, word_len):
                    if s[j:j+word_len] in word_dict:
                        word_dict[s[j:j+word_len]] -= 1
                        if word_dict[s[j:j+word_len]] < 0:
                            word_dict[s[j:j+word_len]] += 1
                            break
                    else:
                        break
                    if j == len(s) - word_len * word_num:
                        res.append(i)
                        break
                    else:
                        word_dict[s[j:j+word_len]] += 1
                word_dict[s[i:i+word_len]] += 1
        return res


        











# Time: O(n)


