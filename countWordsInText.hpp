#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#pragma once

using namespace std;

// Вспомогательная структура для хранения пары "слово: количество"
struct WordCount {
    string word;
    unsigned int count;
};

// Вспомогательная функция для сравнения двух структур WordCount
bool compareByCount(const WordCount& a, const WordCount& b) {
    return a.count > b.count;
}

// Вспомогательная функция для подсчета одного слова в тексте
unsigned int countWord(const string& text, const string& word) {
    unsigned int count = 0;
    size_t pos = 0;

    // Поиск всех вхождений слова в тексте
    while ((pos = text.find(word, pos)) != string::npos) {
        // Проверка границ слова (пробел или начало/конец строки)
        bool isWord = (pos == 0 || !isalpha(text[pos - 1])) &&
                      (pos + word.size() >= text.size() || !isalpha(text[pos + word.size()]));

        if (isWord) {
            ++count;
        }
        pos += word.size();
    }
    return count;
}

// Вспомогательная функция для разбиения строки на слова
vector<string> splitString(const string& str, char delimiter = ' ') {
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

// Основная функция, принимающая три аргумента и возвращающая вектор строк
vector<string> countWordsInText(const string& list_of_words, const string& text, bool reverse = false) {
    vector<string> words = splitString(list_of_words);
    vector<WordCount> counts;

    for (const auto& word : words) {
        unsigned int count = countWord(text, word);
        counts.push_back({word, count});
    }

    // Сортировка по количеству вхождений слов
    if (!reverse) {
        sort(counts.begin(), counts.end(), compareByCount);
    } else {
        sort(counts.rbegin(), counts.rend(), compareByCount);
    }

    vector<string> results;
    for (const auto& wc : counts) {
        results.push_back(wc.word + ": " + to_string(wc.count));
    }

    return results;
}
