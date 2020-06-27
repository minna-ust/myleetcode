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
        map<string, vector<string>> resMap;
        recur(0, s.size(), s, wordDict, res, str, resMap);
        std::cout << "z-----" << __FUNCTION__ << " " << __FILE__ << "::" << __LINE__ << std::endl;
        for (auto item : resMap)
        {
            cout << " key " << item.first  << std::endl;
            for (auto value : item.second)
            {
                cout << value << " \t " << endl;
            }
        }
        return resMap[s.substr(0, s.size())];
    }

    void recur(int start, int end, string &s, vector<string>& wordDict, vector<string> &res, string str, map<string, vector<string>> &resMap)
    {
        if (start >= end)
        {
            // std::cout << str << std::endl;
            // res.push_back(str);
            res.push_back("");
            return;
        }
        if (resMap.count(s.substr(start, end)))
        {
            res = resMap[s.substr(start, end)];
            return;
        }
        for (int i = start + 1; i <= end; ++i)
        {
            auto iter = std::find(wordDict.begin(), wordDict.end(), s.substr(start, i - start));
            if (iter != wordDict.end())
            {
                // str += s.substr(start, i - start) + " ";
                // res.push_back(s.substr(start, i - start));
                string foo = s.substr(start, i - start) + " ";
                cout << "foo " << foo << endl;
                vector<string> bar;
                recur(i, end, s, wordDict, bar, str, resMap);
                for (auto each : bar)
                {
                    string tmp = foo + each;
                    cout << " tmp " << tmp << endl;
                    size_t last = (foo + each).find_last_not_of(' ');
                    res.push_back((foo + each).substr(0, last + 1));
                }
                cout << " #### " << endl;
                for (auto r : res)
                {
                    cout << r << " \t " << endl;
                }
                if (resMap.count(s.substr(start, end)))
                {
                    resMap[s.substr(start, end)] = res;
                }
                else
                {
                    resMap.insert(pair<string, vector<string>>(s.substr(start, end), res));
                }
                // str -= s.substr(start, i - start) + " ";
            }
        }
    }
};
// @lc code=end
