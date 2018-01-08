/*****************************************************************************

*****************************************************************************/

#include "odbsee_tab.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "db_api/odb_system.h"
#include "db_api/odb_lock.h"
#include "pub_ctx.h"

#ifndef 	PK_HOLE_DIRECT
#define PK_HOLE_DIRECT 3  /*带洞直接定位表*/
#endif

using namespace ODB;

OdbseeTab::OdbseeTab()
{

}

OdbseeTab::OdbseeTab( int app_id , int tab_id , int ctx_no )
{
	appId=app_id;
	tableId=tab_id;
	ctxId=ctx_no;                                                                                                                   
}



OdbseeTab::~OdbseeTab()
{

}

int OdbseeTab::DispStdbTab(realtimeTableStruct * & table)
{
	float useRatio=0;
	int ret_code = tab_op.Open(appId, tableId, ctxId);
	if(ret_code < 0)
	{ 
		return -1;
	}
	struct STDB_TAB* stdb;
	stdb = tab_op.GetCurStdbTab ();

	if(stdb->record_sum==0)
	{
		useRatio=0;
	}else
	{
		useRatio=float(stdb->record_number)/stdb->record_sum*100;
	}
	table->recordNum=stdb->record_number;
	table->recordSum=stdb->record_sum;
	table->downloadTime=TransTime(stdb->download_time);
	table->useRatio=useRatio;
	table->pkMemAllocType = stdb->pk_mem_alloc_type;
	cout << "alloc type = " << table -> pkMemAllocType << endl;
	free(stdb);
	return 1;
}

//////////////////////////////////////////////////////////

string OdbseeTab::TransTime(time_t& cur_time)
{
    struct tm *tmp_time;
    char value_string[64];
    string ret_str;
        
    tmp_time = localtime((time_t *)&cur_time);
        
    sprintf(value_string, "");
 
    sprintf(value_string, "%04d-%02d-%02d %02d:%02d:%02d",
                tmp_time->tm_year + 1900,
                tmp_time->tm_mon + 1,
                tmp_time->tm_mday,
                tmp_time->tm_hour,
                tmp_time->tm_min,
                tmp_time->tm_sec);
    ret_str = value_string;
    return ret_str;
}


