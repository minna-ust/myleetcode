/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {

        map<char, int> charMap = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for (char c : text)
        {
            switch (c)
            {
                case 'b':
                    charMap['b']++;
                    break;
                case 'a':
                    charMap['a']++;
                    break;
                case 'l':
                    charMap['l']++;
                    break;
                case 'o':
                    charMap['o']++;
                    break;
                case 'n':
                    charMap['n']++;
                    break;
                default:
                    break;
            }
        }
        int charNums[] = {charMap['b'], charMap['a'], int(charMap['l'] / 2), int(charMap['o'] / 2), charMap['n']};
        return (*std::min_element(charNums, charNums + 5));
    }
};
// @lc code=end
