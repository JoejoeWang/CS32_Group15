#include <iostream> 
#include <vector> 
#include <map>
#include <memory>
#include "Kaiju.h"
  
using namespace std; 
  
int main() { 
    map<string, shared_ptr<Kaiju> > NameToStats; 

    //type of monster to totalPower
    map<style, int> totalPower;
  
  	//put data into the map
    NameToStats["godzila"] = make_shared<Kaiju>(123, "godzilla", "lazer", WATER);
    NameToStats["mothra"] = make_shared<Kaiju>(6, "mothra","magic", AIR);
    NameToStats["muta"] = make_shared<Kaiju>(54, "muta1", "armor", AIR);
    NameToStats["batman"] = make_shared<Kaiju>(1, "batman", "money", LAND);

    //example that this data is a pair
    pair<string, shared_ptr<Kaiju> > kongEntry ("kong", make_shared<Kaiju>(72, "kong", "brute force", LAND) );

    //alternative method to put the data in the map
    NameToStats.insert(kongEntry);

  	//loop through whole map
    cout << "Monster data: " << endl; 
    for (auto entry : NameToStats) {
        cout << entry.first << " stats on size " << *(entry.second) << endl;
        //add to totalPower hashmap
        if (entry.second->getMode() == AIR)
            totalPower[AIR] += 1;
        if (entry.second->getMode() == LAND)
            totalPower[LAND] += 1;
        if (entry.second->getMode() == WATER)
            totalPower[WATER] += 1;
    }

    cout << "game state: " << endl;
    for (auto entry : totalPower) {
      if(entry.first==0){
        cout << "land" << " has this many monsters " << entry.second << endl;
      }
      if(entry.first==1){
        cout << "air" << " has this many monsters " << entry.second << endl;
      }
      if(entry.first==2){
        cout << "water" << " has this many monsters " << entry.second << endl;
      }
    }

    //one way to check if there is data for a given key
    cout << "Data on kong? " << NameToStats.count("kong") << endl;
    cout << "Data on mechagodzilla? " << NameToStats.count("mecha") << endl;

    //access to value data
    cout << "Power of mothra: " << NameToStats["mothra"]->getPower() << endl;
}


std::ostream& operator<<(std::ostream &out, const Kaiju &K) {
      out << "Kaiju Info: " << K.name << " size: " << K.size;
      out << "\nPower: " << K.superPower << " life: " << K.life;
      out << "\nElement: " << K.element << "\n";
    return out;
}