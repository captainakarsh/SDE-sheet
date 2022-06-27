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
        int size(ListNode *head){
        int ans=0;
        while(head){
            ans=ans+1;
            head=head->next;
        }
        return ans;
    }
    void swap(ListNode **headA,ListNode **headB){
        ListNode* t=*headA;
        *headA=*headB;
        *headB=t;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          if(!headA or !headB)return NULL;
        int a=size(headA);
        int b=size(headB);
        if(a<b)
            swap(&headA,&headB);
        a=a>b?a-b:b-a;
        for(int i=1;i<=a;++i){
          headA=headA->next;
        }        
        while(headA != headB){
            if(headA->next == NULL)
                return NULL;
            headA=headA->next;
            headB=headB->next;
        }
         return headA;
    
    }
};