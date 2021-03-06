/**
 * @file debugging1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An example of the utility of print statements in debugging.
 * 
 * Answer:
 * The last time through the loop, x decreases instead of increases.
 * If you make x smaller it doesn't have this problem and if you make 
 * a or b a lot bigger it happens more. 
 * It probably does this because int has a limit to how high it can 
 * store numbers, and when the number is too big parts of the binary 
 * storage gets cut off.
 */

#include <iostream>

using namespace std;

/**
 * @brief Does a thing.
 *
 * Does a thing, I dunno, you tell me.
 */
int main(int argc, char ** argv)
{
    // Much of the following is intentionally undocumented.
    // Part of the assignment is to figure out what is going on.
    // You may need to look up some operators!
    unsigned int a = 120000, b = 85, x = 0;

    // This construct is known as a 'while loop'.
    // The interior of the loop is run if, and while,
    // the given condition is true.
    // The program proceeds past the loop if, and when,
    // the given condition is found to be false just before any iteration
    // of the interior of the loop.
    while (b != 0)
    {
		cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        // This construct is known as a conditional statement
        // ('if' statement).
        // The interior of the statement is run exactly once in its entirety
        // if the given condition is found to be true.
        // Note that 'true' is defined as nonzero,
        // and 'false' is defined as zero.
        if ((b & 1) != 0)
        {
            x += a;
            
        }
        a <<= 1;
        b >>= 1;
        
    }
	cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "x = " << x << endl;
    // Question for you now: so what is x anyway?

    return 0;
}
