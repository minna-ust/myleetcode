#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
        std::map<int, std::vector<std::pair<int, int>>> adjList;
        for (auto flight : flights)
        {
            if (adjList.count(flight[0]))
            {
                adjList[flight[0]].push_back(std::make_pair(flight[1], flight[2]));
            }
            else
            {
                std::vector<std::pair<int, int>> vec;
                vec.emplace_back(std::make_pair(flight[1], flight[2]));

                adjList.insert(std::make_pair(flight[0], vec));
            }
        }


    }
};

int main(int argc, char** argv)
{
    std::cout << argc  << std::endl;
    std::string input(argv[1]);
    input = input.substr(1, input.size() - 2);

    std::vector<std::string> vStr;
    boost::split(vStr, input, boost::is_any_of(","));

    return 0;
}
