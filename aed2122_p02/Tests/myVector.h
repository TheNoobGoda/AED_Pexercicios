#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    T vmax;
    vmax = 0;
    if ( values.size() == 0){
        throw EmptyVector();
    }
    for (int i =0; i< values.size(); i++){
        if (vmax < values.at(i)) {
            vmax = values.at(i);
        }
    }

	return vmax;
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {
    for (int i; i< values.size(); i++){
        for (int j =0; j < i; j++){
            if (values.at(i) == values.at(j)){
                return true;
            }
        }
        for (int j = i+1;j < values.size(); j++){
            if (values.at(i) == values.at(j)){
                return true;
            }
        }
    }

	return false;
}

// TODO
template<class T>
void MyVector<T>::removeDuplicates() {
    for (int i; i< values.size(); i++){
        for (int j =0; j < i; j++){
            if (values.at(i) == values.at(j)){
                values.erase(values.begin()+j);
            }
        }
        for (int j = i+1;j < values.size(); j++){
            if (values.at(i) == values.at(j)){
                values.erase(values.begin()+j);
            }
        }
    }
}

