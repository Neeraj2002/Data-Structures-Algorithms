// Arrays are single block of memeory with partition while 
// Linked list is a multiple block of memory linked to each other
// Size of the linked list can be modified, it has a non-contiguous memory and insertion and deletion is easier
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = n;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

bool search(node* head, int key){
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head=head->next;

    delete todelete;
}

void deletion(node* &head, int val){

    if (head == NULL)
    {
        return;
    }
    if (head-> next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    
    

    node* temp = head;
    while (temp->next->data!=val)
    {
        temp = temp -> next;
    }
    node* todelete = temp -> next;
    temp -> next = temp-> next -> next;

    delete todelete;
}

// There are two methods to reverse a linked list: Iterative and Recursive Method
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while (currptr!=NULL)
    {
        nextptr = currptr -> next;
        currptr -> next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;

}

node* reverseRecursive(node* &head){

    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    node* newhead = reverseRecursive(head->next);
    head->next-> next = head;
    head -> next = NULL;

    return newhead;
}


int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    // display(head);

    insertAtHead(head, 0);

    // deletion(head, 4);
    // deleteAtHead(head);
    display(head);

    cout << search(head, 3) << endl;

    // node* newhead = reverse(head);
    // display(newhead);

    node* newhead = reverseRecursive(head);
    display(newhead);

    
    return 0;
}