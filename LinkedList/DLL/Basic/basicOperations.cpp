#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

 Node* constructDLL(vector<int>& arr) {
        int n = arr.size();
        Node* head = NULL;
        Node* tail = NULL;
        if (n == 0) return head;
        Node* newNode = new Node(arr[0]);
        head = newNode;
        tail = newNode;
        for (int i = 1;i<n;i++) {
            Node* temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail=temp;
        }
        return head;
    }

