// 1 2 3 ---> 1 2 3 4 (插入4， 中位数需后移一位)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        DualPriorityQueue dual_queue(k);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i < k - 1)
            {
                std::cout << "add: " << nums[i] << std::endl;
                dual_queue.insert(nums[i]);
            }
            if ( i == k - 1)
            {
                std::cout << "add: " << nums[i] << std::endl;
                dual_queue.insert(nums[i]);
                res.push_back(dual_queue.getMedian());
            }
            if ( i >= k)
            {
                std::cout << "erase: " << nums[i-k] << " add: " << nums[i]  << std::endl;
                dual_queue.erase(nums[i-k]);
                dual_queue.insert(nums[i]);
                dual_queue.print();
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
        int k_;
    public:
        DualPriorityQueue(int k): k_(k) {}

        template<typename T>
        void print_q(T q)
        {
            while(!q.empty())
            {
                std::cout << q.top() << " ";
                q.pop();
            }
            std::cout << "\n";
        }

        void print()
        {
            print_q(small_q);
            print_q(large_q);
        }

        void insert(int num)
        {
            if (small_q.empty() || num < small_q.top())
            {
                small_q.push(num);
                small_size++;
                make_balance();
            }
            else
            {
                large_q.push(num);
                large_size++;
                make_balance();
            }
        }

        double getMedian()
        {
            if (k_ % 2 == 1)
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
            if (!small_q.empty() && num == small_q.top())
            {
                small_size--;
                prune();
            }
            if (!large_q.empty() && num == large_q.top())
            {
                large_size--;
                prune();
            }
            if (!small_q.empty() && num < small_q.top())
            {
                small_size--;
            }
            if (!large_q.empty() && num > large_q.top())
            {
                large_size--;
            }
            make_balance();
        }

        void make_balance()
        {
            std::cout << "before balance : small size" << small_size << " large size" << large_size << std::endl;
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
            std::cout << "after balance : small size" << small_size << " large size" << large_size << std::endl;
            prune();
        }

        void prune()
        {
            std::cout << "before prune : small size" << small_size << " large size" << large_size << std::endl;
            for (auto pair: delayed)
            {
                std::cout << "key: " << pair.first << " value: " << pair.second << "\n";
            }
            while (!small_q.empty() && delayed.count(small_q.top()))
            {
                delayed[small_q.top()]--;
                if (delayed[small_q.top()] == 0)
                {
                    delayed.erase(small_q.top());
                }
                small_q.pop();
            }

            while (!large_q.empty() && delayed.count(large_q.top()))
            {
                delayed[large_q.top()]--;
                if (delayed[large_q.top()] == 0)
                {
                    delayed.erase(large_q.top());
                }
                large_q.pop();
            }
            std::cout << "after prune : small size" << small_size << " large size" << large_size << std::endl;
        }
    };
};
