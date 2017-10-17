
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MaxNodes = 100;
struct node
{
	bool linked;
	int value;
	node* LinkedNodes[MaxNodes];
	int count = 0;
};

node* NodeArray[MaxNodes] = {};
int numNodes = 0;

void createNode(int aVal)
{
	if (NodeArray[aVal])
	{
		return; //already exists
	}
	else
	{
		NodeArray[aVal] = new node{ false, aVal ,nullptr,0 };
	}
}


void insertLink(node* aSource, node* aNode)
{
	aSource->LinkedNodes[aSource->count] = aNode;
	aSource->count++;
}

bool OpenFile()
{
	ifstream input;
	double startTime;
	char filename[20];
	cout << "Enter File name:" << endl;
	gets_s(filename);

	input.open(filename);
	if (!input)
	{
		cout << "Error : Failed to open the file!";
		return false;
	}

	input >> numNodes;
	cout << numNodes << endl;

	for (int i = 0; i < MaxNodes; i++)
	{
		int node1, node2;
		input >> node1 >> node2;
		createNode(node1);
		createNode(node2);
		insertLink(NodeArray[node1], NodeArray[node2]);
		insertLink(NodeArray[node2], NodeArray[node1]);
	}

	return true;
}

void printNodes()
{
	for (int i = 0; i < numNodes; i++)
	{
		for (int j = 0; j < NodeArray[i]->count; j++)
		{
			if (!NodeArray[i]->LinkedNodes[j]->linked)
			{
				cout << NodeArray[i]->value << " " << NodeArray[i]->LinkedNodes[j]->value << endl;
				NodeArray[i]->LinkedNodes[j]->linked = true;
			}
		}
	}

}

int main()
{
	if (OpenFile())
	{
		printNodes();
	}

	return 0;
}