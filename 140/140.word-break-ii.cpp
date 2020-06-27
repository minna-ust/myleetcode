/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string str;
        recur(0, s.size(), s, wordDict, res, str);
    }

    void recur(int start, int end, string &s, vector<string>& wordDict, vector<string> &res, string str)
    {
        if (start >= end)
        {
            std::cout << str << std::endl;
            res.push_back(str);
            return;
        }
        for (int i = start + 1; i < end; ++i)
        {
            auto iter = std::find(wordDict.begin(), wordDict.end(), s.substr(start, i - start));
            if (iter != wordDict.end())
            {
                str += s.substr(start, i - start) + " ";
                // res.push_back(s.substr(start, i - start));
                recur(i + 1, end, s, wordDict, res, str);
                str -= s.substr(start, i - start) + " ";
            }
        }
    }
};
// @lc code=end
