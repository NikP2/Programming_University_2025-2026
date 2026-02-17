#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string author;
    vector<string> bookNames;
    int pages;
    double price;

    // Вспомогательные методы
    string format(const string& name, const string& auth);
    bool inVector(const vector<string>& vec, const string& name);
    string pure(const string& formattedName);
    string str(double value);

public:
    // Конструкторы
    Book();
    Book(string author, vector<string> bookNames, int pages, double price);
    Book(const Book& other);
    
    // Деструктор
    ~Book();
    
    // Операторы
    Book& operator=(const Book& other);
    Book operator+(const Book& other);
    Book& operator+=(const Book& other);
    Book operator/(const Book& other);
    
    // Геттеры
    string getAuthor();
    vector<string> getNames();
    int getPages();
    double getPrice();
    
    // Сеттеры
    void setAuthor(string author);
    void setPages(int pages);
    void setPrice(double price);
    
    void print();
};