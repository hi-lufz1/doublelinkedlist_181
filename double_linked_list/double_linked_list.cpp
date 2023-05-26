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

	}



}
