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