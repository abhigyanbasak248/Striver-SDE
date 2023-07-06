#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* constructLL(vector<int>& arr) {
        Node *newnode=new Node();
        Node *root=newnode;
        for (auto i:arr) {
            Node *temp=new Node(i);
            root->next=temp;
            root=root->next;
        }
        return newnode->next;
    }

//Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x) {
        Node *newNode=new Node(x);
        newNode->next=head;
        head=newNode;
        return head;
    }
    
    
//Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)  {
        Node *newNode=new Node(x);
        if (head==NULL) head=newNode;
        else {Node *curr=head;
        while (curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=newNode;
        }
        return head;
        
    }

Node* deleteNode(Node *head,int x)
{
    if (x==1) {
        head=head->next;
    }
    else {
        Node* p=head;
        Node* q=head->next;
        for (int i=0;i<x-2;i++) {
            p=p->next;
            q=q->next;
        }
        p->next=q->next;
    }
    return head;
}

//Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        int cnt=0;
        Node *temp=head;
        while (temp!=NULL) {
            temp=temp->next;
            cnt++;
        }
        return cnt;
    
    }


bool searchKey(int n, struct Node* head, int key) {
        Node *temp=head;
        while (temp!=NULL) {
            if (temp->data==key) {
                return true;
                break;
            }
            temp=temp->next;
        }
        return false;
    }