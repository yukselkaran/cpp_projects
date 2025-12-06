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

class CircularLinkedList {
public:
	Node* head;
	CircularLinkedList() {
		head = nullptr;
	}

	void insert(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			head->next = head; // head connect itself if list has 0 item before insertion.
			return;
		}
		Node* current = head;
		while (current->next != head) {// if it is before the head we will add it right after the last node before head.
			current = current->next;
		}
		current->next = newNode;
		newNode->next = head; // this line also makes the circular structure.
	}

	void printList() {
		if (head == nullptr) {
			cout << "List is empty";
			return;
		}
		Node* current = head;
		do {// the reason why we use do-while loop at here is. We initialized current as equals to head and it makes the condition that inside the loop becomes false.
			cout << current->data << " -> ";
			current = current->next;
		} while (current != head);
		cout << "(Head)" << endl;
	}
	bool hasCycle(Node* head) {
		if (head == nullptr)
			return false;
		Node* slow = head;
		Node* fast = head;
		while (fast != 0 && fast->next != 0) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};

int main() {
	CircularLinkedList list;

	list.insert(12);
	list.insert(21);
	list.insert(32);
	list.insert(37);

	list.printList();

	if (list.hasCycle(list.head))
		cout << "Cycle detected" << endl;
	else
		cout << "No cycle." << endl;

	return 0;
}
