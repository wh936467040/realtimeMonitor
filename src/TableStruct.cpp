#include "TableStruct.h"
using namespace std;

realtimeTableStruct::realtimeTableStruct(int ctxNo,int app_no,string app_name,string table,int No)
{
	this->status=ctxNo;
	this->appName=app_name;
	this->tableName=table;
	this->tableNo=No;
	this->appNo=app_no;
}

realtimeTableStruct::~realtimeTableStruct()
{
//	cout<<"free table"<<endl;
}


void realtimeTableStruct::disp()
{
	 cout<<status<<" "<<appNo<<" "<<appName<<" "<<tableNo<<" "<<tableName<<" "<<useRatio<<" "<<downloadTime<<" "<<recordNum<<" "<<recordSum<<endl;
}
