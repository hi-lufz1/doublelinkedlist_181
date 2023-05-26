#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;

};

class DoubleLinkedlist {
private:
	node* START;
public:
	DoubleLinkedlist();
	void addNode();
	bool search(int rollNo, node** previous, node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();

};

DoubleLinkedlist::DoubleLinkedlist() {
	START = NULL;
}

void DoubleLinkedlist::addNode(){
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	node* newNode = new node();//step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nm; // step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // step 3
		if (START != NULL)
			START->prev = newNode; // step 4
		newNode->prev = NULL; //step 5
		START = newNode;//step 6
		return;
	}

	/*inserting a node between two node in the list*/
	node* current = START; //step 1.a
	node* previous = NULL; //step 1.b
	while (current->next != NULL && current->next->noMhs < nim)// step 1 c
	{
		previous = current;//1.d 
		current = current->next;//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate number not allowed" << endl;
		return;
	}

	newNode->next = current->next; //step 4
	newNode->prev = current;//step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; //step 7
}

bool DoubleLinkedlist::search (int rollNo, node** previous, node** current) {
	*previous = NULL;//step 1.a
	*current = START;//step 1.b
	while (*current != NULL && (*current)->noMhs != rollNo) {//step 1.c
		*previous = *current; //step1.d
		*current = (*current)->next; //step1.e
	}
	return (*current != NULL);

}

bool DoubleLinkedlist::deleteNode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step2
	if (previous != NULL)
		previous->next = current->next; //step3
	else
		START = current->next;

	delete current; //step4
	return true;

}

bool DoubleLinkedlist::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;

		}
     }
}

void DoubleLinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->prev << endl;
			currentNode = currentNode->prev;
		}
	}
}
void DoubleLinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedlist::deleteNode(rollNo) == false)
		cout << "Record wnot found" << endl;
	else


	




