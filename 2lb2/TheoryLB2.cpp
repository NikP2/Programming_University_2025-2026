// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> myVector; // создание вектора
//     myVector.push_back(2); // Помещает какой-нибудь элемент в конец вектора
//     myVector.emplace_back(3) // то же самое что и push_back, только быстрее (создаёт элемент прямо в векторе, а не создаёт его отдельно, а потом помещает в вектор)
//     myVector[0] = 100; // Помещаем новое число в вектор в определённое место
//     myVector.at(1) // как myVector[1] только он проверяет не вышли мы за диапазон, но он медленнее
//     myVector.clear() // очищает вектор
//     myVector.pop_back() // Удаляет последний элемент
//     myVector.empty() // Проверяет пустой ли вектор (true - если пустой, false - если не пустой)
//     myVector.resize(10) // изменяет размер вектора на 10. Если новый размер больше старого, то новые элементы будут заполнены нулями

//     // итератор - это указатель на элемент вектора. Он позволяет нам проходить по элементам вектора и изменять их. Итераторы бывают разных типов: begin() - возвращает итератор на первый элемент, end() - возвращает итератор на элемент, следующий за последним элементом, rbegin() - возвращает итератор на последний элемент, rend() - возвращает итератор на элемент, следующий за первым элементом (в обратном порядке). Это как срезы в Python.

//     // auto - это ключевое слово, которое позволяет компилятору автоматически определять тип переменной. Оно может быть использовано для объявления переменных, которые инициализируются значениями, тип которых не известен заранее. Например: с помощью auto можно объявить итератор для вектора, не указывая его тип: auto it = myVector.begin(); // it будет иметь тип vector<int>::iterator
    
//     myVector.insert(myVector.begin() + 1, 55) // вставляет число 55 на вторую позицию (на позицию 1)
//     myVector.erase(myVector.begin() + 1) // удаляет элемент на второй позиции (на позиции 1)
//     myVector.begin() // возвращает итератор на первый элемент
//     myVector.end() // возвращает итератор на элемент, следующий за последним элемент
    
//     unique(myVector.begin(), myVector.end()) // удаляет все повторяющиеся элементы (для этого вектор должен быть отсортирован)
    
//     myVector.capacity() // Почти как size вот только подсчитывает элементы с запасом
//     myVector.reserve(100); // выделяем память на 100. Если мы выведем myVector.capacity(), то вывод будет: 100
//     myVector.shrink_to_fit() // освобождает всю не использованную память теперь, если size() будет равен к примеру 8, то capacity тоже будет равен 8

//     vector<int> vc1(20) // в векторе будут занесены 20 нулей 
//     vector<int> vc1(20, 55) // теперь вместо 20 нулей будет 20 чисел 55
    
//     vector<int> vc2= {1, 2, 3, 4, 5} // Можно создать вектор сразу со значениями

    
//     for (int i = 0; i < myVector.size(); i++) {
//         cout << myVector[i] << endl;
//     }

//     // 1-й способ итерации по вектору исключительно с помощью индексов
//     for (size_t i = 0; i < works.size(); i++) {
//     cout << works[i] << endl;
//     }
//     // 2-й способ итерации по вектору c помощью auto
//     for (const auto& work : works) {
//         cout << work << endl;
//     }
// }

// // // Правило 3-х
// // // Если классу нужен один из сдедующих трёх методов, то ему нужны все три:
// // // 1) Конструктор копирования (Copy Constructor) - используется для создания нового объекта на основе существующего объекта. Он принимает ссылку на объект того же класса и создает новый объект, копируя данные из существующего объекта.
// // // 2) Оператор присваивания (Copy Assignment Operator) - используется для присваивания одного объекта другому объекту того же класса. Он принимает ссылку на объект того же класса и копирует данные из существующего объекта в текущий объект.
// // // 3) Деструктор (Destructor) - используется для освобождения ресурсов, которые были выделены для объекта. Он вызывается автоматически при уничтожении объекта и освобождает все ресурсы, которые были выделены для объекта, такие как память, файлы и т.д.


// //     return 0;
// // }


// // class Book {
// // public:
// //     vector<string> works;
// //     string author;
// //     int pages;
// //     float cost;
    
// //     // 1. ДЕСТРУКТОР - чистим перед удалением
// //     ~Book() {
// //         works.clear();
// //     }
    
// //     // 2. КОНСТРУКТОР КОПИРОВАНИЯ - копируем всё
// //     Book(const Book& other) {
// //         works = other.works;    // Копируем список
// //         author = other.author;  // Копируем автора
// //         pages = other.pages;    // Копируем страницы
// //         cost = other.cost;      // Копируем стоимость
// //     }
    
// //     // 3. ОПЕРАТОР = - заменяем всё
// //     Book& operator=(const Book& other) {
// //         works = other.works;    // Заменяем список
// //         author = other.author;  // Заменяем автора
// //         pages = other.pages;    // Заменяем страницы
// //         cost = other.cost;      // Заменяем стоимость
// //         return *this;
// //     }
// // };


// // Конструктор копирования

// #include <iostream>
// #include <string>
// using namespace std;

// class MyClass {
//     public:
//         int *data;
//         MyClass(int size) {
//             this->data = new int[size];
//             this->Size = size;
//             for (int i = 0; i < size; i++) {
//                 data[i] = i;
//             }
//             cout << "Вызвался конструктор " << this << endl;
//         }
//         // оператор присваивания
//         MyClass & operator= (const MyClass& other) {
//             this->Size = other.Size;
//             cout << "Вызвался оператор =" << this << endl;
//             if (this->data != nullptr) {
//                 delete[] this->data;
//             }
//             return *this;
//         }

//         ~MyClass() {
//             cout << "Вызвался деструктор " << this << endl;
//             delete[] data;
//         }

//         // конструктор копирования
//         MyClass(const MyClass& other) {
//             this->Size = other.Size;
//             this->data = new int[other.Size];
//             for (int i = 0; i < other.Size; i++) {
//                 this->data[i] = other.data[i];
//             }
//             cout << "Вызвался конструктор копирования " << this << endl;
//         }

//     private:
//         int Size;
// };

// int main() {
//     MyClass a(10);
//     MyClass b(2);
//     MyClass c(5);
//     c = a = b;
//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point() {
        x = 0;
        y = 0;
        cout << this << " constructor" << endl;
    }

    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
        cout << this << " constructor" << endl;
    }

    bool operator== (const Point &other){
        // 1-й способ:

        return this->x == other.x && this->y == other.y;

        // 2-й способ:

        // if (this->x == other.x && this->y == other.y){
        //     return true;
        // }
        // else
        //     return false;
    }

    bool operator!= (const Point &other) {
        return !(this->x == other.x && this->y == other.y);
    }

    Point operator+ (const Point &other) {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator- (const Point &other) {
        return Point(this->x - other.x, this->y - other.y);
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

};

int main() {

    Point a(5, 1);
    Point b(9, 1);

    bool result = a != b;

    Point sum = a + b;
    sum.print();
    sum = a - b;
    sum.print();


    return 0;
}