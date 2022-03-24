/* File: isPermutaionsOf.cpp
 * --------------
 * Within this program we check if two words can be considered
 * permutaions of one another, returning a boolean value.
 */

#include "console.h"
#include "simpio.h"
#include "map.h"
using namespace std;

/* Input: a single word
 * Output: a map containing all of the letters/char
 * in the word and their frequency
 *
 * This function is meant to be a helper function. Its purpose
 * is to build a map containing the letters and frequency of letters
 * in a word.
 */
Map<char, int> buildMap(string word){
    Map<char, int> wordMap;
    for(char letter: word){
        if(!wordMap.containsKey(letter)){
            wordMap[letter];
        }
        wordMap[letter]++;
    }
    return wordMap;
}


/* Input: Two words/strings (we want to check if they are permuations of one another)
 * Output: boolean indicating true if they are permuations, false if not
 *
 * Within this program, we first check a base case. If the two words are different lengths,
 * then we automatically know they are not permutations of each other. Otherwise,
 * we use our helper function to build maps for each word with the frewuency of their
 * letters. If the two maps are the same, then the words are permutations of one another(return true),
 * otherwise, they are not (return false).
 */
bool isStringPermutation(string stringOne, string stringTwo){
    if(stringOne.length() != stringTwo.length()){
        return false;
    }
    Map<char, int> wordOneMap = buildMap(stringOne);
    Map<char, int> wordTwoMap = buildMap(stringTwo);
    if(wordOneMap == wordTwoMap){
        return true;
    } else {
        return false;
    }
}


int main()
{
    bool answer = isStringPermutation("asdf", "fsda");  // all tests passed
    cout << answer << endl;

    bool answerTwo = isStringPermutation("asdf", "fsa");
    cout << answerTwo << endl;

    bool answerThree = isStringPermutation("asdf", "fsax");
    cout << answerThree << endl;

    return 0;
}

