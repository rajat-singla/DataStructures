#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

stack<int> insertAtBottom(stack<int> s, int data)
{
    stack<int> temp;

    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(data);

    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    return s;
}

stack<int> reverseRecursive(stack<int> s)
{
    if(s.size()==1)
    {
        return s;
    }
    int data = s.top();
    s.pop();
    stack<int> temp = reverseRecursive(s);

    temp = insertAtBottom(temp,data);
    return temp;
}

int main()
{

    int data;
    stack<int> s;
    cin>> data;

    while(data!=-1)
    {
        s.push(data);
        cin>>data;
    }
    print(s);

    cout<<"Reversing stack recursively"<<endl;
    s=reverseRecursive(s);
    print(s);
}
