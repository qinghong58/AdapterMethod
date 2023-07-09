#include <iostream>
#include <string>
#include<map>
#include<functional>
#include<Windows.h>
#include "NationalApplianceSocket.h"
#include "NationalApplianceSocketAdapter.h"
#include "TypeChoose.h"
#include"NationalAppliancePlug.h"


using namespace std;

int PlugVoltage = 0;
int CheckVolitageFlag = 0;
string SocketType;

void SocketTypeChoose();
void VolitageTypeChoose();
void AmericanAdapterTypeChoose();
void GermanyAdapterTypeChoose();
void ChineseAdapterTypeChoose();
void CheckPlugVoltageFunction();
string americasocketvolitage, germanysocketvolitage, chinesesocketvolitage;
int Americanflag = 0, Germanyflag = 0, Chineseflag = 0;

void Worning()
{
	cout << "С���Ҽ�ס���ˣ��������ǰɣ�" << endl;
}
int Nothing()
{
	cout << "����𿴣�" << endl;
	Sleep(3000);
	return 0;
}
void ShopFunction(int flag)
{
	ShopFunctionMap[0] = Worning;
	ShopFunctionMap[1] = SocketTypeChoose;
	ShopFunctionMap[2] = Nothing;
	if (flag<=2||flag>0)
	{
		ShopFunctionMap[flag]();
	}
	else
	{
		Nothing();
	}

}
void SocketTypeChooseFunction(int flag)
{
    //�������������ָ�룬�洢��map����
	SocketTypeChooseFunctionMap[1] = []() {return American->UseAmericaSocket(); };
	SocketTypeChooseFunctionMap[2] = []() {return Germany->UseGermanySocket(); };
	SocketTypeChooseFunctionMap[3] = []() {return Chinese->UseChineseSocket(); };


	if (flag <= SocketTypeChooseFunctionMap.size() )
	{
		SocketType = SocketTypeChooseFunctionMap[flag]();
	}
	else
	{
		Worning();
	}

}

void CheckPlugVoltageFunction()
{
	PlugVoltageMap[1] = []() {return plug->UseAmericaSocket(american_socket); };
	PlugVoltageMap[2] = []() {return plug->UseGermanySocket(germany_socket); };
	PlugVoltageMap[3] = []() {return plug->UseChineseSocket(chinese_socket); };

	americasocketvolitage = PlugVoltageMap[1]();
	germanysocketvolitage = PlugVoltageMap[2]();
	chinesesocketvolitage = PlugVoltageMap[3]();

	Sleep(3000);
	SocketTypeChoose();
}

int SocketTypeVoltageFunction(int flag)
{
	SocketTypeVoltageFunctionMap[1] = []() {return American->GetVoltage(); };
	SocketTypeVoltageFunctionMap[2] = []() {return Germany->GetVoltage(); };
	SocketTypeVoltageFunctionMap[3] = []() {return Chinese->GetVoltage(); };

	if (flag <= SocketTypeVoltageFunctionMap.size()+1 || flag > SocketTypeVoltageFunctionMap.empty())
	{
		
		PlugVoltage = SocketTypeVoltageFunctionMap[flag]();

	}
	else
	{
		Worning();
	}
	return PlugVoltage;
}

//void AdapterTypeChoose(int flag)
//{
//	AdapterTypeChooseFunction[1] = AmericanAdapterTypeChoose;
//	AdapterTypeChooseFunction[2] = GermanyAdapterTypeChoose;
//	AdapterTypeChooseFunction[3] = ChineseAdapterTypeChoose;
//
//	if (flag > AdapterTypeChooseFunction.empty()|| flag <= AdapterTypeChooseFunction.size())
//	{
//		AdapterTypeChooseFunction[flag]();
//	}
//	else
//	{
//		Worning();
//	}
//}

string AmericanAdapterTypeChooseFunction(int Americanflag)
{
	AmericanAdapterTypeChooseFunctionMap[1] = []() {return american_adapter->AmericanInput(220); };
	AmericanAdapterTypeChooseFunctionMap[2] = []() {return american_adapter->AmericanInput(250); };
	AmericanAdapterTypeChooseFunctionMap[3] = []() {return germany_adapter->GermanyInput(220); };
	AmericanAdapterTypeChooseFunctionMap[4] = []() {return germany_adapter->GermanyInput(110); };
	AmericanAdapterTypeChooseFunctionMap[5] = []() {return chinese_adapter->ChineseInput(250); };
	AmericanAdapterTypeChooseFunctionMap[6] = []() {return chinese_adapter->ChineseInput(110); };



	if (Americanflag > AmericanAdapterTypeChooseFunctionMap.empty() || Americanflag <= AmericanAdapterTypeChooseFunctionMap.size())
	{
		return AmericanAdapterTypeChooseFunctionMap[Americanflag]();
	}
	else
	{
		Worning();
	}
	//return AmericanAdapterTypeChooseFunctionMap[Americanflag]();
}
//string GermanyAdapterTypeChooseFunction(int Germanyflag)
//{
//	GermanyAdapterTypeChooseFunctionMap[1] = []() {return germany_adapter->GermanyInput(220); };
//	GermanyAdapterTypeChooseFunctionMap[2] = []() {return germany_adapter->GermanyInput(250); };
//
//	return GermanyAdapterTypeChooseFunctionMap[Germanyflag]();
//
//
//}

void Shop()
{
	system("cls");
	int flag = 0;

	cout << "��ӭ������ɽ������" << endl;
	cout << "-------------------------" << endl;
	cout << "1.�򼸸���ͷת��������" << endl;
	cout << "2.û�£�����￴��" << endl;
	cout << "-------------------------" << endl;
	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
	cin >> flag;

	ShopFunction(flag);
}

void SocketTypeChoose()
{
	system("cls");
	int flag = 0;
	cout << "��ӭ������ɽ������" << endl;
	cout << "-------------------------" << endl;
	cout << "1.������ͷ" << endl;
	cout << "2.�¹���ͷ" << endl;
	cout << "3.�й���ͷ" << endl;
	cout << "4.�鿴��ͷ��ѹ" << endl;
	cout << "-------------------------" << endl;
	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
	cin >> CheckVolitageFlag;
	flag = CheckVolitageFlag;
	SocketTypeChooseFunction(CheckVolitageFlag);
	system("cls");
	if (CheckVolitageFlag == 4)
	{
		CheckPlugVoltageFunction();
	}
	//CheckPlugVoltageFunction();
	//AdapterTypeChoose(flag);

	AmericanAdapterTypeChoose();
}

void AmericanAdapterTypeChoose()
{
	system("cls");
	int flag = 0;
	cout << "��ӭ������ɽ������" << endl;
	cout << "-------------------------" << endl;
	cout << "1.����->�й�������" << endl;
	cout << "2.����->�¹�������" << endl;
	cout << "3.�¹�->�й�������" << endl;
	cout << "4.�¹�->����������" << endl;
	cout << "5.�й�->�¹�������" << endl;
	cout << "6.�й�->����������" << endl;
	cout << "-------------------------" << endl;
	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
	cin >> Americanflag;

	AmericanAdapterTypeChooseFunction(Americanflag);
}

//void GermanyAdapterTypeChoose()
//{
//	system("cls");
//	//int flag = 0;
//	cout << "��ӭ������ɽ������" << endl;
//	cout << "-------------------------" << endl;
//	cout << "1.�¹�->�й�������" << endl;
//	cout << "2.�¹�->����������" << endl;
//	cout << "-------------------------" << endl;
//	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
//	cin >> Germanyflag;
//
//	//GermanyAdapterTypeChooseFunction(Germanyflag);
//
//}

//void ChineseAdapterTypeChoose()
//{
//	system("cls");
//	int flag = 0;
//	cout << "��ӭ������ɽ������" << endl;
//	cout << "-------------------------" << endl;
//	cout << "1.�й�->�¹�������" << endl;
//	cout << "2.�й�->����������" << endl;
//	cout << "-------------------------" << endl;
//	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
//	cin >> flag;
//
//	//system("cls");
//}

//void VolitageTypeChoose()
//{
//	system("cls");
//	int flag = 0;
//	cout << "��ӭ������ɽ������" << endl;
//	cout << "-------------------------" << endl;
//	cout << "1.��ѹ110V" << endl;
//	cout << "2.��ѹ220V" << endl;
//	cout << "2.��ѹ250V" << endl;
//	cout << "-------------------------" << endl;
//
//	cout << "����������Ҫ��ʲô��Ӧ����ţ���Ҫ�Ұ���" << endl;
//	cin >> flag;
//    SocketTypeVoltageFunction(flag);
//
//}







int main()
{
	Shop();

	//GermanyAdapterTypeChooseFunction(Germanyflag);
	//AmericanAdapterTypeChooseFunction(Americanflag);

	cout <<SocketType<< PlugVoltage << endl;
	return 0;
}