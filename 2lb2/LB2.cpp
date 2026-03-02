#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    
    cout << "1. Create book" << endl;
    cout << "----------------" << endl;
    
    vector<string> names1 = {"Attomic Habbits", "Bible", "Space"};
    Book book1("A", names1, 25, 100.0);
    book1.print();
    
    vector<string> names2 = {"Bible", "Day one", "Interstellar"};
    Book book2("A", names2, 50, 100.0);
    book2.print();
    
    vector<string> names3 = {"Bible", "Day one", "Interstellar"};
    Book book3("B", names3, 50, 100.0);
    book3.print();
    
    cout << "\n2. Operator + (Same authors)" << endl;
    cout << "---------------------------------------" << endl;
    Book bookPlus1 = book1 + book2;
    bookPlus1.print();
    
    cout << "\n3. Operator + (Other authors)" << endl;
    cout << "-----------------------------------" << endl;
    Book bookPlus2 = book1 + book3;
    bookPlus2.print();
    
    cout << "\n4. Operator +=" << endl;
    cout << "------------------" << endl;
    cout << "book2 += book1 (Same authors):" << endl;
    Book bookAssign1 = book2;
    bookAssign1 += book1;
    bookAssign1.print();
    
    cout << "\n5. Operator +=" << endl;
    cout << "------------------" << endl;
    cout << "book2 += book3 (Other authors):" << endl;
    Book bookAssign2 = book2;
    bookAssign2 += book3;
    bookAssign2.print();
    
    cout << "\n6. Operator / (Same authors)" << endl;
    cout << "---------------------------------------" << endl;
    vector<string> names4 = {"Bible", "C", "Bite of Python"};
    Book book4("A", names4, 25, 100.0);
    Book bookDiv1 = book4 / book2;
    bookDiv1.print();
    
    cout << "\n7. Operator / (Other authors)" << endl;
    cout << "-----------------------------------" << endl;
    Book bookDiv2 = book4 / book3;
    bookDiv2.print();
    
    cout << "\n8. Copy constructor" << endl;
    cout << "--------------------------------" << endl;
    Book bookCopy(book1);
    bookCopy.print();
    
    cout << "\n9. Operator =" << endl;
    cout << "-----------------------------" << endl;
    Book bookAssign3;
    bookAssign3 = book3;
    bookAssign3.print();
    
    cout << "The end ^_^" << endl;
    
    return 0;
}