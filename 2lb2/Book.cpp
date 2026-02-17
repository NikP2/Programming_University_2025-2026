#include "Book.h"

using namespace std;

Book::Book() {
    this->author = "Unknown";
    this->pages = 0;
    this->price = 0.0;
    cout << "Default constructor" << endl;
}

Book::Book(string author, vector<string> bookNames, int pages, double price) {
    this->author = author;
    this->bookNames = bookNames;
    this->pages = pages;
    this->price = price;
    cout << "Full constructor" << endl;
}

Book::Book(const Book& other) {
    this->author = other.author;
    this->bookNames = other.bookNames;
    this->pages = other.pages;
    this->price = other.price;
    cout << "Copy constructor" << endl;
}

Book::~Book() {
    cout << "Start distructor" << endl;
    this->bookNames.clear();
}

Book& Book::operator=(const Book& other) {
    cout << "Start operator =" << endl;
    if (this != &other) {
        this->author = other.author;
        this->bookNames = other.bookNames;
        this->pages = other.pages;
        this->price = other.price;
    }
    return *this;
}

Book Book::operator+(const Book& other) {
    cout << "Start operator +" << endl;
    Book result;
    if (this->author != "Unknown" && other.author != "Unknown") {
        if (this->author == other.author) {
            result.author = this->author;
        } else {
            result.author = this->author + " и " + other.author;
        }
    } else {
        result.author = (this->author != "Unknown") ? this->author : other.author;
    }

    vector<string> allNames;
    for (size_t i = 0; i < this->bookNames.size(); i++) {
        if (!inVector(allNames, this->bookNames[i])) {
            allNames.push_back(this->bookNames[i]);
        }
    }
    
    for (size_t i = 0; i < other.bookNames.size(); i++) {
        if (!inVector(allNames, other.bookNames[i])) {
            allNames.push_back(other.bookNames[i]);
        }
    }
    
    result.bookNames = allNames;
    result.pages = this->pages + other.pages;
    result.price = this->price + other.price;
    return result;
}

Book& Book::operator+=(const Book& other) {
    cout << "Start operator +=" << endl;
    
    if (this->author != "Unknown" && other.author != "Unknown") {
        if (this->author != other.author) {
            this->author = this->author + " и " + other.author;
        }
    } else if (this->author == "Unknown") {
        this->author = other.author;
    }
    
    vector<string> allNames;
    
    bool differentAuthors = (this->author.find(" и ") != string::npos);
    
    if (differentAuthors) {
        string firstAuthor = this->author.substr(0, this->author.find(" и "));
        string secondAuthor = other.author;
        for (size_t i = 0; i < this->bookNames.size(); i++) {
            string formattedName = format(pure(this->bookNames[i]), firstAuthor);
            if (!inVector(allNames, formattedName)) {
                allNames.push_back(formattedName);
            }
        }
        for (size_t i = 0; i < other.bookNames.size(); i++) {
            string formattedName = format(pure(other.bookNames[i]), secondAuthor);
            if (!inVector(allNames, formattedName)) {
                allNames.push_back(formattedName);
            }
        }
    } else {
        for (size_t i = 0; i < this->bookNames.size(); i++) {
            string pureName = pure(this->bookNames[i]);
            if (!inVector(allNames, pureName)) {
                allNames.push_back(pureName);
            }
        }
        
        for (size_t i = 0; i < other.bookNames.size(); i++) {
            string pureName = pure(other.bookNames[i]);
            if (!inVector(allNames, pureName)) {
                allNames.push_back(pureName);
            }
        }
    }
    
    this->bookNames = allNames;
    this->pages = this->pages + other.pages;
    this->price = (this->price + other.price) * 0.85;
    
    return *this;
}

Book Book::operator/(const Book& other) {
    cout << "Start operator /" << endl;
    
    Book result;
    
    if (this->author != "Unknown" && other.author != "Unknown") {
        if (this->author == other.author) {
            result.author = this->author;
        } else {
            result.author = this->author + " и " + other.author;
        }
    } else {
        result.author = (this->author != "Unknown") ? this->author : other.author;
    }
    
    vector<string> selectedNames;
    bool differentAuthors = (this->author != other.author) && (this->author != "Unknown") && (other.author != "Unknown");
    
    int count = 0;
    for (size_t i = 0; i < this->bookNames.size() && count < 2; i++) {
        string nameToAdd;
        if (differentAuthors) {
            nameToAdd = format(pure(this->bookNames[i]), this->author);
        } else {
            nameToAdd = pure(this->bookNames[i]);
        }
        
        if (!inVector(selectedNames, nameToAdd)) {
            selectedNames.push_back(nameToAdd);
            count++;
        }
    }
    
    count = 0;
    for (size_t i = 0; i < other.bookNames.size() && count < 2; i++) {
        string nameToAdd;
        if (differentAuthors) {
            nameToAdd = format(pure(other.bookNames[i]), other.author);
        } else {
            nameToAdd = pure(other.bookNames[i]);
        }
        
        if (!inVector(selectedNames, nameToAdd)) {
            selectedNames.push_back(nameToAdd);
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

void Book::setAuthor(string author) { 
    this->author = author; 
}

void Book::setPages(int pages) { 
    this->pages = pages; 
}

void Book::setPrice(double price) { 
    this->price = price; 
}


void Book::print() {
    cout << "<--- Information about book --->" << endl;
    cout << "Author: " << this->author << endl;
    cout << "Pages: " << this->pages << endl;
    cout << "Price: " << str(this->price) << " руб." << endl;
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
    cout << "___________________________" << endl;
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