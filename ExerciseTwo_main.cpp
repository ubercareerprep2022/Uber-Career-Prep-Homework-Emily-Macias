/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "EmployeeTree.h"
#include "vector.h"
#include "queue.h"
using namespace std;

void printLevelByLevel(){
    Queue<employee> levels;
    levels.enqueue(front);
    int levelSize = 1;
    int futureLevelSize = 0;
    int numDequeued = 0;

    while(!levels.isEmpty()){
        employee current = levels.peek();
        cout << "Name:" << current.name << ", " << "Title:" << current.title << endl;
        Vector<employee> subLevel = current.directReports;
        for(int i = 0; i < subLevel.size(); i ++){
            levels.enqueue(subLevel[i]);
        }
        levels.dequeue();
        futureLevelSize += current.directReports.size();
        numDequeued++;
        if(numDequeued == levelSize){
            levelSize = futureLevelSize;
            futureLevelSize = 0;
            numDequeued = 0;
            cout << "" << endl;
        }
    }
}

int main()
{
    front.name = "A";
    front.title = "CEO";
    front.directReports.add({"B", "CFO", {}});
    front.directReports.add({"C", "CTO", {}});

    //Adding third & fourth & fifth rows
    front.directReports[0].directReports.add({"I", "Director", {{"J", "Sales Representative", {{"K", "Sales Intern", {}}}}}});
    front.directReports[1].directReports.add({"D", "Manager", {{"F", "Engineer", {}}, {"G", "Engineer", {}}, {"H", "Engineer", {}}}});
    front.directReports[1].directReports.add({"E", "Manager", {}});

    printLevelByLevel();
    return 0;
}
