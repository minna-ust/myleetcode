#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& originalCells, int N) {
        vector<vector<int>> cellsVector;
        map<vector<int>, int> cellsMap;

        vector<int> cells = originalCells;
        cellsVector.push_back(cells);
        cellsMap.insert(pair<vector<int>, int>(cells, 0));
        vector<int> nextCells = prisonAfterOneDay(cells);
        int vectorIndex = 0;
        while (!cellsMap.count(nextCells))
        {
            cellsVector.push_back(nextCells);
            ++vectorIndex;
            cellsMap.insert(pair<vector<int>, int>(nextCells, vectorIndex));
            nextCells = prisonAfterOneDay(nextCells);
        }
        int cycleStartIndex = cellsMap[nextCells];
        int cycleSize = vectorIndex - cycleStartIndex + 1;
        std::cout << "cycleStartIndex: " << cycleStartIndex << std::endl;

        if (N <= vectorIndex)
        {
            return cellsVector[N];
        }
        else
        {
            int resCycleIndex = (N - cycleStartIndex) % cycleSize;
            return cellsVector[cycleStartIndex + resCycleIndex];
        }
    }


    vector<int> prisonAfterOneDay(vector<int>& originalCells)
    {
        vector<int> newCells;
        newCells.resize(8);
        newCells[0] = 0;
        for (int i = 1; i < 7; ++i)
        {
            if (originalCells[i - 1] == originalCells[i + 1])
            {
                newCells[i] = 1;
            }
            else
            {
                newCells[i] = 0;
            }
        }
        newCells[7] = 0;
        return newCells;
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
    while (getline(cin, line)) {
        vector<int> cells = stringToIntegerVector(line);
        getline(cin, line);
        int N = stringToInteger(line);

        vector<int> ret = Solution().prisonAfterNDays(cells, N);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
