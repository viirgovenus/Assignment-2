
#include <iostream>
#include <stdlib.h>
#include <singleLinkedList.h>

using namespace std;

// Defining a class for a node in a single linked list
class Node {
public:
int info; // Data stored in the node
Node* next;}; // Pointer to next node in the list

// Defining a class for a single linked list inheriting from Node
class List:public Node {
Node *first, *last; // Pointer to the next Node in the list

public: // Constructor to initialize list with null pointers

List() {
first = NULL;
last = NULL;
}

void create(); // Function to create a new node and add it to the end of the list
void insert(); // Function to insert a new node at ta specified position in the list
void delet(); // Function to delete a node from a specified position in the list
void display(); //Function to display the elements of the list
void search(); // Function to search for a specific element in the list
};

// Implementation of create() function
void List::create() {
Node *temp;
temp = new Node;
int n;
cout << "\nPlease enter an element:";
cin >> n;
temp -> info = n;
temp -> next = NULL;

if (first == NULL) {

first=temp;

last=first;

}
else {
last -> next = temp;
last = temp;
}
}

// Implementation of insert() function
void List::insert() {
Node *prev, *cur;
prev = NULL;
cur = first;
int count = 1, pos, ch, n;
Node *temp = new Node;

cout << "\nPlease enter an element:";
cin >> n;

temp -> info = n;
temp -> next = NULL;

cout << "\nWould you like to insert as...\n1:First node?\n2:Last node?\n3:In between the first and last nodes?";
cout << "\nPlease enter your choice:";

cin >> ch;

switch(ch) {

case 1:
temp -> next = first;
first = temp;
break;

case 2:
last -> next = temp;
last = temp;
break;

case 3:
cout << "\nAt what position would you like to insert the element?:";
cin >> pos;

while (count != pos) {
prev = cur;
cur = cur -> next;
count++;
}

if (count==pos) {
prev -> next = temp;
temp -> next = cur;
}

else
cout << "\nUnable to insert element.";
break;}
}

// Implementation of delet() function
void List::delet() {
Node *prev = NULL, * cur = first;
int count = 1, pos, ch;
cout << "\nDelete\n1: At the first node?\n2: At the last node?\n3: In between the first and last nodes? ";
cout << "\nPlease enter your choice:";
cin >> ch;

switch(ch) {

case 1:
if (first != NULL) {
cout << "\nThe deleted element is: "<< first -> info;
first = first -> next;
}

else
cout << "\nUnable to delete element.";
break;

case 2:
while (cur != last) {
prev = cur;
cur = cur -> next;
}
if (cur==last) {
cout << "\nThe deleted element is: " << cur -> info;
prev -> next = NULL;
last = prev;
}
else
cout << "\nUnable to delete element.";
break;

case 3:
cout << "\nPlease enter the position for deletion:";
cin >> pos;
while(count != pos) {
prev = cur;
cur = cur -> next;
count++;
}
if (count == pos) {
cout << "\nThe deleted element is: " << cur -> info;
prev -> next = cur -> next;
}
else
cout << "\nUnable to delete element";
break;
}
}

//Implementation of display() function
void List::display() {
Node *temp = first;
if (temp == NULL) {
cout << "\nThe list is empty.";
}
while (temp != NULL) {
cout << temp -> info;
cout << "-->";
temp = temp -> next;
}
cout << "NULL";
}

// Implementation of search() function
void List::search(){
int value, pos = 0;
bool flag = false;
if(first == NULL) {
cout << "The list is empty";
return;
}
cout << "Please enter the value to be searched:";
cin >> value;
Node *temp;
temp = first;
while(temp != NULL) {
pos++;
if(temp -> info == value){
flag = true;
cout << "Element" << value << "is found at " << pos << " position.";
return;
}
temp = temp -> next;
}
if(!flag) {
cout << "Element" << value << " was not found in the list.";
}
}

// Main function to interact with the single linked list
int main() {

List l;
int ch;
while(1){

cout << "\n**** WELCOME TO THE SINGLE LINKED LIST ****";
cout << "\n1: Create your list\n2: Insert an element\n3: Delete an element\n4: Search for an element\n5: Display your list\n6: Exit\n";
cout << "\nPlease enter your choice:";
cin >> ch;

switch(ch) {

case 1:
l.create();
break;

case 2:
l.insert();
break;

case 3:
l.delet();
break;

case 4:
l.search();
break;

case 5:
l.display();
break;

case 6:
return 0;
}
}
return 0;
}

