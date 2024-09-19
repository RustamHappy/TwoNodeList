#pragma once

#include<string>

using namespace std;

struct Node 
{
	string FIO;
	struct address
	{
		string street;
		int numHome;
		int numApart;
	};
	int numberPhone;
	int balance;
	Node* next;
	Node* pred;
};

void init(Node*& head);

void PredBeg(Node*& head, string FIO, string street, int numHome, int numApart, int numberPhone, int balance);

void NextBeg(Node* head, string FIO, string street, int numHome, int numApart, int numberPhone, int balance);

void PredEnd(Node* head, string FIO, string street, int numHome, int numApart, int numberPhone, int balance);

void NextEnd(Node* head, string FIO, string street, int numHome, int numApart, int numberPhone, int balance);



void DelAll(Node*& head);

void DelHead(Node*& head);

void DelPredFindElem(Node*& head);

void DelNextFindElem(Node*& head);

void DelPredElem(Node* temp);

void DelNextElem(Node* temp);

void DelAllElem(Node*& head);


Node* Search(Node* head);

void Print(Node* head);

bool isEmpty(Node* head);



void SortFIO(Node*& head);

void DelLowBalance(Node*& head);

void PrintTwoMorePhone(Node* head);

void SortNumberPhone(Node*& head);

void FindPhoneNetwork(Node*& head);

void SortBalance(Node*& head);

void PrintLessBalance(Node* head, int balance);

void PrintTwoMorePhoneAndPhoneNetwork(Node* head);