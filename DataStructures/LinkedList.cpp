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

    insertAtHead(head,10);
    insertAtMiddle(head,10,7);
    insertAtTail(head,11);
    print(head);

    return 0;
}
