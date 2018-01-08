/*****************************************************************************

*****************************************************************************/

#include "odbsee_app.h"
#include "db_api/odb_prv_struct.h"
#include "db_api/odb_tableop.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "db_api/odb_system.h"
#include "db_api/odb_lock.h"
#include "pub_ctx.h"
#include "odbsee_tab.h"
#include "TableStruct.h"

using namespace ODB;

OdbseeApp::OdbseeApp()
{
}

OdbseeApp::OdbseeApp(int appId ,char * temp_app_name, short temp_ctx_no )
{
	app_id=appId;
	ctx_no= temp_ctx_no;
	strcpy(app_name,temp_app_name);
}


OdbseeApp::~OdbseeApp()
{

}

int OdbseeApp::DispCtrlTab(vector<realtimeTableStruct *>&tableSet)
{
	std::vector<int>  tableInOneApp;
	int ret= tab_op.GetAllOdbNoByAppName( app_id, tableInOneApp, app_name);
	if (ret <0)
	{
		cout<<"获取应用下表号错误"<<endl;
		return -1;
	}
	for(vector<int> ::iterator it = tableInOneApp.begin();it!=tableInOneApp.end();it++)
	{
		int tableId=int (*it);
		int ret_code = tab_op.Open(app_id,tableId);
		if(ret_code < 0)
		{ 
				  continue;
		}
		char tableName [128]="";
		tab_op.GetTableNameByNo(tableName, tableId);
		realtimeTableStruct* table=new realtimeTableStruct(ctx_no,app_id,app_name,tableName,tableId);
		tableSet.push_back(table);
		//cout<<tableId << "   "<< tableName<<endl;
	}
}


