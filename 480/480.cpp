// 1 2 3 ---> 1 2 3 4 (插入4， 中位数需后移一位)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            DualPriorityQueue.insert(nums[i]);
            if ( i >= k)
            {
                DualPriorityQueue.erase(nums[i-k]);
                res.push_back(DualPriorityQueue.getMedian());
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

        void erase(int num)
        {
            if (num = small_q.top())
            {
                small_q.pop();
            }
            if (num = large_q.pop())
            {
                large_q.pop();
            }
            delayed[num]++;
            if (num < small_q.top())
            {
                small_size--;
            }
            if (num = large_q.pop())
            {
                large_size++;
            }
            make_balance();
        }

        void make_balance()
        {
            if (small_size > large_size + 1)
            {
                large_q.push(small_q.top());
                small_q.pop();
            }
            if (small_size < large_size)
            {
                small_q.push(large_q.top());
                large_q.pop();
            }
            prune();
        }

        void prune()
        {


};
