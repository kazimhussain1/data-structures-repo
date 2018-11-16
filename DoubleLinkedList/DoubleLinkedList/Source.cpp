#include "DoubleList.h"

using namespace std;

int main()
{
	NODE* start = NULL;

	insert(55, &start);
	insert(66, &start);
	insert(77, &start);
	DeleteValue(55, &start);
	DeleteValue(77, &start);
	DeleteValue(66, &start);

	getchar();
}