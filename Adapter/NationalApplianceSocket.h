#pragma once
#include <iostream>
#include <string>

using namespace std;

//��ͬ���ҵĽӿ�
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
            cout << "��ȷ��������ѹ110V" << endl;
        }
        return "������ȷ��������ѹ110V";
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
            cout << "��ȷ���й���ѹ220V" << endl;
        }
        return "������ȷ���й���ѹ";
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
            cout << "��ȷ�ĵ¹���ѹ250V" << endl;
        }
        return "����¹���׼��ѹ";
    }
};