#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Stack
{
    queue<int>* q1;

public:
    Stack()
    {
        q1=new queue<int>();
    }

    ~Stack()
    {
        delete q1;
    }

    void push(int data)
    {
        q1->push(data);
    }

    void pop()
    {
        int sze = q1->size();

        while(--sze)
        {
            q1->push(q1->front());
            q1->pop();
        }
        q1->pop();
    }

    int top()
    {
        int sze = q1->size();

        while(--sze)
        {
            q1->push(q1->front());
            q1->pop();
        }
        int data = q1->front();
        q1->push(q1->front());
        q1->pop();
        return data;
    }

    int size()
    {
        return q1->size();
    }
};

int main()
{
    Stack s;
    s.push(5);
    cout<<"size: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;

    s.push(4);
    cout<<"\nsize: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;

    s.push(10);
    cout<<"\nsize: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;

    s.pop();
    cout<<"\nAfter pop()\nsize: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;

    return 0;
}
