#pragma once
#include "Item.h" 
#include "functionsHelp.h"
using namespace std;

enum class PotionType
{
	strengthPotion,     //Зелье силы
	regenerationPotion, //Зелье регенерации
	speedPotion,        //Зелье скорости
	nightVisionPotion   //Зелье ночного видения
};

class Potions : public Inventory
{
private:
	PotionType Potion;

public:
	void printMes() override;
	Potions(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory, PotionType Potion);
	Potions();
	static void usePotion(vector<Inventory*>& inventory);
};
