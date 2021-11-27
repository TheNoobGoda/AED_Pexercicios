# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//TODO
template <class T> 
bool StackExt<T>::empty() const {
    if (values.size() == 0 and minimums.size() == 0){
        return true;
    }
	return false;
}

//TODO
template <class T> 
T& StackExt<T>::top() {

    return values.top();
}

//TODO
template <class T> 
void StackExt<T>::pop() {
    T n = values.top();
    values.pop();
    if (values.size() == 0){
        minimums.pop();
    }else{
        if (n == minimums.top()) {
            minimums.pop();
            stack<T> aux = values;
            T min = aux.top();
            for (int i = 0; i < aux.size(); i++) {
                if (min > aux.top()) {
                    min = aux.top();
                }
                aux.pop();
            }
            minimums.push(min);
        }
    }
}

//TODO
template <class T> 
void StackExt<T>::push(const T& val) {
    values.push(val);
    if (minimums.size() == 0){
        minimums.push(val);
    }else if(val < minimums.top()){
        minimums.pop();
        minimums.push(val);
    }
}

//TODO
template <class T> 
T& StackExt<T>::findMin() {
    return minimums.top();
}

