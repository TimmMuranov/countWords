#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "countWordsInText.hpp"

using namespace std;

int main() {
    string list_of_words = "слово слово1 слово2";
    string text = "Это тестовый текст, где встречаются такие слова как слово, слово1 и слово2.";

    // Пример вызова без сортировки (по убыванию)
    vector<string> result = countWordsInText(list_of_words, text);
    cout << "Без сортировки:" << endl;
    for (const auto& res : result) {
        cout << res << endl;
    }

    // Пример вызова с сортировкой по возрастанию
    vector<string> result_reverse = countWordsInText(list_of_words, text, true);
    cout << "\nСортировка по возрастанию:" << endl;
    for (const auto& res : result_reverse) {
        cout << res << endl;
    }

    return 0;
}

