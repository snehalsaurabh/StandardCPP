#include<iostream>
using namespace std;

struct node{
    int info;
    node *next;
};
node * traversal(node *start){
    node *temp = start;
    while(temp!=NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void main(){
    node *start = NULL;
    traversal(start);
}
