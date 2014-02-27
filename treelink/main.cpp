#include <iostream>
#include <list>
#include <vector>
using namespace std;

class tree {
    private:
        int element;
        tree *parent_node;
        list<tree*> children;
    public:
        tree( int const &obj, tree *p=nullptr ):element( obj ),parent_node( p ) {}
        int retrieve() const{return element;}
        tree *parent() const{return parent_node;}
        int degree() const{return children.size();}
        bool is_root() const{return (parent()==nullptr);}
        bool is_leaf() const{return ( degree() == 0 );}
        tree *child( int n ) {
		    if ( n < 0 || n >=degree() ) { return nullptr;}
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

            parent_node = nullptr;
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

};


int main()
{
    tree t(10);
    t.insert(12);
    t.insert(14);
    tree* c1=t.child(1);
    c1->insert(45);
    c1->insert(55);

    cout <<  t.size()<< endl;
    return 0;
}
