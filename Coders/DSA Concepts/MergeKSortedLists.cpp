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
   struct comp
    {
        bool operator()(const ListNode *lhs, const ListNode *rhs) const
        {
            return lhs->val > rhs->val;
        }
    };
   
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<ListNode*,vector<ListNode*>,comp>p;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            p.push(lists[i]);
        }
        ListNode *head=new ListNode(0);
        ListNode *res=head;
        while(!p.empty()){
            ListNode *q=p.top();
            p.pop();
            res->next=q;
            res=res->next;
            if(q->next!=NULL)
                p.push(q->next);
        }
        return head->next;
        
 
        
    }
};
