#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "InfixToPostfix.h"

using namespace std;


float operate(float a, float b, char myOperator)
{
	switch (myOperator)
	{
	case '/':
		return a / b;
		break;
	case '*':
		return a * b;
		break;
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '&':
		return a && b;
		break;
	case '|':
		return a || b;
		break;
	case '=':
		return a == b;
		break;
	case '~':
		return a != b;
		break;
	case '<':
		return a < b;
		break;
	case '>':
		return a > b;
		break;
	default:
		return 0.0;
		break;
	}
}


float SolvePostfix(string PostFix)
{
	//string operands;
	map<char, float> values;
	string variables;
	for (size_t i = 0; i < PostFix.length(); i++)
	{
		if ((PostFix[i] >= 'a' && PostFix[i] <= 'z') || (PostFix[i] >= 'A' && PostFix[i] <= 'Z'))
		{
			int flag = 0;
			for (size_t j = 0; j < variables.length(); j++)
			{
				if (variables[j] == PostFix[i])
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				variables.push_back(PostFix[i]);
			}
		}
		else if(PostFix[i] >= '0' && PostFix[i] <= '9')
		{
			values[PostFix[i]] = PostFix[i] - 48;
		}
		
	}

	for (size_t i = 0; i < variables.length(); i++)
	{
		int number;
		cout << "Input value of " << variables[i] << ": ";
		cin >> number;
		values[variables[i]] = number;
	}

	stack<int> operands;
	for (int i = 0; i < PostFix.length(); i++)
	{
		if ((PostFix[i] >= 'a' && PostFix[i] <= 'z') || (PostFix[i] >= 'A' && PostFix[i] <= 'Z'))
		{
			operands.push(values[PostFix[i]]);
		}
		else
		{
			float a, b;
			b = operands.top();
			operands.pop();
			a = operands.top();
			operands.pop();
			operands.push(operate(a, b, PostFix[i]));

		}
	}

	return operands.top();
}

int main()
{
	string Infix = "a+b*c/d";

	string PostFix = InfixToPostfix(Infix);

	cout << PostFix << endl;

	float ans = SolvePostfix(PostFix);

	cout << ans << endl;

	system("pause");

	/*map<char, int> yolo;
	yolo['a'] = 12;
	yolo[' a'] = 1;

	cout << yolo['a'] << endl;


	system("pause");*/
}