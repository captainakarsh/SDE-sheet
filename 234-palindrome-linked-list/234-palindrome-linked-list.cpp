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
    bool help(ListNode **head,ListNode *fast)
    {
        if(!(*head) or !fast) return true;
        if(help(head,fast->next) and (*head)->val == fast->val)
        {
            (*head)=(*head)->next;
            return true;
        }
        return false;
        
    }
    bool isPalindrome(ListNode* head) {
      return help(&head,head);   
    }
};