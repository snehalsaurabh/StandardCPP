#include<iostream>
using namespace std;
struct node{
    int info;
    node * next;
};
node * insertAtEnd(node * start, int key){
    node *new_node = new node;        //New Node Formation happens here. 
    node * temp = start;
    new_node->info=key;               //Value is assigned in the info section of the new node.
    if(start==NULL)                   //If the LL appears to be empty, then there is no end so we simply assign 'START' with the address of new_node.
        start=new_node;
    else{
        while(temp->next!=NULL)       //If the LL iu not empty, we traverse till the end node and then, assign the new_node's address to the end node's 'NEXT' pointer.
            temp=temp->next;
        temp->next=new_node;
    }
    new_node->next=NULL;              //New_Node's 'NEXT' pointer is given the value of NULL as it is at the end.
    return start;
}
void traversal(node * start){
    node *temp = start;
    while(temp!=NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node * START = NULL;
    START = insertAtEnd(START,10);
    traversal(START);
    START = insertAtEnd(START,15);
    traversal(START);
    START = insertAtEnd(START,30);
    traversal(START);
    START = insertAtEnd(START,19);
    traversal(START);
    return 0;
}