#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
using namespace std;

class Piece {
    string id;
    float diameter;
public:
    Piece(string i, float d);
    string getId() const;
    float getDiameter() const;
    static void QuickSort(vector<Piece> &n);
};

#endif
