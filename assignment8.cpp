#include "iostream"
#include "vector"

using namespace std;

class node
{
public:
	int data;
	node *next;

public:
	node()
	{
		data = 0;
		next = nullptr;
	}
	node(int data1, node *next1)
	{
		data = data1;
		next = next1;
	}
	node(int data1)
	{
		data = data1;
		next = nullptr;
	}
};

node *convertarraytolinkedlist(vector<int> &arr)
{
	if (arr.empty())
		return nullptr;
	node *head = new node(arr[0]);
	node *current = head;
	for (int i = 1; i < arr.size(); i++)
	{
		current->next = new node(arr[i]);
		current = current->next;
	}
	return head;
}

void print(node *head)
{
	node *temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

node *both(node *head1, node *head2)
{
	cout << "Students who like both vanilla and butterscotch are: ";
	node *temp1 = head1;
	node *commonHead = nullptr;
	node *commonTail = nullptr;

	while (temp1)
	{
		node *temp2 = head2;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				node *newNode = new node(temp1->data);
				if (commonHead == nullptr)
				{
					commonHead = newNode;
					commonTail = newNode;
				}
				else
				{
					commonTail->next = newNode;
					commonTail = newNode;
				}
				cout << temp1->data << " ";
				break;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	cout << endl;
	return commonHead;
}

node *either(node *common, node *head1, node *head2)
{
	cout << "Students who like either vanilla or butterscotch but not both are: ";
	node *temp1 = head1;
	node *temp2 = head2;

	while (temp1)
	{
		bool found = false;
		node *temp3 = common;
		while (temp3)
		{
			if (temp1->data == temp3->data)
			{
				found = true;
				break;
			}
			temp3 = temp3->next;
		}
		if (!found)
		{
			cout << temp1->data << " ";
		}
		temp1 = temp1->next;
	}

	while (temp2)
	{
		bool found = false;
		node *temp3 = common;
		while (temp3)
		{
			if (temp2->data == temp3->data)
			{
				found = true;
				break;
			}
			temp3 = temp3->next;
		}
		if (!found)
		{
			cout << temp2->data << " ";
		}
		temp2 = temp2->next;
	}
	cout << endl;
	return nullptr;
}

int count(node *head)
{
	node *temp = head;
	int count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

int main()
{
	int size;
	cout<<"enter the number of students "<<endl;
	cin>>size;
	cout<<"enter the size"<<endl;
	vector<int> arr;
	for(int i=0;i<size;i++){
		int x;
		cout<<"element "<<i<<":";
		cin>>x;
		arr.push_back(x);
	}
	int size1;
	cout<<"enter the number of students "<<endl;
	cin>>size1;
	cout<<"enter the students"<<endl;
	vector<int> arr1;
	for(int i=0;i<size1;i++){
		int x;
		cout<<"element "<<i<<":";
		cin>>x;
		arr1.push_back(x);
	}
	int size2;
	cout<<"enter the number of students "<<endl;
	cin>>size2;
	cout<<"enter the students"<<endl;
	vector<int> arr2;
	for(int i=0;i<size2;i++){
		int x;
		cout<<"element "<<i<<":";
		cin>>x;
		arr2.push_back(x);
	}

	node *head = convertarraytolinkedlist(arr);
	node *head1 = convertarraytolinkedlist(arr1);
	node *head2 = convertarraytolinkedlist(arr2);

	print(head1);
	print(head2);

	node *common = both(head1, head2);
	node *notcommon = either(common, head1, head2);

	int count1 = count(head);
	int count2 = count(head1);
	int count3 = count(head2);
	int count4 = count(common);
	int final=count1 -count2 -count3 +count4;
	cout << "Number of students who like neither vanilla nor butterscotch: " <<final << endl;

	return 0;
}
