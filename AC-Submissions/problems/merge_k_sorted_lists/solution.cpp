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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>>pq;
        int len=lists.size();
        for(int i=0;i<len;i++){
            if(lists[i]!=nullptr)pq.push({-(lists[i]->val),lists[i]});
        }
        ListNode* preroot=new ListNode();
        ListNode* curr=preroot;
        while(!pq.empty()){
            curr->next=pq.top().second;
            curr=curr->next;
            pq.pop();
            if(curr->next!=nullptr)pq.push({-(curr->next->val),curr->next});
        }
        if(preroot!=nullptr)preroot=preroot->next;
        return preroot;
    }
};