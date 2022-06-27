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
    ListNode* rev(ListNode* l1,ListNode * l2)
    {
        ListNode *prev=l2,*cur=l1,*ah;
        while(cur != l2)
        {
            ah=cur->next;
            cur->next=prev;
            prev=cur;
            cur=ah;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        if(k<=1) return head;
        ListNode *i=head,*j=head;
        for(int _=1;_<=k;++_) j=j->next;
        while(true)
        {
            ListNode *t;
            if(i==head)
            {
                
                t = rev(i,j);
                head=t;
            }
            else
            {
                t= rev(i->next,j);
                i->next=t;
                for(int l=1;l<=k and i;++l)i=i->next; 
            }
              if(j==NULL)
                break;
            int l;
            for(l=1;l<=k and j;++l)j=j->next; 
            if(l!= k+1)
                break;
          
        }
        return head;
    }
};