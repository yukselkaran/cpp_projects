#include <iostream>
using namespace std;
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
	LinkedList(int h) {
		head = nullptr;
	}

	void insertAtBeginning(int d) {
		Node* newNode = new Node(d);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int d) {
		Node* newNode = new Node(d);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	bool search(int d) {
		Node* searchItem = head;
		while (searchItem!= nullptr) {
			if (searchItem->data == d) {
				return true;
			}
			searchItem = searchItem->next;
		}
		return false;
	}
};
int main()
{
	return 0;
}
