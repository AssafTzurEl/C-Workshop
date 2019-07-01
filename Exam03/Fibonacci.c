#include <malloc.h>
#include <assert.h>
#include "Fibonacci.h"

/* Fibonacci DB: Caches previous results to prevent extra calculations. */

/*
    Assaf's note: Using static to make the DB "private" - not exported by the compiler
    and not "seen" by the linker.
*/
static ull_t *s_fibonacciDb = NULL;
static size_t s_fibonacciDbSize = 0;

ull_t Fibonacci(size_t n)
{
    /* Make sure the cache is initialized: */
    if (!s_fibonacciDb)
    {
        InitFibonacci();
    }

    if (s_fibonacciDbSize <= n) /* s_fibonacciDbSize == n means it's up to n-1 */
    {
        /* Cache miss - need to enhance the cache: */
        size_t oldSize = s_fibonacciDbSize;

        s_fibonacciDbSize = n + 1; /* DB ranges from 0..n */

        ull_t *newDb = (ull_t *) realloc(s_fibonacciDb, s_fibonacciDbSize * sizeof(ull_t));

        /*
           Assaf's note: See realloc's documentation: What it receives, what it does,
           what is returned under which conditions.
        */

        if (newDb)
        {
            s_fibonacciDb = newDb;
        }
        else
        {
            /* Memory allocation error */
            /*
                Assaf's note: The requirements heven't specified what to do in this case.
                In real life (and in the exam), you should point that out to your
                manager, or at least document your decision in the code.
            */

            /*
               Same behavior as number overflow: return zero. A future call to this
               function might succeed in allocating the memory and return a valid value.
            */
            return 0;
        }

        /* Fill the cache from the last existing value to n (which is in index [n+1]): */
        for (size_t index = oldSize; index < s_fibonacciDbSize; ++index)
        {
            s_fibonacciDb[index] = s_fibonacciDb[index - 1] + s_fibonacciDb[index - 2];

            /* Check overflow: If number is wrapped around, set it to zero.
             * If Previous value is already zero, it means we've already wrapped
             * and all values from now on should be zero.
             */
            if ((s_fibonacciDb[index] < s_fibonacciDb[index - 1])
                || (s_fibonacciDb[index - 1] == 0))
            {
                s_fibonacciDb[index] = 0;
            }
        }
    }

    return s_fibonacciDb[n];
}

void InitFibonacci(void)
{
    if (!s_fibonacciDb)
    {
        s_fibonacciDb = malloc(2 * sizeof(ull_t));

        if (s_fibonacciDb)
        {
            s_fibonacciDbSize = 2;
            s_fibonacciDb[0] = 0;
            s_fibonacciDb[1] = 1;
        }
        else
        {
            /* Can't allocate a few bytes - inconceivable! */
            printf("Fatal error: Out of memory. Please contact your administrator\n");
            exit(1);
        }
    }
}

void FinalizeFibonacci(void)
{
    if (s_fibonacciDb)
    {

        /*
           Assaf's note: Advanced topic: Assertions.
       */
        assert(s_fibonacciDbSize != 0);

        free(s_fibonacciDb);
        s_fibonacciDbSize = 0;
    }
}