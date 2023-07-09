#pragma once
#include <iostream>
#include <string>
#include"NationalApplianceSocket.h"

using namespace std;

class Plug
{

public:
	virtual ~Plug() {};

	virtual string UseAmericaSocket(shared_ptr<AmericanSocket> socket)
	{
		return socket->AmericanInput(110);
	}
	virtual string UseGermanySocket(shared_ptr<GermanySocket> socket)
	{
		return socket->GermanyInput(250);
	}
	virtual string UseChineseSocket(shared_ptr<ChineseSocket> socket)
	{
		return socket->ChineseInput(220);
	}

};

class AmericanPlug :public Plug
{
private:
	int voltage = 110;
public:

	int GetVoltage()
	{
		return voltage;
	}

	string UseAmericaSocket() 
	{
		return "��ѡ����������ͷ��";
	}

};

class GermanyPlug :public Plug
{
private:
	int voltage = 250;

public:

	int GetVoltage()
	{
		return voltage;
	}

	string UseGermanySocket()
	{
		return "��ѡ���˵¹���ͷ��" ;
	}
};

class ChinesePlug :public Plug
{
private:
	int voltage = 220;

public:

	int GetVoltage()
	{
		return voltage;
	}

	string UseChineseSocket()
	{
		return "��ѡ�����й���ͷ��";

	}
};