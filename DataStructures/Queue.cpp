#include<iostream>
using namespace std;

class Queue
{
    class Node
    {
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data=data;
            next=NULL;
        }
    };

    Node *F,*R;
    int currSize;
public:
    Queue()
    {
        F=NULL;
        R=NULL;
        currSize=0;
    }

    bool isEmpty()
    {
        return F==NULL;
    }

    int size()
    {
        return currSize;
    }

    void enqueue(int data)
    {
        Node* temp = new Node(data);
        if(isEmpty())
        {
            F=temp;
            R=temp;
        }
        R->next=temp;
        R=temp;
        currSize++;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            return;
        }
        Node* temp = F;
        F=F->next;
        delete temp;
        currSize--;
    }

    int front()
    {
        if(isEmpty())
        {
            return -1;
        }
        return F->data;
    }

    int rear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return R->data;
    }
};

int main()
{
    Queue q;

    cout<<"Enqueue"<<endl;
    q.enqueue(1);
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    q.enqueue(2);
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    q.enqueue(3);
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    q.enqueue(4);
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    q.enqueue(5);
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    cout<<"size after enqueue = "<<q.size()<<endl;

    cout<<"Dequeue 2 times"<<endl;
    q.dequeue();
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    q.dequeue();
    cout<<"front: "<<q.front()<<endl;
    cout<<"rear: "<<q.rear()<<endl;
    cout<<"size after dequeue = "<<q.size()<<endl;
}
