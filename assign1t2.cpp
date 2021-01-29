// assign1t2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class node {
public:
	int data;
	node* next;
};

node* head = new node();

node* traverse(){
	node* n = new node();
	n = head;
	while(n->next != NULL){
		n = n->next;
	}
	return n;
}

void lastNodeDelete(){
	node* n = new node();
	node* nextOfn = new node();
	n = head;
	nextOfn = n->next;
	while(nextOfn->next != NULL){
		n = n->next;
		nextOfn = nextOfn->next;
	}
	n->next = NULL;
}
void deleteAtPos(int pos){
	node* n = new node();
	node* nextOfn = new node();
	n = head;
	nextOfn = n-> next;
	if(pos == 1){
		head = head->next;
	}
	else{
		while(pos > 1){
			n = n-> next;
			nextOfn = nextOfn -> next;
			pos = pos - 1;
		}
		n->next = nextOfn ->next;
	}
}
void printList(node* n) 
{ 
	n = n->next;
    while (n != NULL) { 
		cout << "|"<< n->data << " next node at "<< n->next<<"|"<<"\n"; 
        n = n->next; 
    }
	cout<<"\n";
} 
void insert(int nodeData){
	node* newNode = new node();
	node* n = new node();
	newNode->data = nodeData;
	if(head->next == NULL){
		head->next = newNode;
	}
	else{
		n = traverse();  
		n->next = newNode;
	}
}

void insertAtPosition(int pos,int dat){
	node* newNode = new node();
	node* n = new node();
	n = head;
	newNode->data = dat;
	if(pos == 1){
		newNode->next = head;
		head = newNode;
	}
	else{
		while(pos >= 2){
			n = n->next;
			pos = pos - 1;
		}
		newNode->next = n->next;
		n->next = newNode;
	}
}

int lengthOfList(){
	node* n = new node();
	int len=0;
	n = head;
	while(n->next != NULL){
		len = len + 1;
		n = n->next;
	}
	return len;
}
void modify(int pos, int data){
	node* n = new node();
	n = head;
	if(pos == 1){
		n->data = data;
	}
	else{
		while(pos > 0){
			n = n->next;
			pos = pos - 1;
		}
		n->data = data;		
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{	
	cout << "Linked List" << "\n";
	cout << "Head Node data= " << head->data << " Head Node next address= " << head->next << "\n";

	int choice, nodeData, l;
	do{
		cout<<"Select Operation:-" << "\n";
		cout<<"1. Insert" << "\n";
		cout<<"2. Delete" << "\n";
		cout<<"3. Insert at given position" << "\n";
		cout<<"4. Delete at given position" << "\n";
		cout<<"5. Modify value at given position" << "\n";
		cout<<"6. Print" << "\n";
		cout<<"7. Exit" << "\n";
		cout<<"Enter your choice:-";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout<< "Enter Node data content:-";
				cin>> nodeData;
				insert(nodeData);
				cout<< "New Node added."<< "\n";
				break;
			case 2:
				if(head->next == NULL){
					cout<<"No elements in the list."<<"\n";
					break;
				}
				cout<<"Deleting last node."<<"\n";
				lastNodeDelete();
				cout<<"Deleted."<<"\n";			
				break;
			case 3:
				int position,data;
				cout<<"Enter the position at which to enter new element:-";
				cin>> position;
				cout<< "Enter Node data content:-";
				cin>> data;
				insertAtPosition(position,data);
				cout<<"Node inserted at given position."<<"\n";
				break;
			case 4:
				if(head->next == NULL){
					cout<<"No elements in the list."<<"\n";
					break;
				}
				int posit;
				cout<<"Enter the position to be deleted:-";
				cin>> posit;
				deleteAtPos(posit);
				cout<<"Element deleted from given position."<<"\n";
				break;
			case 5:
				if(head->next == NULL){
					cout<<"No elements in the list."<<"\n";
					break;
				}
				int pos,dat;
				cout<<"Enter Position to modify:-";
				cin>>pos;
				l = lengthOfList();
				if(pos > l){
					cout<<"The value of position is greater than elements in list.\n";
					break;
				}
				cout<<"Enter the new data value:-";
				cin>>dat;
				modify(pos,dat);
				cout<<"The list is modified."<<"\n";
				break;
			case 6:
				if(head->next == NULL){
					cout<<"No elements in the list."<<"\n";
					break;
				}
				printList(head);
				break;
			default:
				cout<< "Exiting the program.";
				break;


		}

	}while(choice != 7);


	cin.get();
	return 0;
}