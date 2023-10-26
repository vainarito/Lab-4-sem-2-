#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <windows.h>

#include"Item.h"
#include"Resource.h"
#include"Potion.h"
#include"Weapon.h"

int inputNum();
int inputObj();
void addItemToInventory(Inventory* item, std::vector<Inventory*>& inventory); // Объявление функции
void printInventory(const vector<Inventory*>& inventory);
void swapItems(vector<Inventory*>& inventory, int slot1, int slot2);
void removeItem(vector<Inventory*>& inventory, int slot);
void removeItemTwoV(vector<Inventory*>& inventory, int slot);
void pick();
void printMenu();
void printMenuInvent(vector<Inventory*>& inventory);
void printInpInv();
void printWeapon();
void printResource();
void printPotion();
void mainMenu();
