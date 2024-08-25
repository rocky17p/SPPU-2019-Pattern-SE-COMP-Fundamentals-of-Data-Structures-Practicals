// #include<iostream>
// #include<vector>
// using namespace std;
// class node 
// {
//     public:
//     int data;
//     node*next;
//     node(int data1,node* next1)
//     {
//         data=data1;
//         next=next1;
//     }
//     node(int data1)
//     {
//         data=data1;
//         next=nullptr;
//     }
// };
// int main () {
//     vector <int> arr ={2,5,8,7};
//     // node x(2,nullptr);
//     // node *y=&x;
//     //instead use the below method
//     node *y=new node(arr[0]);
//     cout<<y->data<<endl;
//     return 0;
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// class node 
// {
//     public:
//     int data;
//     node*next;
//     node(int data1,node* next1)
//     {
//         data=data1;
//         next=next1;
//     }
//     node(int data1)
//     {
//         data=data1;
//         next=nullptr;
//     }
// };
// node*convertarr2ll(vector<int>&arr){
//     node*head=new node(arr[0]);
//     node*mover=head;
//     for(int i=1;i<arr.size();i++){
//     node*temp=new node(arr[i]);
//     mover->next=temp;
//     mover=temp;
//     }
//     return head;
// }
// int main () {
//     vector <int> arr ={2,5,8,7};
//     node*head=convertarr2ll(arr);
//     cout<<head->data;
//     // node x(2,nullptr);
//     // node *y=&x;
//     //instead use the below method
//     // node *y=new node(arr[0]);
//     // cout<<y->data<<endl; 
//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;
class node 
{
    public:
    int data;
    node*next;
    node(int data1,node* next1)
    {
        data=data1;
        next=next1;
    }
    node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
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
int lengthofll(node*head){
    int count=0;
    node*temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}
int checkifpresent(node *head,int val){
    node*temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}
int main () {
    vector <int> arr ={2,5,8,7};
    node*head=convertarr2ll(arr);
    node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<""<<endl;
    cout<<"the length of ll is "<<lengthofll(head)<<endl;
    cout<<checkifpresent(head,2);
}