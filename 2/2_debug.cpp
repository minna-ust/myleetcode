#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        // ListNode* dummyNode1 = new ListNode(0);
        // ListNode* dummyNode2 = new ListNode(0);
        // dummyNode1->next = l1;
        // dummyNode2->next = l2;
        ListNode* dummyNode1 = l1;
        ListNode* dummyNode2 = l2;
        ListNode* copyHead = head;
        int flag = 0;
        int l1morel2Flag = 0;
        int l2morel1Flag = 0;
        while (dummyNode1 != NULL || dummyNode2 != NULL)
        {
            if (dummyNode1 != NULL && dummyNode2 != NULL)
            {
                int tmp = dummyNode1->val + dummyNode2->val + flag;
                fillListNode(head, tmp, flag);
                dummyNode1 = dummyNode1->next;
                dummyNode2 = dummyNode2->next;
            }
            else if (dummyNode1 != NULL && dummyNode2 == NULL)
            {
                l1morel2Flag = 1;
                int tmp = dummyNode1->val + flag;
                fillListNode(head, tmp, flag);
                dummyNode1 = dummyNode1->next;
            }
            else
            {
                l2morel1Flag = 1;
                int tmp = dummyNode2->val + flag;
                fillListNode(head, tmp, flag);
                dummyNode2 = dummyNode2->next;
            }
        }
        if (flag == 1)
        {
            fillLastNode(head, flag);
        }

        // if (l1morel2Flag == 1)
        // {
        //     head = dummyNode1;
        // }
        // else if (l2morel1Flag == 1)
        // {
        //     head = dummyNode2;
        // }
        // else
        // {
        //     int tmp = dummyNode1->val + dummyNode2->val + flag;
        //     fillLastNode(head, tmp, flag);
        // }
        ListNode* pNode = copyHead;
        while (pNode != NULL)
        {
            std::cout << pNode->val << " " << std::endl;
            pNode = pNode->next;
        }
        return copyHead->next;
    }

    void fillListNode(ListNode* &head, int tmp, int &flag)
    {
        ListNode* tmpNode;
        if (tmp >= 10)
        {
            flag = 1;
            tmpNode = new ListNode(tmp - 10);
            // head->val = tmp - 10;
        }
        else
        {
            flag = 0;
            tmpNode = new ListNode(tmp);
            // head->val = tmp;
        }
        head->next = tmpNode;
        // head->next = new ListNode(0);
        head = head->next;
    }

    void fillLastNode(ListNode* &head, int &flag)
    {
        head->next = new ListNode(1);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    string line1 = "[5]";
    string line2 = "[5]";
    ListNode* l1 = stringToListNode(line1);
    ListNode* l2 = stringToListNode(line2);

    ListNode* ret = Solution().addTwoNumbers(l1, l2);

    string out = listNodeToString(ret);
    cout << out << endl;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
