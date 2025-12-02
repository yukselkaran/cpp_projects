#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    void printList(Node* head) {
        if (head == nullptr)
            return;
        cout << head->data << " ";
        printList(head->next);
    }

    int sumOfAllNodes(Node* head) {
        if (head == nullptr)
            return 0;
        return head->data + sumOfAllNodes(head->next);
    }
};

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {//n-th term
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciIterative(int n) {
    int first = 0;
    int second = 1;
    for (int i = 2; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int sumOfFirstNCubes(int n) {
    if (n == 1)
        return 1;
    int sum = n * n * n;
    return sumOfFirstNCubes(n - 1) + sum;
}

int linearSum(int sumList[], int n) {
    if (n == 1)
        return sumList[0];
    return sumList[n - 1] + linearSum(sumList,n-1);
}

void reverseArray(int listToReverse[], int i, int j) {
    if (i < j) {
        int temp = listToReverse[i];
        listToReverse[i] = listToReverse[j];
        listToReverse[j] = temp;
        reverseArray(listToReverse, i + 1, j - 1);
    }
}

int tailRecursiveFactorial(int n, int sum = 1) {
    if (n == 0)
        return sum;
    return tailRecursiveFactorial(n - 1, n * sum);
}

int recursiveBinarySearch(int key, int sortedList[], int low, int high) {
    if (low > high)
        return -1;
    int middle = (low + high) / 2;
    if (key == sortedList[middle])
        return middle;//O(1)
    else if (key < sortedList[middle])
        return recursiveBinarySearch(key, sortedList, low, middle - 1);
    else
        return recursiveBinarySearch(key, sortedList, middle + 1, high);
}
int main()
{
    //test
    cout<<factorial(5)<<endl;
    /*
    5!
    5*4!
    5*4*3!
    5*4*3*2!
    5*4*3*2*1!
    5*4*3*2*1*0!
    */
    cout << endl;

    auto startFibonacci = high_resolution_clock::now();
    cout << "Sonuc: ***" << fibonacci(10) << "*** ";
    auto endFibonacci = high_resolution_clock::now(); 
    auto nanosaniyeFibonacci = duration_cast<nanoseconds>(endFibonacci - startFibonacci);
    cout << "Recursive Fibonacci Islem suresi (Nanosaniye): " << nanosaniyeFibonacci.count() << " ns" << endl;

    auto startFibonacciIterative = high_resolution_clock::now();
    cout << "Sonuc: ***" << fibonacciIterative(10) << "*** ";
    auto endFibonacciIterative = high_resolution_clock::now();
    auto nanosaniyeFibonacciIterative = duration_cast<nanoseconds>(endFibonacciIterative - startFibonacciIterative);
    cout << "Iterative Fibonacci Islem suresi (Nanosaniye): " << nanosaniyeFibonacciIterative.count() << " ns" << endl;
    cout << endl;

    cout << sumOfFirstNCubes(2)<<endl;
    cout << endl;

    int myList[] = { 1, 2, 4, 3, 2 };
    int n = 5;
    cout << linearSum(myList,n)<<endl;
    cout << endl;


    int myList2[] = { 1,2,3,4,5 };
    int a = 5;
    reverseArray(myList2, 0, a - 1);
    for (int i = 0; i < 5; i++) {
        cout << myList2[i] << " ";
    }
    cout << endl<<endl;

    cout << tailRecursiveFactorial(7)<<endl;
    cout << endl;

    int myList3[] = { 1,2,5,7,9,12,17,21,23,27,32 };
    int key = 21;
    cout << recursiveBinarySearch(1,myList3,0,11)<<endl;
    cout << endl;

    LinkedList myLinkedList;
    Node* head = new Node(21);
    Node* node2 = new Node(22);
    Node* node3 = new Node(23);

    myLinkedList.head = head;
    head->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    myLinkedList.printList(head);
    cout << endl<<endl;

    cout << myLinkedList.sumOfAllNodes(head);
}
