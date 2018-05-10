#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next=NULL;
    }
};

int length(node* head)
{
    int length=0;
    while(head!=NULL)
    {
        head=head->next;
        length++;
    }
    return length;
}

//Insertion Functions
void insertAtHead(node*&head,int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return;
    }
    node* temp = new node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(node*&head,int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* newNode = new node(data);
    temp->next=newNode;
}

void insertAtMiddle(node*&head,int data,int position)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    if(position>length(head))
    {
        insertAtTail(head,data);
        return;
    }
    node* temp = head;
    while(position-1&&temp->next!=NULL)
    {
        temp=temp->next;
        position--;
    }
    node* newNode = new node(data);
    newNode->next=temp->next;
    temp->next=newNode;
}
//end of insertion functions


//deletion functions
void deleteAtHead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    node* temp = head;
    head=head->next;
    delete temp;
}

void deleteAtTail(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    node*prev=NULL;
    node*temp=head;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
}
void deleteAtMiddle(node*&head,int position)
{
    if(head==NULL||position==0)
    {
        return;
    }
    if(position==1)
    {
        deleteAtHead(head);
        return;
    }
    if(position>length(head))
    {
        deleteAtTail(head);
        return;
    }
    node*temp=head;
    node*prev =NULL;
    while(position-1&&temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        position--;
    }
    prev->next=temp->next;
    delete temp;
}
//end of deletion functions

void buildList(node*&head)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        insertAtHead(head,data);
        cin>>data;
    }
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;

    buildList(head);
    print(head);

    cout<<"Testing Insertion Functions"<<endl;
    insertAtHead(head,10);
    insertAtMiddle(head,10,7);
    insertAtTail(head,11);
    print(head);

    cout<<"Testing Deletion Functions"<<endl;
    deleteAtHead(head);
    deleteAtMiddle(head,7);
    deleteAtTail(head);
    print(head);

    return 0;
}
