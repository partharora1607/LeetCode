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
    int getsize(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return getsize(head->next) + 1;
}

ListNode *helper(ListNode *head, int k, int size)
{
    if (size < k || head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *c, *p, *n;
    c = head;
    n = NULL;
    p = NULL;
    int count = 0;
    while (c != NULL && count < k)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }
    head->next = helper(c, k, size - k);
    return p;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    int size = getsize(head);
    return helper(head, k, size);
}
};