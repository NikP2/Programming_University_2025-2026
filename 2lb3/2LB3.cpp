#include <iostream>
#include "../inc/Book.hpp"
#include "../inc/lib.hpp"

using namespace std;

void evaluateLabWork() {
    cout << "<---------- Mark ---------->" << endl;
    cout << "Интерес: 8/10 интересно создавать библиотеку (чувствуешь себя hard прогером)" << endl;
    cout << "Сложность: 9/10 (требует понимания ООП)" << endl;
    cout << "------------------------------------\n" << endl;
}

int main() {
    Bookmark bm1("Blue", "Silk", 42);
    cout << "Create bookmark:" << endl;
    bm1.print();
    
    cout << "\nTest ++ and --:" << endl;
    cout << "Current page: " << bm1.getPageNumber() << endl;
    ++bm1;
    cout << "++bm1: " << bm1.getPageNumber() << endl;
    bm1++;
    cout << "bm1++: " << bm1.getPageNumber() << endl;
    --bm1;
    cout << "--bm1: " << bm1.getPageNumber() << endl;
    bm1--;
    cout << "bm1--: " << bm1.getPageNumber() << endl;
    
    
    vector<string> names1 = {"Atomic Habits", "Bible", "Space"};
    Book book1("A", names1, 300, 500.0);
    
    cout << "\nДобавить закладку:" << endl;
    Bookmark* bookmark = new Bookmark("Red", "Paper", 128);
    book1.setBookmark(bookmark);
    delete bookmark;
    
    book1.print();
    
    cout << "\nПеремещение закладки:" << endl;
    Bookmark* bm = book1.getBookmark();
    if (bm != nullptr) {
        ++(*bm);
        cout << "Закладка перемещена на страницу " << bm->getPageNumber() << endl;
    }
    book1.print();
    
    vector<string> names2 = {"Python Programming", "Algorithms", "Data Science"};
    vector<string> names3 = {"C++ Basics", "STL Tutorial", "OOP Patterns"};
    vector<string> names4 = {"JavaScript Guide", "Web Development", "React"};
    
    Book book2("B", names2, 250, 450.0);
    Book book3("C", names3, 320, 550.0);
    Book book4("D", names4, 180, 350.0);
    Book book5("E", vector<string>{"AAA Book", "BBB"}, 100, 200.0);
    
    Shelf shelf(5);
    cout << "\nСтавим книги на полку:" << endl;
    shelf.putBook(&book1);
    shelf.putBook(&book2);
    shelf.putBook(&book3);
    shelf.putBook(&book4);
    shelf.putBook(&book5);
    
    shelf.print();
    
    cout << "\nСортируем книги по названию (bubble-sort):" << endl;
    shelf.sortByName();
    shelf.print();
    
    vector<string> names5 = {"Book X", "Book Y"};
    vector<string> names6 = {"Book Y", "Book Z"};
    
    Book book6("E", names5, 100, 200.0);
    Book book7("E", names6, 150, 250.0);
    Book book8("F", names6, 150, 250.0);
    
    cout << "operator+ (одинаковые авторы):" << endl;
    Book sum1 = book6 + book7;
    sum1.print();
    
    cout << "operator+ (разные авторы):" << endl;
    Book sum2 = book6 + book8;
    sum2.print();
    
    cout << "operator+=:" << endl;
    Book assign1 = book6;
    assign1 += book7;
    assign1.print();
    
    cout << "operator/:" << endl;
    Book div1 = book6 / book7;
    div1.print();
    
    Book testBook("Test Author", vector<string>{"Test Book"}, 100, 500.0);
    cout << "Начальное состояние:" << endl;
    testBook.print();
    
    cout << "\nОценка книги:" << endl;
    testBook.ratePositive();
    testBook.ratePositive();
    testBook.rateNegative();
    cout << "Текущий рейтинг: " << testBook.getRating() << endl;
    
    cout << "\nИзменение ценв:" << endl;
    testBook.changePrice(50.0); 
    testBook.changePrice(-30.0);
    testBook.print();
    evaluateLabWork(); 
    return 0;
}