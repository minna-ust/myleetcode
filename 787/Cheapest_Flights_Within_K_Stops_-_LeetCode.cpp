#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
// #include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>

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

        for (auto list : adjList)
        {
            std::cout << list.first << " \t";
            for (auto pair : adjList[list.first])
            {
                std::cout << pair.first << " " << pair.second << "  ";
            }
            std::cout << std::endl;
        }

    }
};

int main(int argc, char** argv)
{
    std::string input(argv[1]);
    input = input.substr(1, input.size() - 2);
    input = input.substr(1, input.size() - 2);

    std::vector<std::string> vStr;
    // boost::split(vStr, input, boost::is_any_of("],["));
    boost::algorithm::split_regex(vStr, input, boost::regex("\\],\\["));

    std::vector<std::vector<int>> flights;
    for (auto str : vStr)
    {
        std::vector<std::string> vFlight;
        std::vector<int> flight;
        boost::algorithm::split(vFlight, str, boost::is_any_of(","));
        for (auto num : vFlight)
        {
            flight.push_back(std::stoi(num));
        }
        flights.push_back(flight);
    }

    Solution().findCheapestPrice(3, flights, 0, 2, 1);
    return 0;
}
