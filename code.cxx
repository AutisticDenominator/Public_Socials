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
    
    Results Result_List[256];
    int size = 0;

    Persons() = default;
    Persons(string First_Name, string Last_Name){
        this->First_Name = First_Name;
        this->Last_Name = Last_Name;
    }
};

class Toolbox{
public:
    string Request(string Page_Url, string Internal_Url){

        httplib::Client cli(Page_Url);

        if(auto response = cli.Get(Internal_Url)){
            if(response->status == httplib::StatusCode::OK_200){
                return response->body;
            }

            return "ERROR";
        }else{
            return "ERROR";
        }
    }

    array<string, 3> Variations(string Text){
        array<string, 3> Variations;

        Variations[0] = Text;

        for(int i = 0; i < Text.length(); i++){
            Text[i] = toupper(Text[i]);
        }

        Variations[1] = Text;

        for(int i = 0; i < Text.length(); i++){
            Text[i] = tolower(Text[i]);
        }

        Variations[2] = Text;

        return Variations;
    }

    array<string, 30> Instagram(string First_Name, string Last_Name){
        array<string, 3> First_Name_Variations = Variations(First_Name);
        array<string, 3> Last_Name_Variations = Variations(Last_Name);
        array<string, 5> Conjunctions = {"", ".", "_", "-", "+"};
        array<string, 30> Return_Array;

        int index = 0;
        string temp;

        for(int i = 0; i < 3; i++){
            for(int c = 0; c < 5; c++){
                temp = First_Name_Variations[i] + Conjunctions[c] + Last_Name_Variations[i];

                Return_Array[index * 2] = temp;
                Return_Array[(index * 2) + 1] = Request("http://www.instagram.com", "/" + temp);

                index = index + 1;
            }
        }

        return Return_Array;
    }

    array<string, 30> Facebook(string First_Name, string Last_Name){
        array<string, 3> First_Name_Variations = Variations(First_Name);
        array<string, 3> Last_Name_Variations = Variations(Last_Name);
        array<string, 5> Conjunctions = {"", ".", "_", "-", "+"};
        array<string, 30> Return_Array;

        int index = 0;
        string temp;

        for(int i = 0; i < 3; i++){
            for(int c = 0; c < 5; c++){
                temp = First_Name_Variations[i] + Conjunctions[c] + Last_Name_Variations[i];

                Return_Array[index * 2] = temp;
                Return_Array[(index * 2) + 1] = Request("http://www.facebook.com", "/" + temp);

                index = index + 1;
            }
        }

        return Return_Array;
    }

    array<string, 30> LinkedIn(string First_Name, string Last_Name){
        array<string, 3> First_Name_Variations = Variations(First_Name);
        array<string, 3> Last_Name_Variations = Variations(Last_Name);
        array<string, 5> Conjunctions = {"", ".", "_", "-", "+"};
        array<string, 30> Return_Array;

        int index = 0;
        string temp;

        for(int i = 0; i < 3; i++){
            for(int c = 0; c < 5; c++){
                temp = First_Name_Variations[i] + Conjunctions[c] + Last_Name_Variations[i];

                Return_Array[index * 2] = temp;
                Return_Array[(index * 2) + 1] = Request("http://www.linkedin.com", "/in/" + temp);

                index = index + 1;
            }
        }

        return Return_Array;
    }

    array<string, 30> Twitter(string First_Name, string Last_Name){
        array<string, 3> First_Name_Variations = Variations(First_Name);
        array<string, 3> Last_Name_Variations = Variations(Last_Name);
        array<string, 5> Conjunctions = {"", ".", "_", "-", "+"};
        array<string, 30> Return_Array;

        int index = 0;
        string temp;

        for(int i = 0; i < 3; i++){
            for(int c = 0; c < 5; c++){
                temp = First_Name_Variations[i] + Conjunctions[c] + Last_Name_Variations[i];

                Return_Array[index * 2] = temp;
                Return_Array[(index * 2) + 1] = Request("http://www.x.com", "/" + temp);

                index = index + 1;
            }
        }

        return Return_Array;
    }
};

Toolbox Tools;

class Main_Loop{
public:
    Persons People[32];
    int size = 0;

    array<string, 2> Input(){
        string First_Name;
        string Last_Name;
        
 
        cout << "\nEnter the person's first name: ";
        cin >> First_Name;
        cout << "\nEnter the person's last name: ";
        cin >> Last_Name;

        return {First_Name, Last_Name};
    }

    void Create_Person(){
        array<string, 2> Names = this->Input();

        Persons Person(Names[0], Names[1]);

        this->People[this->size] = Person;
        this->size = size + 1;

        array<string, 30> Instagram_Array = Tools.Instagram(Names[0], Names[1]);
        array<string, 30> Facebook_Array = Tools.Facebook(Names[0], Names[1]);
        array<string, 30> LinkedIn_Array = Tools.LinkedIn(Names[0], Names[1]);
        array<string, 30> Twitter_Array = Tools.Twitter(Names[0], Names[1]);

        for(int i = 0; i < 30; i++){
            Results Result(Instagram_Array[(i * 2) + 1], "http://www.instagram.com/" + Instagram_Array[(i * 2) + 1], Instagram_Array[i * 2]);
            Person.Result_List[Person.size] = Result;
            Person.size = Person.size + 1;
        }

        for(int i = 0; i < 30; i++){
            Results Result(Facebook_Array[(i * 2) + 1], "http://www.facebook.com/" + Facebook_Array[(i * 2) + 1], Facebook_Array[i * 2]);
            Person.Result_List[Person.size] = Result;
            Person.size = Person.size + 1;
        }

        for(int i = 0; i < 30; i++){
            Results Result(LinkedIn_Array[(i * 2) + 1], "http://www.linkedin.com/in/" + LinkedIn_Array[(i * 2) + 1], LinkedIn_Array[i * 2]);
            Person.Result_List[Person.size] = Result;
            Person.size = Person.size + 1;
        }

        for(int i = 0; i < 30; i++){
            Results Result(Twitter_Array[(i * 2) + 1], "http://www.x.com/" + Twitter_Array[(i * 2) + 1], Twitter_Array[i * 2]);
            Person.Result_List[Person.size] = Result;
            Person.size = Person.size + 1;
        }
    }

    void Console(){
        string input;

        cout << "\nEnter your command: ";
        cin >> input;

        if(input == "New_Person"){
            this->Create_Person();
        }else if(input == "help"){
            cout << "New_Person - create a new person\nhelp - help\nexit - exit\nDisplay_Persons - display already created persons\n";
        }else if(input == "Display_Persons"){

        }
        else if(input == "exit"){
            return;
        }else{
            Console();
        }
    }
};

int main(){
    return 0;
}