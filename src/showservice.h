#ifndef __SHOWSERVICE_H__
#define __SHOWSERVICE_H__
#include <iostream>
#include "sstream"
#include <pthread.h>
#include "sstream"
#include "priv_para.h"
#include "sam_define.h"
#include "sam_services_define.h"
#include "sam_service.h"
#include "time.h"
#define ITEM_ID_UNCONNECT "00020001"
#define ITEM_ID_ERROR "00020002"
#define ITEM_ID_EXIT "00020003"
#define ITEM_ID_DOUBLE "00020004"
#define ITEM_ID_OVERDATE "00020005"
using namespace std;
const int SLEEP_TIME = 10;
const int SIZE = 64;
const string ITEMID = "100010005";
const string level = "4";
extern string NODEID;

typedef struct TIME {
	char cur_time[32];
};

#endif
