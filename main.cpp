/* File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "map.h"
using namespace std;

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
    bool answer = isStringPermutation("asdf", "fsa");
    cout << answer << endl;
    return 0;
}

