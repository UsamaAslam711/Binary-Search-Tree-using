#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* Left;
	Node* Right;
public:
	Node(int tval)
	{
		data = tval;
		Left = Right = NULL;
	}
	void setData(int tval)
	{
		data = tval;
	}
	void setLeft(Node* tl)
	{
		Left = tl;
	}
	void setRight(Node* tr)
	{
		Right = tr;
	}
	int getData()
	{
		return data;
	}
	Node* getLeft()
	{
		return Left;
	}
	Node* getRight()
	{
		return Right;
	}
	void Display()
	{
		cout << "\t" << data;
	}
};
class BST
{
	Node* Root;
public:
	BST()
	{
		Root = NULL;
	}
	Node* getRoot()
	{
		return Root;
	}
	void Insert(int val)
	{
		Node* N = new Node(val);
		if (Root == NULL)
		{
			Root = N;
			return;
		}
		Node* temp = Root;
		while (true)
		{
			if (N->getData() < temp->getData())
			{
				if (temp->getLeft() == NULL)
				{
					temp->setLeft(N);
					return;
				}
				temp = temp->getLeft();
			}
			else
			{
				if (temp->getRight() == NULL)
				{
					temp->setRight(N);
					return;
				}
				temp = temp->getRight();
			}
		}
	}
	void DisplayPre(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		temp->Display();
		DisplayPre(temp->getLeft());
		DisplayPre(temp->getRight());
	}
	void DisplayIn(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		DisplayIn(temp->getLeft());
		temp->Display();
		DisplayIn(temp->getRight());
	}
	void DisplayPost(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		DisplayPost(temp->getLeft());
		DisplayPost(temp->getRight());
		temp->Display();
	}
	bool Search(int val)
	{
		Node* temp = Root;
		if (Root == NULL)
		{
			cout << "Tree is Empty..." << endl;
			return false;
		}
		while (temp != NULL)
		{
			if (temp->getData() == val)
			{
				return true;
			}
			else if (val < temp->getData())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}
		return false;
	}
	int FindMax(Node* temp)
	{
		if (temp->getRight() == NULL)
		{
			return temp->getData();
		}
		FindMax(temp->getRight());
	}
	int FindMin(Node* temp)
	{
		if (temp->getLeft() == NULL)
		{
			return temp->getData();
		}
		FindMin(temp->getLeft());
	}
	int countItems(Node* temp, int n)
	{
		if (temp == NULL)
		{
			return n;
		}
		n++;
		n = countItems(temp->getLeft(), n);
		return countItems(temp->getRight(), n);
	}
	int SumOfItems(Node* temp, int n)
	{
		if (temp == NULL)
		{
			return n;
		}
		n += temp->getData();
		n = SumOfItems(temp->getLeft(), n);
		return SumOfItems(temp->getRight(), n);
	}
	void Delete(int key)
	{
		bool flag = false;
		Node* temp = Root;
		Node* p = Root;
		if (Root == NULL)
		{
			cout << "Tree is Empty..." << endl;
			return;
		}
		while (temp != NULL)
		{
			if (temp->getData() == key)
			{
				flag = true;
				break;
			}
			else if (key < temp->getData())
			{
				p = temp;
				temp = temp->getLeft();
			}
			else
			{
				p = temp;
				temp = temp->getRight();
			}
		}
		if (flag)
		{
			if ((temp->getRight() == NULL) && (temp->getLeft() == NULL))
			{
				if (temp == Root)
				{
					Root = NULL;
				}
				else if (p->getRight() == temp)
				{
					p->setRight(NULL);
				}
				else
				{
					p->setLeft(NULL);
				}
				delete temp;
			}
			else if ((temp->getLeft() != NULL) && (temp->getRight() != NULL))
			{
				//FOR 2 CHILDS
			}
			else
			{
				if (temp->getRight() != NULL)
				{
					if (temp == Root)
					{
						Root = temp->getRight();
					}
					else if (p->getLeft() == temp)
					{
						p->setLeft(temp->getRight());
					}
					else
					{
						p->setRight(temp->getLeft());
					}
					temp->setRight(NULL);
					delete temp;
				}
				else
				{
					if (temp == Root)
					{
						Root = temp->getLeft();
					}
					else if (p->getLeft() == temp)
					{
						p->setLeft(temp->getLeft());
					}
					else
					{
						p->setRight(temp->getRight());
					}
					temp->setLeft(NULL);
					delete temp;
				}
			}
		}
		else
		{
			cout << "Value Not Found...." << endl;
		}
	}
	void FindParent(int key)
	{
		bool flag = false;
		Node* temp = Root;
		Node* p = Root;
		if (Root == NULL)
		{
			cout << "Tree is Empty..." << endl;
			return;
		}
		while (temp != NULL)
		{
			
			if (temp->getData() == key)
			{
				flag = true;
				break;
			}
			else if (key < temp->getData())
			{
				p = temp;
				temp = temp->getLeft();
			}
			else
			{
				p = temp;
				temp = temp->getRight();
			}
		}
		if (flag)
		{
			if (temp == Root)
			{
				cout << "Already the Root No Parent Exist.." << endl;
				return;
			}
			else
			{
				cout << "Parent of (" << temp->getData() << ")  = " << p->getData() << endl;
			}
		}
		else
		{
			cout << "Value Not Found ..." << endl;
		}
	}
};

void main()
{
	BST t1;
	int val;
	t1.Insert(10);
	t1.Insert(5);
	t1.Insert(15);
	t1.Insert(8);
	t1.Insert(3);
	t1.Insert(11);
	t1.Insert(20);
	cout << "PRE-ORDER : ";
	t1.DisplayPre(t1.getRoot());
	cout << endl << "IN-ORDER : ";
	t1.DisplayIn(t1.getRoot());
	cout << endl << "POST-ORDER : ";
	t1.DisplayPost(t1.getRoot());
	cout << endl << "NUM OF Items :" << t1.countItems(t1.getRoot(), 0) << endl;
	cout << "Sum : " << t1.SumOfItems(t1.getRoot(), 0) << endl;
	cout << "MAX : " << t1.FindMax(t1.getRoot()) << endl;
	cout << "MIN : " << t1.FindMin(t1.getRoot()) << endl;
	cout << "Enter Value to Search : ";
	cin >> val;
	if (t1.Search(val))
	{
		cout << "FOUND VALUE " << val << endl;
	}
	else
	{
		cout << "VALUE NOT FOUND ...." << endl;
	}
	cout << "Enter Value : ";
	cin >> val;
	t1.FindParent(val);
}