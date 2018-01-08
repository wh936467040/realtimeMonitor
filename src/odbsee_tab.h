#include "db_api/odb_tableop.h"
#include "TableStruct.h"
#ifndef __ODBSEE_TAB_h__
#define __ODBSEE_TAB_h__

using namespace ODB;
class OdbseeTab
{
	public:
	OdbseeTab();
	OdbseeTab( int  app_id , int tab_id , int  ctx_no );
	~OdbseeTab();
	CTableOp tab_op;
	int appId;
	int tableId;
	int ctxId;
	int DispStdbTab(realtimeTableStruct * & table);
	int initMark;
	string TransTime(time_t& cur_time);
};

#endif
