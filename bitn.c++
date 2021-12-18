// // 902. Numbers At Most N Given Digit Set
// Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
// Return the number of positive integers that can be generated that are less than or equal to a given integer n.
// Example 1:
// Input: digits = ["1","3","5","7"], n = 100
// Output: 20
// Explanation:
// The 20 numbers that can be written are:
// 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
// Example 2:
// Input: digits = ["1","4","9"], n = 1000000000
// Output: 29523
// Explanation:
// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
// In total, this is 29523 integers that can be written using the digits array.
// Example 3:
// Input: digits = ["7"], n = 8
// Output: 1
// Explanation:
// The 8 numbers that can be written are: 7, 7, 71, 77, 707, 771, 7071, 7717.
// Example 4:
// Input: digits = ["1","2","3","4","5","6","7","8","9"], n = 999999999
// Output: 29523
// Explanation:
// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
// In total, this is 29523 integers that can be written using the digits array.
// Constraints:
// 1 <= digits.length <= 9
// digits[i] contains '0' - '9'
// All the integers will be in the range [0, 999999999].
// All the values in digits are unique.
// digits is sorted in non-decreasing order.
// 1 <= n <= 10^9

class Solution {
public:

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int len = digits.size();
        int res = 0;
        int cur = 0;
        int cur_len = 0;
        

        while (cur_len < len) {
            int cur_num = 0;
            for (int i = cur_len; i < len; i++) {
                cur_num = cur_num * 10 + (digits[i][0] - '0');
            }
            if (cur_num > n) {
                break;
            }
            res += cur_num;
            cur_len++;
        }

    }


};

