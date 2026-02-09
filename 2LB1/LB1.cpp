

#include <iostream>
#include <string>

using namespace std;

class Book {

private:
    string bookName;
    int countPages;
    int mark;
    float cost;

protected:
    string author;
public:
    Book() {
        author = "Unknown";
        bookName = "Unknown";
        countPages = 0;
        mark = 0;
        cost = 0.0;
        cout << "Default constructor" << endl;
    }

    Book(string author, string bookName, int countPages, int mark, float cost) {
        this->author = author;
        this->bookName = bookName;
        this->countPages = countPages;
        this->mark = mark;
        this->cost = cost;
        cout << "Full constructor" << endl;
    }

    Book(const Book& x) {
        author = x.author;
        bookName = x.bookName;
        countPages = x.countPages;
        cost = x.cost;
        mark = x.mark;
        cout << "Copy constructor" << endl;
    }

    ~Book() {
        cout << "Start distructor" << endl;
    }

    string GetBookInfo(){
        return "Author: " + author + " Book name: " + bookName;
    }
    int GetBookPages() {
        return countPages;
    }
    int GetBookMark() {
        return mark;
    }
    float GetBookCost() {
        return cost;
    }

    void SetBookMark(int newMark) {
        if (newMark >= 0 && newMark <= 5) {
            mark = newMark;
            cout << "Mark set to: " << mark << endl;
        }
        else {
            cout << "Error!" << endl;
        }
    }

    void PrintInf() {
        cout << "––––––––––––––––––––––––––––––––––" << endl;
        cout << "Book name: " << bookName << endl;
        cout << "Author: " << author << endl;
        cout << "Mark: " << mark << "/5" << endl;
        cout << "Pages: " << countPages << endl;
        cout << "Cost: " << cost << "$" << endl;
        cout << "––––––––––––––––––––––––––––––––––" << endl;
    }

    void ChangeCost(float newCost) {
        if(newCost >= 0) {
            cost = newCost;
            cout << "Now book cost: " << newCost << endl;
        }
        else {
            cout << "WTF ERROR 404 ^_^" << endl;
        }
    }
};

int main() {
    Book WarAndPeace("Leo Tolstoy", "War and Peace", 1225, 5, 5);
    WarAndPeace.PrintInf();
    WarAndPeace.SetBookMark(4);
    WarAndPeace.ChangeCost(3);

    Book Error;
    Error.PrintInf();

    Book copy = WarAndPeace;
    copy.PrintInf();

    cout << WarAndPeace.GetBookCost() << endl;
    cout << WarAndPeace.GetBookMark() << endl;
    cout << WarAndPeace.GetBookPages() << endl;
    cout << WarAndPeace.GetBookInfo() << endl;

    return 0;
}