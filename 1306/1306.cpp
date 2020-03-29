class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
         set<int> sZero;
         int i = 0;
         for (const auto &a : arr)
         {
             if (a == 0)
             {
                 sZero.insert(i);
             }
             ++i;
         }
         set<int> path;
         recur(arr, start, sZero, path);
         if (sZero.empty())
         {
            return true;
         }
         else
         {
            return false;
         }
    }
    void recur(vector<int>& arr, int index, set<int>& sZero, set<int>& path)
    {
        
        if (sZero.count(index))
        {
            sZero.erase(index);
            return;
        }
        if (path.count(index))
        {
            return;
        }
        path.insert(index);
        recur(arr, index - arr[index], sZero, path);
        
        recur(arr, index + arr[index], sZero, path);
        path.erase(index);
        return;
    }
        
};
