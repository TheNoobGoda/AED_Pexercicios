#include "piece.h"

Piece::Piece(string i, float d): id(i), diameter(d) {}

string Piece::getId() const {
    return id;
}

float Piece::getDiameter() const {
    return diameter;
}

void Piece::QuickSort(vector<Piece> &n) {
    for (int i = 0;i<n.size(); i++){
        for (int j = 0;j<n.size()-1;j++){
            if(n.at(j+1).diameter < n.at(j).diameter){
                Piece aux = n.at(j);
                n.at(j)=n.at(j+1);
                n.at(j+1)= aux;
            }
        }
    }
}
