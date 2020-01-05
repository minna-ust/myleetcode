#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(dp, 0, sizeof(dp));
        return recur(A, K, 0, A.size() - 1);
    }

    double dp[101][101];

    map<pair<int, int>, double> avgResults;
    map<pair<int, int>, double> sumResults;
    double average(vector<int>& A, int start, int range)
    {
        if (avgResults.count(make_pair(start, range)))
            return avgResults[make_pair(start, range)];
        int sum = 0;
        for (int i = start; i < start + range; ++i)
        {
            sum += A[i];
        }
        avgResults.insert(make_pair(make_pair(start, range), (double)sum / range));
        return (double)sum / range;
    }

    double sum(vector<int>& A, int start, int end)
    {
        if (sumResults.count(make_pair(start, end)))
            return sumResults[make_pair(start, end)];
        double res = 0.0;
        for (int i = start; i <= end; ++i)
        {
            res += A[i];
        }
        sumResults.insert(make_pair(make_pair(start, end), res));
        return res;
    }

    double recur(vector<int>& A, int K, int start, int end)
    {
        if (dp[start][K] > 0)
        {
            return dp[start][K];
        }
        if (start < end && K > 1 && K < (end - start + 1))
        {
            double max = 0.0;
            for (int i = 1; i <= end - start + 1 - (K - 1); ++i)
            {
                double tmp = average(A, start, i) + recur(A, K - 1, start + i, end);
                if (tmp > max)
                {
                    max = tmp;
                }
            }
            dp[start][K] = max;
            return max;
        }
        else if (start == end)
        {
            return A[start];
        }
        else if (K == end - start + 1)
        {
            return sum(A, start, end);
        }
        else
        {
            return average(A, start, end - start + 1);
        }
       
    }

};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    vector<int> vec = {9,1,2,3,9};
    double res = Solution().largestSumOfAverages(vec, 3);

    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        double ret = Solution().largestSumOfAverages(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
