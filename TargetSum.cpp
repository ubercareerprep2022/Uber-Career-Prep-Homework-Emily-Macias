/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "qpair.h"
using namespace std;

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
    Vector<pair<int, int>> result = pairThatEqualSum({1, 2, 3, 4, 5}, 5, {});
    return 0;
}
