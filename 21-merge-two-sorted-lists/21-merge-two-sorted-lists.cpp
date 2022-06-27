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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *ans=NULL,**t=&ans,*f=NULL;
        while(l1 && l2)
        {
            *t=new ListNode();
            if(l1->val <= l2->val)
            {
                (*t)->val=l1->val;
                f=l1;
                l1=l1->next;
                delete(f);
            }
            else{
                (*t)->val=l2->val;
                f=l2;
                l2=l2->next;
            delete(f);}
            t=&((*t)->next);
        }
        while(l1)
        {
            *t=new ListNode();   
            (*t)->val=l1->val;
            f=l1;
             l1=l1->next;
            delete(f);
             t=&((*t)->next);
        }
        while(l2)
        {
            *t=new ListNode();   
            (*t)->val=l2->val;
            f=l2;
             l2=l2->next;
            delete(f);
             t=&((*t)->next);
        }
        return(ans);
    }
};