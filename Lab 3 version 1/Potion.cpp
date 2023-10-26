#include "Potion.h"

Potions::Potions(const string& name, bool canStoreMoreThanOne, double weight,  unsigned int totalQuantityInInventory, PotionType Potion)
    : Inventory(name, canStoreMoreThanOne, weight, totalQuantityInInventory), Potion(Potion) {}

void Potions::printMes()
{
    cout << "Какое зелье вы хотите выпить? Введите номер слота: ";
}

void Potions::usePotion(vector<Inventory*>& inventory) {
    Potions* pot = new Potions("Зелье силы", false, 0.5, 1, PotionType::strengthPotion);
    // Показываем инвентарь
    if (inventory.size() == 0) {
        cout << "Инвентарь пуст!" << endl;
        return;
    }
    printInventory(inventory);

    // Запрашиваем у пользователя, какое зелье он хочет выпить
    pot->printMes();
    int num = inputNum();
    num--;

        // Проверяем, корректен ли ввод пользователя
    if (num < 0 || num >= inventory.size()) {
        cout << "Некорректный ввод. Пожалуйста, введите номер слота в диапазоне от 0 до " << inventory.size()  << "." << endl;
        return;
    }
    
    // Получаем предмет из выбранного слота
    Inventory* item = inventory[num];
    Potions* potion = dynamic_cast<Potions*>(item);

    // Проверяем, является ли предмет зельем
    if (potion == nullptr) {
        cout << "Выбранный предмет не является зельем." << endl;
        return;
    }

    // Выводим сообщение в зависимости от типа зелья
    if (potion->getName() == "Зелье регенерации") {
        cout << "Вы выпили зелье регенерации. Ваше здоровье восстановлено!" << endl;
    }
    else if (potion->getName() == "Зелье ночного зрения") {
        cout << "Вы выпили зелье ночного зрения. Вы всёвидящий!" << endl;
    }
    else if (potion->getName() == "Зелье силы") {
        cout << "Вы выпили зелье силы. Ваша сила увеличена!" << endl;
    }
    else {
        cout << "Вы выпили зелье сокорости! Вы прям как Флеш!" << endl;
    }

    // Удаляем зелье из инвентаря
    delete inventory[num];
    inventory.erase(inventory.begin() + num);
}