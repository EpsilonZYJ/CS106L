#include <iostream>//for cin, cout
#include <chrono>//for *fancy* timers
#include <sstream>//for stringstream
#include <iomanip>//for manipulators
#include <fstream>//for file streams
#include <vector>//for vector
#include <unordered_map>
#include <forward_list>
#include <unordered_set>

using namespace std;



void printStateBits(const istream& iss)
{
    cout << (iss.good() ? "G" : "-");
    cout << (iss.fail() ? "F" : "-");
    cout << (iss.eof() ? "E" : "-");
    cout << (iss.bad() ? "B" : "-");
    cout << '\n';
}

int stringToInteger(const string& s)
{
    istringstream iss(s);
    printStateBits(iss);

    int result;
    iss >> result;
    if(iss.fail())  throw std::domain_error("no value int at beginning!");

//    char remain;
//    iss >> remain;
//    if(!iss.fail()) throw std::domain_error("more than a single valid int!");
    if(!iss.eof()) throw std::domain_error("more than a single valid int!");

    printStateBits(iss);

    return result;
}

void stringToIntegerTest()
{
    while(true){
        cout << "Type in an integer:";
        string s;
        if(!getline(cin, s)) throw std::domain_error("getline failed");
        cout << "You type in :" << s << "\n";
        int result = stringToInteger(s);
        cout << "As an integer, this is:" << result << "\n";
        cout << "Half of that is: " << result/2 << "\n";
    }
}

void badWelcomeProgram(){
    string name, response;
    int age;

    cout << "What is your name? ";
//    cin >> name;
    getline(cin, name);

    cout << "What is your age? ";
    cin >> age;

    cout << "Hello " << name << " (age" << age << ")" << '\n';

    cout << "Do you want to try again? ";
//    cin >> response;
    getline(cin, response);

    cout << "You said: " << response << endl;
}

int get_Integer(const string& prompt){
//    cout << prompt;
//    string token;
//    cin >> token;//still a problem
//    istringstream iss(token);
//
//    int result; char trash;
//    if(!(iss >> result)|| iss >> trash)
//        return getInteger(prompt);//bad recursion
//
//    return result;


//    while(true){
//        cout << prompt;
//        string token;
//        cin >> token;//problem: only one token
//        istringstream iss(token);
//
//        int result; char trash;
//        if(iss >> result && !(iss >> trash))
//            return result;
//    }


    while(true){
        cout << prompt;
        string line;
        if(!getline(cin, line))
            throw domain_error("");
        istringstream iss(line);

        int result; char trash;
        if(iss >> result && !(iss >> trash))
            return result;
    }

}

int getInteger(const string& prompt = "[shortened]", const string reprompt = "[shortened]"){
    while(true){
        cout << prompt;
        string line; int result; char trash;
        if(!getline(cin, line))
            throw domain_error("[shortened]");
        istringstream iss(line);
        if(cin >> result && !(cin >> trash))    return result;
        cout << reprompt << endl;
    }
}

string chopBothEnds(const string& str){
    string result = "";
    for(size_t i = 1; i < str.size() - 1; ++ i){
        result += str[i];
    }
    return result;
}


auto calvulateSum(const vector<string>& v){
    auto multiplier = 2.4;
    auto name = "Avery";
    auto betterName1 = string{"Avery"};
    const auto& betterName2 = string{"Avery"};
    auto copy = v;
    auto& reMult = multiplier;
    auto func = [](auto i){return i*2;};

    return betterName1;
}

struct Discount{
    double discountFactor;
    int expirationDate;
    string nameOfDiscount;
};

//char& firstCharBad(string& s){
//    string local = s;
//    return local[0];
//}

char& firstCharGood(string& s){
    return s[0];
}

struct Time{
    int hour, minute;
};

struct Course{
    string code;
    Time start, end;
    vector<string> instructors;
};


pair<int, int> findPriceRange(int dist){
    int min = static_cast<int>(dist * 0.08 + 100);
    int max = static_cast<int>(dist * 0.36 + 750);
    return {min, max};
}


void transformToDST1(vector<Course>& courses){
    for (auto& course : courses){
        course.start.hour ++;
        course.end.hour ++;
    }
}

void transformToDST2(vector<Course>& courses){
    for(auto& [code, start, end, instructors] : courses){
        start.hour ++;
        end.hour ++;
    }
}

//void transformToDST3(const vector<Course>& courses){
//    for (const auto& course : courses){
//        course.start.hour ++;
//        course.end.hour ++;
//    }
//}     //unchanged(using const)

int main() {

//    std::cout << "Hello, World!" << std::endl;
//    ostringstream oss("Ito-En Green Tea",ostringstream ::ate);
//    oss << "16.9 Ounces";
//    cout << oss.str() << endl;


//    istringstream iss("16.9 Ounces");
//
////    double amount;
////    string unit;
////    iss >> amount;
////    iss >> unit;
////
////    cout << amount/2 << endl;
//    int amount;
//    string unit;
//
//    iss >> amount;
//    iss >> unit;
//
//    cout << amount/2 << " " << unit << endl;
//  8 .9


//    stringToIntegerTest();


//    for(int i = 0; i < 100; i++)
//        cout << i << '\n' << std::flush;
//    for(int i = 0; i < 100; i++)
//        cout << i << '\n';
//    cout << std::flush;
//
//    cout << "[" << setw(10) << "Into" << "]";
//    cout << "[" << left << setw(10) << "Into" << "]";
//    cout << "[" << left << setfill('-') << setw(10) << "Into" << "]";


//    badWelcomeProgram();

//    string prompt;
//    cin >> prompt;
//    getInteger(prompt);


//    istringstream iss("16.9\n 24");
//    double val;
//    string line;
//    iss >> val; // val == 16.9
//    getline(iss, line); // line == ""
//    getline(iss, line); // line == " 24"



//    pair, tuple
    auto prices = make_pair(3.4, 5);
    auto values = make_tuple(3, 4, "hi");

    prices.first = prices.second;
    get<0>(values) = get<1>(values);

    auto [a, b] = prices;
    const auto& [x, y, z] = values;

    auto coupon1 = Discount{0.9, 30, "New Years"};
    Discount coupon2 = {0.75, 7, "Valentine's Day"};
    coupon1.discountFactor = 0.8;
    coupon2.expirationDate = coupon1.expirationDate;

    auto [factor, date, name] = coupon1;    //C++17


//    reference
    string tea = "Ito-En";
    string copy = tea;
    string& ref = tea;

    tea[1] = 'a';   //tea = "Iao-En"
    copy[2] = 'b';  //(no change)
    ref = 'c';  //tea = "IaocEn"

    char letterCopy = tea[4];
    char& letterRef = tea[5];

    letterCopy = 'd';   //tea = "IaocEn"(no change)
    letterRef = 'e';    //tea = "IaocEe"
    ref = copy; //tea = "Iab-En"cannot reassign reference

//    char& bad = firstCharBad(tea);  //undefined, ref to local out of scope
    char& good = firstCharGood(tea);    //good ref to tea;


//    uniform initialization
    vector<int> vec{3, 1, 4, 1, 5, 9};
    Course now{
        "CS106L",
        {13, 30}, {14, 30},
        {"Wang", "Zeng"}
    };

    int dist = 6452;
    auto [min, max] = findPriceRange(dist);
    cout << "You can find prices between: "
        << min << " and " << max;


//    initializer
    vector<int> vec1{3};// vec1 = {3}
    vector<int> vec2(3);// vec2 = {0, 0, 0}


    return 0;
}
