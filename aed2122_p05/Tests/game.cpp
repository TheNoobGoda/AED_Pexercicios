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
    return (list<Kid>());
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

    }else if(female.size()<male.size()){
        n=male.size()/female.size();
        while(female.size()>0){
            res.push_back(female.front());
            female.pop();
            for (int i =0;i<n;i++){
                res.push_back(male.front());
                female.pop();
            }
            while(male.size()> 0){
                tooMuch.push(male.front());
                male.pop();
            }
        }
    }else{
        n=1;
    }
    setKids(res);


    return(tooMuch);
}

// TODO
bool Game::operator==(Game& g2) {
	return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}
