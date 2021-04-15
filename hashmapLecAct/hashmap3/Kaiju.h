
#ifndef KAIJU_H
#define KAIJU_H
#include <cmath>

enum style {
    LAND = 0,
    AIR = 1,
    WATER = 2
};

class Kaiju  {
  public:
    Kaiju(int size, std::string name, std::string superPower, style mode): 
    size(size), name(name), superPower(superPower), element(mode), life(100) {}

	std::string getName() const { return name; }
	int getSize()const  { return size; }
	double getLife() const { return life; }
    //life can never be less than 0
    void takeHit(double damage) { life = std::fmax(0.0, life - damage); }
    std::string getPower() const { return superPower; }
    style getMode() const {return element; }

  private:
    int size; //creature size
    std::string name; //creature name
    std::string superPower;
    style element;
    double life; //percentage of ‘health’
};

#endif
