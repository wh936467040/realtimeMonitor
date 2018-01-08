/*
*Copyright(c) 2008,国电南瑞科技股份公司
*All rights reserved.
*
*Filename：       sam_define.h
*Modulename:      for all sysadm modules
*Description:     macro defines
*Author:          gaoyuan
*
*Date            Version               Activities				Modification
*====================================================================
*04/14/2009       1.3                   modified				增加应用锁定功能的支持
*04/10/2009				1.2										modified				共享内存中增加应用名称和节点名称
*03/10/2009       1.1                   modified				将应用总数从256改为512
*  /  /2008       1.0                   created
*********************************************************************
*/

#ifndef _SAM_DEFINE_H_
#define _SAM_DEFINE_H_


#include <vector>
using namespace std;

#ifndef _WINDOWS32
#ifndef _HPUX
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <string>

#include <errno.h>
#include <setjmp.h>
#include <fcntl.h>
#include <math.h>
#include <algorithm>
//#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>

#ifdef _SUN
#undef TRANSPARENT
#endif

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/uio.h>
#include <ctype.h>
#include <signal.h>

#ifdef _ALPHA
#include <sys/systeminfo.h>
#endif

#ifdef _HPUX
#include <sys/param.h> 
#include <sys/pstat.h> 
#include <sys/unistd.h> 
#endif

#else
#include <windows.h>
#include <winsock.h>
#include <direct.h>
#include <io.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <string>
#include <fcntl.h>
#include <algorithm>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <signal.h>
#include <malloc.h>
typedef  char* key_t;
#endif

//
//define
//
#define GET_RECORD_ID(a) ((struct COMM_KEY_STRU*)(&a))->record_id
#define GET_TABLE_NO(a) ((struct COMM_KEY_STRU*)(&a))->table_no
#define GET_COLUMN_ID(a) ((struct COMM_KEY_STRU*)(&a))->column_id

const int              MNG_REORD_OFFSET          =1000000;
//research mode app
const int              REALTIME_MODE_APP         = 1;
const int              RESEARCH_MODE_APP         = 2;
const int              FUTURE_MODE_APP           = 256;
const int              RESEARCH_MODEL_NUM        = 9;
//ntp time differece
//const int              NTP_WARN_DIS              = 10; 
//timer task num
const int              FREQUENCE_SINGLE          = 0;
const int              FREQUENCE_MUTI		     = 1;
const int              MAX_TIMER_TASK_NUM        = 100;
//service type
const int              BASE_SERVICE              = 3400000;
const int              EMS_SERVER                = 1;
const int              EMS_CLIENT                = 2;
const int              EMS_WEBCLIENT             = 4;
const int              WEB_SERVER                = 1024;
//process mask
const int              MASK_REAL                 = 1;
const int              MASK_DTS                  = 2;
const int              MASK_RESEARCH             = 4;
const int              MASK_REAL_WEB             = 65536;
const int              MASK_DTS_WEB              = 131072;
const int              MASK_RESEARCH_WEB         = 262144;
//process report type
const short            PROC_ACT_REPORT           = 1;
const short            PROC_ACT_MONITOR          = 2;

//process message type definition
const short            PROC_NORMAL	             = 1;
const short            PROC_WARN0	             = 2;
const short            PROC_WARN1 	             = 3;
const short            PROC_ERROR0	             = 4;
const short            PROC_ERROR1               = 5;
//process status
const short            PROC_START 	             = 1;
const short            PROC_RUNNING              = 2;
const short            PROC_ABNORMITY            = 3;
const short            PROC_DEADLOOP             = 4;
const short            PROC_STOP                 = 5;
const short            PROC_FAIL                 = 6;

//app status
const unsigned char    APP_START                 = 1;
const unsigned char    APP_STANDBY               = 2;
const unsigned char    APP_DUTY                  = 3;
const unsigned char    APP_FORCESTANDBY          = 4;
const unsigned char    APP_FORCEDUTY             = 5;
const unsigned char    APP_OFFLINE               = 6;
const unsigned char    APP_BAD                   = 7;
const unsigned char    APP_EXIT                  = 8;
//network status
const unsigned char    OFFLINE                   = 0;
const unsigned char    ONLINE                    = 1;
//run status
const unsigned char    IS_EXIT                   = 0;
const unsigned char    IS_RUNNING                = 1;
const unsigned char    IS_START                  = 2;
const unsigned char    IS_RECOVER                = 3;
//app monitor
const int              DIS_BETWEEN_APP_REPORT    = 1;
const int              DIS_COLD_TIME             = 1;
const int              DIS_COLD_UNIT             = 10;
//system data table no
//const short          NODE_INFO_NO	                 = 160;
//const short        APP_DISTRIBUTING_IFO_NO	     = 161;
//const short        NODE_APP_INFO_NO	             = 162;
////const short        APP_PROC_INFO_NO	             = 163;
//const short        SYS_DISTRIBUTING_INFO_NO       = 163;
//const short        PROCESS_INFO_NO	             = 164;
//const short        PROC_STATUS_INFO_NO	         = 165;
//const short        APP_STATUS_INFO_NO	         	 = 166;
//const short        HARD_DISK_INFO_NO             = 167;
//const short        CPU_MEM_TABLE_NO              = 168;
//const short        MNG_PARA_SECTION_NO           = 169;
//const short        MNG_PARA_KEYVALUE_NO          = 170;
const short          MNG_NET_INFO_NO               = 171;
//const short        MNG_APP_DUTY_INFO_NO          = 172;
//const short        MNG_TIMER_INFO                = 173;
//const short        MNG_DISK_INFO_NO              = 177;
//definition

const int          MNG_MAX_APP_NUM               = 1024;//512;//256; modify 20100521
const int          MNG_MAX_PROCESS_NUM           = 600;
const int          MAX_KEY_PROCESS_NUM           = 200;
const int          MAX_OPTION_PROCESS_NUM        = 300;

const int          MAX_DISK_NUM                  = 100;
const int          MAX_NODE_NUM                  = 512;//50;
const int          MNG_MAX_NODE_NUM              = 512;//100;原值已经不够用， gaoyuan 20090425    
const int          MAX_NAME_LEN                  = 40;
const int          MAX_STR_LEN                   = 256;
const int          MNG_MAX_CMD_STR_LEN           = 512; 
const int          MNG_MAX_NET_CARD_NUM          = 2;
const int          MAX_NET_CARD_NUM              = 2;
const int          MAX_SEND_LEN                  = 40960;
const int          MAX_RECV_LEN                  = 40960;
const int          MAX_READ_LEN                  = 1024;
const int          MAX_LEN_OF_BROAD_BUF          = 1024;
const int          MAX_START_TIME                = 3;//10;  modify 20090428
//disk define
const int          MAX_DISTANCE_READ_STATIC	     = 1;
const int          MAX_DISTANCE_READ_DYNAMIC	   = 60;  //5;  modify 20090901
const int          MAX_DISTANCE_READ_DISK        = 10; //600; modify 20090623
const int          REPORT_DISK_USAGES_DISTANCE   = 512;
//
const int          PARA_NUM                      = 6;
const int          MAX_PARA_NUM                  = 10;
const int          PARA_LENGTH                   = /*32*/128; //modify by gaoyuan for Linux   2007/09/22
const int          MNG_COMMAND_LENGTH            = 80;
const int          PATH_LENGTH                   = 80;

const int          CONNECT_TIME_MSECOND          = 200;
const int          TIME_DIS_BETWEEN_START        = 36;
const int          TIME_DIS_BETWEEN_REPORTS      = 16;
const int          MAX_RECEIVE_BUFFER	         = 6000;

//share memory key & sem key
const int          SAM_SHM_KEY                   = 0x1023;
const int          SERVICES_SHM_KEY              = 0x1025;
const int          PROC_SHM_KEY                  = 0x1027;
const int          SAM_NET_SHM_KEY               = 0x1029;

const int          NET_STATUS_SEM_KEY            = 0x1011;
const char         NET_STATUS_SEM_NAME[]         = "NET_STATUS_SEM";
const int          PROC_REPORT_SEM_KEY           = 0x1013;
const char         PROC_REPORT_SEM_NAME[]        = "PROC_REPORT_SEM";
const int          APP_STATUS_SEM_KEY            = 0x1015;
const char         APP_STATUS_SEM_NAME[]         = "APP_STATUS_SEM";

const int          PROC_KEY_SEM_KEY              = 0x1017;
const int          PROC_OPTION_SEM_KEY           = 0x1019;

const int          NODE_NETSTATUS_SEM_KEY        = 0x1021;

const int          NODE_SEM_KEY                  = 0x1111;
const int          SERVICES_SEM_KEY              = 0x1113;
const int          APP_INFO_SEM_KEY              = 0x1115;
const char         APP_INFO_SEM_NAME[]           = "APP_INFO_SEM";
const int          SYSTEM_SEM_INITVAL            = 1;

//other definition
const int          SAM_YES                       = 1;
const int          SAM_NO                        = 0;

//app report type
const int          SAM_APP_START                 = 1001;
const int          SAM_APP_STATUS_CHANGE         = 1002;
const int          SAM_APP_STATUS_REPORT         = 1003;
const int          SAM_APP_SWITCH                = 1005;
const int          SAM_APP_SWITCH_RPS            = 1006;
const int          SAM_APP_EXIT                  = 1007;
//cold app report type
const int          SAM_COLD_STATUS_CHANGE        = 1008;
const int          SAM_COLD_STATUS_REPORT        = 1009;
//proc report type
const short        REPORT_KEY_PROC_STATUS        = 2001;
const short        REPORT_OPTION_PROC_STATUS     = 2002;

//sam trans client report type
const short        REPORT_TRANS_CLIENT_NORMAL    = 1200;
const short        REPORT_TRANS_SERVER_NORMAL    = 1201;

//socket definition
//const int          MNG_SERV_UDP_PORT             = 8001;
//const int          MNG_SERV_TCP_PORT             = 8003;
//const int          MNG_SERV_TCPREXEC_PORT        = 8005;
const int          MNG_TIME_UDP_PORT             = 2345;

//error definition
//add 20090415
const int				    OPEN_PARA_FILE_FAIL   				= -1001;
const int						GET_PARA_FAIL 								= -1002;
const int						GET_NETMASK_FAIL							= -1003;
const int						INPUT_IP_ADDRESS_ERROR				= -1004;
const int						CONVERT_IP_ERROR							= -1005;
const int						PROC_DO_NOT_EXIST 						= -1006;
const int						KILL_PROC_FAIL								= -1007;
const int						CLEAR_PROC_STATUS_FAIL  			= -1008;
const int						CLEAR_NET_STATUS_FAIL	 				= -1009;
const int						CLEAR_APP_STATUS_FAIL    			= -1010;
const int						P_SEM_ERROR 									= -1011;
const int						V_SEM_ERROR										= -1012;
const int						APP_NUM_ERROR									= -1013;
const int						APP_DO_NOT_EXIST 							= -1014;
const int						PROC_STATUS_INPUT_ERROR  			= -1015;
const int						UPDATE_APP_STATUS_FAIL    		= -1016;
const int						SWITCH_FLAG_INPUT_ERROR  			= -1017;
const int						GET_HOSTNAME_ERROR			      = -1018;
const int						GET_BASE_INFO_FAIL				    = -1019;
const int						PROCESS_INFO_NOT_SET					= -1020;
const int						GET_PROCESS_INFO_FAIL					= -1021;
const int						RUN_STATUS_INPUT_ERROR  		  = -1022;
const int						MAP_FILE_FAIL									= -1023;
const int						SHMGET_FAIL										= -1024;
const int						SHMMAT_FAIL										= -1025;
const int						INIT_SEM_FAIL									= -1026;
const int						IS_NOT_SERVER									= -1027;
const int 					NAMETOID_FAIL									= -1028;
const int 					IDTONAME_FAIL									= -1029;
const int 					PARA_INPUT_ERROR   						= -1030;
const int 					INIT_NETINFO_ERROR						= -1031;
const int						GET_NETINFO_ERROR							= -1032;
const int						SET_PROCOK_FAIL								= -1033;
const int						INIT_NIC_FAIL									= -1034;
const int						GET_NIC_FAIL									= -1035;
const int						APP_DO_NOT_RUN  							= -1036;


////////////////////////////////////////////////////////// add 20090415


const int          APP_DONT_DUTY                 = -1910;
const int          APP_DONT_STANDBY              = -1911;
const int          APP_DONT_EXT                  = -1912;
const int          ERR_INPUT_PARA                = -1913;
const int          NO_OTHER_APP_STANDBY          = -1914;
const int          NO_OTHER_APP_DUTY             = -1915;
const int          CAN_NOT_SWITCH_TO_STANDBY     = -1916;
const int          CAN_NOT_SWITCH_TO_DUTY        = -1917;
const int 				 APP_LOCKED										 = -1918; //add 20090414
//max socket address struct size
//const int          MAXSOCKADDR                   = 128;
const int          MNG_PLOT_SIZE                 = 101;

//进程运行类型
const int          START_RESPAWN_OPTION          = 0;
const int          START_RESPAWN_KEY             = 1;
const int          START_ONCE                    = 2;
const int          START_WAIT                    = 3;
const int          STOP_WAIT                     = 4;

//SAM TRANS ERROR DEFINE
const int          ECLIENT_CLOSE                 = -2;
const int          ESERVER_CLOSE                 = -3;
const int          ERECV_ZERO                    = 0;




#ifndef    _WINDOWS32
#ifdef    _ALPHA
#define   socklen_t    int
#endif
#ifdef    _IBM
#define   socklen_t    unsigned long
#endif
#else
#define   socklen_t    int
#endif


//参数管理
const int          PARA_MAX_NAME_LEN             = 40;
const int          PARA_DESCRIBE_LEN             = 40;

//参数管理数据结构
struct PARA_SECTION
{
    int rec_id;
    int parent_id;
    char section_name[PARA_MAX_NAME_LEN];
    char describe_info[PARA_DESCRIBE_LEN];
};

struct PARA_KEYVALUE
{
    int rec_id;
    char key_name[PARA_MAX_NAME_LEN];
    char key_value[PARA_MAX_NAME_LEN];
    char describe_info[PARA_DESCRIBE_LEN];
};

struct SECTION_ID
{
    int section_id;
    int parent_id;
};


typedef struct tag_PARA_KEY_VALUE
{
    char para_key[PARA_MAX_NAME_LEN];
    char para_val[PARA_MAX_NAME_LEN];
} PARA_KEY_VALUE;

//远程启动命令
struct STARTPROG_CMD
{
    char         cmd[MNG_COMMAND_LENGTH];
    char         cmd_param[MAX_STR_LEN];
};
//远程启动回复
struct STARTPROG_CMD_RESPONSES
{
    char         resp_cmd[MAX_STR_LEN];
};

//system struct
//
//struct of app distributing info
//
struct APP_DISTRIBUTING_INFO
{
    int   app_id;
    int   context;
    char  app_name[40];
    int   node_num;
    long   node_1;
    long   node_2;
    long   node_3;
    long   node_4;
    long   node_5;
    long   node_6;
    long   node_7;
    long   node_8;
    long   node_9;
    long   node_10;
    long   node_11;
    long   node_12;
    long   node_13;
    long   node_14;
    long   node_15;
    long   node_16;
    int   occupy_model;
};

struct APP_DISTRIBUTING_INFO_ABBR
{
    int   app_id;
    int   context;
    char  app_name[40];
    int   node_num;
    //int   node[16];
    long  node[16];
    int   cold_node_num;
    //int cold_node[16];
    long  cold_node[16];
};

struct SYS_DISTRIBUTING_INFO_ABBR
{
    int   system_id;
    int   context;
    int   app_id;
    char  app_name[40];
    int   node_num;
    
    //int   node[16];
    long		node[16];
    int   	cold_node_num;
    //int   cold_node[16];
		long 		cold_node[16];
    int   	occupy_model;
};


//
//struct of node app info
//
struct APP_ID_NAME
{
    int app_id;
    char app_name[MAX_NAME_LEN];
};

//
//struct of node app info
//
/* 节点应用关系表 */
struct NODE_APP_INFO
{
	long rec_id;	/* 记录号 */
	int system_id;	/* 系统号 */
	int app_id;	/* 应用号 */
	short context;	/* 应用上下文 */
	long node_id;	/* 节点号 */
	short app_priority;	/* 应用优先级 */
	short cur_status;	/* 应用状态 */
	time_t last_recv_time;	/* 最后刷新时间 */
};

//
//struct of process info
//
struct MNG_PROCESS_INFO
{
    //int           process_id;
    long					process_id;
    int           app_id;
    char          proc_alias[MAX_NAME_LEN];
    char          proc_name[MAX_NAME_LEN];
    int           instance_num;
    int           run_port;
    unsigned char not_used;
//    unsigned char key_proc;
    unsigned char start_type;
    unsigned char auto_run;
    int           run_order;
    unsigned char cycle_start;
    int           cycle_period;
    unsigned char offline_run;
    unsigned char duty_run;
    unsigned char standby_run;
    unsigned char report_type;
    int           occupy_context;
    char          file_path[80];
    char          proc_para[80];
    char          proc_description[80];
    unsigned char run_style;
};

//
//struct of process status info
//
struct PROC_STATUS_INFO
{
    char            proc_alias[MAX_NAME_LEN];
    int             context;
    int             pid;
    char            proc_name[MAX_NAME_LEN];
    int             node_id;
    time_t          start_time;
    int             restart_counter;
    float           occupy_cpu;
    float           occupy_mem;
    unsigned char   cur_status;
    time_t          last_active_time;
    int             app_id;
};

struct APP_STATUS_REPORT_INFO
{
    int           app_id;
    char          app_name[MAX_NAME_LEN]; //add 20090409
    int           node_id;
    char          node_name[MAX_NAME_LEN];
    short         app_priority;
    unsigned char net_status;
    unsigned char cur_status;
    unsigned char all_process_ok;
    time_t        last_receive_info_time;
    time_t        report_time;
    int           run_status;
    int           context;
    short					switch_flag; //20090414
};

//
//struct of process static info
//
struct PROC_STATIC_INFO
{
    //int           process_id; for d5000
    long					process_id;
    char          proc_name[MAX_NAME_LEN];
    char          proc_alias[MAX_NAME_LEN];
    int           instance_num;
    unsigned char not_used;
//    unsigned char key_proc;
    unsigned char start_type;
    unsigned char auto_run;
    int           run_order;
    unsigned char cycle_start;
    int           cycle_period;
    unsigned char offline_run;
    unsigned char duty_run;
    unsigned char standby_run;
    int           occupy_context;
    char          file_path[MNG_COMMAND_LENGTH];
    char          proc_para[MNG_COMMAND_LENGTH];
    unsigned char run_style;
    //char          proc_para[PARA_NUM][PARA_LENGTH];
    //int           para_num;
};
//
//struct
//
struct APP_PROC_STATIC_INFO
{
    int   app_id;
    int   context;
    int   proc_num;
    std::vector<struct PROC_STATIC_INFO>proc_info_stru;
};
//
//struct of node app relation info
//
struct NODE_APP_RELATION
{
    //int node_id;
    long node_id;
    std::vector<struct APP_SERVER_INFO>app_server_stru;
};
//
//struct
//
struct APP_START_REPORT
{
    short          report_type;
    unsigned short checksum;
    int            node_id;
    int            app_id;
    short          app_priority;
    char           context[MAX_NAME_LEN];
    unsigned char  cur_status;
};
//
//struct for process report status to SAM
//
struct PROC_STATUS
{
    int           context;
    int           app_id;
    unsigned char all_proc_ok;
    short         normal_proc_num;
    short         abnormal_proc_num;
};
//
//struct for process control
//
struct PROC_CTL_INFO
{
    int    use_flag;
    int    context;
    int    app_id;
    char   proc_name[MAX_NAME_LEN];
    char   proc_alias[MAX_NAME_LEN];
    char   proc_para[MNG_COMMAND_LENGTH];
    pid_t  proc_id;
    int    para_num;
    time_t start_time;
};

struct APP_STATUS_CHANGE
{
    char project_name[MAX_NAME_LEN];
    int node_id;
    char node_name[MAX_NAME_LEN];
    time_t report_time;
    int app_context;
    int app_id;
    short app_priority;
    unsigned char cur_status;
    unsigned char all_process_ok;
};

//
//union for sam_common
//

union SEMUN {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

//
struct ONE_PROCESS_DEF
{
    int    flag;
    pid_t  pid;
    pid_t  ppid;
    float  pcpu;
    float  pmem;
    time_t stime;
    char   comm[MNG_COMMAND_LENGTH];
    int    actual_para_num;
    char   paras[PARA_NUM][PARA_LENGTH];
    time_t last_get_info_time;
};

//
//struct of key process
//
struct KEY_PROC_INFO
{
    int           context;
    int           app_id;
    pid_t         proc_id;
    char          proc_name[MNG_COMMAND_LENGTH];
    char          proc_alias[MNG_COMMAND_LENGTH];
    int           node_id;
    int           run_port;
    int           instance_num;
    time_t        start_time;
    int           restart_counter;
    float         occupy_cpu;
    float         occupy_mem;
    int           cur_status;
    int           run_order;
    unsigned char auto_run;
    unsigned char offline_run;
    unsigned char duty_run;
    unsigned char standby_run;
    int           occupy_context;
    unsigned char report_type;
    time_t        last_active_time;
    char          proc_para[PARA_NUM][PARA_LENGTH];
    int           para_num;
    char          file_path[PATH_LENGTH];
    unsigned char run_style;
};

//
//struct of option proc
//
struct OPTION_PROC_INFO
{
    int           context;
    int           app_id;
    pid_t         proc_id;
    char          proc_name[MNG_COMMAND_LENGTH];
    char          proc_alias[MAX_NAME_LEN];
    int           cur_status;
    unsigned char report_type;
    time_t           last_active_time;
    char          proc_para[PARA_NUM][PARA_LENGTH];
    int           para_num;
    unsigned char run_style;
};

struct PROC_DYNAMIC_INFO
{
    char  user[MAX_NAME_LEN];
    char  pid[MAX_NAME_LEN];
    char  ppid[MAX_NAME_LEN];
    char  pcpu[MAX_NAME_LEN];
    char  pmem[MAX_NAME_LEN];
    char  stime[MAX_NAME_LEN];
    char  comm[MNG_COMMAND_LENGTH];
    char  para[PARA_NUM][PARA_LENGTH];
    int   para_num;
};

struct ONE_DISK_INFO
{
	long     disk_id; /* disk_id*/
	long     machine_id; /* 节点id */
  char    partition_name[128]; /* 分区名*/
	char    dir_name[128]; /* 挂接目录名*/
	int     total_capacity; /* 总容量(M)*/
	int     used_capacity; /* 已用*/
	int     unused_capacity; /* 未用*/
	float   used_quato; /* 使用率*/
	float   warn_limit;  /*告警极限 */
	time_t	last_time_send_disk;
};

struct CPU_MEM_INFO
{
    long record_id;
    long machine_id; /* 节点名*/
    int occupy_mem;
    int free_mem;
    unsigned short  sys_cpu_usage;
    unsigned short  usr_cpu_usage;
    unsigned short  idle_cpu;  
    float   cpu_warn_limit;  
    time_t  last_time_send_cpu;   
    int			cpuState; 
};

struct VMSTAT_INFO
{
    char r[20];
    char w[20];
    char u[20];
    char act[20];
    char free[20];
    char wire[20];
    char fault[20];
    char cow[20];
    char zero[20];
    char react[20];
    char pin[20];
    char pout[20];
    char intr_in[20];
    char intr_sy[20];
    char intr_cs[20];
#ifdef _ALPHA
    unsigned short  cpu_us;
    unsigned short  cpu_sy;
    unsigned short  cpu_id;
#else
    unsigned int  cpu_us;
    unsigned int  cpu_sy;
    unsigned int  cpu_id;
#endif
};

struct NETSTAT_INFO //modify by gaoyuan 20090708
{
    long record_id; /* 记录号 */
    long node_id;   /* 节点号 */
    char netcard_name[32];  /* 网卡名 */
    char ip_address[32];    /* 网卡地址 */
    unsigned char net_status;   /* 网卡状态 */
    int mtu;    /* 最大传输单元 */
    int tx_queue_len;   /* 传输队列长度 */
    int average_flow;   /* 网卡平均流量(字节每秒) */
    long rx_packets;    /* 接收包的数量 */
    long tx_packets;    /* 发送包的数量 */
    long rx_kbytes; /* 收到的千字节数 */
    long tx_kbytes; /* 发送的千字节数 */
    long rx_errors; /* 收到出错包数 */
    long tx_errors; /* 发送包出错数 */
    long collisions;    /* 发生冲突次数 */
    long last_recv_time;    /* 最后刷新时间 */
};

struct NETSTAT_SYS
{
    int first_in_pkg;
    int first_in_err;
    int first_out_pkg;
    int first_out_err;
    int first_colls;
    int total_in_pkg;
    int total_in_err;
    int total_out_pkg;
    int total_out_err;
    int total_colls;
};

struct STANDBY_NODE_PRIOR
{
    int   node_id;
    int   app_id;
    char  app_name[MAX_NAME_LEN];
    int   priority;
};

/* 应用主机状态信息 */
struct APP_DUTY_INFO
{
	//int 		rec_id;	/* 记录号 */
	long		rec_id;
	int 		app_id;	/* 应用id */
	char 		duty_nodename[MAX_NAME_LEN];	/* 值班节点名 */
	long 		duty_nodeid;	/* 值班节点id */
	time_t 	last_switch_time;	/* 最后切换时间 */
	time_t 	last_active_time;	/* 最后活动时间 */
	int 		context;
};

struct APP_ACTIVENODE_NUM
{
    int context;
    int app_id;
    int count;
    int wait_time;
};

/*定时器结构*/
struct TIMER_INFO
{
    time_t  occur_time;                         /* 时间*/
    char    command[MAX_NAME_LEN];              /* 命令名*/
    char    cmd_para[MAX_STR_LEN];              /* 命令参数*/
    unsigned char frequence;                    /* 频率 0:仅运行一次 1:多次运行*/
    int     interval;                           /* 间隔*/
    unsigned char interval_type;                /* 间隔类型 0:分钟 1:小时 2:天 3:周 4:月 5:年*/
    unsigned char run_style;                    /* 运行方式 1:本节点运行 2:备机运行 3:主机运行 4:指定节点*/
    int     app_id;                             /* 所属应用*/
    //int     node_id;                            /* 节点id*/
    long		node_id;
};

struct TimeDo
{
    struct TIMER_INFO timer_struct;
    int    interval_time;
    int    do_mark;
};

struct PROC_DESC_STRU
{
    char proc_alias[MAX_NAME_LEN] ;
    char proc_description[80]; 
};

struct NODE_INFO_TYPE_STRU
{
    //int node_id;
    long	node_id;
    char node_name[MAX_NAME_LEN];
    unsigned char node_type; 
};

struct NODE_INFO_TYPE_STRU_SYSADM
{
    long	node_id;
    char node_name[MAX_NAME_LEN];
    unsigned char node_status;
    unsigned char node_type;  
 	int 	system_id;	
};

struct NodeNetStatus
{
    char node_name[MAX_NAME_LEN];
    time_t last_active_time;
    unsigned char net_status;
};


struct ProcStatusInfoKey
{
    char proc_alias[MAX_NAME_LEN];
    int  context;
};

struct SysInfoTableCpu
{
#ifndef _IBM
    long lusr;
    long lsys;
    long lidle;
#else
    long long lusr;
    long long lsys;
    long long lidle;
#endif
};


struct RESEARCH_APP_STRU
{
    int app_id;
    int context;
    int occupy_model;
};


struct SysInfoTableSwap
{
    int swap_all;
    int swap_free;
};

struct SystemNameInfo
{
    int system_id;
    char system_name[MAX_NAME_LEN];
};

struct SystemContextInfo
{
    int system_id;
    int context;
    char context_name[MAX_NAME_LEN];
};


struct SystemAppInfo
{
    int system_id;
    int context;
    int app_id;
};


struct FileStatusInfo
{
    char file_name[128];
    int  size;
    time_t mtime;
};

#endif
