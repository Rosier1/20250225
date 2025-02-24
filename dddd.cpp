#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdexcept>
using namespace std;
struct stockIn
{
    string Name;
    string Date;
    int Num;
    bool judgetime(string time1,string time2){
        std::tm currtime={};
        std::tm tm1={};
        std::tm tm2={};
        istringstream ss1(time1);
        istringstream ss2(time2);
        istringstream ss3(this->Date);
        ss1>>get_time(&tm1,"%Y-%m-%d");
        ss2>>get_time(&tm2,"%Y-%m-%d");
        ss3>>get_time(&currtime,"%Y-%m-%d");
        if (ss1.fail()&&ss2.fail()&&ss3.fail()) {
        
            throw std::runtime_error("Failed to parse date");
        }
        time_t time_cur = mktime(&currtime);
        time_t time1_t = mktime(&tm1);
        time_t time2_t = mktime(&tm2);
        if (time_cur == -1 || time1_t == -1 || time2_t == -1) {
        throw std::runtime_error("Invalid time encountered while processing dates");
        }
        return (time_cur >= time1_t && time_cur <= time2_t);
    }
}

int main() {
    try {
        stockIn stock("Apple", "2024-11-15", 100);
        if (stock.judgetime("2024-11-01", "2024-11-30")) {
            std::cout << "The stock is within the date range." << std::endl;
        } else {
            std::cout << "The stock is outside the date range." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
