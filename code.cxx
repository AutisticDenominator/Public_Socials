#include <iostream>
#include <string>
#include <map>
#include <./http_library/cpp-httplib/httplib.h>
using namespace std;

class Results{
public:
    string Username;
    string Url;
    string Page_Body;

    Results() = default;
    Results(string Username, string Url, string Page_Body){
        this->Username = Username;
        this->Url = Url;
        this->Page_Body = Page_Body;
    }
};

class Persons{
public:
    string First_Name;
    string Last_Name;
    string Country;

    Results Result_List[256];

    Persons(string First_Name, string Last_Name, string Country){
        this->First_Name = First_Name;
        this->Last_Name = Last_Name;
        this->Country = Country;
    }
};

int main(){
    return 0;
}