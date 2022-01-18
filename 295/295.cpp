class MedianFinder {
public:
    MedianFinder() {
        priority_queue<int, vector<int>, less<int>> q_min;
        priority_queue<int, vector<int>, greater<int>> q_max;
    }

    void addNum(int num) {
        if (q_min.empty() || num <= q_min.top())
        {
            q_min.push_back(num);
            if (q_min.size() > q_max.size() + 1)
            {
                q_max.push_back(q_min.top());
                q_min.pop();
            }
        }
        else
        {
            q_max.push_back(num);
            if (q_max.size() > q_min.size())
            {
                q_min.push_back(q_max.top());
                q_max.pop();
            }
        }
    }

    double findMedian() {
        if (q_min.size()>q_max.size())
        {
            return q_min.top();
        }
        return (q_min.top() + q_max.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
