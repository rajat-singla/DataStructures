#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Stack
{
    queue<int>* q1,*q2;

public:
    Stack()
    {
        q1=new queue<int>();
        q2=new queue<int>();
    }

    void push(int data)
    {
        q1->push(data);
    }

    void pop()
    {
        while(q1->front()!=q1->back())
        {
            q2->push(q1->front());
            q1->pop();
        }
        q1->pop();
        queue<int>* temp = q2;
        q2=q1;
        q1=temp;
    }

    int top()
    {
        return q1->back();
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
