/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        while (head != nullptr && head->val == 0)
        {
            head = head->next;
        }

        if (head == nullptr)
        {
            return 0;
        }
        ListNode *firstNonZero = head;
        int count = 0;
        while (head != nullptr)
        {
            head = head->next;
            count++;
        }

        int res = 0;
        while (firstNonZero != nullptr)
        {
            if (firstNonZero->val == 1)
            {
                assert(count >= 1 && "count error");
                res += 1 * std::pow(2, count - 1);
            }
            count--;
            firstNonZero = firstNonZero->next;
        }
        return res;
    }
};
// @lc code=end
