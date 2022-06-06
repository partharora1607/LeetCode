/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getsize(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return getsize(head->next) + 1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        // no intersection
        return NULL;
    }

    int m = getsize(headA);
    int n = getsize(headB);

    int ans = min(m, n);
    // 0(m + n);

    ListNode *temp1 = headA , *temp2 = headB;
    int count = 0;
    while (temp1 != NULL && count < m - ans)
    {
        temp1 = temp1->next;
        count++;
    }
    count = 0;
    while (temp2 != NULL && count < n - ans)
    {
        temp2 = temp2->next;
        count++;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        // check
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // 0(m + n) 
    return NULL; // if we don't find my intersection we will return NULL;
}
};