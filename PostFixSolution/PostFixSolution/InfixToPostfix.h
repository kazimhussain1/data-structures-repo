#include <iostream>
#include<string>
#include "Stack.h"


using namespace std;

bool IsGreater(char first, char second)
{
	if (second == -1)
		return true;
	switch (first)
	{
	case '!':
		return true;
		break;
	case '*':
		
		
	case '/':
		if (second == '(' || second == '+' || second == '-' || second == '=' || second == '~' || second == '>' || second == '<' || second == '&' || second == '|')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case '+':

		
	case '-':
		if (second == '(' || second == '=' || second == '~' || second == '>' || second == '<' || second == '&' || second == '|')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case '>':

		
	case '<':

		
	case '=':

		
	case '~':
		if (second == '(' || second == '&' || second == '|')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	
	case '&':
		if (second == '(' || second == '|')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
		break;
	case '|':
		if (second == '(')
		{
			return true;
		}
		return false;
		break;

	default:
		return false;
		break;
	}
}

string InfixToPostfix(string Infix)
{
	Stack Operators;
	string Postfix;
	char myChar;

	for (size_t i = 0; i < Infix.length(); i++)
	{
		if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
		{
			Postfix.push_back(Infix[i]);
		}
		else
		{
			myChar = Infix[i];
			switch (myChar)
			{
			case '(':
				Operators.push('(');
				break;
			case ')':
				while (Operators.peek() != '(')
				{
					Postfix.push_back(Operators.pop());
				}
				Operators.pop();
				break;

			default:
				if (Operators.peek() == -1)
				{
					Operators.push(myChar);
				}
				else if (!IsGreater(myChar, Operators.peek()))
				{
					while (!IsGreater(myChar, Operators.peek()))
					{
						Postfix.push_back(Operators.pop());
					}
					Operators.push(myChar);
				}
				else
				{
					Operators.push(myChar);
				}
				break;
			}
		}
	}
	while (Operators.peek() != -1)
	{
		Postfix.push_back(Operators.pop());
	}

	return Postfix;
}



//string InfixToPostfix(string Infix)
//{
//	Stack Operators;
//	string Postfix;
//	char myChar;
//
//	for (size_t i = 0; i < Infix.length(); i++)
//	{
//		if ( (Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z') )
//		{
//			Postfix.push_back(Infix[i]);
//		}
//		else
//		{
//			myChar = Infix[i];
//			switch (myChar)
//			{
//			case '(':
//				Operators.push('(');
//				break;
//			case ')':
//				while (Operators.peek() != '(')
//				{
//					Postfix.push_back(Operators.pop());
//				}
//				Operators.pop();
//				break;
//
//			case '*':
//				
//			
//			case '/':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('/', Operators.peek()))
//				{
//					while (!IsGreater('/', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//
//				break;
//			case '+':
//
//				
//			case '-':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('-', Operators.peek()))
//				{
//					while (!IsGreater('-', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//				break;
//			case '>':
//
//				;
//			case '<':
//
//				
//			case '=':
//
//				
//			case '~':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('~', Operators.peek()))
//				{
//					while (!IsGreater('~', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//				break;
//			case '!':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('!', Operators.peek()))
//				{
//					while (!IsGreater('!', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//				break;
//			case '&':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('&', Operators.peek()))
//				{
//					while (!IsGreater('&', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//				break;
//			case '|':
//				if (Operators.peek() == -1)
//				{
//					Operators.push(myChar);
//				}
//				else if (!IsGreater('&', Operators.peek()))
//				{
//					while (!IsGreater('&', Operators.peek()))
//					{
//						Postfix.push_back(Operators.pop());
//					}
//					Operators.push(myChar);
//				}
//				else
//				{
//					Operators.push(myChar);
//				}
//				break;
//
//			default:
//				break;
//			}
//		}
//	}
//	while (Operators.peek() != -1)
//	{
//		Postfix.push_back(Operators.pop());
//	}
//
//	return Postfix;
//}
