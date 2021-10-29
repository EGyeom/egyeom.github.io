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

node::node()
{
}

node::~node()
{
}

void node::insert(int num)
{
	s_Node * ptr = new s_Node;

	ptr->data = num;
	ptr->next = NULL;

	if (head == NULL)
	{
		head = ptr;
		return;
	}
	else
	{
		s_Node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
}

void node::print()
{
	s_Node * temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "->";
		temp = temp->next;
	}
}

void node::reverse()
{
	nPrev = NULL;
	nCurr = head;

	while (nCurr != NULL)
	{
		nNext = nCurr->next;
		nCurr->next = nPrev;
		nPrev = nCurr;
		nCurr = nNext;
	}
	head = nPrev;
}

int main()
{
	node nd;
	int num;

	nd.insert(1);
	nd.insert(2);
	nd.insert(3);
	nd.insert(4);
	nd.insert(5);
	nd.insert(6);
	nd.insert(7);

	nd.print();
	std::cout << std::endl;

	//nd.reverse();

	nd.print();
}