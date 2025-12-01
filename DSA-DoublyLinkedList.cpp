#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int d) {
		data = d;
		next = nullptr;
		prev = nullptr;
	}
};
class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void pushFront(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void pushBack(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			return;
		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	void printListForward() {
		if (head == nullptr) {
			cout << "List is empty";
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "NULL";
	}

	void printListBackward() {
		if (head == nullptr) {
			cout << "List is empty";
			return;
		}
		Node* current = tail;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->prev;
		}
		cout << "NULL";
	}

	void removeTail() {
		if (head == nullptr) {
			cout << "List is empty";
			return;
		}
		if (tail->prev != nullptr) {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		else {// if list contains just one element
			delete tail;
			head = nullptr;
			tail = nullptr;
		}

	}

};
int main()
{
	return 0;
}
