// // Классы БАЗА


#include <iostream>
#include <string>

using namespace std;

//public
//protected *
//private

class Car {

private:
    float diametr_tires; // cm
    int wheels;
    string color;
    string mark;
public:

    void set_info() {
        cout << "How many wheels: ";
        cin >> wheels; // Ждем ввода числа
        
        cout << "Diametr tires: ";
        cin >> diametr_tires;
        
        cout << "Color car: ";
        cin >> color;
        
        cout << "Mark car: ";
        cin >> mark;
    }

    void get_info() {
        cout << "Color: " << color << ". Wheels: " << wheels << ". Diametr_tires: " << diametr_tires << ". Mark: " << mark << endl;
    }

};

int main() {

    Car car;
    car.set_info();
    car.get_info();

    return 0;
}


// #include <iostream>
// #include <string>

// using namespace std;

// /* модификаторы доступа
// public - любые вещи будут доступны везде
// private - любые поля или методы доступны искючительно внутри класса
// protected - доступ будет доступен как в исходном классе так и в классе наследника

// инкапсуляция - все поля должны быть закрыты от прямого доступа к ним в другом смысле использование private
// */

// class Building {

// private:
//     int year;
//     string type;
// public: // модификатор доступа public

//     void set_data(int y, string t) {
//         year = y;
//         type = t;
//     }
//     void get_info() {
//         cout << "type: " << type << ". Year: " << year << endl;
//     }
// };

// int main() {
//     Building school;
//     school.set_data(2000, "School");
//     school.get_info();

//     Building house;
//     house.set_data(2008, "House");
//     house.get_info();
    
//     return 0;
// }


// Конструкторы, Диструкторы

/* конструкторы необходимо прописывать в модификаторы доступа public!!! В конструкторах можно делать перегрузку

В методах перегрузку тоже можно делать

Деструкторы - вызываются в момент уничтожения объекта

this - позволяет нам обратиться к вещам, которые находятся внутри самого класса
*/


// #include <iostream>
// #include <string>

// using namespace std;

// class Building {
// private:
//     int year;
//     string type;
// public:
//     Building(int y, string t) { //конструктор
//         set_data(y, t);
//     }

//     Building() {} //пустой конструктор
    
//     void set_data(int year, string type) {
//         this->year = year; //мы обращаемся к текущему классу и устанавливам поле, которое совпадает с названием.
//         this->type = type;
//     }
//     void get_info() {
//         cout << "type: " << type << ". Year: " << year << endl;
//     }

//     ~Building() { //диструктор
//         cout << "Delete object" << endl;
//     }
// };

// int main() {
//     Building school(2000, "School");
//     school.get_info();

//     Building house;
//     house.get_info();
    
//     return 0;
// }


// Инкапсуляция геттер и сеттер (get / set)

/*Геттеры и сеттеры находятся в public они нужны для того, чтобы получить данные (get) или установить (set)*/

// #include <iostream>
// #include <string>

// using namespace std;

// class Point {
// private:
//     int x;
//     int y;

// public:
//     int Get_x() { // геттер (получает значения) 
//         return x;
//     }

//     void Set_x(int valueX) { // сеттер (устанавливает значение)
//         x = valueX;
//     }

//     void Print() {
//         cout << "X = " << x << "\t Y = " << y << endl;
//     }

// };

// int main() {

//     /*Point a;
//     a.x = 12; Так не очень правильно. Лучше всего всегда использовать геттер или сеттер*/

//     Point a;
//     a.Set_x(12);
//     // a.Print();
    
//     int result = a.Get_x();
//     cout << result << endl;

//     return 0;
// }


// #include <iostream>
// #include <string>

// using namespace std;

// class CoffeeGrinder {

// private:
//     bool CheckVoltage() {
//         return false;
//     }

// public:
//     void Start() {
//         bool voltageIsNormal = CheckVoltage();
//         if (voltageIsNormal) {
//             cout << "VjuHHH!" << endl;
//         }
//         else {
//             cout << "Pik Pik" << endl;
//         }
//     }

// };

// int main() {
//     CoffeeGrinder a;
//     a.Start();
//     return 0;
// }