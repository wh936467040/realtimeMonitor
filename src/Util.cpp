#include "iostream"
using namespace std;
string getHomePath()
{
	char path[128] = "";
	sprintf(path, "%s", getenv("HOME"));
	string result=string(path);
	return result;
}

string getD5000HomePath()
{
	char path[128] = "";
	sprintf(path, "%s", getenv("D5000_HOME"));
	string result=string(path);
	return result;
}  

string itos(int i)
{
	char tmp[16]="";
	sprintf(tmp,"%d",i);
	return string(tmp);
}

string ftos(float f)
{
	char tmp[128]="";
	sprintf(tmp,"%f",f);
	return string(tmp);
}

string f2tos(float f)
{
	char tmp[128]="";
	sprintf(tmp,"%.2f",f);
	return tmp;
}


string getSysTime()
{
	char str[64] = "";
	struct tm *ctm;     //æ­¤ç??.???ime.hä¸|-
	time_t ts;
	int year,mon,day,hour,min,sec;
	ts = time(NULL);
	ctm = localtime(&ts);
	year = ctm->tm_year+1900;
	//  cout<<year<<endl;
	mon = ctm->tm_mon+1;
	day = ctm->tm_mday;
	hour = ctm->tm_hour;
	min = ctm->tm_min;
	sec = ctm->tm_sec;
	//  cout<<year<<" "<<mon<<" "<<day<<" "<<hour<<" "<<min<<" "<<sec<<endl;
	sprintf(str,"%04d-%02d-%02d %02d:%02d:%02d",year,mon,day,hour,min,sec);
	string time = str;
	//cout << "time :" << time.c_str() << endl;
	return time;
}
