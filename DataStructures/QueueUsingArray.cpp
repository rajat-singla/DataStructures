#include<iostream>
using namespace std;

class Queue
{

    int* arr;
    int head,tail;
    int maxSize;
    int currSize;

public:
    Queue(int maxSize)
    {
        arr = new int[maxSize];
        head=-1;
        tail=-1;
        this->maxSize=maxSize;
        currSize=0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return currSize==0;
    }

    bool isFull()
    {
        return currSize==maxSize;
    }

    int size()
    {
        return currSize;
    }

    void enqueue(int data)
    {
        if(isFull())
        {
            cout<<"Queue Full! Can not add any more elements"<<endl;
            return;
        }
        ++currSize;
        if(isEmpty())
        {
            arr[++tail]=data;
            ++head;
            return;
        }
        tail = (tail+1)%maxSize;
        arr[tail]=data;

    }

    void dequeue()
    {
        if(isEmpty())
        {
            return;
        }
        head = (head+1)%maxSize;
        --currSize;
    }

    int front()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[head];
    }

    int rear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[tail];
    }
};


int main()
{
    Queue q(4);

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
