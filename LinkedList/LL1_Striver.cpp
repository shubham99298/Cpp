/*
Array is used to store the data in contigous memory allocation
You cannot increase or decrease the size of array
We have indexes in Arrays

Linkedlist
Not store the elements in contigous allocation
we used to find the next element by "next"

in C++= nullptr

where it is Used?
stack and Queue

Example
int x=2;
int *y=&x; // used to store the address of x and *y used to point the value present at that address
cout<<y; // used to print the value present at x

//self define dataType
Struct Node{
    int data;
    Node*next;
   Node(data1,next1){
  data=data1;
  next=next1;
 }
}
// Node *first= new Node(22,nullptr);/

*/

// Q1 Convert An Array into LinkedList
Node* constructLL(vector<int>& arr) {
    //arr=4 2 5 1
    // Write your code here
    Node*head = new Node(arr[0]);// Head ho jayega 4 pe
    Node*ptr=head;

     for(int i=1; i<arr.size(); i++)
     {
         Node *temp = new Node(arr[i]);
         ptr->next=temp;
         ptr=ptr->next;

     }
     return head;
}
//Q2 Length of the LinkedList

int length(Node *head)
{
    Node*temp=head;
   int count=0;
    while(temp){
       temp=temp->next;
       count++;
    }
    return count;
	
}

//Q3 Search the element in LinkedList
int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.

   
    Node<int>*temp=head;
    while(temp){
        
        if(temp->data==k){
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}


