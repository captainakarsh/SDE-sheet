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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *ans=NULL,*cur;
        while(l1  and l2 )
        {
            int x = c+l1->val+l2->val;
            c=x/10;
            ListNode *t = new ListNode(x%10);
            if(ans)
            {
                cur->next=t;
                cur=cur->next;
            }
            else
            {
                ans=t;
                cur=t;
            }
            l1=l1->next,l2=l2->next;
        }
        while(l1)
        {
            int x = c+l1->val;
            c=x/10;
            ListNode *t = new ListNode(x%10);
            if(ans)
            {
                cur->next=t;
                cur=cur->next;
            }
            else
            {
                ans=t;
                cur=t;
            }
            l1=l1->next;
        }
        while(l2)
        {
            int x = c+l2->val;
            c=x/10;
            ListNode *t = new ListNode(x%10);
            if(ans)
            {
                cur->next=t;
                cur=cur->next;
            }
            else
            {
                ans=t;
                cur=t;
            }
            l2=l2->next;
        }
        if(c)
        {
            ListNode *t = new ListNode(c);
            cur->next=t;
        }
        return ans;
    }
};