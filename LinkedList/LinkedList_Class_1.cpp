#include <iostream>
using namespace std;

// insertion at head or tail
class Node {
public:
  int data;
  Node *next;

  // constructor creation
  Node() {
    this->data = 0;
    this->next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// want to insert node at head of linked list
//& by refrerence( wants to change in original linked list)
void insertatHead(Node *&head, Node *&tail, int data)

{
  // NULL WALA CASE
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  // step1 : create new node
  Node *newNode = new Node(data);
  // step 2: point new node next to head
  newNode->next = head;
  // step 3: attach head to new node

  head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data) {

  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // step1:
  Node *newNode = new Node(data);

  tail->next = newNode;

  tail = newNode;
}
void print(Node *head) {

  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}

int main() {

  Node *head = NULL;
  Node *tail = NULL;
  insertatHead(head, tail, 20);
  insertatHead(head, tail, 45);
  insertAtTail(head, tail, 30);

  print(head);
}