#include <iostream>

using namespace std;

//Partially implmented linked list for practice

struct node
{
int age; 	  // D.O.B. would be better
node *next; 	     // Pointer to next node

};

class Single_list {
public:

    node *head;
    Single_list(){
      head=NULL;

    }
    //~Single_list();
    //int size() const;
    //bool empty() const;
    node* front(){
        return head;
    }
    //int back() const;
    //node *tail() const;
    //int count( int const & ) const;
    void push_front( node *a ){
        a->next=head;
        head=a;
    }

    void printall(){
        node* temp;
        temp=head;
        while(temp!=NULL)
        {
         cout<< temp->age << endl;
         temp=temp->next;
        }
    }
    void push_back( node* a ){
        node* temp=head;
        node* temp2;

        while(temp!=NULL)
        {
         temp2=temp;
         temp=temp->next;
        }
        temp2->next=a;
    }
    int pop_front(){
        int x=head->age;
        head=head->next;
        return x;

    }
    //int erase( int const & );
};

int main()
{
    node* x=new node;
    x->age=27;

    node* n1=new node;
    n1->age=11;

    node* n2=new node;
    n2->age=55;

    Single_list li;



    li.push_front(x);
    li.push_front(n1);
    li.push_back(n2);


    //int t=li.pop_front();
    li.printall();




    return 0;
}

