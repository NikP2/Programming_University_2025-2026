#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Book.hpp"

using namespace std;

struct Bookmark {
private:
    string color;
    string material;
    int pageNumber;
public:
    Bookmark();
    Bookmark(string color, string material, int pageNumber);
    Bookmark(const Bookmark& other);
    ~Bookmark();

    string getColor();
    string getMaterial();
    int getPageNumber();
    
    void setColor(string color);
    void setMaterial(string material);
    void setPageNumber(int pageNumber);

    Bookmark& operator++();
    Bookmark operator++(int);
    Bookmark& operator--();
    Bookmark operator--(int);

    void print();
};

class Shelf {
private:
    vector<Book*> books;
    int maxCapacity;
    void swapBooks(int i, int j);

public:
    Shelf();
    Shelf(int maxCapacity);
    Shelf(const Shelf& other);
    ~Shelf();
    vector<Book*> getBooks();
    int getMaxCapacity();
    int getCurrentCount();
    
    void setMaxCapacity(int maxCapacity);
    bool putBook(Book* book);
    void sortByName();
    void print();
    void clear();
};