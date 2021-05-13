#include <stdio.h>
#include "Fibonacci.h"

/*
   Assaf's note: Did you remember to set your project's warning level to All?
*/

/**
 * Fibonacci test.
 */
int main(void)
{
    InitFibonacci();

    for (size_t number = 0; number < 96; ++number)
    {
        printf("%30llu\n", Fibonacci(number));
    }

    /*
       Assaf's note: Check the last two outputs.
    */

    /*
       Assaf's note: Use a debugger and make sure the value is read from the cache.
    */
    printf("%llu\n", Fibonacci(10));


    FinalizeFibonacci();

    return 0;
}