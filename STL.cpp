#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <deque>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

const int kNumInts = 20;
const int ELEM_TO_FIND = 5;

struct Node{
    double x;
    double y;
};

struct SimpleGraph{
    vector<Node> nodes;
    vector<Edge> edges;
};

void doBubbleSort(vector<int>& v){
    for(size_t i = 0; i < v.size(); i ++){
        for(size_t j = 0; j < v.size() - i -1; j ++){
            if(v[j] > v[j+1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

//int main(){
//    vector<int> vec(kNumInts);
//    for(size_t i = 0; i < vec.size(); ++i){
//        vec[i] = rand();
//    }
//    doBubbleSort(vec);
//    for(size_t i = 0; i < vec.size(); ++i){
//        cout << vec[i] << endl;
//    }
//    return 0;
//}

string GetLine(){
    string response;
    std::getline(cin, response);
    return response;
}

void printVec(const vector<int>& vec){
    for(auto elem: vec){
        cout << elem << " ";
    }
    cout << endl;
}
int main(){
    vector<int> vec(kNumInts);
    std::generate(vec.begin(), vec.end(), rand);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, "\n"));


    //associative containers
    std::map<int, float> mp;
    std::set<int> set;
    std::unordered_map<int, float> ump;
    std::unordered_set<int> uset;

    std::map<string, int> frequencyMap;
    cout << "Enter words." << endl;
    while(true){
        cout << ">";
        string response = GetLine();
        if(response.empty()) break;
        std::istringstream stream(response);
        string word;
        while(stream >> word){
            frequencyMap[word];//automatically create an entry and default initialize it if not exist
            frequencyMap.at(word);// throw an error if not exist
            ++frequencyMap[word];
        }
    }
    cout << "Enter words to look up." << endl;
    while(true){
        cout << ">";
        string response = GetLine();
        if(response.empty()) break;
        //Returns the number of keys equal to response
        //In anything but a multimap/multiset, this is
        //either going to be 1 or 0
        if(frequencyMap.count(response)){
            cout << frequencyMap[response] << " entries found." << endl;
        }
        else{
            cout << "None." << endl;
        }
    }

    std::deque<int> dq;
    dq.push_front(1);

    std::stack<int> stk;

    //iterators
    std::set<int> mySet;
    std::set<int>::iterator iter = mySet.begin();
    *iter;  //dereference
    ++iter;
    if(iter == mySet.end()) cout << "End of set." << endl;
    std::set<int>::iterator itr = mySet.begin();
    while(itr != mySet.end()){
        cout << *itr << endl;
        ++itr;
    }
    cout << endl;

    std::pair<std::string, int> p;
    p.first = "Phone number";
    p.second = 6507232300;

    std::pair<std::string, int> p_{"Phone number", 6507232300};
    std::make_pair("Phone number", 6507232300);
    auto time = std::make_pair(1, 45);// Do not need to know the type

    std::multimap<int, int> myMMap;
    myMMap.insert(std::make_pair(3, 3));
    myMMap.insert({3, 12});
    cout << myMMap.count(3) << endl;

    //Map iterator
    std::map<int, int> m;
    std::map<int, int>::iterator i = m.begin();
    std::map<int, int>::iterator end = m.end();
    while(i != end){
        cout << (*i).first << (*i).second << endl;
        ++i;
    }


    std::map<std::string, int> freqMap;
    freqMap = readUserWords();
    std::map<std::string, int>::iterator it = freqMap.begin();
    while (it != freqMap.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }
    for(auto elem : freqMap){
        cout << elem.first << " " << elem.second << endl;
    }
    for(auto [key, value] : freqMap){
        cout << key << " " << value << endl;
    }

    std::set<int> elems{1, 1, 2, 3, 4, 5, 6};
    cout << elems.size() << endl;
    auto testit = std::find(set.begin(), set.end(), ELEM_TO_FIND);
    if(testit != set.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    vector<int> vec1{3, 1, 4, 2, 5, 8, 6, 9, 0};
    printVec(vec1);
    std::sort(vec1.begin(), vec1.begin()+3);

    std::set<int>::iterator iter_low = elems.lower_bound(4);//find the samllest element >= key
    std::set<int>::iterator iter_end = elems.upper_bound(6);//find the smallest element > key
    for(; iter_low != iter_end; ++iter_low){
        cout << *iter_low << " ";
    }

    //myMap.cout(key) is slower than std::find(myMap.begin(), myMap.end(), key)
    return 0;
}