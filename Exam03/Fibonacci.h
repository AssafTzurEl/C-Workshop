#pragma once

/**
 * Shorthand for "unsigned long long int".
 *
 */
typedef unsigned long long int ull_t;

/*
   Assaf's note: It's recommended to use cross-platform, unified size types.
   For example, in this case you may want to take a look at uint64_t, declared
   in <stdint.h>.
*/

/**
 * Returns the nth Fibonacci number.
 *
 * @param n ordinal number
 *
 * @return nth Fibonacci number
 */
ull_t Fibonacci(size_t n);

/**
 * Initializes resources. This is optional: If you don't do it in advance, the
 * first call to Fibonacci() will.
*/
void InitFibonacci(void);

/**
 * Releases resources. Should be called when you're done with Fibonacci.
 *
 * @note This function may be called multiple times. If Fibonacci() is invoked after
 * calling FinalizeFibonacci(), initialization code will be invoked again, and
 * FinalizeFibonacci() will have to be called yet again.
 */
void FinalizeFibonacci(void);