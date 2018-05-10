#include<iostream>
using namespace std;

class Stack
{
    class Node
    {
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data=data;
            next = NULL;
        }
    };

    Node* head;
    int currSize;

public:
    Stack()
    {
        head = NULL;
        currSize=0;
    }

    bool empty()
    {
        return head==NULL;
    }

    int size()
    {
        return currSize;
    }

    void print()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void pop()
    {
        if(empty())
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        currSize--;
    }

    void push(int data)
    {
        currSize++;
        if(empty())
        {
            head = new Node(data);
            return;
        }
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    int top()
    {
        if(empty())
        {
            return -1;
        }
        return head->data;
    }

    ~Stack(){
        while(!empty()){
            pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(5);
    cout<<"size: "<<s.size()<<endl;
    s.print();
    s.push(4);
    cout<<"size: "<<s.size()<<endl;
    s.print();
    s.push(10);
    cout<<"size: "<<s.size()<<endl;
    s.print();
    s.pop();
    cout<<"size: "<<s.size()<<endl;
    s.print();
    cout<<s.top()<<endl;
    cout<<"size: "<<s.size()<<endl;
    return 0;
}
