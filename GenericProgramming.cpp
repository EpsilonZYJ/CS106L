#include <iostream>
#include <vector>
#include <sstream>
#include <concepts>
#include <functional>
#include <iterator>
#include <deque>
#include <set>
#include <algorithm>

using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::deque;
using std::set;

struct Time{
    int hour;
    int minute;
};

struct Course{
    string name;
    double rating;
    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
        os << course.name << " " << course.rating;
        return os;
    }
};

vector<Course> readCourses(){
    vector<Course> v = {{ "CS106B", 4.0 }, { "CS106X", 3.5 }, { "CS107", 4.2 }};
    return v;
}
//pair<int, int> my_minmax(int a, int b){
//    if(a < b) return {a, b};
//    else return {b, a};
//}
template <typename T>
pair<T, T> my_minmax(T a, T b){
    if(a < b) return {a, b};
    else return {b, a};
}

//void printMinAndMax(int min, int max){
//    cout << "Min: " << endl;
//    cout << "Max: " << endl;
//    cout << endl;
//}
template <typename T>
void printMinAndMax(T min, T max){
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << endl;
}

void minmaxTestBasic(){
    auto[min1, max1] = my_minmax(3, -2);
    printMinAndMax(min1, max1);

    auto[min2, max2] = my_minmax(6, 6);
    printMinAndMax(min2, max2);
}

template <typename T>
T getTypeValue(){
    while(true){
        cout << "Enter a " << typeid(T).name() << ": ";

        string line; T result; char extra;
        if(!getline(cin, line))
            throw std::domain_error("Unable to get line from cin.");
        std::istringstream iss(line);
        if(iss >> result && !(iss >> extra))
            return result;
        cout << "Invalid input." << endl;
    }
}

template <typename InputIterator, typename DataType>
int countOccurence(InputIterator begin, InputIterator end, DataType val){
    int count = 0;
    for(auto iter = begin; iter != end; ++iter){
        if(*iter == val) ++count;
    }
    return count;
}

template <typename InputIt1, typename InputIt2>
pair<int ,int> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2){
    while(first1 != last1 && *first1 == *first2){
        ++first1;
        ++first2;
    }
    return {first1, first2};
}

////C++20 Concepts
//template <typename It, typename Type>
//    requires std::input_iterator<It> && boost::algorithm::iterator_of<It> && Equality_comparable<Value_type<It>, Type>
//            int countOccurence(It begin, It end, Type val){
//                int count = 0;
//                for(auto iter = begin; iter != end; ++iter){
//                    if(*iter == val) ++count;
//                }
//                return count;
//            }

template <typename InputIterator, typename UniaryPredicate>
int countOccurences(InputIterator begin, InputIterator end, UniaryPredicate predicate){
    int count = 0;
    for(auto iter = begin; iter != end; ++iter){
        if(predicate(*iter)) ++count;
    }
    return count;
}

template <typename DataType>
inline bool lessThanTwo(DataType val){ return val <2; }

template <typename DataType>
inline bool isEven(DataType val){ return val % 2 == 0; }

template <typename DataType>
inline bool isPastMyBedTime(DataType val){
    return val.hour >= 4;
}

//Pre-C++11 solution
class GreaterThan{
public:
    GreaterThan(int limit) : limit(limit){}
    bool operator() (int val) {return val >= limit;}
private:
    int limit;
};

void erase_all(vector<int>& vec, int val){
    for(auto iter = vec.begin(); iter != vec.end();){
        if(*iter == val) iter = vec.erase(iter);
        else ++iter;
    }
}

int main(){
    //explicit instantiation
    auto [min1, max1] = my_minmax<double>(4.2, -7.9);
    auto [min2, max2] = my_minmax<int>(3, 3);
    auto [min3, max3] = my_minmax<char>('a', 'z');
    auto [min4, max4] = my_minmax<string>("Avery", "Anna");
    auto [min5, max5] = my_minmax<vector<int>>({1, 2}, {3, 1});
//    auto [min6, max6] = my_minmax<Time>({15, 30}, {16, 20});
    int val0 = getTypeValue<int>();
    int val1 = getTypeValue<int>();
    double val2 = getTypeValue<double>();
    cout << "Values: " << val0 << " " << val1 << " " << val2 << endl;
    auto [min6, max6] = my_minmax(string("Avery"), string("Anna"));

    vector<double> vec{1.0, 2.5, 3.0, 2.5, 2.5};
    deque<Time> week4{{3, 40}, {3, 40}, {1, 20}, {8, 2}};

    countOccurences(vec.begin(), vec.end(), lessThanTwo<double>);
    countOccurences(week4.begin(), week4.end(), isPastMyBedTime<Time>);

    //pre-C++11 solution
    int limit = 60;
    vector<int> grades{90, 80, 70, 60, 50, 40, 30, 20, 10};
    GreaterThan func(limit);
    countOccurences(grades.begin(), grades.end(), func);
    //C++11 solution
    auto func2 = [limit](auto val) {return val >= limit;};
    countOccurences(grades.begin(), grades.end(), func2);


    set<string> teas{"black", "green", "oolong"};
    string banned = "boba";
    //using reference capture
    auto likedByAvery = [&teas, banned](auto type){
        return teas.count(type) && type != banned;
    };

    vector<int> vec1{1, 3, 5, 7, 9};
    int limits = 5;
    int num_times_called = 0;
    auto isLessThanLimit = [limits, &num_times_called](auto val) -> bool {
        ++num_times_called;
        return val < limits;
    };
//    //lambda function
//    auto isLessThanLimit = [=, &num_times_called](auto val) -> bool {
//        ++num_times_called;
//        return val < limits;
//    };
//    auto isLessThanLimit = [limits = 0](auto val) -> bool {
//        ++num_times_called;
//        return val < limits;
//    };
    countOccurences(vec1.begin(), vec1.end(), isLessThanLimit);

    auto mult = [](int param, int factor){
        return param * factor;
    };

    auto val = mult(3, 2);
    auto multBound = std::bind(mult, std::placeholders::_1, 2);





    //algorithm
    auto courses = readCourses();

    auto compareRating = [](const Course& c1, const Course& c2){
        return c1.rating < c2.rating;
    };

    std::sort(courses.begin(), courses.end(), compareRating);
    auto median = courses[courses.size()/2];
    nth_element(courses.begin(), courses.begin()+courses.size()/2, courses.end(), compareRating);
    std::copy(courses.begin(), courses.end(),
              std::ostream_iterator<Course>(std::cout, "\n"));

    string deparment = "CS";
    auto isDep = [](auto element){
        return element.name.size() > 2 && element.name.substr(0, 2) == "CS";
    };
    vector<Course> csCourses;
    std::stable_partition(courses.begin(), courses.end(), isDep);
    std::copy_if(courses.begin(), courses.end(), std::back_inserter(csCourses), isDep);
    std::remove_if(courses.begin(), courses.end(), isDep);

    courses.erase(std::remove_if(courses.begin(), courses.end(), isDep), courses.end());


    return 0;
}