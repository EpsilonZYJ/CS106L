#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class StringVector : public vector<string>{
public:
    StringVector& operator+=(const string& element);
    StringVector operator+(const StringVector& other) const;
 private:
    size_type logicalSize;
    size_type allocatedSize;
    string *elems;
};

class Fraction{
private:
    int num;
    int denom;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};
//vector<string>& vector<string>::operator+=(const string& element){
//    push_back(element);
//    return *this;
//}
//
//vector<string>& vector<string>::operator+=(const vector<string>& other){
//    for(string val : other)
//        push_back(val);
//    return *this;
//}


StringVector& StringVector::operator+=(const std::string& element){
    push_back(element);
    return *this;
}

StringVector StringVector::operator+(const StringVector& other) const{
    StringVector result = *this;
    for(const std::string& s : other){
        result += s;
    }
    return result;
}

//symmetric operator such as +, -overload: use non-member function
StringVector operator+(const StringVector& first, const StringVector& second){
    StringVector result = first;
    for(const std::string& s : second){
        result += s;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
    os << f.num << "/" << f.denom;
}

string& vector<string>::operator[](size_t index){
    return elems[index];
}

const string& vector<string>::operator[](size_t index) const{
    return elems[index];
}

StringVector::StringVector():
    logicalSize(0), allocatedSize(kInitialSize){
    elems = new std::string[allocatedSize];
}

int main(){

}