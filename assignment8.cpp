#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class node
{
public:
    float time;
    float duration;
    node *next;
    bool isbooked;
    node(float x, float y, bool booked = false)
    {
        time = x;
        next = nullptr;
        duration = y;
        isbooked = booked;
    }
};
node *makeschedule()
{
    node *head = new node(10.00, 1.00);
    node *temp = head;
    float count = 11.00;
    while (count <= 17.00)
    {
        if (count == 13.00)
        {
            count += 1.00;
            continue;
        }
        node *newnode = new node(count, 1.00);
        temp->next = newnode;
        count += 1.00;
        temp = newnode;
    }
    return head;
}
void displayschedule(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << fixed << setprecision(2) << temp->time << " to " << temp->time +temp->duration << " : " << (temp->isbooked ?"booked":"free") << endl;
        temp = temp->next;
    }
}
void makeappointment(float time,float duration , node *head)
{
    node *temp = head;
    node *prev=nullptr;
    while (temp)
    {
        if (temp->time == time)
        {
            if (!temp->isbooked)
            {
                temp->isbooked = true;
                temp->duration=duration;
                break;
            }
            else
            {
                cout <<fixed<<setprecision(2)<< "the slot is already booked from "<<temp->time <<" to "<<temp->time+temp->duration << endl;
                break;
            }
        }
        prev=temp;
        temp = temp->next;
    }
    node *newnode= new node(time,duration,true);
    prev->next=newnode;
    cout << "Appointment booked from " << fixed << setprecision(2) << newnode->time << " to " << newnode->time + newnode->duration << endl;
}
int main()
{
    node *head = makeschedule();
    displayschedule(head);
    float time;
    cout << "enter the time for booking slot" << endl;
    cin>>time;
    float duration;
    cout<<"enter the duration of slot"<<endl;
    cin>>duration;
    makeappointment(time,duration,head);
    displayschedule(head);
    return 0;
}