#include <iostream>

using namespace std;

struct node{
    double x;
    node* next;
};

class llist{
public:
    node* head;

    llist(){
        head=NULL;
    }

    bool empty(){
        if (head==NULL)
            return true;
        else
            return false;

    }

    void push_front(node* x){
        x->next=head;
        head=x;

    }

    void push_back(node* x){
        node* t=head;

        if(head!=NULL)
        {
        while (t->next!=NULL)
        {
            t=t->next;
        }

        t->next=x;
        }
        else{
            head=x;
        }

    }

    double pop_front(){
        double t=head->x;
        head=head->next;
        return t;

    }



    void printall(){
        node* x=head;

        while (x!=NULL)
        {
            cout << x->x << endl;
            x=x->next;
        }


    }

};


class stack{
public:
    llist ls;
    void push(node* t){
        ls.push_front(t);
    }

    double pop(){
        return ls.pop_front();
    }

    double top(){
        return ls.head->x;
    }

    void printall(){
        ls.printall();
    }
};
class queue{
public:
    llist ls;
    void enqueue(node* t){
        ls.push_back(t);
    }
    double dequeue(){
        return ls.pop_front();
    }
    double front(){
        return ls.head->x;
    }
    void printall(){
        ls.printall();
    }
};
class tree{


};
int main()
{
    //llist li;
    node* n1=new node;
    n1->x=11;

    node* n2=new node;
    n2->x=12;

    node* n3=new node;
    n3->x=13;

    node* n4=new node;
    n4->x=14;


    //li.push_front(n1);
    //li.push_front(n2);
    //li.push_front(n3);
    //li.push_back(n4);

    //cout << "pop --- " << li.pop_front() << endl;


    //li.printall();
//
//    stack si;
//
//    si.push(n1);
//    si.push(n2);
//    si.push(n3);
//    si.push(n4);
//
//
//    si.printall();
//
//    cout << "--------------------------" << endl;
//
//    double t=si.pop();
//    si.printall();


    queue qi;
    qi.enqueue(n1);
    qi.enqueue(n2);
    qi.enqueue(n3);
    qi.enqueue(n4);
    qi.printall();
    qi.dequeue();
    qi.dequeue();
    cout << "----------------------" << endl;

    qi.printall();

    cout << "END" << endl;
    return 0;
}
