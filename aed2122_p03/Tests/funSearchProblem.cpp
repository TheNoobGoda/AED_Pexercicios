#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    int cont = 0;
    for (int i = 0 ; i < values.size(); i++){
        bool bo = true;
        for (int j = 0; j<i ; j++){
            if (values.at(i) <= values.at(j)){
                bo = false;
            }
        }
        if (bo) {
            cont += 1;
        }
    }
    return cont;
}

// TODO
int FunSearchProblem::squareR(int num) {
    vector<int> sqrt;
    for (int i = 1 ; i<num ; i++){
        sqrt.push_back(i);
    }

    int left = 0;
    int right = sqrt.size()-1;

    while (left <= right){
        int middle = (left+right)/2;
        if ((sqrt.at(middle)*sqrt.at(middle)) < num){
            left = middle +1;

        } else if (num < (sqrt.at(middle)*sqrt.at(middle))){
            right = middle -1;

        } else {
            return sqrt.at(middle);
        }
    }

    return 0;
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    bool bo = true;
    int cont = 0;
    int max = 0;
    for (int i = 0; i<values.size(); i++){
        if (max < values.at(i)){
            max = values.at(i);
        }
    }
    if (max > 0){
        cont = 0;
        while (bo){
            cont ++;
            bo = false;
            for (int i = 0; i<values.size(); i++){
                if (cont == values.at(i)){
                    bo = true;
                }
            }

        }
        return cont;
    }else {
        return 0;
    }
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    if (values.size() < numSt){
        return -1;
    }
    int max = 0;
    for (int i = 0; i<values.size(); i++){
        if (max < values.at(i)){
            max = values.at(i);
        }
    }



    return 0;
}

