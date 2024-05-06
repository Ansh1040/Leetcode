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

    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nextt = curr->next;
            curr->next = prev ;
            prev = curr;
            curr = nextt;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;
        int maxNode = INT_MIN;

        while(head){
            if(head->val >= maxNode){
                ans->next = head ;
                ans = ans->next;
            }
            maxNode = max(maxNode, head->val);
            head = head->next;
        }

        ans->next = nullptr; 
        ansHead->next = reverse(ansHead->next);

        return ansHead->next; 
    }
};