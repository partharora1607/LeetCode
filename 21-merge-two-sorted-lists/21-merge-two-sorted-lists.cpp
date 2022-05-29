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
   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *fh = NULL, *ft = NULL;
    ListNode *t1 = list1, *t2 = list2;
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->val < t2->val)
        {
            if (fh == NULL)
            {
                fh = t1;
                ft = t1;
            }
            else
            {
                ft->next = t1;
                ft = ft->next;
            }
            t1 = t1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = t2;
                ft = t2;
            }
            else
            {
                ft->next = t2;
                ft = ft->next;
            }
            t2 = t2->next;
        }
    }
    if(t1 != NULL)
    {
        ft->next = t1;
    }
    if(t2 != NULL)
    {
        ft->next = t2;
    }
    return fh;
}
};