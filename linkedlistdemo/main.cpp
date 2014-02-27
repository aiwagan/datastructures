#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> li;

    li.push_front(4);
    li.push_front(9);
    li.push_front(10);


    cout << li.size()<< endl;
    return 0;
}
