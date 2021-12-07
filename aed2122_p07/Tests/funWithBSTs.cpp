// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2012]

#include <set>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
// TODO
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {

    set<int> s1;
    for (int i = 0;i<collection.size();i++){
        s1.insert(collection.at(i));
    }

    set<int> s2 = s1;

    for (int i = 0;i<bag.size();i++){
        s1.insert(bag.at(i));
    }

  return s1.size()-s2.size();
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
// TODO
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    multiset<int> s1;
    multiset<int> s2;
    for (int i = 0;i<alice.size();i++){
        s1.insert(alice.at(i));
    }

    for (int i = 0;i<bruno.size();i++){
        s2.insert(bruno.at(i));
    }
    while (s1.size() > 0 && s2.size()> 0){
        auto it1 =s1.end();
        auto it2 = s2.end();
        it1--;
        it2--;
        if (*it1<*it2){
            int c = *it2-*it1;
            s1.erase(it1);
            s2.erase(it2);
            s2.insert(c);
        }else if(*it2<*it1){
            int c = *it1-*it2;
            s2.erase(it2);
            s1.erase(it1);
            s1.insert(c);
        }else{
            s1.erase(it1);
            s2.erase(it2);
        }
    }
    int n= 0;
    if (s1.size()<s2.size()){
        n -= s2.size();
    }else if(s2.size()<s1.size()){
        n += s1.size();
    }
  return n;
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
// TODO
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    //set<pair<string,int>> s1(reviews.begin(),reviews.end());
    set<string> s1;
    for (int i =0;i<reviews.size();i++){
        s1.insert(reviews.at(i).first);
    }
  return s1.size();
}

// ..............................
// b) O filme com mais reviews
// TODO
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
}

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    return answer;
}
