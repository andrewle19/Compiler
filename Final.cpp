#include <iostream>
using namespace std;
int main()
{
int P13 , PRS , Q3;
PRS = 121;
cout << PRS << endl;;
Q3 = 10;
P13 = PRS - Q3 * ( 3 + PRS * Q3 ) ;
cout << P13 << endl;;
cout << Q3 << endl;;
return 0;
}