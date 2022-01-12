#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

//TODO
void Dictionary::readFile(ifstream &f) {
    while (!f.eof()){
        string word;
        string mean;
        getline(f, word);
        getline(f, mean);
        words.insert(WordMean (word, mean));
    }
}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    for (auto it{words.begin()}, end{words.end()}; it != end; previous = *(it++))
        if (word1 <= (*it).getWord()) {
            next = *(it);
            break;
        }

    if (word1 == next.getWord())
        return next.getMeaning();

    return "word not found";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}

//TODO
void Dictionary::print() const {
    //words.printTree();
}

bool WordMean::operator<(const WordMean &wordMean)const {
    if (this->getWord() < wordMean.getWord()){
        return true;
    }else{
        return false;
    }
}

bool WordMean::operator==(const WordMean &wordMean)const {
    if (this->getWord() == wordMean.getWord()){
        return true;
    }else{
        return false;
    }
}
