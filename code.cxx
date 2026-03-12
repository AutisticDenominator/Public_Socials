#include <iostream>
#include <string>
#include <map>
#include <./http_library/cpp-httplib/httplib.h>
using namespace std;

class Persons{
public:
    string First_Name;
    string Last_Name;
    string Country;

    Persons(string First_Name, string Last_Name, string Country){
        this->First_Name = First_Name;
        this->Last_Name = Last_Name;
        this->Country = Country;
    }
};

class Results{
public:
    string Username;
    string Url;
    string Page_Body;

    Results(string Username, string Url, string Page_Body){
        this->Username = Username;
        this->Url = Url;
        this->Page_Body = Page_Body;
    }
};

int main(){
    return 0;
}