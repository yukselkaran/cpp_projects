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
class SinglyLinkedList {
public:
	Node* head;
	SinglyLinkedList() {
		head = nullptr;
	}
	bool isEmpty() {
		return head == nullptr;
	}

	void pushFront(int d) {
		Node* newNode = new Node(d);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void pushBack(int d) {
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

	void removeFront() {
		if (isEmpty()) {
			cout << "list is empty";
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void removeBack() {
		if (isEmpty()) {
			cout << "list is empty";
			return;
		}
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* temp = head;

		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

	void deleteAt(int index) {
		if (index < 0 || index >= size()) {
			cout << "invalid index";
			return;
		}
		if (index == 0) {
			removeFront();
			return;
		}
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		Node* deletedNode = temp->next;
		temp->next = temp->next->next;
		delete deletedNode;
	}

	int get(int index) {
		if (index < 0 || index >= size()) {
			cout << "invalid input";
			return;
		}
		Node* getData = head;
		for (int i = 0; i < index; i++) {
			getData = getData->next;
		}
		return getData->data;
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

	void insertAt(int index,int data) {
		if (index<0 || index>size()) {
			cout << "invalid index";
			return;
		}
		if (index == 0) {
			pushFront(data);
			return;
		}
		Node* newNode = new Node(data);
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;

	}

	int size() {
		int counter = 0;
		Node* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			counter++;	
		}
		return counter;
	}

	void printLlist() {
		if (isEmpty()) {
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << " NULL";
	}

	void printReverseHelper(Node* node) {
		if (node == nullptr)
			return;

		printReverseHelper(node->next);
		cout << node->data << " -> ";
	}
	void printReverse() {
		if (isEmpty) {
			cout << "List is Empty";
			return;
		}
		printReverseHelper(head);
		cout << "NULL";
	}
};
int main()
{
	return 0;
}


