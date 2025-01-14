#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "countWordsInText.hpp"

using namespace std;

int main() {
    string list_of_words;
    cout << "Введите список слов..." << endl;
    cin >> list_of_words;
    
    string text;
    cout << "Введите текст..." << endl;
    cin >> text;
    
    vector<string> result = countWordsInText(list_of_words, text);
    for (const auto& res : result) {
        cout << res << endl;
    }
    return 0;
}

