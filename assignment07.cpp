//============================================================================
// Name        : xyz.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<vector>
using namespace std ;
class node{
    public:
    int seatno;
    int row;
    bool isbooked;
    node *next;
    node *prev;
    node(int x,int y,bool booked=false){
        seatno=x;
        row=y;
        isbooked=booked;
        next=nullptr;
        prev=nullptr;
    }
};
        node *rows[10];
class theater{
public:
	void maketheater(){
	    for(int i=0;i<10;i++){
	        node *head= new node(1,i+1);
	        node *temp = head;
	        rows[i]=head;
	        for(int j=2;j<=7;j++){
	            node *nextseat= new node(j,i+1);
	            temp->next= nextseat;
	            nextseat->prev= temp;
	            temp=nextseat;
	        }
	        temp->next=head;
	        head->prev=temp;
	    }
	}
	void displayseats(){
	    for (int i = 0; i < 10; i++)
	    {
	        node *current = rows[i];
	        cout << "Row " << i + 1 << ": ";
	        do
	        {
	            if (!current->isbooked)
	            {
	                cout << current->seatno << " ";
	            }
	            current = current->next;
	        } while (current != rows[i]);
	        cout << endl;
	    }
	}
	void bookseats(int row,int seatnos){
		node *current=rows[row-1];
		int count=0;
		while(current)
		{
			if(!current->isbooked){
				count++;
				current=current->next;
			}
			else if(current->isbooked){
				count=0;
				current=current->next;

			}
			if(count==seatnos){
				break;
			}
		}
		current=current->prev;
		while(count--){
			current->isbooked=true;
			current=current->prev;
		}
	}
	void cancelseat(int row, int seatno)
	{
	    node *current = rows[row - 1];
	    bool found = false;
	    do
	    {
	        if (current->seatno == seatno)
	        {
	            found = true;
	            if (current->isbooked)
	            {
	                current->isbooked = false;
	                cout << "seat" << seatno << "row" << row << " booking cancelled" << endl;
	            }
	            else
	            {
	                cout << "the seat is not booked" << endl;
	            }
	        }
	    } while (current != rows[row - 1]);
	    if (!found)
	    {
	        cout << "seat not found" << endl;
	    }
	}
};
int main () {
	theater t;
    t.maketheater();
    int choice;
    int rowno,seatno;
    do
    {
        cout << "menu" << endl;
        cout << "1.bookseat" << endl;
        cout << "2.cancelbooking" << endl;
        cout << "3.display available seats" << endl;
        cout << "4.exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:{

            cout << "enter the row no(1-10)" << endl;
            cin >> rowno;
            int noseats;
            cout << "enter the no of seats to book" << endl;
            cin >> noseats;

            t.bookseats(rowno,noseats);
            break;
        }
        case 2:
            cout << "enter the row no(1-10)" << endl;
            cin >> rowno;
            cout << "enter the seat number(1-7):" << endl;
            cin >> seatno;
            t.cancelseat(rowno, seatno);
            break;
        case 3:
            t.displayseats();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice enter from(1-4)" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
