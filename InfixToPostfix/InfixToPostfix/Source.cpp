#include <iostream>
#include "InfixToPostfix.h"

using namespace std;

int main()
{


	string Infix = "a+(b*c-(d+e*f/d-e)+(x+y*c))";

	cout << InfixToPostfix(Infix) << endl;

	//cout << IsGreater('-','*') << endl;

	system("pause");
}