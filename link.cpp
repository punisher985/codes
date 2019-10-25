#include<iostream>
using namespace std;

class Node
{
 public:
   int data;
   Node* next;
 Node(int d)
 {
   data = d;
   next = NULL;
 }
};



int length(Node* head)
{
  int count=0;
  while(head)
  {
    count++;
    head = head->next;
  }
  return count;
}

void insertionAtFront(Node* &head, Node* &tail, int d)
{
  if(head == NULL)
  {
    Node* n = new Node(d);
    head = n;
    tail = n;
    return;
  }
  Node* n = new Node(d);
  n->next = head;
  head = n;
}

void insertionAtEnd(Node* &head, Node* &tail, int d)
{
  if(head == NULL)
  {
    Node* n = new Node(d);
    head = n;
    tail = n;
    return;
  }

  Node* n = new Node(d);
  tail->next = n;
  tail = n;
}

void insertionAtPosition(Node* &head, Node* &tail, int d, int p)
{

  int l = length(head);
  if(p==0)
  {
    insertionAtFront(head,tail,d);
    return;
  }

  else if(p>l)
  {
    insertionAtEnd(head,tail,d);
    return;
  }

  else
  {
    Node* temp = head;
    for(int i=1; i<p; i++)
    {
      temp = temp->next;
    }

    Node* n = new Node(d);
    n->next = temp->next;
    temp->next = n;
  }


}

void deleteAtFront(Node* &head, Node* &tail)
{
  if(!head)
  {
    return;
  }
  else if(head==tail)
  {
    delete head;
    head = NULL;
    tail = NULL;
  }
  else
  {
    Node* temp = head;
    head = temp->next;
    //temp->next = NULL;
    delete temp;
  }
}

void deleteAtEnd(Node* &head, Node* &tail)
{
  if(!head)
  {
    return;
  }
  else if(head==tail)
  {
    delete head;
    head = NULL;
    tail = NULL;
  }
  else
  {
    Node* temp = head;
    while(temp->next!=tail)
    {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
  }
}

void deleteAtPosition()
{

}

Node* mid(Node* head)
{
  if(!head)
  {
    return NULL;
  }
  Node* slow = head;
  Node* fast = head->next;

  while(fast!=NULL and fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node* Lsearch(Node* head, int d)
{
  if(!head)
  {
    return NULL;
  }
  while(head)
  {
     if(head->data == d)
     {
       return head;
     }
     head = head->next;
  }
  return NULL;
}

Node* rSearch(Node* head, int d)
{
  if(!head)
  {
    return NULL;
  }
  if(head->data == d)
  {
    return head;
  }
  return rSearch(head->next,d);
}

Node* reverseLL(Node* head)
{
  Node* prev = NULL;
  Node* curr = head;

  while(curr)
  {
    Node* n = curr->next;
    curr->next=prev;
    prev=curr;
    curr = n;
  }
  return prev;
}

void print(Node* head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;

  }
  cout<<endl;

}


main()
{
  Node* head = NULL;
  Node* tail = NULL;
  insertionAtFront(head, tail, 5);
  insertionAtFront(head, tail, 4);
  insertionAtFront(head, tail, 3);
  insertionAtFront(head, tail, 2);
  insertionAtFront(head, tail, 1);

  insertionAtEnd(head, tail, 7);

  insertionAtPosition(head, tail, 11, 4);

  print(head);
  //cout<<length(head)<<endl;
  deleteAtEnd(head,tail);
  print(head);

  deleteAtFront(head,tail);
  print(head);

cout<<"Reversed LL : ";
Node* newHead = reverseLL(head);
print(newHead);

  return 0;
}
