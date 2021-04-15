#include <iostream> 
#include <vector> 
#include <map>
#include <memory>
#include "Kaiju.h"
  
using namespace std; 
  
int main() { 
    map<string, Kaiju *> NameToStats; 

    //type of monster to totalPower
    map<string, int> totalPower;
  
  	//put data into the map
    NameToStats["godzila"] = new Kaiju(123, "godzilla", "lazer", WATER);
    NameToStats["mothra"] = new Kaiju(6, "mothra","magic", AIR);
    NameToStats["muta"] = new Kaiju(54, "muta1", "armor", AIR);

    //example that this data is a pair
    pair<string, Kaiju * > kongEntry ("kong", new Kaiju(72, "kong", "brute force", LAND) );

    //alternative method to put the data in the map
    NameToStats.insert(kongEntry);

  	//loop through whole map
    cout << "Monster data: " << endl; 
    for (auto entry : NameToStats) {
        cout << entry.first << " stats on size " << entry.second->getSize() << endl;
        //add to totalPower hashmap
        if (entry.second->getMode() == AIR)
            totalPower["air"] += 1;
        if (entry.second->getMode() == LAND)
            totalPower["land"] += 1;
    }

    cout << "game state: " << endl;
    for (auto entry : totalPower) {
        cout << entry.first << " has this many monsters " << entry.second << endl;
    }

    //one way to check if there is data for a given key
    cout << "Data on kong? " << NameToStats.count("kong") << endl;
    cout << "Data on mechagodzilla? " << NameToStats.count("mecha") << endl;

    //access to value data
    cout << "Power of mothra: " << NameToStats["mothra"]->getPower() << endl;
  
  delete NameToStats["godzila"];
    delete NameToStats["mothra"];
    delete NameToStats["muta"];
    delete NameToStats["kong"];
}
