#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class tree {
    private:
        int element;
        tree *parent_node;
        list<tree*> children;
    public:
        tree( int const &obj, tree *p=NULL ):element( obj ),parent_node( p ) {}
        int retrieve() const{return element;}
        tree *parent() const{return parent_node;}
        int degree() const{return children.size();}
        bool is_root() const{return (parent()==NULL);}
        bool is_leaf() const{return ( degree() == 0 );}
        tree *child( int n ) {
		    if ( n < 0 || n >=degree() ) { return NULL;}
		    list<tree*>::iterator it=children.begin();
            for (int i=1; i < n; i++) it++;
    	    return *it;
		}

        void insert( int const & obj ){children.push_back( new tree( obj, this ) );}
        void insert( tree * m ){
                if ( !m->is_root() ) {
                    m->detach();
                }

            m->parent_node = this;
            children.push_back( m );
        }


        void detach(){
            if ( is_root() ) return;
            parent()->children.remove( this );

            parent_node = NULL;
        }

    int size()  {
        int s = 1;
        for (list<tree*>::iterator it=children.begin(); it != children.end(); ++it){
            s += (*it)->size();
        }

        return s;
    }

    int height() {
        int h = 0;
        for (list<tree*>::iterator it=children.begin(); it != children.end(); ++it){
            h = max(h, 1+(*it)->height());
        }
        return h;
    }

    void dfs()  {

        for (list<tree*>::iterator it=children.begin(); it != children.end(); ++it){
            (*it)->dfs();
        }

        cout << retrieve() << endl;

    }

    void preorder(){
        stack<tree*> st;

        tree* top=this;

        while(top!=NULL){
            cout << top->retrieve() << endl;
            for (list<tree*>::reverse_iterator it=top->children.rbegin(); it != top->children.rend(); ++it){
                st.push(*it);
            }
            top=st.top();
            st.pop();

        }

    }

    void bft(){
        queue<tree*> qu;
        qu.push(this);


        while(!qu.empty()){
            tree* node=qu.front();
            qu.pop();
            cout << node->retrieve() << endl;
            for (list<tree*>::iterator it=node->children.begin(); it != node->children.end(); ++it){
                qu.push(*it);
            }


        }

    }


};


int main()
{
    tree t(10);
    t.insert(12);
    t.insert(14);
    tree* c1=t.child(0);
    c1->insert(45);
    c1->insert(55);
    tree* c2= t.child(1);
    c2->insert(34);
    c2->insert(90);
    c2->insert(198);

    //cout <<  t.size()<< endl;
    t.dfs();
    //t.bft();
    //t.preorder();
    //t.postorder();
    return 0;
}
