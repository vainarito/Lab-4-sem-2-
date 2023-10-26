#pragma once
#include "Item.h" 
#include "functionsHelp.h"
using namespace std;

enum class WeaponType
{
    sword,       // меч 
    bow,         // лук
    arrow,       // стрела 
    hatchet,     // топор
    pick,        // кирка  
};

class Weapon : public Inventory
{
public:

    Weapon(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory, WeaponType type);
    Weapon();
    static void useWeapon(vector<Inventory*>& inventory);
    void printMes() override;
private:
    WeaponType typeWeapon;
};
