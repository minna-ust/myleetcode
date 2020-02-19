#include "stdcom.hpp"
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return nums;
        }
        int length = nums.size();
        quickSort(nums, 0, length);
        return nums;
    }

    void quickSort(vector<int>& nums, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = partition(nums, start, end);
        quickSort(nums, start, mid);
        quickSort(nums, mid + 1, end);
    }

    int partition(vector<int>& nums, int start, int end)
    {
        int cmp = end;
        int indexToSwap = start - 1;
        for (int i = start; i < end; ++i)
        {
            if (nums[i] <= nums[cmp])
            {
                indexToSwap += 1;
                swap(nums[indexToSwap], nums[i]);
            }
        }
        indexToSwap += 1;
        swap(nums[indexToSwap], nums[end]);
        return indexToSwap;
    }
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> ret = Solution().sortArray(nums);

    // while (getline(cin, line)) {
    //     vector<int> nums = stringToIntegerVector(line);
        

    //     string out = integerVectorToString(ret);
    //     cout << out << endl;
    // }
    return 0;
}
