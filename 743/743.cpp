#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/regex.hpp>
#include <queue>

using namespace std;

typedef pair<int, int> iipair;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // int distances[N] = {numeric_limits<int>::max()};
        int distances[N];
        for (int i = 0; i < N; i++)
        {
            distances[i] = numeric_limits<int>::max();
            cout << distances[i] << endl;
        }
        cout << " ---------------------" << endl;
        // bool white[N] = {true};
        bool gray[N] = {false};
        bool black[N] = {false};

        map<int, vector<pair<int, int>>> graph;
        for (const auto &time : times)
        {
            if (graph.count(time[0]))
            {
                graph[time[0]].emplace_back(make_pair(time[1], time[2]));
            }
            else
            {
                vector<pair<int, int>> value;
                value.emplace_back(make_pair(time[1], time[2]));
                graph.insert(make_pair(time[0], value));
            }
        }

        for (const auto &v : graph)
        {
            cout << "vertex: " << v.first << endl;
            for (const auto &e : graph[v.first])
            {
                cout << "edge: " << e.first << " weight: " << e.second << endl;
            }
        }

        gray[K - 1] = true;
        distances[K - 1] = 0;
        priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
        set<int> s;

        pq.push(make_pair(0, K));
        while (!pq.empty())
        {
            iipair u = pq.top();
            pq.pop();
            if (black[u.second - 1])
                continue;
            for (const auto &edge : graph[u.second])
            {
                if (distances[edge.first - 1] > distances[u.second - 1] + edge.second)
                {
                    distances[edge.first - 1] = distances[u.second - 1] + edge.second;
                    pq.push(make_pair(distances[edge.first - 1], edge.first));
                }
            }
            black[u.second - 1] = true;
        }

        int res = 0;
        for (int i = 0; i < N; i++)
        {
            // cout << distances[i] << endl;
            if (distances[i] == numeric_limits<int>::max())
            {
                return -1;
            }
            res = max(res, distances[i]);
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    std::string input(argv[1]);
    input = input.substr(1, input.size() - 2);
    input = input.substr(1, input.size() - 2);

    std::vector<std::string> vStr;
    boost::algorithm::split_regex(vStr, input, boost::regex("\\],\\["));

    std::vector<std::vector<int>> times;
    for (auto str : vStr)
    {
        std::vector<std::string> vStrTime;
        std::vector<int> time;
        boost::algorithm::split(vStrTime, str, boost::is_any_of(","));
        for (auto num : vStrTime)
        {
            time.push_back(std::stoi(num));
        }
        times.push_back(time);
    }

    Solution().networkDelayTime(times, 4, 2);

    return 0;
}
