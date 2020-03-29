#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
         set<int> sZero;
         int i = 0;
         for (const auto &a : arr)
         {
             if (a == 0)
             {
                 sZero.insert(i);
             }
             ++i;
         }
         int originalSetSize = sZero.size();
         set<int> path;
         recur(arr, start, sZero, path);
         if (sZero.size() < originalSetSize)
         {
            return true;
         }
         else
         {
            return false;
         }
    }
    void recur(vector<int>& arr, int index, set<int>& sZero, set<int>& path)
    {
        if (index < 0 || index > arr.size() - 1)
        {
            return;
        }
        if (sZero.count(index))
        {
            sZero.erase(index);
            return;
        }
        if (path.count(index))
        {
            return;
        }
        path.insert(index);
        recur(arr, index - arr[index], sZero, path);
        
        recur(arr, index + arr[index], sZero, path);
        path.erase(index);
        return;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    vector<int> arr = {0,3,0,6,3,3,4};
    int start = 6;
    bool ret = Solution().canReach(arr, start);

    // while (getline(cin, line)) {
    //     vector<int> arr = stringToIntegerVector(line);
    //     getline(cin, line);
    //     int start = stringToInteger(line);
        
    //     bool ret = Solution().canReach(arr, start);

    //     string out = boolToString(ret);
    //     cout << out << endl;
    // }
    return 0;
}
