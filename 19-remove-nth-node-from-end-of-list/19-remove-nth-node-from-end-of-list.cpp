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

ListNode *helper(ListNode *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (n == 0)
    {
        return head->next;
    }
    head->next = helper(head->next, n - 1);
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int size = getsize(head);
    int m = size - n;
    return helper(head, m); // m = index
}
};