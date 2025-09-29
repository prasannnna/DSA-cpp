#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int middleNode(Node* head) {
    if(head == nullptr) return -1;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    if(n == 0) {
        cout << -1;
        return -1;
    }
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++ ) {
        Node* node = new Node(arr[i]);
        temp->next = node;
        temp = temp->next;
    }
    int ans = middleNode(head);
    cout << ans;   
}