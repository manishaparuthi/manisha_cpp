/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* tempa=A;
    ListNode* tempb=B;
    ListNode* C=NULL;
    ListNode* temp=NULL;
    ListNode* prev=NULL;
    int carry=0;
    
   while(tempa!=NULL || tempb!= NULL)
    {
        int valc=(tempa?tempa->val:0)+(tempb?tempb->val:0)+carry;
        if(valc>9)
        {
            valc=valc%10;
            carry=1;
        }
        else
        {
            valc=valc;
            carry=0;
        }
        temp=new ListNode(valc);
        if(C==NULL)
        {
            C=temp;
        }
        else
        {
            prev->next=temp;
        }
        prev=temp;
        if(tempa)
        {
            tempa=tempa->next;
        }
        if(tempb)
        {
            tempb=tempb->next;
        }
    }
    if(carry==1)
    {
        temp->next = new ListNode(carry);
    }
  return C;
}
