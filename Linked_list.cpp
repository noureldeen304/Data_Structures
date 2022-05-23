#include<iostream>
#include<cassert>
using namespace std;
template<class t>
class linkedlist
{
	struct node
	{
		t item;
		node* next;
	};
	node* front;
	node* last;
	int length;
public:
	linkedlist()
	{
		last = front = NULL;
		length = 0;
	}
	bool isempty()
	{
		return length == 0;
	}
	void AddAtFirst(t x)
	{
		if (isempty())
		{
			front = new node;
			front->item = x;
			front->next = NULL;
			last = front;
			length++;
		}
		else
		{
			node* newnode = new node;
			newnode->item = x;
			newnode->next = front;
			front = newnode;
			length++;
		}

	}
	void AddAtLast(t x)
	{
		if (isempty())
		{
			last->item = x;
			last->next = NULL;
			front = last;
			length++;
		}
		else
		{
			node* newnode = new node;
			newnode->item = x;
			newnode->next = NULL;
			last->next = newnode;
			last = newnode;
			length++;
		}
	}
	void RemoveAtFirst()
	{
		if (this->isempty())
		{
			cout << "The linked list is empty\n";
		}
		else if (length == 1)
		{
			front = last = NULL;
			length--;
		}
		else
		{
			node* temp = front;
			front = front->next;
			delete temp;
			temp->next = NULL;
			length--;
		}
	}
	void RemoveAtLast()
	{
		if (this->length == 1)
		{
			this->front = last = NULL;
			this->length--;
		}
		else
		{
			node* pvr = this->front;
			node* cur = this->front->next;
			while (cur->next != NULL)
			{
				pvr = cur;
				cur = cur->next;
			}
			pvr->next = NULL;
			last = pvr;
			delete cur;
			length--;
		}
	}
	void RemoveAtPos(int x)
	{
		if (x<1 || x>length)
			cout << "out of range\n";
		else if (x == 1)
			RemoveAtFirst();
		else if (x == length)
			RemoveAtLast();
		else
		{
			node* cur = front;
			node* pvr = front->next;
			for (int i = 1; i < (x - 1); i++)
			{
				cur = pvr;
				pvr = pvr->next;
			}
			cur->next = pvr->next;
			delete pvr;
			pvr->next = NULL;
			length--;
		}
	}
	void AddAtPos(t x, int pos)
	{
		if (pos<1 || pos>length)
			cout << "out of range\n";
		else if (pos == 1)
			AddAtFirst(x);
		else if (pos == length)
			AddAtLast(x);
		else
		{
			node* newnode = new node;
			newnode->item = x;
			node* pvr = front;
			node* cur = new node;
			for (int i = 1; i < pos; i++)
			{
				cur = pvr;
				pvr = pvr->next;
			}
			newnode->next = pvr;
			cur->next = newnode;
			length++;
		}
	}
	t getfront()
	{
		return this->front->item;
	}
	void display()
	{
		int c = 0;
		node* cur = this->front;
		while (cur != NULL)
		{
			cout << c << "." << cur->item << "\n";
			cur = cur->next;
			c++;
		}
		cout << "******************\n";
	}
	int search(t x)
	{
		node* cur = front;
		int pos = 0;
		while (cur != NULL)
		{
			if (cur->item == x)
			{
				return pos;
			}
			cur = cur->next;
			pos++;
		}
		return -1;

	}
};
int main()
{
	linkedlist <string>x;
	x.AddAtFirst("nour");
	x.AddAtLast("ahmed");
	x.AddAtLast("rana");
	x.AddAtLast("ali");
	x.display();
	x.RemoveAtPos(1);
	x.display();

	return 0;
}