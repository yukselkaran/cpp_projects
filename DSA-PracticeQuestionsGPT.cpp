#include <bits/stdc++.h>
using namespace std;

/* ===================================================
   Singly Linked List Node + Basic Helpers
   =================================================== */
struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* insertLast(Node* head, int val) {
    Node* n = new Node(val);
    if (!head) return n;
    Node* p = head;
    while (p->next) p = p->next;
    p->next = n;
    return head;
}

Node* buildFromVector(const vector<int>& v) {
    Node* head = nullptr;
    for (int x : v) head = insertLast(head, x);
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

void freeList(Node* head) {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

/* ===================================================
   Q8 — Delete First Occurrence of Key
   =================================================== */
Node* deleteFirstOccurrence(Node* head, int key) {
    if (!head) return head;

    if (head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        return head;
    }

    Node* curr = head;
    while (curr->next && curr->next->data != key)
        curr = curr->next;

    if (!curr->next) return head;

    Node* t = curr->next;
    curr->next = curr->next->next;
    delete t;

    return head;
}

/* ===================================================
   Q9 — Sum of Even Numbers (Non-tail & Tail Recursion)
   =================================================== */
int sumEvenNonTail(Node* head) {
    if (!head) return 0;
    int add = (head->data % 2 == 0) ? head->data : 0;
    return add + sumEvenNonTail(head->next);
}

int sumEvenTail(Node* head, int acc = 0) {
    if (!head) return acc;
    if (head->data % 2 == 0) acc += head->data;
    return sumEvenTail(head->next, acc);
}

/* ===================================================
   Q11 — Find Minimum Element
   =================================================== */
int findMin(Node* head) {
    if (!head) {
        cout << "Error: The list is empty.\n";
        return 0;
    }
    int mn = head->data;
    Node* p = head->next;
    while (p) {
        if (p->data < mn) mn = p->data;
        p = p->next;
    }
    return mn;
}

/* ===================================================
   Q12 — Tail Recursive Fibonacci
   =================================================== */
int f_tail_fib(int n, int a, int b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return f_tail_fib(n - 1, b, a + b);
}

int fib(int n) {
    return f_tail_fib(n, 0, 1);
}

/* ===================================================
   Q13 — Sum of Digits (Non-tail & Tail)
   =================================================== */
int sumOfDigitsNonTail(int num) {
    if (num == 0) return 0;
    return (num % 10) + sumOfDigitsNonTail(num / 10);
}

int sumOfDigitsTail(int num, int acc = 0) {
    if (num == 0) return acc;
    return sumOfDigitsTail(num / 10, acc + (num % 10));
}

/* ===================================================
   Q14 — Cycle Detection (Floyd)
   =================================================== */
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

/* ===================================================
   Q15 — Move Key to End (Your Simpler Version)
   =================================================== */
int moveKeyToEnd(Node*& head, Node*& tail, int key) {

    if (head == nullptr)
        return 0;

    Node* curr = head;
    Node* prev = nullptr;

    int count = 0;

    while (curr != nullptr) {

        if (curr->data == key) {
            count++;

            if (curr == head) {
                head = head->next;
                tail->next = curr;
                tail = curr;
                curr = head;
                tail->next = nullptr;
            } else {
                prev->next = curr->next;
                tail->next = curr;
                tail = curr;
                curr = prev->next;
                tail->next = nullptr;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return count;
}

/* ===================================================
   MAIN — Test All Required Questions
   =================================================== */
int main() {

    cout << "Q8 — Delete First Occurrence:\n";
    Node* h8 = buildFromVector({14,20,30,40,20,34});
    h8 = deleteFirstOccurrence(h8, 20);
    printList(h8);
    freeList(h8);

    cout << "\nQ9 — Sum Even:\n";
    Node* h9 = buildFromVector({1,2,3,4,5,6});
    cout << sumEvenNonTail(h9) << "\n";
    cout << sumEvenTail(h9) << "\n";
    freeList(h9);

    cout << "\nQ11 — Find Min:\n";
    Node* h11 = buildFromVector({12,7,25,3,18});
    cout << findMin(h11) << "\n";
    freeList(h11);

    cout << "\nQ12 — Fibonacci:\n";
    for (int i=0;i<=10;i++) cout << fib(i) << " ";
    cout << "\n";

    cout << "\nQ13 — Sum of Digits:\n";
    cout << sumOfDigitsNonTail(12345) << " ";
    cout << sumOfDigitsTail(12345) << "\n";

    cout << "\nQ14 — Cycle Detection:\n";
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next = b; b->next = c; c->next = nullptr;
    cout << (hasCycle(a) ? "Cycle" : "No Cycle") << "\n";
    c->next = b;
    cout << (hasCycle(a) ? "Cycle" : "No Cycle") << "\n";
    c->next = nullptr;
    delete a; delete b; delete c;

    cout << "\nQ15 — Move Key to End:\n";
    Node* h15 = buildFromVector({14,20,30,40,30,25,30,15});
    Node* tail = h15;
    while (tail->next) tail = tail->next;
    int moved = moveKeyToEnd(h15, tail, 30);
    printList(h15);
    cout << "Moved count = " << moved << "\n";

    freeList(h15);

    return 0;
}
