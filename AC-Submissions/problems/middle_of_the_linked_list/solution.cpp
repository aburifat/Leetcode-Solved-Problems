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
    ListNode* middleNode(ListNode* head) {
        int ct=0;
        ListNode* curr=new ListNode();
        curr=head;
        while(head!=nullptr){
            ct++;
            if(ct%2==0)curr=curr->next;
            head=head->next;
        }
        return curr;
    }
};