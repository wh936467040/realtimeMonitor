#include "iostream"
#include "AppStruct.h"
using namespace std;
appStruct::appStruct(int No,int status,string Name)
{
	appNo=No;
	appStatus=status;
	appName=Name;
}


appStruct::~appStruct()
{
// cout<<"free appset"<<endl;
}

