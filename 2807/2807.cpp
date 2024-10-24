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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode* current = head;
        ListNode* next = current->next;
        while (next) {
            ListNode* new_node = new ListNode(std::gcd(current->val, next->val));
            new_node->next = next;
            current->next = new_node;

            current = next;
            next = next->next;
        }
        return head;
    }
};
