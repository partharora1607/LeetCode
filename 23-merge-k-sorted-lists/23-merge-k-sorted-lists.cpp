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
    ListNode *merge2List(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1, *temp2 = head2;
    ListNode *fh = NULL, *ft = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val < temp2->val)
        {
            if (fh == NULL)
            {
                fh = temp1;
                ft = temp1;
            }
            else
            {
                ft->next = temp1;
                ft = ft->next;
            }
            temp1 = temp1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = temp2;
                ft = temp2;
            }
            else
            {
                ft->next = temp2;
                ft = ft->next;
            }
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
    {
        ft->next = temp1;
    }
    if (temp2 != NULL)
    {
        ft->next = temp2;
    }
    return fh;
}

ListNode *mergeKLists(vector<ListNode *> &v, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    if (si == ei)
    {
        return v[si];
    }
    ListNode *ans1 = mergeKLists(v, si + 1, ei);
    ListNode *fans = merge2List(v[si], ans1);
    return fans;
}

ListNode *mergeKLists(vector<ListNode *> &v)
{
    int n = v.size();
    return mergeKLists(v, 0, n - 1);
}
};