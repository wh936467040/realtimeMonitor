#include "iostream"
#include "vector"
#include "alarmSet.h"
using namespace std;

extern vector<AlarmTable *> alarmSet;

/*
int main()
{
	cout<<"111111"<<endl;
	insertTableIntoAlarmSet("111","111","111","1111");
	cout<<"222222"<<endl;
	cout<<findTableFromAlarmSet("111","111")<<endl;
	cout<<"333333"<<endl;
	deleteTableFromAlarmSet("111","111");
	cout<<"444444"<<endl;
	cout<<findTableFromAlarmSet("111","111")<<endl;
}
*/

AlarmTable* findTableFromAlarmSet(string appName,string tableName)
{
	for(vector<AlarmTable*>::iterator it = alarmSet.begin(); it != alarmSet.end(); ++it)
	{
		if((*it) == NULL ) continue;
		if((*it)->appName==appName && (*it)->tableName==tableName)
		{
			return (*it);
		}
	}
	return NULL;
}

bool deleteTableFromAlarmSet(string appName,string tableName)
{
	for(vector<AlarmTable*>::iterator it = alarmSet.begin(); it != alarmSet.end(); ++it)
	{   
                if((*it) == NULL ) continue;
		if((*it)->appName==appName && (*it)->tableName==tableName)
		{
			alarmSet.erase(it);
			delete (*it);
			*it=NULL;
			return true;
			//break;
		}
	}
	return false;
}

bool insertTableIntoAlarmSet(string appName,string tableName,string startTime,string data)
{
	if(findTableFromAlarmSet(appName,tableName)!=NULL)
	{
		return false;
	}
	AlarmTable * it=new AlarmTable(appName,tableName,startTime,data);
	alarmSet.push_back(it);
	return true;
}

