#include <vector>
#include <deque>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

//namespace mymeta{
//    template <typename T>
//    struct identity{
//        using type = T;
//        identity() = delete;
//        ~identity() = delete;
//    };
//
//    template <int V>
//    struct identity{
//        static const int value = V;
//    };
//
//    template <typename T, typename U>
//    struct is_same{
//        static const bool value = false;
//    };
//
//    template <typename T>
//    struct is_same<T, T>{
//        static const bool value = true;
//    };
//
//    template <typename T>
//    struct is_pointer{
//        static const bool value = false;
//    };
//
//    template <typename T>
//    struct is_pointer<T*>{
//        static const bool value = true;
//    };
//
//    template <typename T>
//    struct remove_const{
//        using type = T;
//    };
//
//    template <typename T>
//    struct remove_const<const T>{
//        using type = T;
//    };
//}


template <typename It>
size_t my_distance(It first, It last){
    using category = typename std::iterator_traits<It>::iterator_category;

    if constexpr (std::is_same<category, std::random_access_iterator_tag>::value){
        return last - first;
    }else{
        size_t count = 0;
        while(first != last){
            ++first;
            ++count;
        }
        return count;
    }
}

int main(){
//    std::set<std::string> names = {"Anna", "Ethan", "Nikhil", "Avery"};
    std::vector<std::string> names = {"Anna", "Ethan", "Nikhil", "Avery"};

    auto anna_iter = find(names.begin(), names.end(), "Anna");
    auto avery_iter = find(names.begin(), names.end(), "Avery");

    return my_distance(anna_iter, avery_iter);

}