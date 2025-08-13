/*
 * Greek mathematicians took a special interest in numbers that are equal to the
 * sum of their proper divisors, which is simply any divisor less than the number
 * itself. They called such numbers perfect numbers. For example, 6 is a perfect
 * number because it is the sum of 1, 2, and 3, which are the integers less than 6
 * that divide evenly into 6. Similarly, 28 is a perfect number because it is the
 * sum of 1, 2, 4, 7, and 14.
 *
 * Write a predicate function isPerfect that takes an integer n and returns
 * true if n is perfect, and false otherwise. Test your implementation by
 * writing a main program that uses the isPerfect function to check for perfect
 * numbers in the range 1 to 9999 by testing each number in turn. When a perfect
 * number is found, your program should display it on the screen. The first two
 * lines of output should be 6 and 28. Your program should find two other perfect
 * numbers in the range as well.
 */

#include <iostream>
#include <cmath> // Required for the sqrt function.

// Function decleration.
bool isPerfect(int n);

int main()
{
    std::cout << "Searching for perfect numbers between 1 and 9999..." << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    for (int i = 1; i <= 9999; ++i)
    {
        if (isPerfect(i))
        {
            std::cout << i << " is a perfect number." << std::endl;
        }
    }

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Search complete." << std::endl;

    return 0;
}

// Function definition.
bool isPerfect(int n)
{
    // A perfect number must be positive and 1 is not a perfect number.
    if (n <= 1)
    {
        return false;
    }

    // Starting with 1, because 1 is a proper divisor for all n < 1.
    int sumOfDivisors = 1;

    // To find other divisors, only need to check up to the square root of n.
    for (int i = 2; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            sumOfDivisors += i;

            // Add the pair divisor (n/i), but if n is perfect square,
            // do not add same divisor second time.
            if (i * i != n)
            {
                sumOfDivisors += (n / i);
            }
        }
    }

    // Return true if sum of divisors of number is equal to number itself.
    return (sumOfDivisors == n);
}