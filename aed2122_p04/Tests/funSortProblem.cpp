#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if (products.size() > k){
        std::sort(products.begin(), products.end());
        for (int i = products.size(); i>k ;i--){
            products.pop_back();
        }
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (values.size()< nc){
        return -1;
    } else{
        vector<int> v;
        for (int i = 0;i < values.size(); i++){
            v.push_back(values.at(i));
        }

        std::sort(v.begin(),v.end());
        int max = v.at(v.size()-1);
        int imax = v.size()-1;
        int min = v.at(0);
        int imin = 0;
        while ((imax-imin+1) > nc){
            if((max-v.at(imax-1)) < (v.at(imin+1))-min){
                imin ++;
                min = v.at(imin);
            } else{
                imax --;
                max = v.at(imax);
            }
        }
        return max-min;
    }
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int max = 1;
    for (int i = 0; i<arrival.size(); i++) {
        int cont = 1;
        for (int j = 0; j < i; j++){
            if(arrival.at(i)<= departure.at(j)){
                cont ++;
            }
        }
        if(max < cont){
            max = cont;
        }
    }
    return max;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    Piece::QuickSort(nuts);
    Piece::QuickSort(bolts);

}

