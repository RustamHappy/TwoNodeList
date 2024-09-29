#pragma once

#include<string>

using namespace std;

struct Node
{
	string FIO;
	struct Address
	{
		string street;
		string numHome;
		string numApart;
	};
	Address address;
	string numberPhone;
	string balance;
	Node* next;
	Node* pred;
};

void init(Node*& head, Node*& tail);

void appendInBegin(Node*& head, Node*& tail);

void PredBeg(Node*& head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance);

void NextBeg(Node* head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance);

void PredEnd(Node* head, Node* tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance);

void NextEnd(Node* head, Node*& tail, string FIO, string street, string numHome, string numApart, string numberPhone, string balance);



void DelAll(Node*& head, Node*& tail);

void DelHead(Node*& head, Node* tail);

void DelTail(Node* head, Node*& tail);

void DelPredFindElem(Node*& head, Node* tail);

void DelNextFindElem(Node*& head, Node* tail);

void DelPredElem(Node*& head, Node* tail);

void DelNextElem(Node*& head, Node* tail);

void DelAllElem(Node*& head, Node* tail);


Node* Search(Node*& head, Node* tail);

void Print(Node* head, Node* tail);

bool isEmpty(Node*& head, Node* tail);

void swap(Node*& a, Node*& b);



void SortFIO(Node*& head, Node*& tail);

void DelLowBalance(Node*& head, Node* tail);

void PrintTwoMorePhone(Node*& head, Node* tail);

void SortNumberPhone(Node*& head, Node* tail);

void FindPhoneNetwork(Node*& head, Node* tail);

void SortBalance(Node*& head, Node* tail);

void PrintLessBalance(Node*& head, Node* tail, int balance);

void PrintTwoMorePhoneAndPhoneNetwork(Node*& head, Node* tail);