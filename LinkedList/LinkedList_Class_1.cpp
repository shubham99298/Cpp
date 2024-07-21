#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node() {
    this->data = 0;
    this->next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void print(Node *&head) {
  Node *temp = head;
  while (temp) {
    // print data
    // point to next
    // stop when temp is null
    cout << temp->data << " ";
    temp = temp->next;
  }
}

void insertAtHead(Node *&head, Node *&tail, int data) {

  // Create a Node First
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail=newNode;
  }
  Node *newNode = new Node(data);
  // newNode k next ko head pe point krdo
  newNode->next = head;
  // head ko newNode pe point krdo
  head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail=newNode;
  }

  Node *newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;
}
int main() {
  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  first->next = second;
  second->next = third;
  third->next = NULL;
  insertAtHead(first, third, 50);
  insertAtTail(first, third, 80);

  print(first);
}