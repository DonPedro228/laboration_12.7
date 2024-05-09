#include <iostream>
using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};



void push(Elem*& top, Info value);
void inputList(Elem*& top);
void printList(Elem* top);
void setOperations(Elem* list1, Elem* list2);

int main() {
    Elem* list1 = NULL;
    Elem* list2 = NULL;

	cout << "Input -1 if you want stop input: "  << endl;
	inputList(list1);

    cout << "Input -1 if you want stop input: " << endl;
    inputList(list2);

	cout << "List1: " << endl;
	printList(list1);

    cout << "List2: " << endl;
    printList(list2);

    setOperations(list1, list2);


	return 0;
}

void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->link = top; 
	top = tmp; 
}

void inputList(Elem*& top)
{
	Info value;
	while (true)
	{
		cin >> value;
		if (value == -1) 
			break;
		push(top, value); 
	}
}

void printList(Elem* top)
{
	Elem* current = top;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;
}


void setOperations(Elem* list1, Elem* list2)
{
    cout << "Theoretical-multiple union of lists: " << endl;
    Elem* current1 = list1;
    while (current1 != NULL)
    {
        cout << current1->info << " ";
        current1 = current1->link;
    }
    Elem* current2 = list2;
    while (current2 != NULL)
    {
        Elem* current1 = list1;
        bool exists = false;
        while (current1 != NULL)
        {
            if (current1->info == current2->info)
            {
                exists = true;
                break;
            }
            current1 = current1->link;
        }
        if (!exists)
            cout << current2->info << " ";
        current2 = current2->link;
    }
    cout << endl;

    cout << "Theoretical multiple difference of lists: " << endl;
    current1 = list1;
    while (current1 != NULL)
    {
        bool exists = false;
        current2 = list2;
        while (current2 != NULL)
        {
            if (current1->info == current2->info)
            {
                exists = true;
                break;
            }
            current2 = current2->link;
        }
        if (!exists)
            cout << current1->info << " ";
        current1 = current1->link;
    }
    cout << endl;

    cout << "Theoretical-multiple intersection of lists: " << endl;
    current1 = list1;
    while (current1 != NULL)
    {
        current2 = list2;
        while (current2 != NULL)
        {
            if (current1->info == current2->info)
            {
                cout << current1->info << " ";
                break;
            }
            current2 = current2->link;
        }
        current1 = current1->link;
    }
    cout << endl;
}