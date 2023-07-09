#pragma once

#include <iostream>
#include <string>
#include<memory>
#include "NationalApplianceSocket.h"

using namespace std;

class AmericanAdpater : public AmericanSocket 
{
private:

    int voltage = 110;

    shared_ptr<AmericanAdpater> socket_american;

    shared_ptr<GermanySocket> american_To_germany=make_shared<GermanySocket>();
    shared_ptr<ChineseSocket> american_To_chinese= make_shared<ChineseSocket>();
public:

    AmericanAdpater() {};

    AmericanAdpater(shared_ptr<AmericanAdpater> socket) : socket_american(socket) {};

    string AmericanInput(int inputVoltage) const 
    {
        if (inputVoltage==250)
        {
            return this->american_To_germany->GermanyInput(american_To_germany->GetVoltage());
        }
        else if (inputVoltage == 220)
        {
            return this->american_To_chinese->ChineseInput(american_To_chinese->GetVoltage());
        }

    }

};

class GermanyAdapter :public GermanySocket
{
private:
    int voltage = 250;


    shared_ptr<GermanyAdapter> socket_germany;

    shared_ptr<AmericanSocket> germany_To_american = make_shared<AmericanSocket>();
    shared_ptr<ChineseSocket> germany_To_chinese= make_shared<ChineseSocket>();

public:

    GermanyAdapter() {};

    GermanyAdapter(shared_ptr<GermanyAdapter> socket) : socket_germany(socket) {};

    string GermanyInput(int inputVoltage) const 
    {
        if (inputVoltage == 110)
        {
            return this->germany_To_american->AmericanInput(germany_To_american->GetVoltage());
        }
        else if (inputVoltage == 220)
        {
            return this->germany_To_chinese->ChineseInput(germany_To_chinese->GetVoltage());
        }

    }
};

class ChineseAdapter :public ChineseSocket
{
private:
    int voltage = 220;


    shared_ptr<ChineseAdapter> socket_chinese;

    shared_ptr<AmericanSocket> chinese_To_american = make_shared<AmericanSocket>();
    shared_ptr<GermanySocket> chinese_To_germany = make_shared<GermanySocket>();

public:

    ChineseAdapter() {};

    ChineseAdapter(shared_ptr<ChineseAdapter> socket) : socket_chinese(socket) {};

    string ChineseInput(int inputVoltage) const 
    {
        if (inputVoltage == 110)
        {
            return this->chinese_To_american->AmericanInput(chinese_To_american->GetVoltage());
        }
        else if (inputVoltage == 250)
        {
            return this->chinese_To_germany->GermanyInput(chinese_To_germany->GetVoltage());
        }

    }

};

