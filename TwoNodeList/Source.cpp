#include <iostream>
#include "FunTwo.h"

int main()
{
	setlocale(LC_ALL,"ru");
	Node* head = new Node;
	Node* tail = new Node;
	init(head, tail);
	appendInBegin(head, tail);
	Print(head, tail);
	cout << endl;
	SortFIO(head, tail);
	Print(head, tail);
}