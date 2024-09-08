class Solution {
public:
   int getLength(ListNode*head){
    int len=0;
    ListNode*temp=head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;

   }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int len=getLength(head);
        ListNode*temp=head;
         if (len==1 && n==1) {
            delete head;
            return NULL;
        }
          if (len == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
       
        for(int i=0; i<len-n-1; i++){
          temp=temp->next;
        }
         ListNode*newNode=temp->next;
        temp->next=newNode->next;
        delete newNode;
        return head;
    }
};