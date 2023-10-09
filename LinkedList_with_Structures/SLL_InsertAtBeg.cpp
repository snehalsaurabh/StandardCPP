#include<iostream>
using namespace std;
struct node{
    int info;
    node *next;
};
node * insertAtBeg(node *start, int key){
    node *new_node = new node;
    new_node->info=key;
    new_node->next=start;
    start=new_node;
    return start;
}
void traversal(node *start){
    node *temp = start;
    while(temp!=NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node *START = NULL;
    START = insertAtBeg(START,10);
    traversal(START);
    START = insertAtBeg(START,20);
    traversal(START);
    START = insertAtBeg(START,30);
    traversal(START);
    START = insertAtBeg(START,40);
    traversal(START);
    return 0;
}