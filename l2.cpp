#include<iostream>
#include<vector>
using namespace std ;
class node{
    public:
    int data;
    node *next;
    node(int x,node *next1){
        data=x;
        next=next1;
    }
    node(int x){
        data=x;
        next=nullptr;
    }
};
void print(node *head){
    while(head)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
    cout << endl;
    }
node*convertarr2ll(vector<int>&arr){
    node*head=new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
    node*temp=new node(arr[i]);
    mover->next=temp;
    mover=temp;
    }
    return head;
}
node*removehead(node *head ){
    if(head==NULL) return head;
    node *temp=head;
    head=head->next;
    delete temp;
    return head;   
}
node*removetail(node *head){
    if(head == NULL || head->next==NULL) return NULL;
    node *temp =head;
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
int main () {
    vector<int> v1={1,2,3,4};
    node *head=convertarr2ll(v1);
    // cout<<head->data<<endl;
    // head=removehead(head);
    // cout<<head->data<<endl;
    // cout<<endl;
    // print(head);
    head=removetail(head);
    print(head);
    return 0;
}