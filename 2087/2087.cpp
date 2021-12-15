//
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int result_cost = 0;
        bool right_side = homePos[1] > startPos[1] ? true : false;
        bool down_side = homePos[0] > startPos[0] ? true : false;

        if (down_side)
        {
            for (int i = startPos[0]; i < homePos[0]; ++i)
            {
                result_cost += rowCosts[i + 1];
            }
        }
        else
        {
            for (int i = startPos[0]; i > homePos[0]; --i)
            {
                result_cost += rowCosts[i - 1];
            }
        }
        if (right_side)
        {
            for (int i = startPos[1]; i < homePos[1]; ++i)
            {
                result_cost += colCosts[i + 1];
            }
        }
        else
        {
            for (int i = startPos[1]; i > homePos[1]; --i)
            {
                result_cost += colCosts[i - 1];
            }
        }

        return result_cost;
    }
};
