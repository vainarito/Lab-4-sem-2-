#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;



class Inventory abstract
{
public:

    Inventory(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory);
    virtual ~Inventory() {}
    virtual void printMes() = 0;

    int getMaxQISlot() const;
    static unsigned int getSizeInventory();
    unsigned int getTotalQuantityInInventory() const;
    void setTotalQuantityInInventory(unsigned int quantity);
    const string& getName() const;
    double getWeight() const;
    void setWeight(double weight);
    bool getCanStoreMoreThanOne() const;

private:
    static int nextID;
    const int id;

    // название предмета 
    string name;
    // можно ли хранить предмет больше одного в слоте 
    bool canStoreMoreThanOne;
    // масса предмета
    double weight;
    // количество определённого предмета всего в инвентаре 
    unsigned int totalQuantityInInventory;
    // количество слотов занятые предметом 
    unsigned int numSlotsOccupied;
    // макс. число предметов для одноого слота 
    const unsigned int It_maximum_quantity_in_inventory_slot;
    static const unsigned int It_inventory_size;
};
