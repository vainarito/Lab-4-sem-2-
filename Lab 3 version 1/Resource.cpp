    #include "Resource.h"

    Resource::Resource(const string& name, bool canStoreMoreThanOne, double weight, unsigned int totalQuantityInInventory, ResourceType resource)
        : Inventory(name, canStoreMoreThanOne, weight, totalQuantityInInventory), resource(resource) {}
    

    void Resource::printMes() {
        // Запрашиваем у пользователя, какой инструмент он хочет скрафтить
        cout << "Какой инструмент вы хотите скрафтить?\n"
            << "1. Меч (требуется 2 любых ресурса)\n"
            << "2. Лук (требуется 3 дерева)\n"
            << "3. Стрела (требуется 1 дерево)\n"
            << "4. Кирка (требуется 3 любых ресурса)\n"
            << "5. Топор (требуется 3 любых ресурса)\n"
            << "Ваш выбор: ";
    }
   
    void Resource::craftItem(vector<Inventory*>& inventory) {
        Resource* res = new Resource("Золото", true, 0.5, 5, ResourceType::gold);
        res->printMes();

        int choice = inputNum();
        
        // Проверяем, достаточно ли ресурсов для выбранного инструмента
        switch (choice) {
        case 1: // Меч
            craftWeapon(inventory, "Меч", 2);
            break;
        case 2: // Лук
            craftWeapon(inventory, "Лук", ResourceType::tree, 3);
            break;
        case 3: // Стрела
            craftWeapon(inventory, "Стрела", ResourceType::tree, 1);
            break;
        case 4: // Кирка
        case 5: // Топор
            craftWeapon(inventory, choice == 4 ? "Кирка" : "Топор", 3);
            break;
        default:
            cout << "Некорректный ввод." << endl;
        }
    }

    void Resource::craftWeapon(vector<Inventory*>& inventory, const string& name, int required) {
        for (int i = 0; i < inventory.size(); i++) {
            Resource* resource = dynamic_cast<Resource*>(inventory[i]);
            if (resource != nullptr && resource->getTotalQuantityInInventory() >= required) {
                resource->setTotalQuantityInInventory(resource->getTotalQuantityInInventory() - required);

                if (resource->getTotalQuantityInInventory() == 0) {
                    delete inventory[i];
                    inventory.erase(inventory.begin() + i);
                }

                // Создаем новый предмет в зависимости от выбора пользователя
                Weapon* newWeapon;
                if (name == "Меч") {
                    newWeapon = new Weapon(name, false, 5, 1, WeaponType::sword);
                }
                else if (name == "Лук") {
                    newWeapon = new Weapon(name, false, 5, 1, WeaponType::bow);
                }
                else if (name == "Стрела") {
                    newWeapon = new Weapon(name, false, 5, 1, WeaponType::arrow);
                }
                else if (name == "Кирка") {
                    newWeapon = new Weapon(name, false, 5, 1, WeaponType::pick);
                }
                else { // Топор
                    newWeapon = new Weapon(name, false, 5, 1, WeaponType::hatchet);
                }

                // Добавляем новый предмет в инвентарь
                addItemToInventory(newWeapon, inventory);

                cout << name << " успешно скрафчен!" << endl;
                return;
            }
        }

        cout << "Недостаточно ресурсов для крафта " << name << "." << endl;
    }

    void Resource::craftWeapon(vector<Inventory*>& inventory, const string& name, ResourceType type, int required) {
        for (int i = 0; i < inventory.size(); i++) {
            Resource* resource = dynamic_cast<Resource*>(inventory[i]);
            if (resource != nullptr && resource->resource == type && resource->getTotalQuantityInInventory() >= required) {
                resource->setTotalQuantityInInventory(resource->getTotalQuantityInInventory() - required);

                if (resource->getTotalQuantityInInventory() == 0) {
                    delete inventory[i];
                    inventory.erase(inventory.begin() + i);
                }

               
                if (name == "Лук") {
                    Weapon* newWeapon = new Weapon(name, false, 1.0, 1, WeaponType::bow);
                    addItemToInventory(newWeapon, inventory);
                }
                else if (name == "Стрела") {
                    Weapon* newWeapon = new Weapon(name, false, 1.0, 1, WeaponType::arrow);
                    addItemToInventory(newWeapon, inventory);
                }
               

            

                cout << name << " успешно скрафчен!" << endl;
                return;
            }
        }

        cout << "Недостаточно ресурсов для крафта " << name << "." << endl;
    }
