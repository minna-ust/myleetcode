#include "stdcom.hpp"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //!!!!! boundary check
        if (pHead == nullptr)
            return pHead;
        //!!!!!
        bool headDuped = false;
        ListNode *toDelete = nullptr;
        while (pHead->next != nullptr && pHead->val == pHead->next->val)
        {
            headDuped = true;
            toDelete = pHead->next;
            pHead->next = pHead->next->next;
            delete toDelete;
        }
        ListNode *pParent = pHead;
        ListNode *pCurrent = pHead->next;
        while (pCurrent != nullptr && pCurrent->next != nullptr)
        {
            if (pCurrent->val == pCurrent->next->val)
            {
                toDelete = pCurrent;
                pCurrent = pCurrent->next;
                delete toDelete;
                while (pCurrent->next != nullptr && pCurrent->next->val == pCurrent->val)
                {
                    toDelete = pCurrent;
                    pCurrent = pCurrent->next;
                    delete toDelete;
                }
                toDelete = pCurrent;
                pCurrent = pCurrent->next;
                pParent->next = pCurrent;
                delete toDelete;
            }
            else
            {
                pParent = pCurrent;
                pCurrent = pCurrent->next;
            }
         }
         if (headDuped)
         {
            return pHead->next;
         }
         else
         {
            return pHead;
         }
    }

/*
 * Iterate the passed array one by one and create a ListNode
 * for each element and append it in last ListNode's next pointer.
 * Also keep a track of last ListNode created while iteration to
 * update its next pointer in next iteration.
 * Also store the first ListNode created,that we will returned as
 * root ListNode in end.
 **/
    ListNode * createListFromArray(int * ptr, int arraySize)
    {
        ListNode * nodePtr = nullptr;
        ListNode * rootNodePtr = nullptr;
        ListNode * lastNodePtr = nullptr;
        for(int i = 0 ; i < arraySize; i++)
        {
            if(!nodePtr)
            {
                nodePtr = new ListNode(*(ptr+i));
                if(!rootNodePtr)
                    rootNodePtr = nodePtr;
                if(lastNodePtr)
                    lastNodePtr->next = nodePtr;
            }
            lastNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        return rootNodePtr;
    }

    /*
     * Iterate through all nodes and display content
     * of each ListNode untill end of linked list is reached.
     **/
    void displayLinkedList(ListNode *ptr)
    {
        while(ptr != nullptr)
        {
            std::cout<< ptr->val <<" ";
            ptr = ptr->next;
        }
        std::cout<<std::endl;
    }
/*
 * Store the next pointer of passed ListNode as temp variable.
 * Delete the current pointer and pass the earlier stored next pointer
 * to destroyList funtion.
 *
 * If ptr is null it means its the end of linked list, so just return
 * because complete linked list is deleted.
 **/
    void destroyList(ListNode * ptr)
    {
        if(ptr)
        {
            ListNode * pNext = ptr->next;
            delete ptr;
            destroyList(pNext);
        }
    }
};

/*
 * Testing functions.
 **/
int main()
{
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    Solution solution;
    ListNode * ptr = solution.createListFromArray(arr, sizeof(arr)/sizeof(int));
    solution.displayLinkedList(ptr);
    // solution.destroyList(ptr);
    solution.deleteDuplication(ptr);
    solution.displayLinkedList(ptr);

    return 0;
}
