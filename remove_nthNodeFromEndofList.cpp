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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode (0, head);
        ListNode* temp= dummy; 

        for(int i=1;i<=n;i++){
            head=head->next; 
        }

        while(head != NULL){
            head = head->next; 
            temp = temp->next; 
        }

        temp->next = temp->next->next; 

        ListNode* res = dummy->next;
        delete dummy;
        
        return res;

    }
};
