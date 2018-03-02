/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int length(ListNode* A)
 {
     int leng=0;
     ListNode* temp=A;
     while(temp!=NULL)
     {
         temp=temp->next;
         leng++;
     }
     return leng;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
   if(B>length(A))
   {
       A=A->next;
   }
   else
   {
       ListNode* temp=A;
    ListNode* temp1=A;
    ListNode* prevTemp1;
    for(int i=0;i<B;i++)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        prevTemp1=temp1;
        temp=temp->next;
        temp1=temp1->next;
        //cout<<" enter ";
    }
    if(temp1==A)
    {
        A=A->next;
    }
    else
    {
        prevTemp1->next=prevTemp1->next->next;
   }
   }
   return A;
    
}
