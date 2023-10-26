#include"functionsHelp.h"

using namespace std;
int inputNum()
{
    int  num = 0;
    while (!(cin >> num))
    {
        cin.clear(); // очистить флаги ошибок
        cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // игнорировать некорректный ввод
        cout << "Некорректный ввод. Пожалуйста, введите число: ";
    }
    return num;
}

int inputObj()
{
    int num = 0;
    while (!(cin >> num) || num > 64)
    {
        cin.clear(); // очистить флаги ошибок
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // игнорировать некорректный ввод
        cout << "Некорректный ввод. Пожалуйста, введите число не больше 64: ";
    }
    return num;
}


void addItemToInventory(Inventory* item, vector<Inventory*>& inventory) {
    // Сначала пытаемся добавить предметы в уже существующие слоты
    for (Inventory* invItem : inventory) 
    {
        if (typeid(*invItem) == typeid(*item) && invItem->getName() == item->getName() && invItem->getCanStoreMoreThanOne() && invItem->getTotalQuantityInInventory() < invItem->getMaxQISlot())
        {
            int spaceInSlot = invItem->getMaxQISlot() - invItem->getTotalQuantityInInventory();

            if (spaceInSlot >= item->getTotalQuantityInInventory())
            {
                invItem->setTotalQuantityInInventory(invItem->getTotalQuantityInInventory() + item->getTotalQuantityInInventory());
                return;
            }
            else
            {
                invItem->setTotalQuantityInInventory(invItem->getTotalQuantityInInventory() + spaceInSlot);
                item->setTotalQuantityInInventory(item->getTotalQuantityInInventory() - spaceInSlot);
            }
        }
    }

    // Если остались еще предметы, пытаемся добавить их в новый слот
    if (item->getTotalQuantityInInventory() > 0)
    {
        if (inventory.size() < Inventory::getSizeInventory()) 
        {
            inventory.push_back(item);
           
        }
        else
        {
            // Если нет свободных слотов, сообщаем пользователю
            cout << "Инвентарь полон!" << endl;
        }
    }
}




void printInventory(const vector<Inventory*>& inventory) {
    cout << "Содержимое инвентаря:" << endl;
    int i = 1;
    for (const auto& item : inventory) {
        cout << i << " - ";
        cout << "Название: " << item->getName() << ", ";
        cout << "Вес: " << item->getWeight() << ", ";
        cout << "Количество: " << item->getTotalQuantityInInventory() << endl;
        i++;
    }
}

void swapItems(vector<Inventory*>& inventory, int slot1, int slot2) {
    slot1--;
    slot2--;
    if (slot1 < inventory.size() && slot2 < inventory.size()) {
        Inventory* temp = inventory[slot1];
        inventory[slot1] = inventory[slot2];
        inventory[slot2] = temp;
    }
    else {
        cout << "Один из слотов пуст." << endl;
    }
}

void removeItem(vector<Inventory*>& inventory, int slot) {
    slot--;
    if (slot < inventory.size()) {
        delete inventory[slot];
        inventory.erase(inventory.begin() + slot);
    }
    else {
        cout << "Слот пуст." << endl;
    }
}
void removeItemTwoV(vector<Inventory*>& inventory, int slot) {
    if (slot < inventory.size()) {
        delete inventory[slot];
        inventory.erase(inventory.begin() + slot);
    }
    else {
        cout << "Слот пуст." << endl;
    }
}
void pick()
{
    system("cls");
    cout << "Замахиваемся киркой!" << endl;
    Sleep(1000);
    cout << "Добываем ресурсы!" << endl;
    Sleep(1000);
    cout << "Ресурс добыт!" << endl;
}

void printMenu()
{
    cout << "+======================================+" << endl;
    cout << "|Выберете с чем надо взаимодействовать:|" << endl;
    cout << "+======================================+" << endl;
    cout << "|1. - Просмотр инвентаря               |" << endl;
    cout << "|2. - Взаимодействовать с инструментами|" << endl;
    cout << "|3. - Выпить зелье                     |" << endl;
    cout << "|4. - Крафт предметов                  |" << endl;
	cout << "|5. - Шифрование строки (доп)          |" << endl;
    cout << "|6. - Завершение \"игры\"                |" << endl;
    cout << "+======================================+" << endl;
    cout << "Ваш выбор:";
}
void printMenuInvent(vector<Inventory*>& inventory)
{
    cout << "+============================================+" << endl;
    cout << "|Размер инвенторя: " << inventory.capacity() << " слотов!                |" << endl;
    cout << "|Занято " << inventory.size() << " из " << inventory.capacity() << " слотов!                      |" << endl;
    cout << "+============================================+" << endl;
    cout << "|Выберите что вы хотите сделать в инвентаре: |" << endl; // -
    cout << "|1. - Выдать предмет                         |" << endl; // -
    cout << "|2. - Поменять продметы местами              |" << endl; // -
    cout << "|3. - Выбросить предмет                      |" << endl; // -
    cout << "+============================================+" << endl;
    cout << "Ваш выбор: ";
}
void printInpInv()
{
    system("cls");
    cout << "+==========================+" << endl;
    cout << "|Что вы можете выдать:     |" << endl;
    cout << "|1. - Инструмент           |" << endl; // +
    cout << "|2. - Ресурсы              |" << endl; // +
    cout << "|3. - Зелье                |" << endl; // +
    cout << "+==========================+" << endl;
    cout << "Ваш выбор:";
}

void printWeapon()
{
    system("cls");
    cout << "+=================================+" << endl;
    cout << "|Вы можете получить:              |" << endl; // +
    cout << "|1. - Меч                         |" << endl; // +
    cout << "|2. - Лук                         |" << endl; // +
    cout << "|3. - Стрела                      |" << endl; // +
    cout << "|4. - Топор                       |" << endl; // +
    cout << "|5. - Кирку                       |" << endl; // +
    cout << "+=================================+" << endl;
    cout << "Ваш выбор:";
}

void printResource()
{
    system("cls");
    cout << "+=================================+" << endl;
    cout << "|Вы можете получить:              |" << endl;
    cout << "|1. - Алмазы                      |" << endl; // +
    cout << "|2. - Золото                      |" << endl; // +
    cout << "|3. - Железо                      |" << endl; // +
    cout << "|4. - Камень                      |" << endl; // +
    cout << "|5. - Дерево                      |" << endl; // +
    cout << "+=================================+" << endl;
    cout << "Ваш выбор:";
}

void printPotion()
{
    system("cls");
    cout << "+=================================+" << endl;
    cout << "|Вы можете получить:              |" << endl; // +
    cout << "|1. - Зелье силы                  |" << endl; // +
    cout << "|2. - Зелье регенерации           |" << endl; // +
    cout << "|3. - Зелье скорости              |" << endl; // +
    cout << "|4. - Зелье ночного видения       |" << endl; // +
    cout << "+=================================+" << endl;
    cout << "Ваш выбор:";
}

string encodeRailFence(string text, int n) {
	vector<string> rails(n);
	int rail = 0;
	int change = 1;

	for (char c : text) {
		rails[rail].push_back(c);
		if (rail == 0) {
			change = 1;
		}
		else if (rail == n - 1) {
			change = -1;
		}
		rail += change;
	}

	std::string result;
	for (auto& rail : rails) {
		result += rail;
	}
	return result;
}

string decodeRailFence(string cipher, int n) {
	vector<string> rails(n);
	int len = cipher.length();
	int rail = 0;
	int change = 1;

	for (int i = 0; i < len; i++) {
		if (rail == 0) {
			change = 1;
		}
		else if (rail == n - 1) {
			change = -1;
		}
		rails[rail].push_back('*');
		rail += change;
	}

	int index = 0;
	for (auto& rail : rails) {
		for (char& c : rail) {
			c = cipher[index++];
		}
	}

	string result;
	rail = 0;
	change = 1;

	for (int i = 0; i < len; i++) {
		if (rail == 0) {
			change = 1;
		}
		else if (rail == n - 1) {
			change = -1;
		}
		result.push_back(rails[rail][0]);
		rails[rail].erase(rails[rail].begin());
		rail += change;
	}

	return result;
}

void mainMenu()
{
	char text[256];
	int n;
	unsigned int slot, slot1, slot2;
	unsigned int quantityOfItem = 0;
	unsigned int num = 0;
	vector<Inventory*> Ivent;
	
	
	
	do {
		printMenu();
		num = inputNum();


		Ivent.reserve(Inventory::getSizeInventory());

		switch (num)
		{
		case 1:
		{
			system("cls");
			printInventory(Ivent);
			printMenuInvent(Ivent);
			num = inputNum();

			switch (num)
			{
			case 1:
			{
				printInpInv();
				num = inputNum();

				switch (num)
				{
				case 1:
				{
					printWeapon();
					num = inputNum();

					switch (num)
					{
					case 1:
					{

						system("cls");
						Weapon* weap = new Weapon("Меч", false, 5, 1, WeaponType::sword);
						addItemToInventory(weap, Ivent);

						break;
					}
					case 2:
					{
						system("cls");
						Weapon* weap = new Weapon("Лук", false, 5, 1, WeaponType::bow);
						addItemToInventory(weap, Ivent);
						break;
					}
					case 3:
					{
						system("cls");
						cout << "Введите количество стрел:" << endl;
						quantityOfItem = inputObj();
						Weapon* weap = new Weapon("Стрела", true, 5, quantityOfItem, WeaponType::arrow);
						addItemToInventory(weap, Ivent);
						break;
					}
					case 4:
					{
						system("cls");
						Weapon* weap = new Weapon("Топор", false, 5, 1, WeaponType::hatchet);
						addItemToInventory(weap, Ivent);

						break;
					}
					case 5:
					{
						system("cls");
						Weapon* weap = new Weapon("Кирку", false, 5, 1, WeaponType::pick);
						addItemToInventory(weap, Ivent);
						break;
					}
					default:
					{
						cout << "Нет такого варианта!" << endl;
						break;
					}
					}
					break;
				}

				case 2:
				{
					printResource();
					num = inputNum();
					switch (num)
					{
					case 1:
					{
						system("cls");
						cout << "Введите количество алмазов:" << endl;
						quantityOfItem = inputObj();
						Resource* resource = new Resource("Алмазы", true, 0.5, quantityOfItem, ResourceType::diamonds);
						addItemToInventory(resource, Ivent);
						break;
					}
					case 2:
					{
						system("cls");
						cout << "Введите количество золота:" << endl;
						quantityOfItem = inputObj();
						Resource* resource = new Resource("Золото", true, 0.5, quantityOfItem, ResourceType::gold);
						addItemToInventory(resource, Ivent);
						break;
					}
					case 3:
					{
						system("cls");
						cout << "Введите количество железа:" << endl;
						quantityOfItem = inputObj();
						Resource* resource = new Resource("Железо", true, 0.5, quantityOfItem, ResourceType::iron);
						addItemToInventory(resource, Ivent);
						break;
					}
					case 4:
					{
						system("cls");
						cout << "Введите количество камня:" << endl;
						quantityOfItem = inputObj();
						Resource* resource = new Resource("Камень", true, 0.5, quantityOfItem, ResourceType::stone);
						addItemToInventory(resource, Ivent);
						break;
					}
					case 5:
					{
						system("cls");
						cout << "Введите количество дерева:" << endl;
						quantityOfItem = inputObj();
						Resource* resource = new Resource("Дерево", true, 0.5, quantityOfItem, ResourceType::tree);
						addItemToInventory(resource, Ivent);
						break;
					}
					default:
					{
						cout << "Нет такого варианта!" << endl;
						break;
					}
					}
					break;
				}

				case 3:
				{
					printPotion();
					num = inputNum();
					switch (num)
					{
					case 1:
					{
						system("cls");
						Potions* pot = new Potions("Зелье силы", false, 0.5, 1, PotionType::strengthPotion);
						addItemToInventory(pot, Ivent);
						break;
					}
					case 2:
					{
						system("cls");
						Potions* pot = new Potions("Зелье регенерации", false, 0.5, 1, PotionType::regenerationPotion);
						addItemToInventory(pot, Ivent);
						break;
					}
					case 3:
					{
						system("cls");
						Potions* pot = new Potions("Зелье сокорости", false, 0.5, 1, PotionType::regenerationPotion);
						addItemToInventory(pot, Ivent);
						break;
					}
					case 4:
					{
						system("cls");
						Potions* pot = new Potions("Зелье ночного зрения", false, 0.5, 1, PotionType::nightVisionPotion);
						addItemToInventory(pot, Ivent);
						break;
					}
					default:
					{
						cout << "Нет такого варианта!" << endl;
						break;
					}
					}
					break;
				}

				default:
				{
					cout << "Нет такого варианта!" << endl;
					break;
				}
				}

				break;
			}
			case 2:
			{
				system("cls");
				printInventory(Ivent);
				cout << "------------------------------\n" << "Введите номера двух слотов для обмена: ";
				slot1 = inputNum();
				slot2 = inputNum();
				swapItems(Ivent, slot1, slot2);
				break;
			}
			case 3:
			{
				system("cls");
				printInventory(Ivent);
				cout << "------------------------------\n" << "Введите номер слота для удаления: ";
				slot = inputNum();
				removeItem(Ivent, slot);
				break;
			}
			default:
			{
				cout << "Нет такого варианта!" << endl;
				break;
			}
			}
			break;
		}

		case 2:
		{
			system("cls");
			Weapon::useWeapon(Ivent);
			break;
		}

		case 3:
		{
			system("cls");
			Potions::usePotion(Ivent);
			break;
		}

		case 4:
		{
			system("cls");
			printInventory(Ivent);
			Resource::craftItem(Ivent);
			break;
		}
		case 5:
		{

			
			char text[256];
			int n;

			cout << "Введите строку для кодирования: ";
			cin.ignore(1000, '\n'); 
			cin.getline(text, 256);

			cout << "Введите количество рельсов: ";
			cin >> n;
			cin.ignore(1000, '\n'); 

			string str(text); 
			string encoded = encodeRailFence(str, n);
			cout << "Закодированная строка: " << encoded << std::endl;

			string decoded = decodeRailFence(encoded, n);
			cout << "Декодированная строка: " << decoded << std::endl;


		}
		case 6:
		{
			exit(0);
		}
		default:
		{
			cout << "Нет такого варианта!" << endl;
			break;
		}
		}
	} while (num);
}