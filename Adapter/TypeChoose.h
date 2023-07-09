#pragma once
#include <iostream>
#include <string>
#include<Map>
#include<functional>
#include"NationalApplianceSocket.h"
#include"TypeChoose.h"
#include"NationalAppliancePlug.h"

using namespace std;



//map<int, shared_ptr<ChineseSocket>>ch;
//map<int, shared_ptr<GermanySocket>>ger;
//map<int, shared_ptr<AmericanSocket>>Am;

shared_ptr<AmericanPlug>American = make_shared<AmericanPlug>();
shared_ptr<GermanyPlug>Germany = make_shared<GermanyPlug>();
shared_ptr<ChinesePlug>Chinese = make_shared<ChinesePlug>();

shared_ptr<AmericanAdpater>american_adapter = make_shared<AmericanAdpater>();
shared_ptr<GermanyAdapter>germany_adapter = make_shared<GermanyAdapter>();
shared_ptr<ChineseAdapter>chinese_adapter = make_shared<ChineseAdapter>();

shared_ptr<AmericanSocket>american_socket = make_shared< AmericanSocket>();
shared_ptr<GermanySocket>germany_socket = make_shared< GermanySocket>();
shared_ptr<ChineseSocket>chinese_socket = make_shared< ChineseSocket>();

shared_ptr<Plug>plug = make_shared<Plug>();

map<int, function<string()>>AmericanAdapterTypeChooseFunctionMap;

//map<int, function<string()>>GermanyAdapterTypeChooseFunctionMap;
//map<int, function<string()>>ChineseAdapterTypeChooseFunctionMap;

map<int, function<string()>> SocketTypeChooseFunctionMap;
map<int, function<int()>> SocketTypeVoltageFunctionMap;
map<int, function<void()>> ShopFunctionMap;
map<int, function<string()>>PlugVoltageMap;

map<int, function<void()>>AdapterTypeChooseFunction;

//map<int, shared_ptr<AmericanPlug>> AmericanPlugFunctionMap;
//map<int, shared_ptr<GermanyPlug>> GermanyPlugFunctionMap;
//map<int, shared_ptr<ChinesePlug>> ChinesePlugFunctionMap;

