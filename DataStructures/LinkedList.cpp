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

//search functions
bool searchRecursive(node*head,int key)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data==key)
    {
        return true;
    }
    else
    {
        return searchRecursive(head->next,key);
    }
}

bool searchIterative(node* head, int key)
{

    while(head!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}
//end of search functions

//building list functions
void buildList(node*&head)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        insertAtTail(head,data);
        cin>>data;
    }
}

istream& operator>>(istream& is,node*& head)
{
    buildList(head);
    return is;
}
//end of building list functions

//printing list functions

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream& os,node*& head)
{
    print(head);
    return os;
}
//end of printing list functions

//reversing Linked List functions
node* reverseIterative(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    node *prev, *curr, *next = NULL;
    curr=head;

    while(curr->next!=NULL)
    {
        next=curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
    }
    curr->next=prev;
    return curr;
}

node* reverseRecursive(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    node* revHead = reverseRecursive(head->next);
    head->next->next=head;
    head->next = NULL;
    return revHead;
}
//end of reversing Linked List functions

//midpoint of Linked List using runner technique
node* midPoint(node* head){

    if(head==NULL||head->next==NULL){
        return head;
    }
    node *slow = head;
    node* fast = head;

    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

//kth Node from end of Linked List
node* findNodeFromLast(node* head,int k){
    if(k>length(head)){
        return NULL;
    }

    node *slow=head,*fast=head;
    int temp=k;
    while(temp--){
        fast=fast->next;
    }
    int len = length(head);
    temp = len-k;
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
int main()
{
    node* head = NULL;

    buildList(head);
    print(head);

    //    cout<<"Testing Insertion Functions"<<endl;
    //    insertAtHead(head,10);
    //    insertAtMiddle(head,10,7);
    //    insertAtTail(head,11);
    //    print(head);
    //
    //    cout<<"Testing Deletion Functions"<<endl;
    //    deleteAtHead(head);
    //    deleteAtMiddle(head,7);
    //    deleteAtTail(head);
    //    print(head);

    //    cout<<"Testing iterative search: "<<searchIterative(head,5)<<endl;
    //    cout<<"Testing recursive search: "<<searchRecursive(head,9)<<endl;

    /*head=NULL;
    cout<<"Testing operator overloading"<<endl;
    cout<<"-->Enter List"<<endl;
    cin>>head;
    cout<<"-->Entered List"<<endl;
    cout<<head;*/

    // cout<<"Testing iterative reverse"<<endl;
    // print(reverseIterative(head));
    //cout<<"Testing recursive reverse"<<endl;
    //print(reverseRecursive(head));

    cout<<"Testing midPoint"<<endl;
    cout<<midPoint(head)->data<<endl;

    cout<<"Testing Kth node from last: k=2"<<endl;
    cout<<findNodeFromLast(head,2)->data<<endl;

    return 0;
}
