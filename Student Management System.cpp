#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
	Node* next;
};

Node* head = new Node();

bool check(int x);
void Insert(int roll, string Name, string Dept, int Marks);
void Search(int roll);
int Delete(int roll);
void Display();

int main()
{
	head = NULL;
	string Name, Dept;
	int Roll, Marks;
	int opt;

do{
		cout <<endl;
    	cout <<"-=-=-=-=-=-=-=-=[ Student Record Management System ]=-=-=-=-=-=-=-=-" <<endl;
		cout <<" Please input a number to perform any of the operation:" <<endl;
		cout <<"\n\t\t(1) -> Create a New Record" <<endl;
		cout <<"\t\t(2) -> Delete a Record" <<endl;
		cout <<"\t\t(3) -> Search a Student Roll No." <<endl;
		cout <<"\t\t(4) -> Display All the Students Record" <<endl;
		cout <<"\t\t(5) -> Clear the Screen" <<endl;
		cout <<"\t\t(0) -> Exit"<<endl<<endl;
		cout <<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;	
		cout <<endl <<"Enter your Choice ->> ";
		cin>> opt;
    
    switch (opt) 
	{
    case 1:
    	cout <<endl;
	    cout <<"Enter the Name of Student: ";
		cin >>Name;
		cout <<"Enter the Roll Number of Student: ";
		cin >>Roll;
		cout <<"Enter The Department of Student: ";
		cin >>Dept;
		cout <<"Enter The Total Marks of Student: ";
		cin >>Marks;
		Insert(Roll, Name, Dept, Marks);
      	break; 
    case 2:
    	cout <<"\nEnter the Roll Number of Student you would like to Delete: ";
		cin >>Roll;
		Delete(Roll);
    	break;
    case 3:
    	cout <<"\nEnter the Roll Number of Student you would like to Search: ";
		cin >> Roll;
		Search(Roll);
    	break;
    case 4:
    	Display();
    	break;
    case 5:
    	system ("CLS");
    	break;
    case 0:
    	cout<<"You have Exited" <<endl;
      	break;
    default:
    	cout<<"Enter Proper Option number" <<endl;
	}
  	}while (opt != 0);
    return 0;
}

bool check(int x)
{
	if(head == NULL)
	{	
		return false;
	}
	Node *temp = new Node;
	temp = head;

	while(temp != NULL) 
	{
		if (temp->roll == x)
		{	
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void Insert(int roll, string Name, string Dept, int Marks)
{
	if(check(roll)) 
	{
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<" ** This Roll Number Already Exist in the Record **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		return;
	}

	Node *newNode = new Node();
	newNode->roll = roll;
	newNode->Name = Name;
	newNode->Dept = Dept;
	newNode->Marks = Marks;
	newNode->next = NULL;

	if(head == NULL || (head->roll >= newNode->roll)) 
	{
		newNode->next = head;
		head = newNode;
	}

	else {
		Node *current = head;
		while (current->next != NULL && current->next->roll < newNode->roll) 
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	
	cout <<endl;
	cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout << " ** A New Student Record has been Inserted **" <<endl;
	cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
}

int Delete(int roll)
{
	Node *temp = head;
	Node *temp1 = NULL;

	if(temp != NULL && temp->roll == roll) 
	{
		head = temp->next;
		delete temp;
		
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<"** Record for Roll No." <<roll <<" has been Deleted **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		return 0;
	}

	while(temp != NULL && temp->roll != roll) 
	{
		temp1 = temp;
		temp = temp->next;
	}
	if(temp == NULL) 
	{
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<"** The Record is Empty so there's Nothing to be Deleted **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		return -1;
		
		temp1->next = temp->next;

		delete temp;
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<"** The Record has been Deleted **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;

		return 0;
	}
}

void Search(int roll)
{
	if(!head)  //if head == NULL
	{
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<" ** The Student Record is Empty **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		return;
	}

	else 
	{
		Node *srch = head;
		while (srch) {
			if (srch->roll == roll) 
			{
				cout <<endl;
				cout <<"--=============(~)=============--"<<endl;
				cout <<"  Displaying Student Information\n"<<endl;
				cout << "Name: \t\t" <<srch->Name <<endl;
				cout << "Roll Number: \t" <<srch->roll <<endl;
				cout << "Department:\t"	<<srch->Dept <<endl;
				cout << "Marks: \t\t" << srch->Marks <<endl;
				cout <<"--=============================--"<<endl;
				return;
			}
			srch = srch->next;
		}

		if(srch == NULL)
		{
			cout <<endl;
			cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout <<"** The Roll Number you're Searching is not Available **" <<endl;
			cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		}
	}
}

void Display()
{
	Node *temp = head;
	if (temp == NULL) 
	{
		cout <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout <<"** The Record is not Available **" <<endl;
		cout <<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	}
	else 
	{
		cout <<endl;
		cout <<"--=======================(~)=======================--"<<endl;
		cout << "RollNo.\t\tName\t\tDept.\t\tMarks"<<endl;

		while(temp != NULL) 
		{
			cout << temp->roll << "\t\t";
			cout << temp->Name << "\t\t";
			cout << temp->Dept << "\t\t";
			cout << temp->Marks << endl;
			temp = temp->next;
		}
		cout <<"--=================================================--"<<endl;
	}
}
