
#include "Weapon.h"
#include "Resource.h"


Weapon::Weapon(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory, WeaponType type)
    : Inventory(name, canStoreMoreThanOne, weight, totalQuantityInInventory),
    typeWeapon(type) {}

void Weapon::printMes() {
    cout << "Выберите инструмент из инвентаря:" << endl;
}

void Weapon::useWeapon(vector<Inventory*>& inventory) {
    printInventory(inventory);
    Weapon* weap = new Weapon("Меч", false, 5, 1, WeaponType::sword);

    weap->printMes();
    int num = inputNum();
    num--;
    if (num < 0 || num >= inventory.size()) {
        cout << "Некорректный ввод. Пожалуйста, введите номер слота в диапазоне от 0 до " << inventory.size() - 1 << "." << endl;
        return;
    }

    Inventory* item = inventory[num];
    Weapon* weapon = dynamic_cast<Weapon*>(item);

    if (weapon == nullptr) {
        cout << "Выбранный предмет не является инструментом." << endl;
        return;
    }


    // Добавить соответствующий ресурс +5
    if (weapon->getName() == "Кирка") 
    {
        cout << "Выберите ресурс для добычи:\n" << "1. - Алмазы\n" << "2. - Золото\n" << "3. - Железо\n" << "4. - Камень" << "Ваш выбор:";
        num = inputNum();
        // Создайте новый объект ресурса в зависимости от выбора пользователя
       
        switch (num) {
        case 1: {
            pick();
            Resource* resource = new Resource("Алмазы", true, 0.5, 5, ResourceType::diamonds);
            addItemToInventory(resource, inventory);
            break;
        }
        case 2: {
            pick();
            Resource* resource = new Resource("Золото", true, 0.5, 5, ResourceType::gold);
            addItemToInventory(resource, inventory);
            break;
        }
        case 3: {
            pick();
            Resource* resource = new Resource("Железо", true, 0.5, 5, ResourceType::iron);
            addItemToInventory(resource, inventory);
            break;
        }
        case 4: {
            pick();
            Resource* resource = new Resource("Камень", true, 0.5, 5, ResourceType::stone);
            addItemToInventory(resource, inventory);
            break;
        }
        default:
            cout << "Некорректный ввод." << endl;
            return;
        }
        
    }

    else if (weapon->getName() == "Топор")
    {
        system("cls");
        cout << "Замахиваемся топором!" << endl;
        Sleep(1000);
        cout << "Добываем дерево!" << endl;
        Sleep(1000);
        cout << "Дерево добыто!" << endl;
        // Создайте новый объект ресурса для дерева
        Resource* tree = new Resource("Дерево", true, 0.5, 5, ResourceType::tree);
        // Добавьте дерево в инвентарь
        addItemToInventory(tree, inventory);
    }

    else if (weapon->getName() == "Меч")
    {
        system("cls");
        cout << "Убиваем моба мечом!" << endl;
        Sleep(1000);
        cout << "Почти убили моба!" << endl;
        Sleep(1000);
        cout << "Моб был убит!" << endl;
    }
    else if (weapon->getName() == "Лук")
    {

        // Проверяем, есть ли стрелы в инвентаре
        bool hasArrows = false;
        for (Inventory* item : inventory) {
            if (item->getName() == "Стрела") {
                hasArrows = true;
                break;
            }
        }

        // Если стрел нет, выводим сообщение об ошибке и возвращаем вес обратно
        if (!hasArrows) {
            cout << "У вас нет стрел для использования лука!" << endl;
            return;
        }

        // Если стрелы есть, используем лук и уменьшаем количество стрел
        system("cls");
        cout << "Достаём стрелу для выстрела!" << endl;
        Sleep(1000);
        cout << "Делаем выстрел!" << endl;
        Sleep(1000);
        cout << "Моб убит!" << endl;

        // Уменьшаем количество стрел в инвентаре
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i]->getName() == "Стрела") {
                inventory[i]->setTotalQuantityInInventory(inventory[i]->getTotalQuantityInInventory() - 1);

                // Если количество стрел в слоте равно нулю, удаляем этот слот
                if (inventory[i]->getTotalQuantityInInventory() == 0) {
                    delete inventory[i];
                    inventory.erase(inventory.begin() + i);
                }

                break;
            }
        }

    }

    
  
    double newWeight = weapon->getWeight() - 0.5;
    weapon->setWeight(newWeight);
    
        
    if (newWeight == 0) {
        cout << "Оружие сломалось от использования." << endl;
        removeItemTwoV(inventory, num);
    }
    
   
}
