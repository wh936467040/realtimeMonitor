#ifndef __TableStruct_H__
#define __TableStruct_H__

#include "iostream"
using namespace std;

class realtimeTableStruct
{
	public:
		int status;
		int pkMemAllocType;
		int appNo;
		string appName;
		string tableName;
		int tableNo;
		float useRatio;
		string downloadTime;
		int accessNum;
		int recordNum;
		int recordSum;
		void disp();
		realtimeTableStruct(int ctxNo,int app_no,string app,string table,int No);
		~realtimeTableStruct();
};

#endif
