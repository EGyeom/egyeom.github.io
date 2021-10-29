#include <iostream>
struct s_Node {

	int data;
	s_Node * next = NULL;

};


class node
{
public:
	node();
	~node();
	
	s_Node * head;
	s_Node * nPrev;
	s_Node * nCurr;
	s_Node * nNext;

	void insert(int num);

	void print();

	void reverse();

};

