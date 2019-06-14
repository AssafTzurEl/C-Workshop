#include "Utils.h"

static int IsLarger_internal(int x, int y)
{
	return x > y;
}

int Max(int a, int b)
{
	return IsLarger_internal(a, b) ? a : b;
}
