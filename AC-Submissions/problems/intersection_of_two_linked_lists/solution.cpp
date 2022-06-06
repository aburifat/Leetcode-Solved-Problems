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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,bool>mp;
        while(headA!=NULL){
            mp[headA]=true;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(!mp[headB]){
                headB=headB->next;
            }
            else{
                return headB;
            }
        }
        return NULL;
    }
};