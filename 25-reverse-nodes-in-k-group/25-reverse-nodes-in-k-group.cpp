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
    ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *temp1 = head;
    int count = 0;
    while (temp1 != NULL && count < k - 1)
    {
        temp1 = temp1->next;
        count++;
    }
    if (temp1 == NULL)
    {
        return head;
    }
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL && prev != temp1)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}
};