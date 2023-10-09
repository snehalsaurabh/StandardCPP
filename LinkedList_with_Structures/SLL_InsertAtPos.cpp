#include<iostream>
using namespace std;
struct node{
    int info;
    node *next;
};
void traversal(node *start){
    node *temp = start;
    while(temp!=NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
node * insertAtPos(node *start, int key, int pos){
    node * new_node = new node;
    node * temp = start;
    if(pos<1){
        cout<<"Invalid Position"<<endl;
        return start;
    }
    new_node->info=key;
    if(pos==1){
        new_node->next=start;
        start=new_node;
        return start;
    }
    for(int i=1;i<=pos-2 && temp!=NULL;i++) //We iterate to 2nd_last_node before POS because...
        temp=temp->next;                    //Here, 2nd_last_node'NEXT holds the address of last_node which is given to temp here.
    if(temp==NULL){
        cout<<"Insertion position is greater than the end node + 1"<<endl;
        return start;
    }
    new_node->next=temp->next;              //Last_node before insertion contains the address of next_node. The new_node comes in between this last_node and next_node.
    temp->next=new_node;
    return start;
}
int main(){
    node * START = NULL;
    START = insertAtPos(START,10,1);
    traversal(START);
    START = insertAtPos(START,20,1);
    traversal(START);
    START = insertAtPos(START,30,1);
    traversal(START);
    START = insertAtPos(START,40,1);
    traversal(START);
    START = insertAtPos(START,50,3);
    traversal(START);
    START = insertAtPos(START,70,2);
    traversal(START);
    return 0;
}