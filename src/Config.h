#include "iostream"
using namespace std;
class Config
{
public:
	string nodeId;
	int tableUseRatioAlarm;
	int tableAccessNumAlarm;

	string serverIpMain;
	int serverPortMain;
	string serverIpBak;
	int serverPortBak;

	string alarmServerIpMain;
	int alarmServerPortMain;
	string alarmServerIpBak;
	int alarmServerPortBak;

	int rtdatabaseMark;
	int collectPeriod;

	string status1;
	string appName1;
	string appId1;
	string table1;

	string status2;
	string appName2;
	string appId2;
	string table2;

	string status3;
	string appName3;
	string appId3;
	string table3;

	Config();
	~Config();	
	int getConfInfo();
	int getAlarmConfInfo();

};


