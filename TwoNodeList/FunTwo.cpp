#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "FunTwo.h"

using namespace std;

void init(Node*& head, Node*& tail)
{
	head = nullptr;
	tail = nullptr;
}

void appendInBegin(Node*& head, Node*& tail)
{
	setlocale(LC_ALL, "ru");
	string b[5][9] = { {"Шилова", "Эдуарда", "Владленовна", "Светлая", "5", "10", "4536829", "6876437", "50"}, 
					   { "Виноградова", "Людмила", "Никитевна", "Темная", "8", "5", "4654358", "5269854", "150" },
					   { "Белозёрова", "Элеонора", "Геннадьевна", "Серая", "9", "52", "6892535", "1234567", "0" },
					   { "Самсонов", "Елисей", "Сергеевич", "Белоснежка", "53", "8", "4650000", "", "150"},
					   { "Силин", "Борис", "Ефимович", "Гномиков", "92", "6", "9875260", "", "-500" } };
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		Node* temp = new Node;
		temp->FIO = b[i][j] + " " + b[i][j + 1] + " " + b[i][j + 2];
		j += 3;
		temp->address.street = b[i][j];
		j++;
		temp->address.numHome = b[i][j];
		j++;
		temp->address.numApart = b[i][j];
		j++;
		while (b[i][j] != b[i][8])
		{
			if (b[i][j] != "")
			{
				temp->numberPhone += (b[i][j] + "");
			}
			j++;
		}
		temp->balance = b[i][8];
		if (head == nullptr || tail == nullptr)
		{
			head = temp;
			tail = temp;
			temp->next = nullptr;
			temp->pred = nullptr;
		}
		else
		{
			Node* LastEl = head;
			while (LastEl->next != nullptr)
			{
				LastEl = LastEl->next;
			}
			temp->next = nullptr;
			temp->pred = LastEl;
			LastEl->next = temp;
			tail = temp;
		}
		j = 0;
	}
}

void PredBeg(Node*& head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance)
{
	Node* FirstEl = new Node;
	Node* temp = head;
	FirstEl->FIO = FIO;
	FirstEl->address.street = street;
	FirstEl->address.numHome = numHome;
	FirstEl->address.numApart = numApart;
	FirstEl->numberPhone = numberPhone;
	FirstEl->balance = balance;

	FirstEl->pred = nullptr;
	temp->pred = FirstEl;
	FirstEl->next = temp;
	head = FirstEl;
}

void NextBeg(Node* head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance)
{
	Node* FirstEl = head;
	Node* temp = new Node;
	temp->FIO = FIO;
	temp->address.street = street;
	temp->address.numHome = numHome;
	temp->address.numApart = numApart;
	temp->numberPhone = numberPhone;
	temp->balance = balance;

	temp->pred = FirstEl;
	temp->next = FirstEl->next;
	FirstEl->next = temp;
}

void PredEnd(Node* head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance)
{
	Node* LastEl = tail;
	Node* temp = new Node;
	temp->FIO = FIO;
	temp->address.street = street;
	temp->address.numHome = numHome;
	temp->address.numApart = numApart;
	temp->numberPhone = numberPhone;
	temp->balance = balance;

	LastEl->pred->next = temp;
	temp->pred = LastEl->pred;
	temp->next = LastEl;
	LastEl->pred = temp;
}

void NextEnd(Node* head, Node*& tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance)
{
	Node* temp = tail;
	Node* LastEl = new Node;
	LastEl->FIO = FIO;
	LastEl->address.street = street;
	LastEl->address.numHome = numHome;
	LastEl->address.numApart = numApart;
	LastEl->numberPhone = numberPhone;
	LastEl->balance = balance;

	LastEl->pred = temp;
	LastEl->next = nullptr;
	temp->next = LastEl;
	tail = LastEl;
}

void DelAll(Node*& head, Node*& tail)
{
	Node* temp = head;
	Node* DelIt = new Node;
	while (temp != nullptr)
	{
		DelIt = temp;
		temp = temp->next;
		delete DelIt;
	}
	head = nullptr;
	tail = nullptr;
}

void Print(Node* head, Node* tail)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->FIO << " " << temp->address.street << " " << temp->address.numHome << " " << temp->address.numApart << " " << temp->numberPhone << " " << temp->balance << endl;
		temp = temp->next;
	}
}

void swap(Node*& a, Node*& b)
{
	string FIO = a->FIO;
	string street = a->address.street;
	string numHome = a->address.numHome;
	string numApart = a->address.numApart;
	string numberPhone = a->numberPhone;
	string balance = a->balance;

	a->FIO = b->FIO;
	a->address.street = b->address.street;
	a->address.numHome = b->address.numHome;
	a->address.numApart = b->address.numApart;
	a->numberPhone = b->numberPhone;
	a->balance = b->balance;

	b->FIO = FIO;
	b->address.street = street;
	b->address.numHome = numHome;
	b->address.numApart = numApart;
	b->numberPhone = numberPhone;
	b->balance = balance;
}

void SortFIO(Node*& head, Node*& tail)
{
	Node* temp;
	bool check = false;
	while (!check)
	{
		check = true;
		temp = head;

		while (temp->next != nullptr)
		{
			if (temp->FIO > temp->next->FIO)
			{
				check = false;
				swap(temp, temp->next);
			}
			temp = temp->next;
		}
	}
}

