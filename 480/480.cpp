// 1 2 3 ---> 1 2 3 4 (插入4， 中位数需后移一位)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        DualPriorityQueue dual_queue;
        for (int i = 0; i < nums.size(); ++i)
        {
            dual_queue.insert(nums[i]);
            if ( i >= k)
            {
                dual_queue.erase(nums[i-k]);
                res.push_back(dual_queue.getMedian());
            }
        }
        return res;
    }

    class DualPriorityQueue
    {
    private:
        priority_queue<int,vector<int>,less<int>> small_q;
        priority_queue<int,vector<int>,greater<int>> large_q;
        std::unordered_map<int,int> delayed;
        int small_size = 0;
        int large_size = 0;
    public:
        void insert(int num)
        {
            if (small_q.empty() || num < small_q.top())
            {
                small_q.push(num);
                make_balance();
            }
            else
            {
                large_q.push(num);
                make_balance();
            }
        }

        double getMedian()
        {
            if (k % 2 == 1)
            {
                return small_q.top();
            }
            else
            {
                return (small_q.top() + large_q.top()) / 2.0;
            }
        }

        void erase(int num)
        {
            delayed[num]++;
            if (num == small_q.top())
            {
                prune();
            }
            if (num == large_q.top())
            {
                prune();
            }
            if (num < small_q.top())
            {
                small_size--;
            }
            if (num > large_q.top())
            {
                large_size--;
            }
            make_balance();
        }

        void make_balance()
        {
            if (small_size > large_size + 1)
            {
                large_q.push(small_q.top());
                small_q.pop();
                large_size++;
                small_size--;
            }
            if (small_size < large_size)
            {
                small_q.push(large_q.top());
                large_q.pop();
                small_size++;
                large_size--;
            }
            prune();
        }

        void prune()
        {
            while (delayed.count(min_q.top()))
            {
                delayed[min_q.top()]--;
                min_q.pop();
            }
            while (delayed.count(max_q.top()))
            {
                delayed[max_q.top()]--;
                max_q.pop();
            }
        }
    };
