#pragma once
#include <iostream> // input output ���� ���
#include <string>  // ���ڿ�
#include <vector> // namespace std ������ �̰� �����
using namespace std; //std���̺귯�� namespace 

// SmartHome
class SmartHome {
private:
    //Ŭ���� ������ (member variable, attribute, field) : ����
    string owner; //���ڿ�
    int temperature; //������
    int humidity; //
    bool security; // ture or false
public:
    // Ŭ���� �Լ��� (member function, method):����
    // ������
    // �Ű����� �μ� �߿�, temperature : �Ű����� , o : �μ�
    SmartHome(string owner, int temperature, int humidity, bool security) {
        this->owner = owner;
        this->temperature = temperature;
        this->humidity = humidity;
        this->security = security;
    }
    // Parameter�Ű�����, Argument �μ�
    SmartHome(string o, int t, int h, bool sec)
        : temperature(t), humidity(h), secruity(sec) {
        strcpy(owner, o);
   }
    
    
    //�Ҹ���(������ �ݴ�) ~smarthome() {}
    ~SmartHome() {}
    
    void setTemperature(int temperature) {
        this->temperature = temperature;
    }
    void setHumidity(int humidity) { //humidity �Ű�����
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
        cout << "������: " << this->owner << endl;
        cout << "�µ�: " << this->temperature << "��" << endl;
        cout << "����: " << this->humidity << "%" << endl;
        if (this->security) {
            cout << " security on" << endl;
        }
        else {
            cout << "security off" << endl;
        }
    }
};
