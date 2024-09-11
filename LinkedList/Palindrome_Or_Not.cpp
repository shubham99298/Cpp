
class Solution {
public:
sPalindrome(ListNode* head) {
        stack<int>st;

        ListNode*temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;

        }
        temp=head;

        while(temp && !st.empty()){
            if(temp->val!=st.top()){
                return false;
            }
            else{
                temp=temp->next;
                st.pop();
            }

        }
        return true;
    }
};


//2nd Method

class Solution {
public:
   ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*frwd=NULL;
        while(curr!=NULL){
             frwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
     
        ListNode*slow=head;
        ListNode*fast=head->next;

        while(fast){
            fast=fast->next;

            if(fast){
                 slow=slow->next;
                fast=fast->next;
            }
        }
        ListNode*reverseHead=reverseList(slow->next);
        ListNode*temp1=head;
        ListNode*temp2=reverseHead;

        while(temp1 && temp2)
        {
            if(temp1->val!=temp2->val){
                return false;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return true;

    }
};