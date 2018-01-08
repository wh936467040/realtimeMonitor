#include "db_api/odb_prv_struct.h"
#include "db_api/odb_tableop.h"
#include "TableStruct.h"
#include "odbsee_tab.h"
#ifndef __ODBSEE_APP_H__
#define __ODBSEE_APP_H__
using namespace ODB;

class OdbseeApp
{
	public:
	CTableOp tab_op;
	int app_id;
	int ctx_no;
	char app_name[128];
	OdbseeApp();
	OdbseeApp(int appId, char * temp_app_name, short ctx_no );
	~OdbseeApp();
	public:
	int DispCtrlTab(vector<realtimeTableStruct *>&tableSet);
	int getTable(int tableNo);
	
};

#endif
