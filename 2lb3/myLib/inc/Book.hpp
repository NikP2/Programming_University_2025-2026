#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Bookmark;

class Book {
private:
    string author;
    vector<string> bookNames;
    int pages;
    double price;
    int rating;
    Bookmark* bookmark;

    string format(const string& name, const string& auth);
    bool inVector(const vector<string>& vec, const string& name);
    string pure(const string& formattedName);
    string str(double value);

public:
    Book();
    Book(string author, vector<string> bookNames, int pages, double price);
    Book(const Book& other);
    ~Book();
    Book& operator=(const Book& other);
    Book operator+(const Book& other);
    Book& operator+=(const Book& other);
    Book operator/(const Book& other);
    
    string getAuthor();
    vector<string> getNames();
    int getPages();
    double getPrice();
    int getRating();
    
    void setAuthor(string author);
    void setPages(int pages);
    void setPrice(double price);
    void setRating(int rating);
    
    void ratePositive();
    void rateNegative();
    void changePrice(double x);
    void setBookmark(Bookmark* bm);
    Bookmark* getBookmark();
    void removeBookmark();
    
    void print();
};