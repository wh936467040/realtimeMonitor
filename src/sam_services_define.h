/*
*Copyright(c) 2008,国电南瑞科技股份公司
*All rights reserved.
*
*Filename：       sam_services_define.h
*Modulename:      for all sysadm modules
*Description:     macro defines
*Author:          gaoyuan
*
*Date            Version               Activities				Modification
*====================================================================
*04/14/2009       1.2                   modified				增加应用锁定功能的支持
*04/10/2009				1.1										modified				共享内存中增加应用名称和节点名称
*  /  /2008       1.0                   created
*********************************************************************
*/

#ifndef __SAM_SERVICES_DEFINE_H__
#define __SAM_SERVICES_DEFINE_H__

#include "sam_define.h"
#ifndef _WINDOWS32
#include <sys/time.h>
#ifndef _HPUX
#include <unistd.h>
#endif
#include <netinet/in.h>

#ifdef _SUN
#undef TRANSPARENT
#endif

#else
#include <windows.h>
#include <time.h>
#include <sys/timeb.h>
typedef   DWORD pid_t;
#endif

//const int          MNG_MAX_NAME_LEN              = 40;
const int          MNG_MAX_STR_LEN               = 256;

//
//struct for process report
//
struct PROC_REPORT_INFO {
    int           context;
    int           app_id;
    char          proc_alias[MAX_NAME_LEN];
    pid_t         proc_id;
    time_t        mon_time;
    time_t        start_time;
    int           proc_run_port;
    int           report_moncycle;
    int           msg_level;
    int           status_change;
    char          proc_msg[MNG_MAX_STR_LEN];
    int           proc_beat;
};

//
//struct of net card status
//
struct NET_CARD_STATUS
{
    unsigned char      use_flag;
    char               net_card_id[MAX_NAME_LEN];
    unsigned char      net_card_ok;
};

struct APP_STATUS_INFO 
{
    int           context;
    int           app_id;
    char          app_name[MAX_NAME_LEN]; //modify 20090409
    int           node_id;
    char          node_name[MAX_NAME_LEN]; //add 20090409
    short         app_priority;
    unsigned char cur_status;
    unsigned char net_status;
    unsigned char all_proc_ok;
    int           normal_key_proc_num;
    int           bad_key_proc_num;
    time_t        last_active_time;
    unsigned char run_status;
    short					switch_flag; //add 20090414
    char					reserve[20]; //add 20090414
};

//
//struct of node info
//
struct NODE_INFO
{
    //int           node_id;
    long					node_id;
    char          node_name[40];
    unsigned char net_status;
    float         cpu_used;
    float         mem_used;
    unsigned char node_status;
    unsigned char net1_status;
    unsigned char net2_status;
    unsigned char node_type;
    char          desc_info[64];
    unsigned char not_use_flag;
    time_t           last_report_time;
};

struct MODIFY_NODE_INFO
{
    unsigned char net_status;
    float         cpu_used;
    float         mem_used;
    unsigned char node_status;
    unsigned char net1_status;
    unsigned char net2_status;
    char          desc_info[64];
    unsigned char not_use_flag;
    time_t        last_report_time;
};

struct MODIFY_NODE_TIME
{
    //int           node_id;
    long					node_id;
    unsigned char node_type;
    time_t        last_report_time;
    int           system_id;
};

struct MODIFY_NET_TIME
{
    long record_id; /* 记录号 */
    long node_id;   /* 节点号 */
    char netcard_name[32];  /* 网卡名 */
    unsigned char net_status;   /* 网卡状态 */
   	long last_recv_time;    /* 最后刷新时间 */
};

struct MODIFY_NET_NONE
{    
	unsigned char net_status;   /* 网卡状态 */
  int average_flow;   /* 网卡平均流量(字节每秒) */    
};

struct NODE_INFO_TABLE
{
    //int          node_id;
    long 				 node_id;
    char         node_name[40];
};

struct NODE_INFO_TABLE_TYPE
{
    long 				 		node_id;
    char         		node_name[40];
    unsigned char		node_type;
};

struct SERVICES_INFO
{
    int           use_flag;
    int           context;
    int           app_id;
    char          service_name[80];//proc_alias;
    int           run_port;
};

//
//struct of app status info
//
struct APP_STATUS_TABLE_INFO
{
    int           app_id;
    char          app_name[MAX_NAME_LEN]; //add 20090409
    int           node_id;
    char          node_name[MAX_NAME_LEN]; //add 20090409
    //long					node_id;
    short         app_priority;
    unsigned char net_status;
    unsigned char cur_status;
    unsigned char all_process_ok;
    //int           last_receive_info_time;
    time_t 					last_receive_info_time;
    int           context;
};


struct SYS_APP_TABLE_INFO
{
    int system_id;
    int context;
    int app_id;
    int node_id;
    //long node_id;
    short app_priority;
    unsigned char net_status;
    unsigned char cur_status;
    unsigned char all_process_ok;
    time_t last_receive_info_time;
    unsigned char cold_flag;
};

struct APP_STATUS_TABLE_INFO_SERV
{
    int           app_id;
    char          app_name[MAX_NAME_LEN];
    int           node_id;
    //long					node_id;
    char          node_name[MAX_NAME_LEN];
    short         app_priority;
    unsigned char net_status;
    unsigned char cur_status;
    unsigned char all_process_ok;
    time_t        last_receive_info_time;
    int           context;
    short					switch_flag; //add 20090414
};
 
#endif