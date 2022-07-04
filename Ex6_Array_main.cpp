/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include <fstream>
#include "MapData.h"
#include "error.h"
#include <chrono>
using namespace std;


dictionary::dictionary(){
    allocatedSize = 5;
    logicalSize = 0;
    elems =  new pair[allocatedSize];
}


dictionary::~dictionary(){
    delete[] elems;
}


int dictionary::size(){
    return logicalSize;
}


void dictionary::grow(){
    pair* helper = new pair[allocatedSize * 2];
    for(int i = 0; i < allocatedSize; i ++){
        helper[i] = elems[i];
    }
    allocatedSize = allocatedSize * 2;
    delete[] elems;
    elems = helper;
}


long dictionary::find(string name){
    for(int i = 0; i < logicalSize; i ++){
        if(elems[i].name == name){
            return elems[i].phoneNumber;
        }
    }
    return -1;
}


void dictionary::insert(string name, long phoneNumber){
    if(logicalSize == allocatedSize){
        grow();
    }
    elems[logicalSize].name = name;
    elems[logicalSize].phoneNumber = phoneNumber;
    logicalSize++;
}


int main()
{

    //Adding information into the phoneBook I created
    dictionary phoneBook;
    ifstream readFile;
    readFile.open("data.csv");
    auto start = chrono::steady_clock::now();
    if(!readFile.is_open()){
        error("Sorry, file is not open");
    } else {
        while(readFile){
            string line;
            getline(readFile, line);
            int index = line.find(",");  // use split function instead
            // Why did adding this make a difference with our data?
            if(index >= 0){
                string identification = line.substr(0, index);
                string phoneString = line.substr(index + 1);
                long long phoneNumber = stoll(phoneString);
                phoneBook.insert(identification, phoneNumber);
            }
        }
    }
    auto end = chrono::steady_clock::now();
    // Checking the size of the phoneBook I created to make sure it is 1000000
    cout << "size: " << phoneBook.size() << endl;
    cout << "Duration of Insert:" << " " << chrono::duration_cast<chrono:: milliseconds>(end - start).count() << "ms" << endl;

    //Checking to make sure the phoneBook I created has all the IDs in search.txt
    ifstream checkMapFile;
    checkMapFile.open("search.txt");
    int successfulLookups = 0;
    auto checkStartTime = chrono::steady_clock::now();
    if(!checkMapFile.is_open()){
        error("Sorry, the file is not open");
    } else {
        while(checkMapFile){
            string lines;
            getline(checkMapFile, lines);
            if(phoneBook.find(lines) != -1){
                successfulLookups++;
            }
        }
    }
    auto checkEndTime = chrono::steady_clock:: now();
    cout << "find() was called " << successfulLookups << " times" << endl;
    cout << "Insert took " << chrono::duration_cast<chrono::milliseconds>(checkEndTime - checkStartTime).count() << " ms" << endl;
    return 0;
}
