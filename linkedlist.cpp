#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    Node(int val)
    {
      data=val;
    }
}
Node* head=NULL;
void insertAtHead(Node*& head,int val)
{
  if(head==NULL)
  {
    head->data=val;
    head->next=NULL;
  }
  else{
    Node* temp=new Node(val);
    temp->next=head;
  }
}
void insertAtTail(Node*& head,int val)
{
  if(head==NULL)
  {
    insertAtHead(val);
  }
  else{
    Node* temp=new Node(val);
    
    while(head->next!=NULL)
    {
      head=head->next;
    }
    head->next=temp;
    temp->next=NULL;
  }
}
void insertAtPosition(Node*& head,int val,int pos)
{
  Node* current=head;
  if(pos==1)
  {
    insertAtHead(head,val);
  }
  else{
    int count=1;
    Node* temp=new Node(val);
  while(current->next!=NULL && count<pos-1)
  {
    current=current->next;
    count++;
  }
  if(current->next=NULL)
  {
    cout<<"Position out of bounds!";
  }
  }
}
void printList(Node* head)
{
  if(head==NULL)
  {
    cout<<"Empty list";
  }
  while(head!=NULL)
  {
    cout<<head->data<<"->";
    head=head->next;
  }
  cout<<"-> NULL"<<endl;
}
void deleteAtHead(Node*& head)
{
  if(head==NULL)
  {
    cout<<"Empty list"<<endl;
  }
Node* temp=head;
head=head->next;
delete temp;
printList(head);
}
void deleteAtTail(Node*& head)
{
  if(head==NULL)
  {
    cout<<"Empty list";
  }
  Node* temp=head;

  while(temp->next->next!=NULL)
  {
    temp=temp->next;
  }
  Node* current=temp;
  temp=temp->next;
  delete temp;
  current->next=NULL;
}
void deleteAtPosition(Node*& head,int pos)
{

}
int main() {
    int choice, value, position;
    
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Print List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head, value);
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(head, value);
                break;

            case 3:
                cout << "Enter value and position to insert at: ";
                cin >> value >> position;
                insertAtPosition(head, value, position);
                break;

            case 4:
                deleteAtHead(head);
                break;

            case 5:
                deleteAtTail(head);
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPosition(head, position);
                break;

            case 7:
                printList(head);
                break;

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
