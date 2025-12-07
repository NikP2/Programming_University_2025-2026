// ЛАБ-7

// ПУНКТ 1

#include <iostream>
#include <vector>
#include <climits>

void watch(const std::vector<int>& vec) {
    if(vec.size() == 0) {
        std::cout << "[" << "]" << std::endl;
    }
    else {
        std::cout << "[ ";
        for(int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
}

void push_start(std::vector<int>& vec) {
    int value;
    std::cout << "Введите число для добавления в начало: ";
    std::cin >> value;
    vec.insert(vec.existsgin(), value);
    std::cout << "Элемент " << value << " добавлен в начало.\n";
}

void push_end(std::vector<int>& vec) {
    int value;
    vec.reserve(1);
    std::cout << "Введите число для добавления в конец: ";
    std::cin >> value;
    vec.push_back(value);
    std::cout << "Элемент " << value << " добавлен в конец.\n";
}

void cleaning(std::vector<int>& vec) {
    vec.clear();
    std::cout << "Массив очищен!" << std::endl;
}

void search(std::vector<int>& vec) {
    int value;
    std::cout << "Введите число которое хотите найти в массиве: ";
    std::cin >> value;
    std::cout << "[ ";
    for(int i = 0; i < vec.size(); i++) {
            if(value == vec[i]) {
                std::cout << i << " ";
            }
        }
    std::cout << "]";
    std::cout << std::endl;
}

void my(std::vector<int>& vec) {
    int mi = INT_MAX;
    std::cout << "Ваш массив до: ";
    std::cout << "[ ";
        for(int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    std::cout << "]";
    std::cout << std::endl;

    for(int i = 0; i < vec.size(); i++) {
            if(mi > abs(vec[i]) && (vec[i] != 0)) {
                mi = abs(vec[i]);
            }
        }
    vec.resize(vec.size() + mi, 0);
    std::cout << "Ваш массив После: ";
    std::cout << "[ ";
        for(int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    std::cout << "]";
    std::cout << std::endl;
}

int main(){
    int ans = -1;
    std::vector<int> vec;
    while (ans != 0) {
        std::cout << "Выберите нужный пункт: " << '\n';
        std::cout << "0 - Выход" << '\n';
        std::cout << "1 - Просмотр массива" << '\n';
        std::cout << "2 - Добавить элемент в НАЧАЛО массива" << '\n';
        std::cout << "3 - Добавить элемент в КОНЕЦ массива" << '\n';
        std::cout << "4 - Очистить массив" << '\n';
        std::cout << "5 - Поиск элементов массива" << '\n';
        std::cout << "6 - Добавление в конец нулей по определённому сценарию" << '\n';
        std::cin >> ans;
        if (ans == 0) {
            std::cout << "Программа завершена!" << std::endl;
        }
        else if (ans == 1) {
            watch(vec);
        }
        else if (ans == 2) {
            push_start(vec);
        }
        else if (ans == 3) {
            push_end(vec);
        }
        else if (ans == 4) {
            cleaning(vec);
        }
        else if (ans == 5) {
            search(vec);
        }
        else if (ans == 6) {
            my(vec);
        }
        else {
            std::cout << "Такой команды нет :(" << std::endl;
        }
    }
    return 0;
}


// ПУНКТ 2

#include <iostream>
#include <array>

void value(std::array<int, 10> arr) {
    std::cout << "Массив ДО сортировки: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Массив ПОСЛЕ сортировки по ВОЗРАСТАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "Массив ПОСЛЕ сортировки по УБЫВАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void link(std::array<int, 10>& arr) {
    std::cout << "Массив ДО сортировки: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Массив ПОСЛЕ сортировки по ВОЗРАСТАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "Массив ПОСЛЕ сортировки по УБЫВАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void pointer(std::array<int, 10>* arr) {
    std::cout << "Массив ДО сортировки: ";
    for (int i = 0; i < 10; i++) {
        std::cout << (*arr)[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if ((*arr)[j] > (*arr)[j + 1]) {
                int temp = (*arr)[j];
                (*arr)[j] = (*arr)[j + 1];
                (*arr)[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Массив ПОСЛЕ сортировки по ВОЗРАСТАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << (*arr)[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if ((*arr)[j] < (*arr)[j + 1]) {
                int temp = (*arr)[j];
                (*arr)[j] = (*arr)[j + 1];
                (*arr)[j + 1] = temp;
            }
        }
    }

    std::cout << "Массив ПОСЛЕ сортировки по УБЫВАНИЮ: ";
    for (int i = 0; i < 10; i++) {
        std::cout << (*arr)[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 10> arr;
    int x;
    int fl;
    for (int i = 0; i < 10; i++) {
        fl = 1;
        while (fl == 1) {
            std::cout << "Введи число из дипазона [-10; 10]: " << '\n';
            std::cin >> x;
            if ((-10 <= x) && (x <= 10)) {
                arr[i] = x;
                fl = 0;
            }
            else {
                std::cout << "Введи число из дипазона [-10; 10]!!! " << '\n';
            }
        }
    }

    std::cout << "ПО УКАЗАТЕЛЮ: " << '\n';
    std::array<int, 10> copy_arr = arr;
    pointer(&copy_arr);
    std::cout << "ПО ЗНАЧЕНИЮ: " << '\n';
    value(arr);
    std::cout << "ПО ССЫЛКЕ: " << '\n';
    link(arr);


    return 0;
}

/* Передача массива в функцию по ЗНАЧЕНИЮ:

// 1. Работает с копией, не меняет оригинал
// 2. Нужна доп память для копии
// 3. работает слегка медленее из-за копирования 
// 4. Простой синтаксис

*/

// ---------------------------------------------

/* Передача массива в функцию по ССЫЛКЕ:

// 1. Передаёт ссылку на массив и меняет оригинал
// 2. Не нужна доп память для копии
// 3  работает быстрее и менее муторно (нужен всего лишь смперсант &)
// 4. Простой синтаксис

// */

// ---------------------------------------------


/*
// Передача массива в функцию по УКАЗАТЕЛЮ:

// 1. Передаёт адрес массива в памяти, меняет оригинал
// 2. Надо разыменовывать указатель
// 3. для низкоуровневых операций
// 4. более муторный синтаксис
// */

//ПУНКТ 3

/* Выбрал vector в первом пункте из-за его большего функционала, так-как надо было добавлять элементы в разные месте и постоянно менять массив, что проще c вектором, чем с array. Во втором пункте я выбрал array так как у меня больше не было выбора. Array слегка прост в понимании, он схож с обычным массивом. В array легче задать размер, чем в векторе. std::array<int, 10> (размер по просту фиксирован). Можно ещё сказать, что vector находится в куче, так как по сути это динамический массив, в то время array находится в стэке. Общее: Они оба работают с массивами, вот только vector более функционален и глубок, поэтому он будет использован в 1 пункте.  Здесь нет выбора! Во втором пункте размер фиксирован, в первом он динамичен, что лучше для vector.*/

// ---------------------------------------------------------------------------------------------------

// ЛАБ-8

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Lock {
    string material;
    string design;
};

struct MidPearl {
    string color;
    float size;
    bool exists;
};

struct EndPearl {
    string color;
    float size;
    bool exists;
};

struct Jewelry {
    Lock lock;
    MidPearl midPearl;
    EndPearl endPearl;
    int id;
    
    bool isFinished() const {
        return !lock.material.empty() && midPearl.exists && endPearl.exists;
    }
};

vector<Jewelry> catalog;
int nextId = 1;

void viewElement() {
    cout << endl;
    if (catalog.empty()) {
        cout << "Каталог пуст! Создайте украшения!";
        return;
    }
    
    cout << "\n----------> ПРОСМОТР УКРАШЕНИЯ <----------" << endl;
    cout << "Введите ID украшения (1-" << catalog.size() << "): ";
    int id;
    cin >> id;
    
    if (id < 1 || id > catalog.size()) {
        cout << "Неверный ID!";
        return;
    }
    
    bool found = false;
    for (int i = 0; i < catalog.size(); i++) {
    if (catalog[i].id == id) {
        found = true;
        cout << "УКРАШЕНИЕ №" << catalog[i].id << endl;
        
        cout << "ЗАМОК: ";
        if (catalog[i].lock.material.empty()) {
            cout << "отсутствует" << endl;
        } else {
            cout << catalog[i].lock.material << endl;
        }
        cout << "ДИЗАЙН: ";
        if (catalog[i].lock.design.empty()) {
            cout << "не указан" << endl;
        } else {
            cout << catalog[i].lock.design << endl;
        }
        
        cout << "ЖЕМЧУГ СЕРЕДИНЫ: ";
        if (catalog[i].midPearl.exists) {
            cout << catalog[i].midPearl.color << ", " << catalog[i].midPearl.size << " мм" << endl;
        } else {
            cout << "отсутствует" << endl;
        }
        
        cout << "ЖЕМЧУГ КОНЦА: ";
        if (catalog[i].endPearl.exists) {
            cout << catalog[i].endPearl.color << ", " << catalog[i].endPearl.size << " мм" << endl;
        } else {
            cout << "отсутствует" << endl;
        }
        
        cout << "СТАТУС: ";
        if (catalog[i].isFinished()) {
            cout << "ЗАКОНЧЕНО" << endl;
        } else {
            cout << "НЕЗАКОНЧЕНО" << endl;
        }
        break;
    }
}
    
    if (!found) {
        cout << "Украшение не найдено!" << endl;
    }
}

void create() {
    cout << "\n----------> СОЗДАНИЕ НОВОГО УКРАШЕНИЯ <----------" << endl;
    
    Jewelry newJewelry;
    if (nextId <= 5) {
        newJewelry.id = nextId++;
        string ch;
        cout << "Добавить замок? (y/n): ";
        cin >> ch;
        if (ch == "y" || ch == "Y") {
            cout << "Материал замка: ";
            cin >> newJewelry.lock.material;
            cout << "Дизайн замка: ";
            cin >> newJewelry.lock.design;
        } else {
            newJewelry.lock.material = "";
            newJewelry.lock.design = "";
        }
        
        cout << "Добавить жемчуг середины? (y/n): ";
        cin >> ch;
        if (ch == "y" || ch == "Y") {
            newJewelry.midPearl.exists = true;
            cout << "Цвет жемчуга середины: ";
            cin >> newJewelry.midPearl.color;
            cout << "Размер жемчуга середины (мм): ";
            cin >> newJewelry.midPearl.size;
        } else {
            newJewelry.midPearl.exists = false;
            newJewelry.midPearl.color = "";
            newJewelry.midPearl.size = 0.0;
        }
        
        cout << "Добавить жемчуг конца? (y/n): ";
        cin >> ch;
        if (ch == "y" || ch == "Y") {
            newJewelry.endPearl.exists = true;
            cout << "Цвет жемчуга конца: ";
            cin >> newJewelry.endPearl.color;
            cout << "Размер жемчуга конца (мм): ";
            cin >> newJewelry.endPearl.size;
        } else {
            newJewelry.endPearl.exists = false;
            newJewelry.endPearl.color = "";
            newJewelry.endPearl.size = 0.0;
        }
        cout << endl;
        catalog.push_back(newJewelry);
        cout << "Украшение №" << newJewelry.id << " создано!" << endl;
    }
    else {
        cout << endl;
        cout << "На этом всё! Прилавок переполнен!" << endl;
    }
}

void Unfinished() {
    cout << "----------> НЕЗАКОНЧЕННЫЕ УКРАШЕНИЯ <----------" << endl;
    bool found = false;
    for (int i = 0; i < catalog.size(); i++) {
        if (!catalog[i].isFinished()) {
            found = true;
            cout << "Украшение №" << catalog[i].id << ":" << endl;
            cout << "Не хватает: ";
            if (catalog[i].lock.material.empty()) {
                cout << "замка, ";
            } 
            if (!catalog[i].midPearl.exists) { 
                cout << "жемчуга середины, ";
            }
            if (!catalog[i].endPearl.exists) {
                cout << "жемчуга конца.";
            }
        }
        cout << endl;
    }
    
    if (!found) {
        cout << "Незаконченных украшений нет." << endl;
    }
}

void viewAll() {
    if (catalog.empty()) {
        cout << "Каталог пуст!" << endl;
        return;
    }
    cout << "----------> ВСЕ УКРАШЕНИЯ <----------" << endl;
    cout << endl;
    for (int i = 0; i < catalog.size(); i++) {
        cout << "Украшение №" << catalog[i].id << ": ";
        if (catalog[i].isFinished()) {
            cout << "ЗАКОНЧЕНО" << endl;
        } else {
            cout << "НЕЗАКОНЧЕНО" << endl;
        }
    }
}

void Menu() {
    cout << "\n----------> Меню <----------" << endl;
    cout << "1. Просмотреть конкретное украшение" << endl;
    cout << "2. Создать новое украшение" << endl;
    cout << "3. Показать только незаконченные украшения" << endl;
    cout << "4. Показать все украшения" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите пункт: ";
}


int main() {  
    string ch;
    do {
        Menu();
        cin >> ch;
        if (ch == "1") {
            viewElement();
        }
        else if (ch == "2") {
            create();
        }
        else if (ch == "3") {
            Unfinished();
        }
        else if (ch == "4") {
            viewAll();
        }
        else if (ch == "0") {
            if (catalog.size() >= 3) {
                cout << "До скорой встречи!" << endl;
                break;
            }
            else {
                cout << endl;
                cout << "Недостаточно украшений. Соберите ещё! Уже собрали: " << catalog.size() << endl;
                ch = "-1";
            }
        }
        else {
            cout << endl;
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
        cout << endl;
        
    } while (ch != "0");
    return 0;
}