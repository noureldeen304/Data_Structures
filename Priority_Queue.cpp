#include<iostream>
#include<vector>
using namespace std;
class Priorityqueue
{
private:
	vector<int> heap;
	int index_of_right_child(int index_of_parent)
	{
		int p = (index_of_parent * 2) + 2;
		if (p >= heap.size())
			return -1;
		else
			return p;
	}
	int index_of_left_child(int index_of_parent)
	{
		int p = (index_of_parent * 2) + 1;
		if (p >= heap.size())
			return-1;
		else return p;
	}
	int parent(int index_of_child)
	{
		return (index_of_child == 0) ? -1 : (index_of_child - 1) / 2;
	}
	void reheapup(int pos)
	{
		if (pos == 0 || heap[parent(pos)] < heap[pos])
			return;
		swap(heap[parent(pos)], heap[pos]);
		reheapup(parent(pos)); // parent(pos)--------> the new pos of our node after swapping
	}
	void reheapdown(int pos)
	{
		int smallestchildpos = index_of_left_child(pos);
		if (smallestchildpos == -1) // no left child therefore no right child
			return;
		

			int rightchildpos = index_of_right_child(pos);
			if (rightchildpos != -1)
				if (heap.size() >= 3)
				{
					if (heap[rightchildpos] <= heap[smallestchildpos])
						smallestchildpos = rightchildpos;
				}			
		
		if(heap.size()>=2)
			if(heap[pos] > heap[smallestchildpos])
			{
				swap(heap[pos], heap[smallestchildpos]);
				reheapdown(smallestchildpos);
			}
	}
public:
	void pop()
	{
		if (heap.size() > 0)
		{
			heap[0] = heap.back();
			heap.pop_back();
			reheapdown(0);
		}
	}
	int top()
	{
		if (size()!= 0)
			return heap.front();
	}
	void push(int key)
	{
		
		heap.push_back(key);
		reheapup( heap.size()- 1 );
	}
	void print()
	{
		copy(heap.begin(), heap.end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
	}
	int size()
	{
		return heap.size();	
	}
};
int main()
{
	Priorityqueue pq;
	int num, cur;
	cout << "Enter number of digits you want to sort: "; cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> cur;
		pq.push(cur);
	}
	cout << "Result:\n";
	for (int i = 0; i < num; i++)
	{
		cout << pq.top()<< " ";
		pq.pop();
	}
	
	cout << "\n\n";
	return 0;
}