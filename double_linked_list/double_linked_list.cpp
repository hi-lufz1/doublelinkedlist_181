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
node* current




}

