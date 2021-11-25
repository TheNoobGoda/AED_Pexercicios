#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

bool Product::operator<(const Product p1) {
    if (price < p1.price){
        return true;
    }else if(price == p1.price){
        return (weight < p1.weight);
    }else return false;
}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}
