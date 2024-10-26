#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <numeric> //accumulate, inner_product
#include <cmath>

using std::cout;    using std::endl;
using std::ifstream;using std::string;
using std::vector;

const vector<string> FEATURE_VEC{"a", "about"};

int countOccurences(const string& word, const string& text);
vector<int> createFreqVec(const string& text);

string fileToString(ifstream& file){
    string ret = "";
    string line;

    while(std::getline(file, line)){
        std::transform(line.begin(), line.end(), line.begin(), tolower);
//        std::transform(line.begin(), line.end(), std::back_inserter(ret), tolower); // this is slower
        ret += line + " ";
    }
    return ret;
}

int dotProduct(const vector<int>& vec1, const vector<int>& vec2){
    return std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
}

int mag(const vector<int>& vec){
    return std::sqrt(dotProduct(vec, vec));
}

double getSimilarity(const string& text1, const string& text2){
    vector<int> freqVec1 = createFreqVec(text1);
    vector<int> freqVec2 = createFreqVec(text2);

    int dotProd = dotProduct(freqVec1, freqVec2);

    return dotProd / (mag(freqVec1) * mag(freqVec2));
}

vector<int> createFreqVec(const string& text){
    vector<int> result;
    for (const auto& word: FEATURE_VEC){
        result.push_back(countOccurences(word, text));
    }
    return result;
}

int countOccurences(const string& word, const string& text){
    //"the" vs "there"
    string toFine = " " + word + " ";
    //<regex>

    auto curr = text.begin();
    auto end = text.end();
    int count = 0;

    while(curr != end){
        auto found = std::search(curr, end, toFine.begin(), toFine.end());
        if(found == end) break;
        ++count;
        curr = found + 1;
    }
    return count;
}

int main(){
    ifstream file1("madison.txt");
    ifstream file2("jj.txt");
    ifstream file3("hamilton.txt");
    ifstream file4("unknown.txt");

    string f_mad = fileToString(file1);
    string f_jj = fileToString(file2);
    string f_ham = fileToString(file3);
    string f_unk = fileToString(file4);


    cout << "Similarity - madison <-> unknown: " << getSimilarity(f_mad, f_unk) << endl;
    cout << "Similarity - jj <-> unknown: " << getSimilarity(f_jj, f_unk) << endl;
    cout << "Similarity - hamilton <-> unknown: " << getSimilarity(f_ham, f_unk) << endl;
    return 0;
}