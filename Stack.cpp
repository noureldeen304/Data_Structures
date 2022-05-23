#include <iostream>
#include <string>
using namespace std;
template <class t>
class stack
{
	struct node
	{
		t item;
		node* next;
	};
	node* top;
	int count;
public:
	stack()
	{
		top = NULL;
		count = 0;
	}
	void push(t newitem)
	{

		node *newitemptr=new node;
		newitemptr->item = newitem;
		newitemptr->next = top;
		top = newitemptr;
		count++;
	}
	bool isempty()
	{
		return top == NULL;
	}
	void pop()
	{
		if(isempty())
		{
			cout << "The stack is empty\n";
		}
		else
		{
			node* temp=top;
			top = top->next;
			temp = NULL;
			count--;
		}
	}
	//Removes and saves the deleted value
	void pop(t &del)
	{
		if (this.is_empty())
			cout << "The stack is empty\n";
		node* temp=top;
		del = temp->item;
		temp = NULL;
		top = top->next;
	}

	void gettop()
	{

		cout << "stack top: " << top->item << "\n";
	}
	void print()
	{
		cout << "Stack elements:\n";
		node* cur = top;
		while(cur!=NULL)
		{
			cout <<cur->item << "\n";
			cur=cur->next;
		}
		cout << "\n";
	}
	int size()
	{
		return this->count;
	}
};

int main()
{
	stack<int> x;
	x.push(10);
	x.push(20);
	x.push(30);
	x.push(40);
	x.print();
	x.pop();
	cout << "After deleting one element\n";
	x.print();


return 0;
}


