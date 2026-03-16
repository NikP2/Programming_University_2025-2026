#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "C.UTF-8");
    setlocale(LC_CTYPE, "C.UTF-8");
    
    // Пункт 0
    wstring rus = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя";
    wstring eng = L"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    
    wcout << L"Русский алфавит:" << endl;
    for (int i = 0; i < rus.length(); i++) {
        int code = static_cast<int>(static_cast<unsigned char>(rus[i]));
        wcout << rus[i] << L" : " << code << endl;
    }
    
    wcout << L"\nАнглийский алфавит:" << endl;
    for (int i = 0; i < eng.length(); i++) {
        int code = static_cast<int>(eng[i]);
        wcout << eng[i] << L" : " << code << endl;
    }
    cout << endl;

    // Пункт 1
    ofstream tout;
    
    char sog[] = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    
    char str[201] = {0};
    char result[201] = {0};
    int i = 0, j = 0;
    
    tout.open("text.txt");
    cout << "Введите текст не более 100 символов: ";
    
    while (i < 200) {
        char ch = cin.get();
        if (ch == '\n') {
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    
    cout << "Исходный текст: " << str << endl;
    
    for (int n = 0; n < i; n++) {
        char c = str[n];
        bool issog = false;
        for (int k = 0; sog[k] != '\0'; k++) {
            if (c == sog[k]) {
                issog = true;
                break;
            }
        }
        if (!issog) {
            result[j] = c;
            j++;
        }
    }
    result[j] = '\0';
    
    cout << "После удаления согласных: " << result << endl;
    tout << result;
    tout.close();
    
    return 0;
}