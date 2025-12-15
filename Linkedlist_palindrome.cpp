#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* reverse_ll(Node* middle){
    Node* prev = NULL;
    Node* curr = middle;
    while(curr){
        Node* nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
    return prev;
}
bool isPalindrome(Node* head){
    if(!head || !head->next){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // For odd length linked list fast != NULL
    if(fast) slow = slow->next;
    Node* second_part = reverse_ll(slow);
    Node* first_part = head;
    while(second_part){
        if(second_part->data != first_part->data){
            return false;
        }
        second_part = second_part->next;
        first_part = first_part->next;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    if(isPalindrome(head)){
        cout << "Palindrome";
    } else {
        cout << "Not a Palindrome";
    }
}