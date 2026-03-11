#include "../inc/lib.hpp"
#include "../inc/Book.hpp"

using namespace std;

Bookmark::Bookmark() {
    color = "Red";
    material = "Paper";
    pageNumber = 1;
    cout << "Bookmark default constructor" << endl;
}

Bookmark::Bookmark(string color, string material, int pageNumber) {
    this->color = color;
    this->material = material;
    if (pageNumber > 0) {
        this->pageNumber = pageNumber;
    } else {
        this->pageNumber = 1;
    }
    cout << "Bookmark full constructor" << endl;
}

Bookmark::Bookmark(const Bookmark& other) {
    color = other.color;
    material = other.material;
    pageNumber = other.pageNumber;
    cout << "Bookmark copy constructor" << endl;
}

Bookmark::~Bookmark() {
    cout << "Bookmark destructor" << endl;
}

string Bookmark::getColor() {
    return color;
}

string Bookmark::getMaterial() {
    return material;
}

int Bookmark::getPageNumber() {
    return pageNumber;
}

void Bookmark::setColor(string color) {
    this->color = color;
}

void Bookmark::setMaterial(string material) {
    this->material = material;
}

void Bookmark::setPageNumber(int pageNumber) {
    if (pageNumber > 0) {
        this->pageNumber = pageNumber;
    }
}

Bookmark& Bookmark::operator++() {
    ++pageNumber;
    return *this;
}

Bookmark Bookmark::operator++(int) {
    Bookmark temp = *this;
    ++pageNumber;
    return temp;
}

Bookmark& Bookmark::operator--() {
    if (pageNumber > 1) {
        --pageNumber;
    }
    return *this;
}

Bookmark Bookmark::operator--(int) {
    Bookmark temp = *this;
    
    if (pageNumber > 1) {
        --pageNumber;
    }
    
    return temp;
}

void Bookmark::print() {
    cout << "<--- Bookmark Info --->" << endl;
    cout << "Color: " << color << endl;
    cout << "Material: " << material << endl;
    cout << "Page: " << pageNumber << endl;
    cout << "<---------------------->" << endl;
}

Shelf::Shelf() {
    maxCapacity = 10;
    books.clear();
    cout << "Shelf default constructor" << endl;
}

Shelf::Shelf(int maxCapacity) {
    if (maxCapacity > 0) {
        this->maxCapacity = maxCapacity;
    } else {
        this->maxCapacity = 10;
    }
    books.clear();
    cout << "Shelf constructor with capacity " << this->maxCapacity << endl;
}

Shelf::Shelf(const Shelf& other) {
    maxCapacity = other.maxCapacity;
    books = other.books;
    cout << "Shelf copy constructor" << endl;
}

Shelf::~Shelf() {
    cout << "Shelf destructor" << endl;
    books.clear();
}

vector<Book*> Shelf::getBooks() {
    return books;
}

int Shelf::getMaxCapacity() {
    return maxCapacity;
}

int Shelf::getCurrentCount() {
    return books.size();
}

void Shelf::setMaxCapacity(int maxCapacity) {
    if (maxCapacity > 0) {
        this->maxCapacity = maxCapacity;
    }
}

bool Shelf::putBook(Book* book) {
    if (book == nullptr) {
        cout << "Error. Empty result" << endl;
        return false;
    }
    
    if (books.size() >= maxCapacity) {
        cout << "Error. Shelf is full!" << endl;
        return false;
    }
    
    books.push_back(book);
    
    vector<string> bookNames = book->getNames();
    if (!bookNames.empty()) {
        cout << "Book " << bookNames[0] << " placed on shelf. ";
    } else {
        cout << "Book placed on shelf ";
    }
    
    cout << "Current: " << books.size() << "/" << maxCapacity << endl;
    return true;
}

void Shelf::swapBooks(int i, int j) {
    bool firstIndexValid = (i >= 0 && i < books.size());
    bool secondIndexValid = (j >= 0 && j < books.size());
    
    if (firstIndexValid && secondIndexValid) {
        Book* temp = books[i];
        books[i] = books[j];
        books[j] = temp;
    }
}

void Shelf::sortByName() {
    if (books.empty()) {
        cout << "Shelf is empty..." << endl;
        return;
    }
    
    int bookCount = books.size();
    
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            vector<string> namesFirst = books[j]->getNames();
            vector<string> namesSecond = books[j + 1]->getNames();
            bool hasNames = (!namesFirst.empty() && !namesSecond.empty());
            
            if (hasNames) {
                string titleFirst = namesFirst[0];
                string titleSecond = namesSecond[0];
                
                bool needToSwap = false;
                
                int minLength = titleFirst.length();
                if (titleSecond.length() < minLength) {
                    minLength = titleSecond.length();
                }
                
                for (int k = 0; k < minLength; k++) {
                    if (titleFirst[k] > titleSecond[k]) {
                        needToSwap = true;
                        break;
                    } else if (titleFirst[k] < titleSecond[k]) {
                        needToSwap = false;
                        break;
                    }
                }
                
                if (!needToSwap && (titleFirst.length() > titleSecond.length())) {
                    needToSwap = true;
                }
                
                if (needToSwap) {
                    swapBooks(j, j + 1);
                }
            }
        }
    }
    
    cout << "Books sorted!" << endl;
}

void Shelf::print() {
    cout << "\n<-------- Shelf Info --------->" << endl;
    cout << "Capacity: " << maxCapacity << endl;
    cout << "Current books: " << books.size() << endl;
    
    if (books.empty()) {
        cout << "Shelf is empty." << endl;
    } else {
        cout << "Books on shelf:" << endl;
        
        for (int i = 0; i < books.size(); i++) {
            cout << "  " << (i + 1) << ". ";
            
            if (books[i] != nullptr) {
                vector<string> bookNames = books[i]->getNames();
                
                if (!bookNames.empty()) {
                    cout << bookNames[0];
                } else {
                    cout << "Unknown title";
                }
                cout << " by " << books[i]->getAuthor();
            } else {
                cout << "Empty :(";
            }
            
            cout << endl;
        }
    }
    
    cout << "<------------------->\n" << endl;
}

void Shelf::clear() {
    books.clear();
    cout << "Shelf cleared" << endl;
}