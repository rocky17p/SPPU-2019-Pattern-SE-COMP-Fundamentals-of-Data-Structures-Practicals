#include<iostream>
#include<vector>
using namespace std ;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int x,Node*next1,Node *prev1){
        data=x;
        next=next1;
        prev=prev1;
    }
    Node(int x){
        data=x;
        next=nullptr;
        prev = nullptr;
    }
};                  
Node *convertarr2dll(vector<int>&v){
    Node *head=new Node(v[0]);
    Node *back =head;
    for(int i=1;i<v.size();i++){
        Node *temp= new Node(v[i],nullptr,back);
        back->next=temp;
        back=temp;
    }
    return head;
}
Node *reversedll(Node *head){// 0(n) and 0(1)`
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *back=NULL;
    Node *current=head;
    while(current!=NULL){
        back=current->prev;
        current->prev=current->next;
        current->next=back;
        current=current->prev;
    }
    return back->prev;
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main () {
    vector<int> v1={1,2,3,4};
    Node *head=new Node(v1[0]);
    head=convertarr2dll(v1);
    print(head);
    return 0;
}