#ifndef __cdr__
#define __cdr__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


struct Date
{
    int day;
    int month;
    int year;
};

struct time
{
    int hour;
    int minutes;
};

class cdr
{
private:
    char cdr_uniq_id[11];
    char originator_number[15];
    char destination_number[15];
    char date[9];
    char init_time[6];
    int duration;
    char type;
    char tarrif;
    int fault_condition;
public:
    cdr(char [],char [],char [],char [] ,char [],int ,char ,char ,int );
   // void set_time(int ,int );
   // void set_date(int ,int ,int );
    char* get_originator();
    char* get_cdr_uniq_id();
    char* get_destination_number();
    char* get_date();
    char* get_init_time();
    int get_duration();
    char get_type();
    char get_tarrif();
    int get_fault_condition();
};




#endif
