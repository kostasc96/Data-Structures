#include "cdr.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


cdr::cdr(char a[11],char b[15],char c[15],char d[9],char e[6],int f,char g,char h,int i):duration(f),type(g),tarrif(h),fault_condition(i)
{
    strcpy(date,d);
    strcpy(init_time,e);
    strcpy(cdr_uniq_id,a);
    strcpy(originator_number,b);
    strcpy(destination_number,c);
}


char* cdr::get_originator()
{
    return originator_number;
}


char* cdr::get_cdr_uniq_id()
{
    return cdr_uniq_id;
}

char* cdr::get_destination_number()
{
    return destination_number;
}

char* cdr::get_date()
{
    return date;
}

char* cdr::get_init_time()
{
    return init_time;
}

int cdr::get_duration()
{
    return duration;
}

char cdr::get_type()
{
    return type;
}

char cdr::get_tarrif()
{
    return tarrif;
}

int cdr::get_fault_condition()
{
    return fault_condition;
}
