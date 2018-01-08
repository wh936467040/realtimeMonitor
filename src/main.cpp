#include "iostream"
//#include "map"
#include "alarmSet.h"
#include "showservice.h"
#include "AppStruct.h"
#include "algorithm"
#include "db_api/odb_prv_struct.h"
#include "db_api/odb_tableop.h"
#include "TableStruct.h"
#include "odbsee_app.h"
#include "odbsee_tab.h"
#include "Util.h"
#include "vector.h"
#include "sendinfo.h"
#include "Config.h"
using namespace ODB;
using namespace std;
void *getTableAccessTime(void*);
void * getTableUseRatio();
string getNodeName();
bool GreaterSort(realtimeTableStruct*a,realtimeTableStruct* b);
vector<AlarmTable*> alarmSet;
int main()
{
	Config *conf=new Config();
	conf->getConfInfo();
	cout<<conf->collectPeriod<<endl;
	
	SendInfo send;
	SendInfo sendAlarm;
	send.m_port_main=conf->serverPortMain;
	send.m_ip_main=conf->serverIpMain;
	send.m_port_back=conf->serverPortBak;
	send.m_ip_back=conf->serverIpBak;
	sendAlarm.m_port_main=conf->alarmServerPortMain;
	sendAlarm.m_ip_main=conf->alarmServerIpMain;
	sendAlarm.m_port_back=conf->alarmServerPortBak;
	sendAlarm.m_ip_back=conf->alarmServerIpBak;
	sendAlarm.alarm_port_main=conf->alarmServerPortMain;
	sendAlarm.alarm_ip_main=conf->alarmServerIpMain;
	sendAlarm.alarm_port_back=conf->alarmServerPortBak;
	sendAlarm.alarm_ip_back=conf->alarmServerIpBak;
	string statTime=getSysTime();
	sendAlarm.sendDStartAlarmInfo(conf->nodeId,"00020015",statTime);
	sendAlarm.sendDStartAlarmInfo(conf->nodeId,"00020014",statTime);
	sleep(5);
	pthread_attr_t pth_attr_acc;                                                                                                      
	pthread_attr_init(&pth_attr_acc);
	pthread_attr_setdetachstate(&pth_attr_acc,PTHREAD_CREATE_DETACHED);
	pthread_t pth_acc; 
   	
	int ret2 =0;
	ret2=pthread_create(&pth_acc,&pth_attr_acc,getTableAccessTime,(void*) NULL);
	if(ret2!=0)
	{
		cout<<"create thread getTableAccessTime error"<<endl;
	}

	while(1)
	{
		getTableUseRatio();
		sleep(30);
	}
	delete conf;
}


void * getTableUseRatio()
{

	Config * conf=new Config();
	conf->getConfInfo();
	conf->getAlarmConfInfo();

	SendInfo send;
	SendInfo sendAlarm;
	
	send.m_port_main=conf->serverPortMain;
	send.m_ip_main=conf->serverIpMain;
	send.m_port_back=conf->serverPortBak;
	send.m_ip_back=conf->serverIpBak;
	
	sendAlarm.m_port_main=conf->alarmServerPortMain;
	sendAlarm.m_ip_main=conf->alarmServerIpMain;
	sendAlarm.m_port_back=conf->alarmServerPortBak;
	sendAlarm.m_ip_back=conf->alarmServerIpBak;

	sendAlarm.alarm_port_main=conf->alarmServerPortMain;
	sendAlarm.alarm_ip_main=conf->alarmServerIpMain;
	sendAlarm.alarm_port_back=conf->alarmServerPortBak;                                                                                    
	sendAlarm.alarm_ip_back=conf->alarmServerIpBak;

	cout<<"alarmServer "<<conf->alarmServerIpMain<<":"<<conf->alarmServerPortMain<<endl;
	
	int tableUseRatioAlarm=conf->tableUseRatioAlarm;

	int tmp_cur_status = 8;
	int map_size = 0;
	int res = 0;
	time_t curr_time;
	string  context_name = "";
	char 	refresh_str[32] = "";
	char    switch_str[16] = "";  //add 20090414
	int 	dutyflag_public[7] = {0}; //add 20091120
	char public_host_name[7][MAX_NAME_LEN] = {""};
	class CServicesManage services_class;
	vector<appStruct*> appSet;
	vector<realtimeTableStruct*> tableSet;
	struct REALTIME_STATE_INFO tableInfo;           
	tableInfo.appname="";
	tableInfo.tableid="";
	tableInfo.tablename="";
	tableInfo.use_ratio="";
	tableInfo.record_num="";
	tableInfo.record_sum=""; 

	for( int i = 0; i < MNG_MAX_APP_NUM; i ++ )
	{
		if(strlen(services_class.m_AppStatusPtr[i].app_name)!=0)
		{
		 	int status=services_class.m_AppStatusPtr[i].context;
			string nodeName=services_class.m_AppStatusPtr[i].node_name;
			cout<<nodeName<<endl;
			if(status==1&&nodeName==getNodeName())
			{
				string appName=(string)services_class.m_AppStatusPtr[i].app_name;
				int appId=services_class.m_AppStatusPtr[i].app_id;
				appStruct* app=new appStruct(appId,status,string(appName));
				appSet.push_back(app);
			}
		}
	}

	string statTime=getSysTime(); 
	
	for(vector<appStruct*>::iterator it = appSet.begin(); it != appSet.end(); ++it)
	{
		if((*it)->appName.length()<2)
		{
			continue;
		}
		string  app = (*it)->appName.substr(0,5);	
		//cout << app << endl;
		if(app == "scada")
		{
			OdbseeApp *a=new OdbseeApp((*it)->appNo,const_cast<char*>((*it)->appName.c_str()),(*it)->appStatus);
			a->DispCtrlTab(tableSet);
			delete a;
		}
	}

	for(vector<realtimeTableStruct*>::iterator it2 = tableSet.begin(); it2 != tableSet.end(); ++it2)
	{   

		if((*it2)->appName.length() <2 ||(*it2)->tableName.length()<2)
		{
			continue ;
		} 
		OdbseeTab tableViewer( (*it2)->appNo, (*it2)->tableNo, (*it2)->status);
		
		tableViewer.DispStdbTab(*it2);
		//(*it2)->disp();
		if((*it2)->useRatio>=conf->tableUseRatioAlarm && (*it2) -> recordSum >1  )
		{
			if(findTableFromAlarmSet((*it2)->appName,(*it2)->tableName)!=NULL)
			{
				continue;
			}
			if((*it2) ->pkMemAllocType ==3 && (*it2) -> useRatio > 100 )
			{
				struct ALARM_INFO_D5000 alarmInfo;
				alarmInfo.itemid="00020015";
				alarmInfo.data= "实时库表空间使用率超过100%,将影响插入和更新的效率: " + (*it2)->appName+"."+(*it2)->tableName+" 使用率 : "+f2tos((*it2)->useRatio);
				cout<<"告警内容"<<alarmInfo.data<<endl;
				sendAlarm.sendD5000AlarmInfo(conf->nodeId,statTime, alarmInfo);
				insertTableIntoAlarmSet((*it2)->appName,(*it2)->tableName,statTime,alarmInfo.data);
			}
			else if((*it2) ->pkMemAllocType !=3)
			{
				struct ALARM_INFO_D5000 alarmInfo;
				alarmInfo.itemid="00020015";
	     			alarmInfo.data= "实时库表空间使用率过高, 将无法写入数据:" + (*it2)->appName+"."+(*it2)->tableName+" 使用率 : "+f2tos((*it2)->useRatio);
				cout<<"告警内容"<<alarmInfo.data<<endl;
				sendAlarm.sendD5000AlarmInfo(conf->nodeId,statTime, alarmInfo);
				insertTableIntoAlarmSet((*it2)->appName,(*it2)->tableName,statTime,alarmInfo.data);
			}
		}
		else
		{
			AlarmTable * tp=NULL;
			tp=findTableFromAlarmSet((*it2)->appName,(*it2)->tableName);
			if(tp!=NULL)
			{  	
				string itemid="00020015";
				string flag =tp->data;
				string startTime=tp->startTime;
				deleteTableFromAlarmSet((*it2)->appName,(*it2)->tableName);
				sendAlarm.sendD5000DisAlarmInfo(conf->nodeId,itemid,startTime,statTime,flag);
				cout<<"cancel Alarm "<<endl;
			}
		}
	}

	sort(tableSet.begin(),tableSet.end(),GreaterSort);
	int i=0;
	
	string downloadTime ="";
	string downloadNum="";
	int downloadCount=0;
	string sendAppName="";
	string sendTableId="";
	string sendTableName="";
	string sendUseRatio="";
	string sendTableRecordNum="";
	string sendTableRecordSum="";
	for(vector<realtimeTableStruct*>::iterator it3 = tableSet.begin(); it3 != tableSet.end(); ++it3)
	{
		if((*it3)->downloadTime.length()>5 && i<5&&(*it3)->appName.length()>1)
		{
			
			sendAppName=sendAppName+";"+(*it3)->appName;
			downloadTime=(*it3)->downloadTime;			
			sendTableId=sendTableId+";"+itos((*it3)->tableNo);
			sendTableName=sendTableName+";"+(*it3)->tableName;
			sendUseRatio=sendUseRatio+";"+f2tos((*it3)->useRatio);
			sendTableRecordNum=sendTableRecordNum+";"+itos((*it3)->recordNum);
			sendTableRecordSum=sendTableRecordSum+";"+itos((*it3)->recordSum);
			i++;
		}
		else if((*it3)->downloadTime.length()>5 )
		{
			downloadCount++;
		}
	}
	if(sendAppName.length()<2)
	{
		cout<<"no data need to send ,there is no scada table in rtdb" << endl;
		for(vector<realtimeTableStruct*>::iterator it3 = tableSet.begin(); it3 != tableSet.end(); ++it3)
       		{
                	delete *it3;
                	*it3=NULL;
       		}
       		tableSet.clear();
      		vector<realtimeTableStruct*>(tableSet).swap(tableSet);


       		for(vector<appStruct*>::iterator it4 = appSet.begin(); it4 != appSet.end(); ++it4)
       		{
          		delete *it4;
            		*it4=NULL;
       		}
       		appSet.clear();
        	vector<appStruct *>(appSet).swap(appSet);
       		delete conf;
	}
	else {
		tableInfo.appname=sendAppName.substr(1,sendAppName.length()-1);
		tableInfo.tableid=sendTableId.substr(1,sendTableId.length()-1);
		tableInfo.tablename=sendTableName.substr(1,sendTableName.length()-1);
		tableInfo.use_ratio=sendUseRatio.substr(1,sendUseRatio.length()-1);
		tableInfo.record_num=sendTableRecordNum.substr(1,sendTableRecordNum.length()-1);
		tableInfo.record_sum=sendTableRecordSum.substr(1,sendTableRecordSum.length()-1);
		cout<<tableInfo.tableid<<endl;
		downloadNum=itos(downloadCount);
		struct REALTIME_DOWNLOAD_NUM  realtime_download_info;
		realtime_download_info.download_num=downloadNum;
		realtime_download_info.download_time=downloadTime;
		send.sendRealtimeDownloadNumInfo(conf->nodeId,statTime,realtime_download_info);
		send.sendRealtimeStateInfo(conf->nodeId,statTime,tableInfo);    
		for(vector<realtimeTableStruct*>::iterator it3 = tableSet.begin(); it3 != tableSet.end(); ++it3)
		{
			delete *it3;                                                               
			*it3=NULL;
		}
		tableSet.clear();
		vector<realtimeTableStruct*>(tableSet).swap(tableSet);


		for(vector<appStruct*>::iterator it4 = appSet.begin(); it4 != appSet.end(); ++it4)
		{	
		    delete *it4;
	   	 *it4=NULL;
		}
		appSet.clear();
		vector<appStruct *>(appSet).swap(appSet);
		delete conf;
	}

}


int alarmMark[3]={0,0,0};
string flag[3]={"","",""};
string startTime[3]={"","",""};
void* getTableAccessTime(void *)
{
	Config * conf=new Config();
	conf->getConfInfo();
	conf->getAlarmConfInfo();	
	SendInfo send;
	SendInfo sendAlarm;

	send.m_port_main=conf->serverPortMain;
	send.m_ip_main=conf->serverIpMain;
	send.m_port_back=conf->serverPortBak;
	send.m_ip_back=conf->serverIpBak;

	sendAlarm.m_port_main=conf->alarmServerPortMain;
	sendAlarm.m_ip_main=conf->alarmServerIpMain;
	sendAlarm.m_port_back=conf->alarmServerPortBak;
	sendAlarm.m_ip_back=conf->alarmServerIpBak;
	
	sendAlarm.alarm_port_main=conf->alarmServerPortMain;
	sendAlarm.alarm_ip_main=conf->alarmServerIpMain;
	sendAlarm.alarm_port_back=conf->alarmServerPortBak;
	sendAlarm.alarm_ip_back=conf->alarmServerIpBak;

	cout<<"****alarmServer "<<conf->alarmServerIpMain<<":"<<conf->alarmServerPortMain<<endl;
	int tableAccessNumAlarm=conf->tableAccessNumAlarm;
	
	string statusArray[3];
	string appNameArray[3];
	string appIdArray[3];
	string tableArray[3];
	
	statusArray[0]=conf->status1;
	appNameArray[0]=conf->appName1;
	appIdArray[0]=conf->appId1;
	tableArray[0]=conf->table1;

	statusArray[1]=conf->status2;
	appNameArray[1]=conf->appName2;
	appIdArray[1]=conf->appId2;
	tableArray[1]=conf->table2;

	statusArray[2]=conf->status3;
	appNameArray[2]=conf->appName3;
	appIdArray[2]=conf->appId3;
	tableArray[2]=conf->table3;

	string datPath="";
	string HomePath=getD5000HomePath();
	while(1)
	{
		string statTime=getSysTime();
		for(int i=0;i<3;i++)
		{
			string status=statusArray[i];
			string appName=appNameArray[i];
			if(appName.length()<1)
			{
				cout<<"配置应用名有误"<<endl;
				continue;
			}
			string appId=appIdArray[i];
			string table=tableArray[i];
			int accessNum=0;
			string cmd="";

			if(status=="realtime")
			{
			    datPath=HomePath+"/data/rtdbms"+"/context01/"+appName+"/"+table+".dat";
				cmd = "lsof -a " + datPath + "|wc -l";
			} 
			else
			{
				cout<<"input a realtime table "<<endl;
				continue;
			}
			FILE * fp=NULL;
			fp=popen(cmd.c_str(),"r");
			if(fp==NULL)
			{
				accessNum=-1;
				//return -1;
				sleep(5);
				continue;
			}
			char str[1024]="";
			fgets(str,sizeof(str),fp);
			accessNum=atoi(str);
			if(accessNum>0)
			{
				accessNum=accessNum-1;
			}
			//cout<<cmd<<endl;
			//cout<<accessNum<<endl;
			if(accessNum>tableAccessNumAlarm && alarmMark[i]==0)
			{
				struct ALARM_INFO_D5000 alarmInfo;
				alarmInfo.itemid="00020014";
				alarmInfo.data="实时库表" + appName+"."+table+" 访问次数过高,次数: "+itos(accessNum);
				cout<<"send alarm"<<endl;
				cout<<"告警内容"<<alarmInfo.data<<endl;
				sendAlarm.sendD5000AlarmInfo(conf->nodeId,statTime, alarmInfo);
				alarmMark[i]=1;
				flag[i]=alarmInfo.data;
				startTime[i]=statTime;
			}
			else if(accessNum<tableAccessNumAlarm && alarmMark[i]!=0)
			{
				if(alarmMark[i]==1)
				{
					alarmMark[i]=0;
					sendAlarm.sendD5000DisAlarmInfo(conf->nodeId,"00020014",startTime[i],statTime,flag[i]);
					cout<<"cancle Alarm"<<endl;
				}
			}
			struct REALTIME_TABLE_ACCESS tableInfo;
			tableInfo.app_id=appId;
			tableInfo.table_name=table;
			tableInfo.access_num=itos(accessNum);
			pclose(fp);
			send.sendRealtimeAccessNumInfo(conf->nodeId,statTime,tableInfo);
		}
		sleep(conf->collectPeriod);
	 }
	delete conf;
	//return 1;
}


string  getNodeName()
{
	string nodeName="";
	string cmd="uname -n";
	FILE * fp =NULL;
	fp=popen(cmd.c_str(),"r");
	if(fp==NULL)
	{
		return "-1";
	}
	char str[256];
	fgets(str,sizeof(str),fp);
	nodeName=string(str);
	nodeName=nodeName.substr(0,nodeName.length()-1);
	cout<<nodeName<<endl;
	pclose(fp);
	return nodeName;                                                                                                                       
}
bool GreaterSort(realtimeTableStruct*a,realtimeTableStruct* b)
{
	return (a->useRatio>b->useRatio);
}
