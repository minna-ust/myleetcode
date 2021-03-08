输入;
2 ---> 3 ---> 4 ---> 5;
输出;
5 ---> 4 ---> 3 ---> 2;
-----------------------;
2 ---> 3 ---> 4 ---> 5;
nullptr <--- 2 <--- 3 <--- 4 , 5;
struct ListNode
{
    int mKey;
    ListNode *mpNext;
};

ListNode* ReverseList(ListNode *pHead)
{
    if (pHead == nullptr || pHead->mpNext == nullptr)
    {
        return pHead;
    }
    ListNode *pCur = pHead;
    ListNode *pCurNext = pCur->mpNext;
    ListNode *pCurNextNext = pCurNext->mpNext;
    if (pCurNextNext == nullptr)
    {
        pCurNext->mpNext = pCur;
        pCur->mpNext = nullptr;
        return pCurNext;
    }

    ListNode *tmp1 = nullptr;
    ListNode *tmp2 = nullptr;
    while (pCurNext != nullptr)
    {
        ListNode *tmp1 = pCurNext->mpNext;
        pCurNext->mpNext = pCur;
        if (pCur == pHead)
        {
            pCur->mpNext = nullptr;
        }
        else
        {
            pCur->mpNext = tmp2;
        }
        tmp2 = pCurNext;
        pCur = tmp1;
        if (tmp1 == nullptr)
        {
            return pCurNext;
        }
        pCurNext = pCur->mpNext;
    }
    pCur->mpNext = tmp2;
    return pCur;
}
