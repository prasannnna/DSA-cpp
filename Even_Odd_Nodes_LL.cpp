#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};

Node* head = nullptr;
Node* tail = nullptr;

void insertAtLast(int val){
    Node* newnode = new Node(val);
    if(!head) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* evenOddArrange(Node* head) {
    if(!head || !head->next) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(4);
    insertAtLast(5);
    insertAtLast(6);
    insertAtLast(7);
    insertAtLast(8);

    cout << "Original List: ";
    printList(head);

    head = evenOddArrange(head);

    cout << "\nModified List: ";
    printList(head);
    return 0;

}
