#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
//iterative
ListNode* reverseList(ListNode* head) {
        ListNode * dummy = NULL;
        while (head) {
            ListNode* n = head -> next;
            head -> next = dummy;
            dummy = head;
            head = n;
        }
        return dummy;
    }