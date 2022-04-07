/*
 * File: targetSum.cpp
 * --------------
 * Within this program, a vector of pairs is returned with all
 * of the pair of numbers that add to a specific targetSum. We choose
 * from integers obtained from an inputted Vector of integers (inputted by
 * the user of our program).
 */


#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "qpair.h"
using namespace std;

/* Input: a vector of integers, a targetSum that the integers should add to
 * Output: a vector of the pairs of integers that add to the target sum
 *
 * Within this function we first check a base case. If our inputted vector
 * contains less than 2 items, we return our "soFar" which is a vector of all
 * the "successful pairs" that we are building up through our recursion. Otherwise,
 * we take the first number in the vector (stored using a variable called currentNum)
 * and use a for loop to try and pair it with every remaining number in the vector.
 * If it pairs with another int to equal the targetSum, we pair them together, remove
 * them from the vector, and add them to the vector of pairs that we are building up (our soFar).
 * If our number does not pair with anything to equal the targetSum, we simply move on
 * with our recursion without including a new pair to our soFar and with that number
 * removed from our list.
 *
 * Note: I am making the assumption that no number can every be used twice. Once we use
 * it /observe it once, it is removed from the list.
 */
Vector<pair<int, int>> pairThatEqualSum(Vector<int> inputNums, int targetSum, Vector<pair<int, int>> soFar){
    if(inputNums.size() < 2){
        return soFar;
    }
    int currentNum = inputNums[0];
    Vector<int> remaining = inputNums.subList(1);
    for(int i = 0; i < remaining.size(); i++){
        if(currentNum + remaining[i] == targetSum){
            pair<int, int> matchedNums = {currentNum, remaining[i]};
            remaining.remove(i);
            return pairThatEqualSum(remaining, targetSum, soFar + matchedNums);
        }
    }
    return pairThatEqualSum(remaining, targetSum, soFar);
}

int main()
{
    // all tests yielded the expected results
    Vector<pair<int, int>> result = pairThatEqualSum({1, 2, 3, 4, 5}, 5, {});
    Vector<pair<int, int>> resultOne = pairThatEqualSum({1, 2, 3, 4, 5}, 1 , {});
    Vector<pair<int, int>> resultTwo = pairThatEqualSum({1, 2, 3, 4, 5}, 7, {});
    return 0;
}
