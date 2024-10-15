#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
class queue
{
public:
    node *front = nullptr;
    node *back = nullptr;
    queue()
    {
        front = nullptr;
        back = nullptr;
    }
    bool isempty()
    {
        return (front == nullptr);
    }
    void frontinsert(int value)
    {
        node *newnode = new node(value);
        if (isempty())
        {
            front = newnode;
            back = newnode;
        }
        else
        {
            newnode->next = front;
            front->prev = newnode;
            front = newnode;
        }
    }
    void backinsert(int value)
    {
        node *newnode = new node(value);
        if (isempty())
        {
            front = newnode;
            back = newnode;
        }
        else{
            back->next=newnode;
            newnode->prev=back;
            back=newnode;
        }
    }
    void frontdelete(){
        if(isempty()){
            cout<<"the queue is already empty"<<endl;
        }
        node *temp=front;
        if(front==back){
            front=back=nullptr;
        }
        else{
            front=front->next;
            front->prev=nullptr;
        }
        delete temp;
    }
    void backdelete() {
    if (isempty()) {
        cout << "The queue is already empty." << endl;
        return;
    }
    
    node *temp = back;

    if (front == back) {
        front = back = nullptr;
    } else {
        back = back->prev;
        back->next = nullptr;
    }

    delete temp;
}

    void display(){ 
        if(isempty()){
            cout<<"the queue is empty"<<endl;
            return ;
        }
        node *temp=front;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    queue q1;
    q1.frontinsert(10);
    q1.frontinsert(20);
    q1.backinsert(30);
    q1.display();
    q1.frontinsert(40);
    q1.display();
    q1.frontdelete();
    q1.display();
    q1.backdelete();
    q1.display();
    return 0;
}