#include <cassert>
#include "stdcom.hpp"
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        int residual = num.size() - k;

        if (residual <= 0)
            return "0";
        vector<vector<string>> dp;
        dp.resize(residual);

        for (int i = 0; i < residual; ++i)
        {
            dp[i].resize(len);
            dp[i][len - 1 - i] = num.substr(len - 1 - i, i + 1);
            for (int j = len - 1 - i - 1; j >= 0; --j)
            {
                if (i == 0)
                {
                    if (num.substr(j, 1).compare(dp[i][j + 1]) >= 0)
                    {
                        dp[i][j] = dp[i][j + 1];
                    }
                    else
                    {
                        dp[i][j] = num.substr(j, 1);
                    }
                }
                else
                {
                    if ((num.substr(j, 1) + dp[i - 1][j + 1]).compare(dp[i][j + 1]) >= 0)
                    {
                        dp[i][j] = dp[i][j + 1];
                    }
                    else
                    {
                        dp[i][j] = num.substr(j, 1) + dp[i - 1][j + 1];
                    }
                }
            }
        }
        cout << dp[residual - 1][0] << endl;
        string str = dp[residual - 1][0];
        return str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    string num = "1432219";
    int k = 3;
    string ret = Solution().removeKdigits(num, k);


    // while (getline(cin, line)) {
    //     string num = stringToString(line);
    //     getline(cin, line);
    //     int k = stringToInteger(line);
        

    //     string out = (ret);
    //     cout << out << endl;
    // }
    return 0;
}
