#include <iostream>
#include <string>

using namespace std;

class DatabaseHelper {
    DatabaseHelper(){
        cout<<"Connect to DB" << endl;
    };
    static DatabaseHelper* databaseConnection;

    string data;

public:
    DatabaseHelper(const DatabaseHelper&) = delete;
    void operator = (const DatabaseHelper&) = delete;

    static DatabaseHelper* getConnection(){
        if (databaseConnection == nullptr)
            databaseConnection = new DatabaseHelper();
        return databaseConnection;
    }

    string SelectData() const{
        return data;
    }

    void insertData(string d) {
        cout<<"New data:" << d << " insert data" << endl;
        data = d;
    }
};
DatabaseHelper* DatabaseHelper::databaseConnection = nullptr;

int main(){

    DatabaseHelper::getConnection()->insertData("123");

    cout<< "Fetching data from the database: " <<DatabaseHelper::getConnection() ->SelectData() << endl;

}