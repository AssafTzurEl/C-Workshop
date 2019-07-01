#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "Utils.h"

static int IsLarger_internal(double x, double y)
{
	return x > y;
}

void main()
{
	int max = Max(10, 20);
    ++max;

	if (IsLarger_internal(10.0, 20.3))
	{
		// ...
	}
}