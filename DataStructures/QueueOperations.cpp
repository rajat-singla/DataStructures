#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseUsingStack(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void print(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){

    queue<int> q;
    for(int i=1;i<9;i++){
        q.push(i);
    }
    print(q);

    cout<<"Reversing queue using stack"<<endl;
    reverseUsingStack(q);
    print(q);
}
