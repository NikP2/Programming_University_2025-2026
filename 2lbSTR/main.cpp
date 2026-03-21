#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

bool isRus(wchar_t c) {
    return (c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я') || c == L'Ё' || c == L'ё';
}

bool isLetDig(wchar_t c) {
    return isRus(c) || (c >= L'0' && c <= L'9');
}


wstring clean(wstring& s) {
    int st = 0;
    int en = s.length() - 1;
    while (st <= en && !isLetDig(s[st])) {
        st++;
    }
    while (en >= st && !isRus(s[en])){
     en--;
    }
        
    if (st > en) {
        return L"";
    }
    return s.substr(st, en - st + 1);
}

wstring toLower(wstring& s) {
    wstring res = s;
    for (size_t i = 0; i < res.length(); i++) {
        if (res[i] >= L'А' && res[i] <= L'Я') {
        res[i] = res[i] + (L'а' - L'А');
        }
            
        else if (res[i] == L'Ё'){
             res[i] = L'ё';
        }
    }
    return res;
}

// Проверка, содержит ли слово запрещённые буквы
bool hasZ(wstring& word, wstring& zletters) {
    wstring lowerWord = toLower(word);
    for (size_t i = 0; i < lowerWord.length(); i++) {
        for (size_t j = 0; j < zletters.length(); j++) {
            if (lowerWord[i] == zletters[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    wcout.imbue(std::locale("ru_RU.UTF-8"));
    ios_base::sync_with_stdio(false);
    
    // Пункт 0
    wstring rus = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя";
    wstring eng = L"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    wstring znak = L",.!?;:-()\"\'";
    wstring dig = L"0123456789";

    wcout << L"Русский алфавит:" << endl;
    for (size_t i = 0; i < rus.length(); i++) {
    wcout << rus[i] << L" : " << static_cast<int>(rus[i]) << endl;
}

    wcout << L"\nАнглийский алфавит:" << endl;
    for (size_t i = 0; i < eng.length(); i++) {
        int code = static_cast<int>(eng[i]);
        wcout << eng[i] << L" : " << code << endl;
    }

    wcout << L"\nЗнаки препинания:" << endl;
    for (size_t i = 0; i < znak.length(); i++) {
        int code = static_cast<int>(znak[i]);
        wcout << znak[i] << L" : " << code << endl;
    }

    wcout << L"\nЦифры:" << endl;
    for (size_t i = 0; i < dig.length(); i++) {
        int code = static_cast<int>(dig[i]);
        wcout << dig[i] << L" : " << code << endl;
    }
    wcout << endl;

    // Пункт 1
    wchar_t sog[] = L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    
    wchar_t str[201] = {0};
    wchar_t result[201] = {0};
    int i = 0, j = 0;
    
    wprintf(L"Введите текст не более 100 символов: ");
    
    while (i < 200) {
        wchar_t ch = getwchar();
        if (ch == L'\n') {
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i] = L'\0';
    
    wprintf(L"Исходный текст: %ls\n", str);
    
    for (int n = 0; n < i; n++) {
        wchar_t c = str[n];
        bool issog = false;
        for (int k = 0; sog[k] != L'\0'; k++) {
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
    wprintf(L"После удаления согласных: %ls\n", result);

    // Пункт 2
    wifstream fin("input.txt");
    if (!fin.is_open()) {
        wcout << L"Error opening file!";
        return 1;
    }
    
    int n;
    wstring zstr;
    
    fin >> n;
    fin.ignore();
    
    getline(fin, zstr);
    if (zstr.empty()) {
        wcout << L"Error reading string!";
        return 0;
    }
    
    fin.close();
    
    wcout << L"N = " << n << endl;
    wcout << L"Запрещённое слово = " << zstr << endl;
    
    wstring zletters;
    wstring lowerz = toLower(zstr);
    for (size_t i = 0; i < lowerz.length(); i++) {
        if (zletters.find(lowerz[i]) == wstring::npos) {
            zletters += lowerz[i];
        }
    }

    wifstream textF("text.txt");
    if (!textF.is_open()) {
        wcout << L"Error opening file!\n";
        return 1;
    }
    
    const int mx = 100000;
    wstring words[mx];
    int lens[mx];
    int cnt = 0;
    wstring cur;
    wchar_t ch;
    
    while (textF.get(ch)) {
        if (isLetDig(ch)) {
            cur += ch;
        } 
        else {
            if (!cur.empty() && cnt < mx) {
                wstring w = clean(cur);
                if (!w.empty()) {
                    if (!hasZ(w, zletters)) {
                        wstring lowerW = toLower(w);
                        bool unik = true;
                        for (int i = 0; i < cnt; i++) {
                            if (toLower(words[i]) == lowerW) {
                                unik = false;
                                break;
                            }
                        }
                        
                        if (unik) {
                            words[cnt] = w;
                            lens[cnt] = w.length();
                            cnt++;
                        }
                    }
                }
                cur.clear();
            } 
            else {
                cur.clear();
            }
        }
    }

    if (!cur.empty() && cnt < mx) {
        wstring w = clean(cur);
        if (!w.empty()) {
            if (!hasZ(w, zletters)) {
                wstring lowerW = toLower(w);
                bool unik = true;
                
                for (int i = 0; i < cnt; i++) {
                    if (toLower(words[i]) == lowerW) {
                        unik = false;
                        break;
                    }
                }
                
                if (unik) {
                    words[cnt] = w;
                    lens[cnt] = w.length();
                    cnt++;
                }
            }
        }
    }
    textF.close();
    
    if (cnt == 0) {
        wcout << L"Нет нужных слов\n";
        return 0;
    }
    
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (lens[j] < lens[j + 1]) {
                int tmpL = lens[j];
                lens[j] = lens[j + 1];
                lens[j + 1] = tmpL;
                
                wstring tmpW = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tmpW;
            } else if (lens[j] == lens[j + 1]) {
                if (toLower(words[j]) > toLower(words[j + 1])) {
                    wstring tmpW = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = tmpW;
                }
            }
        }
    }
    
    // ========== ЗАПИСЬ РЕЗУЛЬТАТА В result.txt ==========
    wofstream outFile("result.txt");
    if (!outFile.is_open()) {
        wcout << L"Error opening file!";
        return 1;
    }

    int take;
        if (n < cnt) {
            take = n;
        } 
        else {
            take = cnt;
        }
    
    for (int i = 0; i < take; i++) {
        outFile << words[i] << endl;
        wcout << words[i] << endl;;
    }
    outFile.close();

    return 0;
}