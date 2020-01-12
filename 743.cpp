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
        queue<int> q;
        q.push(K);
        distances[K - 1] = 0;
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            if (black[vertex-1] == false)
            {
                for (const auto &edge : graph[vertex])
                {
                    q.push(edge.first);
                    gray[edge.first - 1] = true;
                    // cout << "debug: " << edge.first << " " << distances[edge.first - 1]  << "   " << distances[vertex - 1] + edge.second << endl;
                    distances[edge.first - 1] = min(distances[edge.first -1], distances[vertex - 1] + edge.second);

                }
                black[vertex - 1] = true;
            }
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
