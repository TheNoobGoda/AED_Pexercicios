#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    //return (list<Kid>());
    return kids;
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    kids = l1;
}

// TODO
Kid Game::loseGame(string phrase) {
    list<Kid>::iterator it = kids.begin();
    int num = numberOfWords(phrase);
    while (kids.size() > 1) {
        int jumps= num;
        while(kids.size()<jumps){
            jumps-=kids.size();
        }
        for (int i = 0; i < jumps; i++) {
            it++;
            if(i > kids.size()-1){
                it=kids.begin();
            }
        }
        kids.erase(it);
    }
    return kids.front();

}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> res;
    for (auto it : kids){
        if (it.getAge()> id){
            res.push_back(it);
            kids.remove(it);
        }
    }
    return (res);
}

// TODO
queue<Kid> Game::rearrange() {
    queue<Kid> male;
    queue<Kid> female;
    list<Kid> res;
    queue<Kid> tooMuch;
    int n;
    for (auto it : kids){
        if (it.getSex() == 'f'){
            female.push(it);
        }else{
            male.push(it);
        }
    }
    if(male.size()<female.size()){
        n=female.size()/male.size();
        while(male.size()>0){
            res.push_back(male.front());
            male.pop();
            for (int i =0;i<n;i++){
                res.push_back(female.front());
                female.pop();
            }
        }
        while(female.size()> 0){
            tooMuch.push(female.front());
            female.pop();
        }

    }else if(female.size()<=male.size()){
        n=male.size()/female.size();
        while(female.size()>0) {
            res.push_back(female.front());
            female.pop();
            for (int i = 0; i < n; i++) {
                res.push_back(male.front());
                male.pop();
            }
        }
        while(male.size()> 0){
            tooMuch.push(male.front());
            male.pop();
        }

    }
    setKids(res);


    return(tooMuch);
}

// TODO
bool Game::operator==(Game& g2) {
    list<Kid> kids2 = g2.getKids();
    if (kids.size() != kids2.size()){
        return false;
    }
    auto it = kids.begin();
    for (auto it2 : kids2){
        if (it->getName() != it2.getName()){
            return false;
        }else if(it->getAge() != it2.getAge()){
            return false;
        }else if(it->getSex() != it2.getSex()){
            return false;
        }
        advance(it,1);
    }
	return true;
}

// TODO
list<Kid> Game::shuffle() const {
    list<Kid> res;
    list<Kid> kids2 = kids;

    for (auto it : kids){
        auto it2 =kids2.begin();
        int n = rand()%kids2.size();
        advance(it2,n);
        res.push_back(*it2);
        kids2.remove(*it2);

    }
	return (res);
}
