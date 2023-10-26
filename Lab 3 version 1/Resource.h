#pragma once
#include "Item.h" 
#include "functionsHelp.h"
#include "Weapon.h"
using namespace std;

enum class ResourceType
{
	diamonds,
	gold,
	iron,
	stone,	
	tree
};

class Resource : public Inventory
{
private:
	ResourceType resource;
public:
	Resource(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory, ResourceType resourse);
	
	void printMes() override;
	
	static void craftWeapon(vector<Inventory*>& inventory, const string& name, int required);
	static void craftItem(vector<Inventory*>& inventory);
	static void craftWeapon(vector<Inventory*>& inventory, const string& name, ResourceType type, int required);
};
