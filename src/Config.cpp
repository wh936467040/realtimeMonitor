#include "iostream"
#include "Config.h"
#include "Util.h"
using namespace std;
/*
int main()
{
	Config* conf=new Config();
	conf->getConfInfo();
	return 0;
}
*/

Config::~Config()
{
}
Config::Config()
{
	nodeId="0";
	serverIpMain="0";
	serverPortMain=0;
	serverIpBak="0";
	serverPortBak=0;
	rtdatabaseMark=0;
	collectPeriod=0;

	status1="0";
	appName1="0";
	appId1="";
	table1="0";

	status2="0";
	appName2="0";
	appId2="";
	table2="0";

	status3="0";
	appName3="0";
	appId3="";
	table3="0";
	tableUseRatioAlarm=90;                                                                                                                
	tableAccessNumAlarm=10;
}


int Config::getConfInfo()
{
	//string Home =getD5000HomePath();
	char path[256]="";
	//string ConfigFile=Home + "/conf/auto_monitor.conf";
	string ConfigFile = "../conf/auto_monitor.conf";
	strcpy(path,ConfigFile.c_str());
	FILE *pp;
	pp = fopen(path,"r");
	if(NULL == pp)
	{
		cout<<"conf file open failed,check you path"<<endl;
		return -1;
	}
	string str_code;
	string str_content;
	char buf[128];
	string str = "";
	int index = 0;
	while(fgets(buf, 128, pp) != NULL)
	{
		str = buf;
		str = str.substr(0,str.length()-1);
		index = str.find_first_of(":", 0);
		if(index > 0)
		{
			str_code = str.substr(0, index);
			str_content = str.substr(index+1, str.length());
			if(str_code ==  "id" || str_code == "ID")
			{
				nodeId=str_content;
			//	cout<<"nodeID           "<<nodeId<<endl;
			}
			else if(str_code ==  "time" || str_code == "TIME")
			{
				collectPeriod=atoi(str_content.c_str());
				cout<<"collect_period   "<<collectPeriod<<endl;
			}
			else if(str_code ==  "serverport" || str_code == "SERVERPORT")
			{
				serverPortMain=atoi(str_content.c_str());
			//	cout<<"mainPort           "<<atoi(str_content.c_str())<<endl;			
			}
			else if(str_code == "serverip" || str_code == "SERVERIP")
			{
				serverIpMain=str_content;
			//	cout<<"serverIpMain  :"<<serverIpMain<<endl;
			}
			else if(str_code == "serverport_bak" || str_code == "SERVERPORT_BAK")
			{
				serverPortBak=atoi(str_content.c_str());
			//	cout<<"serverPortBak  :"<<serverPortBak<<endl;
			}
			else if(str_code ==  "serverip_bak" || str_code == "SERVERIP_BAK")
			{
				//	s_sendinfo.m_ip_back = str_content.c_str();
				serverIpBak=str_content;
			//	cout<<"serverIpBak    :"<<endl;
			}

			else if(str_code ==  "table1" || str_code == "table1")
			{
				index= str_content.find_first_of(",", 0);
				status1 =str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appName1=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appId1=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				table1=str_content;

				cout<<status1<<endl;
				cout<<appName1<<endl;
				cout<<appId1<<endl;
				cout<<table1<<endl;
			}
			else if(str_code ==  "table2" || str_code == "table2")
			{
				index= str_content.find_first_of(",", 0);
				status2 =str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appName2=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appId2=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				table2=str_content;
				cout<<status2<<endl;
				cout<<appName2<<endl;
				cout<<appId2<<endl;
				cout<<table2<<endl;
			}
			else if(str_code ==  "table3" || str_code == "table3")
			{
				index= str_content.find_first_of(",", 0);
				status3 =str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appName3=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				index= str_content.find_first_of(",",0);
				appId3=str_content.substr(0,index);
				str_content=str_content.substr(index+1,str_content.length()-1);
				table3=str_content;
				cout<<status3<<endl;
				cout<<appName3<<endl;
				cout<<appId3<<endl;
				cout<<table3<<endl;
			}
			else if(str_code ==  "alarmport" || str_code == "ALARMPORT")
			{
				alarmServerPortMain=atoi(str_content.c_str());
				cout<<"alarmmainPort           "<<atoi(str_content.c_str())<<endl;          
			}
			else if(str_code == "alarmip" || str_code == "ALARMIP")
			{
				alarmServerIpMain=str_content;
				//  cout<<"serverIpMain  :"<<serverIpMain<<endl;
			}
			else if(str_code == "alarmport_bak" || str_code == "ALARMPORT_BAK")
			{
				alarmServerPortBak=atoi(str_content.c_str());
				//  cout<<"serverPortBak  :"<<serverPortBak<<endl;
			}
			else if(str_code ==  "alarmip_bak" || str_code == "ALARMIP_BAK")
			{
				//  s_sendinfo.m_ip_back = str_content.c_str();
				alarmServerIpBak=str_content;
				//  cout<<"serverIpBak    :"<<endl;
			}
			else if(str_code ==  "rtdatabase" || str_code == "RTDATABASE")
			{
				int mark =atoi(str_content.c_str());
				if(mark==0)
				{
					fclose(pp);
					cout<<"本机无实时数据库"<<endl;
					exit(0);
				}
			}
		}
		/*else
		{
			string str_hard = "rtdatabaseMark";
			if(strstr(str.c_str(), str_hard.c_str()) != NULL)
			{
				return 1;
			}
		}*/	 
	}
	fclose(pp);
	return 0;
}

int Config::getAlarmConfInfo()
{
	string Home =getD5000HomePath();
	char path[256]="";
	string ConfigFile=Home+"/conf/AlarmInfo.conf";
	strcpy(path,ConfigFile.c_str());
	FILE *pp;
	pp = fopen(path,"r");
	if(NULL == pp)
	{
		cout<<ConfigFile<<"open failed,check you path"<<endl;
		return -1;
	}
	string str_code;
	string str_content;
	char buf[128];
	string str = "";
	int index = 0;
	while(fgets(buf, 128, pp) != NULL)
	{
		str = buf;
		str = str.substr(0,str.length()-1);
		index = str.find_first_of(":", 0);
		if(index > 0)
		{
			str_code = str.substr(0, index);
			str_content = str.substr(index+1, str.length());

			if(str_code ==  "tableUseRatioAlarm" || str_code == "00020015")
			{
				tableUseRatioAlarm=atoi(str_content.c_str());
				//  cout<<"serverIpBak    :"<<endl;
			}
			
			else if(str_code ==  "tableAccessNumAlarm" || str_code == "00020014")
			{
				//  s_sendinfo.m_ip_back = str_content.c_str();
				tableAccessNumAlarm=atoi(str_content.c_str());
				//  cout<<"serverIpBak    :"<<endl;
			}
		}
	}
	fclose(pp);
	return 0;
}

