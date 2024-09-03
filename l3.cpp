#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *back;
    node(int x,node*next1,node *back1){
        data=x;
        next=next1;
        back=back1;
    }
    node(int x){
        data=x;
        next=nullptr;
        back = nullptr;
    }
};                  
node *convertarr2dll(vector<int>&v){
    node *head=new node(v[0]);
    node *prev =head;
    for(int i=1;i<v.size();i++){
        node *temp= new node(v[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node *deletehead(node *head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    node *prev =head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    return head;
}
node *deletetail(node *head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    node *prev =head;
    while(prev->next->next !=nullptr){
        prev=prev->next;
    }
    prev->next=nullptr;
    return head;
}
node *deletekthelement( node *head,int k){
    if(head==NULL) return NULL;
    int count=0;
    node *knode=head;
    while(knode!=NULL){
        count++;
        if(count==k) {
            break;
            }
        knode=knode->next;
    }
    node *prev=knode->back;
    node *front=knode->next;
    if(prev==NULL && front==NULL) {
        return NULL;
    }
    else if (prev==NULL)
    {
        return deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }
    else{
        prev->next=front;
        front->back=prev;

        knode->next=nullptr;
        knode->back=nullptr;
    }
    return head;
}
void deletenode(node *temp){
    node *prev=temp->back;
    node*front=temp->next;
    if(front==nullptr){
        prev->next=nullptr;
        temp->back=nullptr;
        free (temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    free(temp);
    return;
}
// node *deletenode(node *head,int k){
//     node *prev=head;
//     while(prev->data!=k){
//         prev=prev->next;
//     }
//     if(prev->back==nullptr && prev->next==nullptr){
//         return NULL;
//     }
//     else if(prev->back==nullptr){
//         return deletehead(head);
//     }
//     else if(prev->next==nullptr){
//         return deletetail(head);
//     }
//     else{
//     node *front=prev->next;
//     node *back=prev->back;
//     prev->next=nullptr;
//     prev->back=nullptr;
//     delete prev;
//     front->back=back;
//     back->next=front;
//     }
//     return head;
// }
node *insertbeforehead(node *head,int k){
    if(head==NULL) return new node(k);
    node *newhead=new node(k,head,nullptr);
    head->back=newhead;
    return newhead;
}
node *insertbeforetail(node *head,int k){
    if(head->next=NULL){
        return insertbeforehead(head,k);
    }
    node *temp=head;
    while(temp->next->next !=nullptr){
        temp=temp->next;
    }
    node *front= temp->next;
    node *beforetail= new node(k,temp->next,temp);
    temp->next=beforetail;
    front->back=beforetail;
    return head;
}
node *insertbeforekthelement(node *head,int k,int val){
    if(k==1){
        return insertbeforehead(head,val);
    }
    int count=1;
    node *temp=head;
    while(temp!=NULL){
        if(count==k) break;
        count++;
        temp=temp->next;
    }
    node *prev=temp->back;
    node *newelement= new node(val,temp,prev);
    prev->next=newelement;
    temp->back=newelement;
    return head;
}
node *insertbeforenode(node *head,int k,int val){
    node *temp=head;
    while(temp->data!=k){
        temp=temp->next;
    }
    node *prev= temp->back;
    node *newelement= new node(val,temp,prev);
    prev->next=newelement;
    temp->back=newelement;
    return head;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    vector<int> v1={29,30,31,32};
    node *head=convertarr2dll(v1);
    //head=deletehead(head);
    //head=deletetail(head);
    //head=deletekthelement(head,3);
    deletenode(head->next);
    //head=deletenode(head,4);
    //head=insertbeforehead(head,10);
    //head=insertbeforetail(head,10);
    //head=insertbeforekthelement(head,5,22);
    //head=insertbeforenode(head,3,2);
    print(head);
    return 0;
}