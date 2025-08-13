/*
 * Even though clients of the <cmath> library typically don’t need to understand
 * how functions like sqrt work internally, the implementers of that library have
 * to be able to design an effective algorithm and write the necessary code. If you
 * were asked to implement the sqrt function without using the library version,
 * there are many strategies you could adopt. One of the easiest strategies to
 * understand is successive approximation, in which you make a guess at the
 * solution and then refine that guess by choosing new values that move closer to
 * the solution.
 * You can use successive approximation to determine the square root of x by
 * adopting the following strategy:
 * 1. Begin by guessing that the square root is x / 2. Call that guess g.
 * 2. The actual square root must lie between g and x / g. At each step in the
 * successive approximation, generate a new guess by averaging g and x / g.
 * 3. Repeat step 2 until the values g and x / g are as close together as the
 * precision of the hardware allows. In C++, the best way to check for this
 * condition is to test whether the average is equal to either of the values used
 * to generate it.
 * Use this strategy to write your own implementation of the sqrt function.
 */

#include <iostream>

double mySqrt(double x);

int main()
{
    std::cout << "Enter a number to find its square root: ";
    double number;
    std::cin >> number;

    double result = mySqrt(number);

    if (result == -1)
    {
        std::cout << "Error: Negative numbers do not have a real square root." << std::endl;
    }
    else
    {
        std::cout << "The square root of " << number << " is approximately: " << result << std::endl;
    }

    return 0;
}

double mySqrt(double x)
{
    // The square root is not a real number for negative inputs.
    if (x < 0)
    {
        return -1;
    }

    // The square root of 0 is 0.
    if (x == 0)
    {
        return 0;
    }

    // Begin by guessing that the square root is x / 2. Call that guess g.
    double g = x / 2.0;

    while (true)
    {
        // Generate a new guess by averaging g and x / g.
        double newGuess = (g + x / g) / 2.0;

        // Repeat until the values are as close as the precision allows.
        // When the new guess is identical to the old guess, it is the square root.
        if (newGuess == g)
        {
            break;
        }

        // Update guess for the next iteration.
        g = newGuess;
    }

    return g;
}

/*
 * Explanation of the Logic: The "Rectangle to Square" Method
 * ----------------------------------------------------------
 * The core idea behind this approximation method is surprisingly simple
 * and can be understood by turning the math problem into a geometry problem.
 * What is the square root of a number 'x'?
 * Geometrically, it's the side length of a SQUARE whose area is 'x'.
 * Our goal is to find this side length.
 *
 * 1. The First Guess: Drawing a Rectangle
 * Let's say we want to find the square root of x = 25. We're looking for a
 * square with an area of 25.
 * We start by making a guess 'g'. Let's guess g = 10.
 * Now, let's draw a RECTANGLE that has an area of 25 and one side equal to our
 * guess (10). What must the other side be?
 * It must be x / g, which is 25 / 10 = 2.5.
 * We now have a 10 by 2.5 rectangle. This is not a square, because the sides
 * are not equal.
 *
 * 2. The Key Insight: The Answer is Always in Between
 * Notice something crucial:
 * Our guess (10) was LARGER than the true square root (5).
 * The other side (2.5) was SMALLER than the true square root (5).
 * This is always true! The real square root will always lie *between* our
 * guess 'g' and its pair 'x / g'.
 *
 * 3. The Logical Next Step: Take the Average
 * Since we know the true answer is between our two sides (10 and 2.5), the
 * most logical place to look for a better guess is right in the middle.
 * So, we take their average:
 * New, better guess = (10 + 2.5) / 2 = 6.25
 * Look how much closer we are to the real answer of 5!
 *
 * 4. The Iterative Process: Morphing the Rectangle into a Square
 * We just repeat the process. Our new guess is g = 6.25.
 * The other side is now 25 / 6.25 = 4.
 * Our new rectangle is 6.25-by-4. It's still not a square, but it's much
 * more "square-like" than the first one.
 * Our next, even better guess is the average: (6.25 + 4) / 2 = 5.125.
 *
 * Each time we repeat this, the long side of the rectangle gets shorter, and
 * the short side gets longer. They converge towards each other. The process
 * stops when the two sides become equal (or as equal as the computer's
 * precision allows).
 * When the sides are finally equal, our rectangle has become a perfect SQUARE,
 * and its side length is the square root we were looking for. This is why the
 * code stops when `newGuess == g`.
 */