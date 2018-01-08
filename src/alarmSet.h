#include "iostream"
#include "vector"
using namespace std;
class AlarmTable
{
	public :
	AlarmTable(string app,string table,string start,string data)
	{
		this->appName=app;
		this->tableName=table;
		this->startTime=start;
		this->data=data;
	};
	string appName;
	string tableName;
	string startTime;
	string data;
	~AlarmTable(){};
};
extern vector<AlarmTable *> alarmSet;

AlarmTable * findTableFromAlarmSet(string appName,string tableName);
bool deleteTableFromAlarmSet(string appName,string tableName);
bool insertTableIntoAlarmSet(string appName,string tableName,string start,string data);
