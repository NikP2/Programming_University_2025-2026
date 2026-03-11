#include "../inc/Book.hpp"
#include "../inc/lib.hpp"

using namespace std;

Book::Book() {
    this->author = "Unknown";
    this->pages = 0;
    this->price = 0.0;
    this->rating = 0;
    this->bookmark = nullptr;
    cout << "Book: Default constructor" << endl;
}

Book::Book(string author, vector<string> bookNames, int pages, double price) {
    this->author = author;
    this->bookNames = bookNames;
    this->pages = pages;
    this->price = price;
    this->rating = 0;
    this->bookmark = nullptr;
    cout << "Book: Full constructor" << endl;
}

Book::Book(const Book& other) {
    this->author = other.author;
    this->bookNames = other.bookNames;
    this->pages = other.pages;
    this->price = other.price;
    this->rating = other.rating;
    
    if (other.bookmark != nullptr) {
        this->bookmark = new Bookmark(*other.bookmark);
    } else {
        this->bookmark = nullptr;
    }
    
    cout << "Book: Copy constructor" << endl;
}

Book::~Book() {
    cout << "Book: Destructor" << endl;
    if (bookmark != nullptr) {
        delete bookmark;
        bookmark = nullptr;
    }
    this->bookNames.clear();
}

Book& Book::operator=(const Book& other) {
    cout << "Book: Operator =" << endl;
    if (this != &other) {
        this->author = other.author;
        this->bookNames = other.bookNames;
        this->pages = other.pages;
        this->price = other.price;
        this->rating = other.rating;
        
        if (this->bookmark != nullptr) {
            delete this->bookmark;
            this->bookmark = nullptr;
        }
        
        if (other.bookmark != nullptr) {
            this->bookmark = new Bookmark(*other.bookmark);
        }
    }
    return *this;
}

Book Book::operator+(const Book& other) {
    cout << "Book: Operator +" << endl;
    Book result;
    vector<string> allNames;
    
    for (size_t i = 0; i < this->bookNames.size(); i++) {
        allNames.push_back(this->bookNames[i]);
    }
    for (size_t i = 0; i < other.bookNames.size(); i++) {
        allNames.push_back(other.bookNames[i]);
    }

    if (this->author != other.author) {
        result.author = this->author + " и " + other.author;
        result.bookNames = allNames;
    } else {
        result.author = this->author;
        vector<string> uniqueNames;
        for (size_t i = 0; i < allNames.size(); i++) {
            bool found = false;
            for (size_t j = 0; j < uniqueNames.size(); j++) {
                if (allNames[i] == uniqueNames[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                uniqueNames.push_back(allNames[i]);
            }
        }
        result.bookNames = uniqueNames;
    }
    
    result.pages = this->pages + other.pages;
    result.price = this->price + other.price;
    
    return result;
}

Book& Book::operator+=(const Book& other) {
    cout << "Book: Operator +=" << endl;
    
    if (this->author != other.author) {
        this->author = this->author + " и " + other.author;
    }
    
    vector<string> allNames;
    for (size_t i = 0; i < this->bookNames.size(); i++) {
        allNames.push_back(this->bookNames[i]);
    }
    for (size_t i = 0; i < other.bookNames.size(); i++) {
        allNames.push_back(other.bookNames[i]);
    }
    
    vector<string> uniqueNames;
    for (size_t i = 0; i < allNames.size(); i++) {
        bool found = false;
        for (size_t j = 0; j < uniqueNames.size(); j++) {
            if (allNames[i] == uniqueNames[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueNames.push_back(allNames[i]);
        }
    }
    
    this->bookNames = uniqueNames;
    this->pages = this->pages + other.pages;
    this->price = (this->price + other.price) * 0.85;
    
    return *this;
}

Book Book::operator/(const Book& other) {
    cout << "Book: Operator /" << endl;
    
    Book result;
    
    if (this->author != "Unknown" && other.author != "Unknown") {
        if (this->author == other.author) {
            result.author = this->author;
        } else {
            result.author = this->author + " и " + other.author;
        }
    } else {
         if (this->author != "Unknown") {
            result.author = this->author;
        } else {
            result.author = other.author;
        }
    }
    
    vector<string> selectedNames;
    int count = 0;
    for (size_t i = 0; i < this->bookNames.size() && count < 2; i++) {
        if (!inVector(selectedNames, this->bookNames[i])) {
            selectedNames.push_back(this->bookNames[i]);
            count++;
        }
    }
    
    count = 0;
    for (size_t i = 0; i < other.bookNames.size() && count < 2; i++) {
        if (!inVector(selectedNames, other.bookNames[i])) {
            selectedNames.push_back(other.bookNames[i]);
            count++;
        }
    }
    
    result.bookNames = selectedNames;
    result.pages = static_cast<int>((this->pages + other.pages) * 0.7);
    result.price = (this->price + other.price) * 1.1;
    return result;
}

string Book::getAuthor() {
    return this->author;
}

vector<string> Book::getNames() {
    return this->bookNames;
}

int Book::getPages() {
    return this->pages;
}

double Book::getPrice() {
    return this->price;
}

int Book::getRating() {
    return this->rating;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setPages(int pages) {
    this->pages = pages;
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setRating(int rating) {
    this->rating = rating;
}

void Book::setBookmark(Bookmark* bm) {
    if (this->bookmark != nullptr) {
        delete this->bookmark;
    }
    
    if (bm != nullptr) {
        this->bookmark = new Bookmark(*bm);
        cout << "Bookmark placed in book." << endl;
    } else {
        this->bookmark = nullptr;
    }
}

Bookmark* Book::getBookmark() {
    return this->bookmark;
}

void Book::removeBookmark() {
    if (this->bookmark != nullptr) {
        delete this->bookmark;
        this->bookmark = nullptr;
        cout << "Bookmark removed from book." << endl;
    } else {
        cout << "No bookmark in this book." << endl;
    }
}

void Book::ratePositive() {
    rating++;
    cout << "Rating + to " << rating << endl;
}

void Book::rateNegative() {
    rating--;
    cout << "Rating - to " << rating << endl;
}

void Book::changePrice(double x) {
    price += x;
    cout << "Price changed by " << x << ". New price: " << price << endl;
}

void Book::print() {
    cout << "<--- Information about book --->" << endl;
    cout << "Author: " << this->author << endl;
    cout << "Pages: " << this->pages << endl;
    cout << "Price: " << this->price << " руб." << endl;
    cout << "Rating: " << this->rating << endl;
    cout << "Bookname (" << this->bookNames.size() << "): ";
    
    if (this->bookNames.empty()) {
        cout << "Unknown bookname";
    } else {
        cout << "[";
        for (size_t i = 0; i < this->bookNames.size(); i++) {
            cout << this->bookNames[i];
            if (i < this->bookNames.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
    }
    cout << endl;
    
    if (this->bookmark != nullptr) {
        cout << "Bookmark: Yes (page " << bookmark->getPageNumber() << ")" << endl;
    } else {
        cout << "Bookmark: No" << endl;
    }
    
    cout << "-----------------------" << endl;
}

string Book::format(const string& name, const string& auth) {
    if (auth.empty() || auth == "Unknown") {
        return name;
    }
    return auth + "+" + name;
}

bool Book::inVector(const vector<string>& vec, const string& name) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == name) {
            return true;
        }
    }
    return false;
}

string Book::pure(const string& formattedName) {
    for (size_t i = 0; i < formattedName.length(); i++) {
        if (formattedName[i] == '+') {
            return formattedName.substr(i + 1);
        }
    }
    return formattedName;
}

string Book::str(double value) {
    int intPart = static_cast<int>(value);
    int fracPart = static_cast<int>((value - intPart) * 100 + 0.5);
    
    string result;
    
    if (intPart == 0) {
        result = "0";
    } else {
        int temp = intPart;
        while (temp > 0) {
            char digit = '0' + (temp % 10);
            result = digit + result;
            temp /= 10;
        }
    }
    result += ".";
    
    if (fracPart < 10) {
        result += "0";
    }
    if (fracPart == 0) {
        result += "0";
    } else {
        int temp = fracPart;
        string fracStr;
        while (temp > 0) {
            char digit = '0' + (temp % 10);
            fracStr = digit + fracStr;
            temp /= 10;
        }
        result += fracStr;
    }
    return result;
}