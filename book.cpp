#include<iostream>
#include<string.h>
using namespace std;

struct node 
{
	string label;
	int ch_count;
	struct node *child[10];		
} * root;

class GT
{
	public:
	void create_tree();
	void display(node*r1);
	
	GT()
	{
		root = NULL;
		
	}
};

void GT::create_tree()
{
	int tbook,tchapter, i, j, k;
	root = new node;
	cout << "Enter the name of book : ";
	cin.get();
	getline(cin,root->label);
	cout << "Enter the number of chapter in book : ";
	cin >> tchapter;
	root->ch_count = tchapter;
	for (i = 0; i < tchapter; i++)
	{
		root->child[i] = new node;
		cout << "Enter the name of chapter " << i + 1 << " : ";
		cin.get();
		getline(cin, root->child[i]->label);
		cout << "Enter number of section in Chapter : " << root->child[i]->label << " : ";
		cin >> root->child[i]->ch_count;
		for (j = 0; j< root->child[i]->ch_count; j++)
		{
			root->child[i]->child[j] = new node;
			cout << "Enter the name of section " << j + 1 << " : ";
			cin.get();
			getline(cin, root->child[i]->child[j]->label);
			
		}		
		
	} 
}

void GT :: display(node *r1)
{
	int i, j, k, tchapters;
	if (r1 != NULL)
	{
		cout << "\n-----Book Hierarchy---";
		cout << "\n Book title : " << r1->label;
		tchapters = r1->ch_count;
		for (i = 0; i < tchapters; i++)
		{
			cout << "\nChapter " << i + 1;
			cout << " : " << r1->child[i]->label;
			cout << "\nSections : ";
			for (j = 0; j < r1->child[i]->ch_count; j++)
			{
				cout << "\n" << r1->child[i]->child[j]->label;
			}
		}
	}
	cout << endl;
}

int main()
{
	int Choice;
	GT gt;
	while (1)
	{
		cout << "----------------------" << endl;
		cout << "Book Tree Creatiom" << endl;
		cout << "----------------------" << endl;
		cout << "1.Create" << endl;
		cout << "2.Display" << endl;
		cout << "3.Quit" << endl;
		cout << "Enter Your Choice : ";
		cin >> Choice;
		switch (Choice)
		{
		case 1:	
			gt.create_tree();
		case 2:
		    gt.display(root);
		case 3:
		    cout << "Thanks for using this program !!! ";
			exit(1);
		default:
		    cout << "Wrong Choice!!!" << endl;		
		}
	}
	return 0;
}
