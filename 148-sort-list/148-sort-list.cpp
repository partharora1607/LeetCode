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
    
    void helper(ListNode * head){
        priority_queue<int , vector<int> , greater<int>> pq;
        ListNode *temp = head;
        while(temp != NULL){
            pq.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!pq.empty()){
            temp->val = pq.top();
            pq.pop();
            temp = temp->next;
        }
        
    }
    
    ListNode* sortList(ListNode* head) {
        helper(head);
        return head;
    }
};