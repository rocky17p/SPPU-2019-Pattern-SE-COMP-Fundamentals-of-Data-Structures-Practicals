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
void bookseats(int row,vector<int>seatnos){
        for (int seatno : seatnos)
    {

        node *current = rows[row - 1];
        bool found = false;
        do
        {
            if (current->seatno == seatno)
            {
                found = true;
                if (!current->isbooked)
                {
                    current->isbooked = true;
                    cout << "seat " << seatno << " row " << row << " is booked" << endl;
                }
                else
                {
                    cout << "the seat is already booked" << endl;
                }
                break;
            }
            current = current->next;
        } while (current != rows[row - 1]);
        if (!found)
        {
            cout << "seat not found" << endl;
        }
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
int main () {
    maketheater();
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

            vector<int> seatnos;
            cout << "enter the row no(1-10)" << endl;
            cin >> rowno;
            int seats;
            cout << "enter the no of seats to book" << endl;
            cin >> seats;
            for (int i = 0; i < seats; i++)
            {
                cout << "enter the seat number(1-7):" << endl;
                cin >> seatno;
                seatnos.push_back(seatno);
            }
            bookseats(rowno, seatnos);
            break;
        }
        case 2:
            cout << "enter the row no(1-10)" << endl;
            cin >> rowno;
            cout << "enter the seat number(1-7):" << endl;
            cin >> seatno;
            cancelseat(rowno, seatno);
            break;
        case 3:
            displayseats();
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