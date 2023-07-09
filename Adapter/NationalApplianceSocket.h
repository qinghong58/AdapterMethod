#pragma once
#include <iostream>
#include <string>

using namespace std;

//不同国家的接口
//template <class CountrySocket>
class AmericanSocket
{
private:
    int voltage = 110;
public:
    virtual ~AmericanSocket() = default;

    int GetVoltage() 
    { 
        return voltage;
    }
    virtual string AmericanInput(int inputVoltage) const
    {
        if (voltage == inputVoltage) 
        {
            cout << "正确的美国电压110V" << endl;
        }
        return "输入正确的美国电压110V";
    }
};

class ChineseSocket 
{
private:

    int voltage = 220;
public:

    virtual ~ChineseSocket() = default;
    int GetVoltage()
    { 
        return voltage;
    }
    string ChineseInput(int inputVoltage) const 
    {
        if (voltage == inputVoltage)
        {
            cout << "正确的中国电压220V" << endl;
        }
        return "输入正确的中国电压";
    }
};

class GermanySocket
{
private:

    int voltage = 250;
public:

    virtual ~GermanySocket() = default;

    int GetVoltage()
    {
        return voltage;
    }
    string GermanyInput(int inputVoltage) const
    {
        if (voltage == inputVoltage)
        {
            cout << "正确的德国电压250V" << endl;
        }
        return "输入德国标准电压";
    }
};