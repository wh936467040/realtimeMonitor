#ifndef __SENDINFO_H__
#define __SENDINFO_H__

#include <stdio.h>
#include <iostream.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

const string TYPE_TIME_INFO = "0";
const string TYPE_ITEM_INFO = "1";
const string TYPE_SERVER_INFO = "2";
const string TYPE_DISK_INFO = "3";
const string TYPE_NET_INFO = "4";
//const string TYPE_SHOWSERVICE_INFO = "5";
const string TYPE_DB_IO_STAT = "6";
const string TYPE_DB_MEM_STAT = "7";
const string TYPE_DB_SESSION_STAT = "8";
const string TYPE_DB_SQL_STAT = "9";
const string TYPE_DB_STAT = "10";
const string TYPE_DB_TABLESPACE_STAT = "11";
const string TYPE_NET_ICMP = "12";
const string TYPE_PROCESS_DYNAMIC_INFO = "13";
const string TYPE_SERVICE_INFO = "14";
const string TYPE_MSGBUF_INFO = "15";
const string TYPE_PROXY_INFO = "16";
const string TYPE_CORE_INFO = "17";
const string TYPE_NETSTAT_INFO = "18";
const string TYPE_DALARM_INFO = "19";
const string TYPE_SCADA_DATA_INFO = "20";
const string TYPE_DB_STATIC_STAT_INFO = "21";
const string TYPE_JUMP_INFO = "22";
const string TYPE_DISPATCH_LINK_STATE_INFO = "23";
const string TYPE_MSG_CHANNEL_INFO = "24";
const string TYPE_SYSCTL_DATA_INFO = "25";
const string TYPE_DSYSTEM_STATUS_INFO = "26";
const string TYPE_REALTIME_STATE_INFO = "27";
const string TYPE_JOB_MGR_INFO = "28";
const string TYPE_REALTIME_ACCESSNUM_INFO = "29";
const string TYPE_REALTIME_DOWNLOADNUM_INFO = "30";
const string TYPE_SERVICE_STATUS_INFO = "31";
const string TYPE_TOP_CPU_INFO = "32";
const string TYPE_TOP_MEM_INFO = "33";
const string TYPE_SERVER_PHY = "34";
const string TYPE_ALL = "43";
const string TYPE_ALARM_INFO_HARD = "44";
const string TYPE_ALARM_INFO_DISHARD = "45";
const string TYPE_ALARM_INFO_SYS = "46";
const string TYPE_ALARM_INFO_DISYS = "47";
const string TYPE_ALARM_INFO = "48";
const string TYPE_DISALARM_INFO = "49";
const string TYPE_NOTICE_INFO = "50";
const string TYPE_DSTART_ALARM_INFO = "51";

const string SHOWSERVICE_INFO = "10001";
const string PROCESS_DYNAMIC_INFO_ = "10002";
const string DATA_SCADA_DATAQ_ACCORD = "10003";
const string DATA_SCADA_DATAQ_BALANCE = "10004";
const string DATA_SCADA_DATAQ_DEVICE = "10005";
const string DATA_SCADA_DATAQ_MEASURE = "10006";
const string DATA_SCADA_DATAQ_MODEL = "10007";
const string DATA_SCADA_DATAQ_SUBSTATION = "10008";
const string DATA_SCADA_DATAQ_UPLOAD = "10009";
const string DATA_SCADA_DATAQ_YX = "10010";
const string SYSCTL_DATA_INFO_ = "10024";
const string SERVICE_STATUS_INFO ="10030";
const string PORT_NETINFO = "10031";
const string TOP_READ = "10032";
const string TOP_SOCKET_CONNECT = "10033";
const string TOP_WRITE = "10034";
const string FILE_VERSION = "10035";
const string DATA_MAIN_FRAM_NODE = "10048";
const string DATA_DC_EQU = "10049";
const string DATA_CLOCK_MGR = "10050";
const string DATA_PUM_DATA = "10052";
const string KID_CONNECT_NAME = "20002";
const string UPDATE_FILE_VERSION = "20004";
const string RESEND_PKG_FORMULA_DEFINE = "20005";
const string JBZDH_CPUINFO = "30001";
const string JBZDH_MEMINFO = "30002";
const string JBZDH_ENCRATEINFO = "30003";
const string JBZDH_DEVCOUNT = "30004";
const string JBZDH_NETFLOW = "30005";
const string JBZDH_SECURITYINDEX = "30006";
const string JBZDH_HISENCRATE = "30007";
const string JBZDH_HISONLINERATE = "30008";
const string JBZDH_HISDEVCOUNT = "30009";
const string JBZDH_HISWARNINGNUM = "30010";
const string JBZDH_HISSECURITYINDEX = "30011";
const string JBZDH_MONITORINFO = "30012";
const string JBZDH_WARNINGCURVE = "30013";
const string JBZDH_WARNINGLIST = "30014";
const string JBZDH_WARNINGNUM = "30015";
const string FORMULA_CLASS_INFO = "30016";
const string FORMULA_DEFINE = "30017";
const string JBZDH_HISVOLONLINERATE = "30018";
const string SESSION_ALARM_INFO = "40001";



struct SHOWSERVEICE_INFO {
	string context; //̬��,���̬�м���;�ָʾ����context1;context2;context3
	string app;  //Ӧ�úţ����Ӧ������;�ָ������contextһһ��Ӧ
	string app_name;//Ӧ����
	string priority;// ���ȼ���������ͬ��
	string status;//��ǰ״̬��������ͬ��
	string nodename;//�ڵ�����������ͬ��
	string fresh_status;//ˢ��״̬��������ͬ��
	string switch_status;//�л�״̬��������ͬ��
};

struct DB_IO_STAT {
	string read_count; //������
	string write_count; //д����
	string read_bytes; //����С
	string write_bytes; //д��С
};

struct DB_MEM_STAT {
	string mem_total_bytes; //�ڴ��ܴ�С
	string mem_used_bytes; //�ڴ������ܴ�С
	string os_used_bytes; //os�����ܴ�С
	string buf_bytes; //buf��С
	string log_buf_bytes; //��־buf��С
};

struct DB_SESSION_STAT {
	string sess_addr; //session��ַ
	string create_time; //����ʱ��
	string login_name; //��¼��
	string client_app; //
	string client_ip; //�ͻ���ip
	string status; //״̬
	string sql_text; //sql���
	string cpu_time; //
	string cpu_time_call; //
	string logic_read; //
	string logic_read_call; //
	string mem_used; //�����ڴ�
};

struct DB_SQL_STAT {
	string start_time; //ִ��ʱ��
	string exec_time; //ִ��ʱ��
	string client_ip; //�ͻ���ip
	string db_name; //���ݿ���
	string login_name; //��¼��
	string app_name; //Ӧ����
	string sess_addr;
	string tran_id;
	string sql_text; //sql���
};

struct DB_STAT {
	string session_count; //session����
	string trx_count;
	string start_time;
};

struct DB_STATIC_STAT{
	string version;
	string max_session_count;
	string port;
};

struct DB_TABLESPACE_STAT {
	string tp_name; //
	string group_name; //����
	string file_path; //�ļ�·��
	string tp_id; //
	string group_id; //
	string file_id; //�ļ�id
	string file_num; //�ļ�����
	string total_bytes; //�ܴ�С
	string free_bytes; //���д�С
	string use_ratio; //ʹ����
};

struct NET_ICMP {
	string net_ip; //ip��ַ
	string net_mac; //mac��ַ
};

struct PROCESS_DYNAMIC_INFO {
	string context_name; //̬
	string app_name;  //Ӧ����
	string proc_name; //������
	string critical; //���̵ȼ�
	string status; //����״̬
	string cpu_percent; //cpuʹ����
	string mem_occupy; //�ڴ�ռ����
	string run_time; //����ʱ��
	string start_time; //��ʼʱ��
	string thread_num; //�߳���
	string file_discriptor_used; //ռ���ļ���������
	string coredump_num; //coredump����
	string disk_read; //���̶�������
	string disk_write; //����д������
	string net_in; //����������
	string net_out; //����������
	string str_time; //��ǰʱ��
	string proc_pid; //����pid
	string core_lasttime;//�����¼�
	string coredump_sum;//core�ܺ�
};

struct SERVICE_INFO {
	string name; //������
	string sysid; //ϵͳid
	string servid; //����id
	string addr; //������ַ
	string port; //�˿ں�
	string balance; //����
	string connum; //������
	string accessnum; //������
};

struct MSGBUF_INFO {
	string recv_msg; //��Ϣ���߽�����Ϣ��
	string send_msg; //��Ϣ���߷�����Ϣ��
};

struct PROXY_INFO {
	string prot;  //Э����
	string recv_q;//����������
	string send_q;//����������
	string foreign_addr;//���ص�ַ
	string local_addr;//���ӵ�ַ
	string status;//����״̬
	string process;//��������pid
};

struct CORE_INFO {
	string core_name;
	string serv_name;
	string core_time;
};
/*
 * ���ݴ���Ľڵ�����ʱ��ͼ������ƴ��xml
 * nodeID��   �ڵ���
 * time:      ���ʱ��
 * map_item:  ���ֵ����ʽΪ��<itemid,value>
 */

 struct NET_STAT_INFO  //��������
{
    string Id;    
	string netcard_name;/* ������ */
	string ip_addr;/* ������ַ */
    string net_status;   /* ����״̬ */
    string mtu;    /* ����䵥Ԫ */
    string tx_queue_len;   /* ������г��� */
    string average_flow;   /* ����ƽ������(�ֽ�ÿ��) */
    string rx_packets;    /* ���հ������� */
    string tx_packets;    /* ���Ͱ������� */
    string rx_kbytes; /* �յ���ǧ�ֽ��� */
    string tx_kbytes; /* ���͵�ǧ�ֽ��� */
    string rx_errors; /* �յ�������� */
    string tx_errors; /* ���Ͱ������� */
    string collisions;    /* ������ͻ���� */
};

struct ALARM_INFO
{
	string itemid;
	string data;
};

struct NOTICE_INFO
{
	string itemid;
	string data;
};
struct ALARM_INFO_HARD
{
	string itemid;
	string data;
};

struct ALARM_INFO_D5000
{
	string itemid;
	string data;
};

struct DISALARM_INFO_D5000
{
	string itemid;
	string starttime;
	string endtime;
	string flag;
};

struct SCADA_DATA_QUALITY
{
	string kid;//key_id
	string current_data;
	string field_id;//���
	string flash_flag;//ˢ�±�־
	string unflash_time;
};


struct JUMP_INFO
{
	string key_id;//key_id
	string desc;
	string field_id;//���
	string jump_flag;//�Ƿ������־
	string jump_time;//����ʱ��
};

struct DISPATCHCENTER_LINK_STATE
{
	string dispatchcenter_name;//�ַ�������
	string link_state;//��·״̬
	string link_num;//��·��
};

struct MSG_CHANNEL_INFO
{
	string channel_id;//ͨ����
	string event_id;//�¼���
	string event_count;//�¼���������
	string event_length;//�¼������ֽ���
};

struct SYSCTL_DATA_INFO
{
	string sum_page;//������ڴ�ҳ������
	string usable_page;//ʣ�๲���ڴ�ҳ������
	string sum_mins;//������ڴ�ε�����
	string usable_mins;//ʣ�๲���ڴ�ε�����
	string sum_array;//����ź���������
	string usable_array;//ʣ���ź���������
};

struct DSYSTEM_STATUS_INFO
{
	string start_time;//D5000���п�ʼʱ��
	string operation_time;//D5000��������ʱ��
	string status;//D5000����״̬
};

struct REALTIME_STATE_INFO
{
	string tableid;//��id
	string appname;//Ӧ����
	string tablename;//����
	string use_ratio;//ʹ����
	string record_num;//��¼��
	string record_sum;//��¼����
};
struct JOB_MGR
{
	string node_name;//�ڵ���
	string command;//����
	string run_time;//��ʼ����ʱ��
};
struct REALTIME_TABLE_ACCESS
{
	string app_id;//Ӧ�ú�
	string table_name;//����
	string access_num;//���ʴ���
};
struct REALTIME_DOWNLOAD_NUM
{
	string download_num;//��װ����
	string download_time;//��װʱ��
};

struct SERVICE_STATUS
{
	string name;//������
	string serv_host;//������
	string serv_port;//�����˿�
	string client_ip;//�ͻ���ip
	string client_port;//�ͻ��˶˿�
	string status;//״̬
};

struct TOP3_INFO
{
	string pid;
	string top_mem;
	string top_cpu;
	string command;
};


class SendInfo 
{
public:
	int m_port_main;
	string m_ip_main;
	int m_port_back;
	string m_ip_back;
	int alarm_port_main;
	string alarm_ip_main;
	int alarm_port_back;
	string alarm_ip_back;

public:
	string createXML(string nodeID, string time, map<string, string> map_item);

	int ifReSendXml(string xml);
	/*
	 * ͨ��tcp���ӷ���xml����
	 * port: ���ӵķ������˵Ķ˿ں�
	 * ip:   ���ӵķ������˵�ip��ַ
	 * */
	int sendXML(string xml);
	int sendBackXML(string xml);
	int ifReSendAlarmXml(string xml);
	int sendAlarmXML(string xml);
	int sendAlarmBackXML(string xml);

	/*
	 * ���������Ͷ�̬��item����
	 * nodeID:  �ڵ�š����̺Ż���������
	 * time:    ���ʱ��
	 * map_time: <itemid, value> ������������ݵļ�ֵ������
	 * port:    ���ӵķ������˶˿ں�
	 * ip:      ���ӵķ�������ip��ַ
	 */
	int sendInfo(string nodeID, string time, map<string, string>map_item);

	/*
	 * ���������ͼ���ʱ������
	 * nodeID:  �ڵ��
	 * time:    ���ʱ��
	 * port:    ���ӵķ������˶˿ں�
	 * ip:      ���ӵķ�������ip��ַ
	 */
	int sendTimeInfo(string nodeID, string time);

	/*
	 * ���ݴ���ķ�������̬��Ϣ����XML
	 * nodeID:    ������id
	 * name:      �������ڵ���
	 * memTotal:  �ڴ�������
	 * cpuNumber: cpu����
	 * diskCapacity: ����������
	 * system:    ����ϵͳ��Ϣ
	 * */
	string createServerXML(string nodeID, string name,string memTotal, string cpuNumber, string diskCapacity, string system,string ip,string mac,string mask_ip,string safekey_id);

	/*
	 * ���������ͷ�������̬��Ϣ
	 * nodeID:   �������ڵ��
	 * name:     ��������
	 * memTotal: �ڴ�������
	 * cpuNumber:cpu����
	 * diskCapacity: �ڴ�������
	 * system:   ϵͳ�汾��Ϣ
	 * port:     ���ӵķ������˶˿ں�
	 * ip:       ���ӵķ�������ip��ַ
	 */
	int sendServerInfo(string nodeID, string name, int memTotal, int cpuNumber, long diskCapacity, string system,string ip,string mac,string mask_ip,string safekey_id);

	/*
	 * �����������ļ�ϵͳ�ľ�̬��Ϣ
	 * nodeID:    �������ڵ��
	 * id:        �ļ�ϵͳ���,���id�м���;�ָʾ����id1;id2;id3
	 * name:      �ļ�ϵͳ���ƣ����name��;�ָ������idһһ��Ӧ
	 * content:   �ļ�ϵͳĿ¼��������ͬ��
	 * capyacity: �ļ�ϵͳ��������������ͬ��
	 * port:      ���ӵķ������˶˿ں�
	 * ip:        ���ӵķ�������ip��ַ
	 * */
	int sendDiskInfo(string nodeID, string id, string name, string content, string capacity);

	/*
	 * ��������������ľ�̬��Ϣ
	 * nodeID�� �ڵ���
	 * id:      �������,���id�м���;�ָʾ����id1;id2;id3
	 * name:    �����������name��;�ָ������idһһ��Ӧ
	 * ip:      ����Ip��������ͬ��
	 * mac:     ������MAC��ַ��������ͬ��
	 * port:    ���ӵķ������˶˿ں�
	 * server_ip:���ӵķ�������ip��ַ
	 * */
	int sendNetInfo(string nodeID, string id, string name ,string ip, string mac);

	/*
	 * ����������Ӧ��״̬��Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         Ӧ��״̬�ṹ����Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */
	int sendShowServiceInfo(string nodeID, string time, SHOWSERVEICE_INFO info);

	/*
	 * �������������ݿ�IO��Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         ���ݿ�IO��Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */
	int sendDBIoStatInfo(string nodeid,string time,DB_IO_STAT info);

	/*
	 * �������������ݿ��ڴ���Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         ���ݿ��ڴ���Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */
	int sendDBMemStatInfo(string nodeid,string time,DB_MEM_STAT info);

	/*
	 * ����������session��Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         session��Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */
	int sendDBSessionStatInfo(string nodeid,string time,DB_SESSION_STAT info);

	/*
	 * ���������ͳ�ʱSQL��Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         ��ʱSQL��Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */

	int sendDBSqlStat(string nodeID, string time, DB_SQL_STAT info);

	/*
	 * �������������ݿ�״̬��Ϣ
	 * nodeID��      �ڵ���
	 * time:         �ɼ�ʱ��
	 * info:         ���ݿ�״̬��Ϣ
	 * port:         ���ӵķ������˶˿ں�
	 * server_ip:    ���ӵķ�������ip��ַ
	 * */
	int sendDBStat(string nodeID, string time, DB_STAT info);
	
	int sendDBStaticStat(string nodeID, string time, DB_STATIC_STAT info);

	int sendDBTableSpaceStat(string nodeID, string time, DB_TABLESPACE_STAT info);

	int sendNetIcmpInfo(string time, NET_ICMP info);

	int sendProcessDynamicInfo(string nodeid,string time,PROCESS_DYNAMIC_INFO info);

	int sendServiceInfo(string nodeid,string time,SERVICE_INFO info);

	int sendMsgBufInfo(string nodeid,string time,MSGBUF_INFO info);

	int sendProxyInfo(string nodeid,string time,PROXY_INFO info);

	int sendCoreInfo(string nodeid,string time,CORE_INFO info);
	
	int sendNetStatInfo(string nodeid,string time,NET_STAT_INFO info);
	
	int sendHardAlarmInfo(string nodeid,string starttime, ALARM_INFO_HARD info);
	
	int sendDHardAlarmInfo(string nodeid,string itemid,string starttime,string endtime);
	
	int sendD5000AlarmInfo(string nodeid,string starttime, ALARM_INFO_D5000 info);
	
	//Ӧ��ȡ���澯
	int sendD5000DisAlarmInfo(string nodeid,DISALARM_INFO_D5000 info);
	
	int sendD5000DisAlarmInfo(string nodeid,string itemid,string starttime,string endtime,string flag);
	
	//��ȡ���澯��Ӳ��+ϵͳ
	int sendDAlarmInfo(string nodeid,string itemid,string starttime,string endtime,string data);
	
	//�¸澯��Ӳ��+ϵͳ
	int sendAlarmInfo(string nodeid,string starttime, ALARM_INFO info);
	
	int sendNoticeInfo(string nodeid,string starttime, NOTICE_INFO info);
	
	int sendDStartAlarmInfo(string nodeid,string itemid,string time);
	
	int sendScadaData(string nodeid,string time,SCADA_DATA_QUALITY info);
	
	int sendJumpInfo(string nodeid,string time,JUMP_INFO info);
	
	int sendDispatchLinkStateInfo(string nodeid,string time,DISPATCHCENTER_LINK_STATE info);
	
	int sendMSGChannelInfo(string nodeid,string time,MSG_CHANNEL_INFO info);
	
	int sendSysctlDataInfo(string nodeid,string time,SYSCTL_DATA_INFO info);
	
	int sendDsystemStatusInfo(string nodeid,string time,DSYSTEM_STATUS_INFO info);
	
	int sendRealtimeStateInfo(string nodeid,string time,REALTIME_STATE_INFO info);
	
	int sendJobMgrInfo(string nodeid,string time,JOB_MGR info);
	
	int sendRealtimeAccessNumInfo(string nodeid,string time,REALTIME_TABLE_ACCESS info);
	
	int sendRealtimeDownloadNumInfo(string nodeid,string time,REALTIME_DOWNLOAD_NUM info);
	
	int sendServiceStatusInfo(string nodeid,string time,SERVICE_STATUS info);
	
	int sendTopCpuInfo(string nodeid,string time,TOP3_INFO info);
	
	int sendTopMemInfo(string nodeid,string time,TOP3_INFO info);

	int sendAllInfo(string type,string nodeid,string time,vector<string> vec);
	
	vector<string> parseListData(string &str, string &delim);
};

#endif
