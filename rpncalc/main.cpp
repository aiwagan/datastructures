#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


double evalrpn(stack<string> & tks)  {
  double x,y;
  auto tk = tks.top();  tks.pop();
  auto n = tk.size();
  if (n==1 && string("+-*/").find(tk)!=string::npos)  {
    y = evalrpn(tks);
    x = evalrpn(tks);
    if      (tk[0]=='+')  x += y;
    else if (tk[0]=='-')  x -= y;
    else if (tk[0]=='*')  x *= y;
    else                  x /= y;
  }  else  {
    std::string::size_type sz;
    x = stod(tk,&sz);
  }
  return x;
}

int main()  {
  string s;
  while (getline(cin,s))  {
    stack<string> tks;
    istringstream sstr(s);
    string tk;
    while (sstr >> tk)  tks.push(tk);
    if (!tks.empty())
      {
        auto z = evalrpn(tks);
        cout << z << endl;
      }
  }
  return 0;
}
