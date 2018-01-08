/*******************************************************************
ModuleName: priv_para
FileName: priv_para.h
Author:   liangyi
DESCRIPTION:
History:
Date       	Version		Activities
====================================================================
03/11/2003   1.0        created
********************************************************************/

#ifndef __PRIV_PARA_H__
#define __PRIV_PARA_H__

#include <vector>
using namespace std;

class CPrivParaManage
{
public:
    CPrivParaManage(){}
    virtual ~CPrivParaManage(){}
    
public:
    static CPrivParaManage *CreateObject(char * para_file_name=NULL);   //�ú���������������жϷ������ݿ⻹�Ǳ����ļ���
    static void RemoveObject(CPrivParaManage *ptr);                //�ͷ�����ռ�Ŀռ�
public:
    enum { PARA_KEY_LEN = 64, PARA_VAL_LEN = 1024 };
    
    typedef struct tag_PARA_KEY_VALUE
    {
        char para_key[PARA_KEY_LEN];
        char para_val[PARA_VAL_LEN];
    } PARA_KEY_VALUE;
    
    typedef vector<PARA_KEY_VALUE> VECT_KEY_VALUE;
public:
    virtual int  SetKey( char *section, char *key, char *para_value ){return -1;}  //���ùؼ�ֵ
    virtual int  SetKey( char *section, char *key, int   para_value ){return -1;}
    virtual int  SetKey( char *section, char *key, double para_value ){return -1;}
    
    virtual int  GetKey( char *section, char *key, char  *para_value, int bufsize ) = 0; //��ȡ�ؼ�ֵ
    virtual int	 GetKey( char *section, char *key, int	 &para_value ) = 0;	             //���ı�����ֵ
    virtual int	 GetKey( char *section, char *key, double &para_value ) = 0;
    
    virtual int  DelKey( char *section, char *key ){return -1;}          //ɾ���ؼ�ֵ
    
    virtual int  GetKeyNum( char *section, int &key_num ){return -1;}	  //��ȡ�����ļ��еķֽڸ����ͷֽ�������¼����
    virtual int  SetKeys( char *section, PARA_KEY_VALUE *keys, int key_set_num ){return -1;}	 //����һ���ֽ������йؼ�ֵ
    virtual int  GetKeys( char *section, PARA_KEY_VALUE *keys, int key_buf_num ){return -1;}	 //��ȡһ���ֽ������йؼ�ֵ
    
    virtual int  SetKeys( char *section, VECT_KEY_VALUE& keys ){return -1;}	 //����һ���ֽ������йؼ�ֵ
    virtual int  GetKeys( char *section, VECT_KEY_VALUE& keys ) = 0;	 //��ȡһ���ֽ������йؼ�ֵ
    virtual int  GetKeys( char *section, char *match_word,  VECT_KEY_VALUE& keys ) = 0;	 //��ȡһ���ֽ��°���match_word�����в���ֵ
};

#endif
