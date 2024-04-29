#pragma once
#include <iostream> // input output 쉽게 사용
#include <string>  // 문자열
#include <vector> // namespace std 없으면 이거 써야함
using namespace std; //std라이브러리 namespace 

// SmartHome
class SmartHome {
private:
    //클래스 변수들 (member variable, attribute, field) : 시험
    string owner; //문자열
    int temperature; //정수형
    int humidity; //
    bool security; // ture or false
public:
    // 클래스 함수들 (member function, method):시험
    // 생성자
    // 매개변수 인수 중요, temperature : 매개변수 , o : 인수
    SmartHome(string owner, int temperature, int humidity, bool security) {
        this->owner = owner;
        this->temperature = temperature;
        this->humidity = humidity;
        this->security = security;
    }
    // Parameter매개변수, Argument 인수
    SmartHome(string o, int t, int h, bool sec)
        : temperature(t), humidity(h), secruity(sec) {
        strcpy(owner, o);
   }
    
    
    //소멸자(생성자 반대) ~smarthome() {}
    ~SmartHome() {}
    
    void setTemperature(int temperature) {
        this->temperature = temperature;
    }
    void setHumidity(int humidity) { //humidity 매개변수
        this->humidity = humidity;
    }
    void setSecurity(bool security) {
        this->security = security;
    }
    string getOwner() {
        return this->owner;
    }
    int getTemperature() {
        return this->temperature;
    }
    int getHumidity() {
        return this->humidity;
    }
    bool getSecurity() {
        return this->security;
    }
    void printStatus() {
        cout << "집주인: " << this->owner << endl;
        cout << "온도: " << this->temperature << "도" << endl;
        cout << "습도: " << this->humidity << "%" << endl;
        if (this->security) {
            cout << " security on" << endl;
        }
        else {
            cout << "security off" << endl;
        }
    }
};
