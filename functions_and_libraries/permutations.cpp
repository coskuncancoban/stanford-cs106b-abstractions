/*
 * The combinations function C(n, k) described in this chapter determines the
 * number of ways you can choose k values from a set of n elements, ignoring the
 * order of the elements. If the order of the value matters—so that, in the case of
 * the coin example, choosing a quarter first and then a dime is seen as distinct
 * from choosing a dime and then a quarter—you need to use a different function,
 * which computes the number of permutations, which are all the ways of
 * ordering k elements taken from a collection of size n. This function is denoted
 * as P(n, k), and has the following mathematical formulation:
 * P(n, k) = n! / (n - k)!
 * Although this definition is mathematically correct, it is not well suited to
 * implementation in practice because the factorials involved can get much too
 * large to store in an integer variable, even when the answer is small.
 * Write a function permutations(n, k) that computes the P(n, k) function
 * without calling the fact function. Part of your job in this problem is to figure
 * out how to compute this value efficiently. To do so, you will probably find it
 * useful to play around with some relatively small values to get a sense of how
 * the factorials in the numerator and denominator of the formula behave.
 */

/*
 * The formula is simplified from n! / (n - k)!
 * to n * (n - 1) * ... * (n - k + 1).
 */

#include <iostream>

long long permutations(int n, int k);

int main()
{
    int n, k;

    std::cout << "This program calculates P(n, k)." << std::endl;
    std::cout << "Enter the value for n (total elements): ";
    std::cin >> n;
    std::cout << "Enter the value for k (elements to choose): ";
    std::cin >> k;

    // Permutations are not defined if k > n, or if either is negative.
    if (k < 0 || n < 0 || k > n)
    {
        std::cout << "Error: Invalid input. n and k must be non-negative, and n must be >= k." << std::endl;
    }
    else
    {
        long long result = permutations(n, k);
        std::cout << "The number of permutations P(" << n << ", " << k << ") is: " << result << std::endl;
    }

    return 0;
}

long long permutations(int n, int k)
{
    // Use long long to store the result to prevent overflow.
    long long result = 1;

    // Calculate n * (n - 1) * ... * (n - k + 1).
    for (int i = 0; i < k; ++i)
    {
        result *= (n - i);
    }

    return result;
}