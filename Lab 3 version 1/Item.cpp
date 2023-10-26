#pragma once
#include"Item.h"
using namespace std;


int Inventory::getMaxQISlot() const
{
    return It_maximum_quantity_in_inventory_slot;
}
unsigned int Inventory::getSizeInventory()
{
    return It_inventory_size;
}
unsigned int Inventory::getTotalQuantityInInventory() const {
    return totalQuantityInInventory;
}
void Inventory::setTotalQuantityInInventory(unsigned int quantity)
{
    totalQuantityInInventory = quantity;
}
Inventory::Inventory(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory)
    : id(nextID++),
    name(name),
    canStoreMoreThanOne(canStoreMoreThanOne),
    weight(weight),
    totalQuantityInInventory(totalQuantityInInventory),
    It_maximum_quantity_in_inventory_slot(64)
{
    numSlotsOccupied = ceil(static_cast<float>(totalQuantityInInventory) / getMaxQISlot());
}

const std::string& Inventory::getName() const {
    return name;
}

double Inventory::getWeight() const 
{
    return weight;
}

void Inventory::setWeight(double weight) {
    this->weight = weight;
}
bool Inventory::getCanStoreMoreThanOne() const
{
    return canStoreMoreThanOne;
}
int Inventory::nextID = 0;
const unsigned int Inventory::It_inventory_size = 27;

