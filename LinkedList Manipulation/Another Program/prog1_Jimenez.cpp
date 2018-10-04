//Benjamin Jimenez
#include <iostream>
using namespace std;

template <class T>
class singleList
{
private:
	struct node
	{
		T data; //data
		node * next;    //initialuze node
	}   *head;  //initialize head

public:
	singleList();
	~singleList();
    void size();    //finds the size of the list
    void print();   //prints the list
    bool isEmpty(); //checks if list is empty
    bool search(T d);   //checks fro specific number in list
	void add(T d);  //adds number to the list
	void remove(T d);   //removes number from the list
};

template <class T>
singleList<T>::singleList()
{
	head = NULL;    //initializes head of linked list
}

template <class T>
singleList<T>::~singleList()
{
	node *p, *q;    //node for head and temp
	p = head;
	if(p == NULL) return;   //if heads null exit
	while(p) {
		q = p->next;    //move to next link
		delete p;
		p = q;
	}
}

template <class T>
void singleList<T>::size()
{
	node *p;    //for head
    int count=0;    //count will have value of size
	if(head == NULL) return;
	p = head;
	while(p) {
        p=p->next;  //p = next node
        count++;    //count rises
    }
    cout << "The size is " << count << endl;    //displays count
}

template <class T>  //DONE
void singleList<T>::print()
{
	node *p;    //for head
	if(head == NULL) return;    //if heads empty, leave
	p = head;
	while(p) {
			cout << p->data << ' '; //print values
		p = p->next;    //next node
	}
}

template <class T>  //DONE
void singleList<T>::add(T d)
{
	node *p, *q;
    /* creates new node to store new value */
	if(head == NULL) {
		head = new node;    //creates new node
		head->data = d;
		head->next = NULL;  //intitializes next
		return;
	}
	p = head;
	while(p->next != NULL)
		p = p->next;
	q = new node;
	q->data = d;    //stores new data
	q->next = NULL;
	p->next = q;
}

template <class T>  //DONE
void singleList<T>::remove(T d)
{
	node *p, *q;
	if(head == NULL) return;    //if list is empty
	p = head;
	while(p) {
		if(p->data == d) {  //finds value
			q->next = p->next;  //tmp value
			delete p;   //deletes value
			return;
		}
		q = p;
		p = p->next;    //next location
	}
}

template <class T>
bool singleList<T>::search(T d)
{
	node *p;
	if(head == NULL) return false;  //if list is empty
	p = head;
	while(p != NULL) {
		if(p->data == d) {  //if value is found
			return true;
		}
		p = p->next;    //next location
	}
    return false;
}

template <class T>
bool singleList<T>::isEmpty()
{
	if(head == NULL)    //list is empty
    return true;
    else
	return false;
}


int main()
{
    int choice, tmp;
	singleList<int> num;
    /* stores numbers 1-10 into list at beginning */
    for(tmp=1;tmp<=10;tmp++){
        num.add(tmp);
    }
    cout << "Numbers 1-10 have been automatically added to the list.\n";
    /* Menu for different options */
        do
        {
            cout << "  3110 Linked List Menu\n";
            cout << "  ====================================\n";
            cout << "  1.  Return Size of List\n";
            cout << "  2.  Print Linked List\n";
            cout << "  3.  Check if List is Empty\n";
            cout << "  4.  Search\n";
            cout << "  5.  Add a Value\n";
            cout << "  6.  Remove a Value\n\n";
            cout << "  0.  Exit\n";
            cout << "  ====================================\n";
            cout << "  Enter your choice: ";
            cin >> choice;
            cout << endl;

            switch (choice)
            {
                case 0:
                    cout << "Have a great day!\n"; break;
                case 1:
                    num.size(); //size function
                    break;

                case 2:
                    num.print();    //print function
                    cout << "\n";
                    break;
                case 3: //checks if list is empty
                    if(num.isEmpty() == true) cout <<"The List is empty.\n";
                    else cout << "The list is not empty.\n";
                    break;

                case 4: //searches for number
                    cout << "Enter number you would like to search for: ";
                    cin >> tmp;
                    if(num.search(tmp) == true) cout << tmp << " is in the list.\n";
                    else cout << tmp << " is not in the list.\n";
                    break;

                case 5: //adds number
                    cout << "Enter the number you would like to add: ";
                    cin >> tmp;
                    if(num.search(tmp) == true){    //checks if in list
                    cout << tmp << " is already in the list.\n";
                    break;
                    }
                    num.add(tmp);   //add number function
                    break;

                case 6: //removes number
                    cout << "Enter the number you would like to remove: ";
                    cin >> tmp;
                    if(num.search(tmp) == false){   //checks if in list
                    cout << tmp << " is not in the list.\n";
                    break;
                    }
                    num.remove(tmp);    //remove number function
                    break;

                default: cout << choice << "is not a valid menu item.\n";
                    cout << endl;
            }

        }while (choice != 0);   //user chooses to exit with 0

	return 0;
}
