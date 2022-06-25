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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *temp = head;
        vector<int> ar;
        while(temp != NULL){
            ar.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0 , j = ar.size() - 1;
        while(i < j){
            if(ar[i] != ar[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};