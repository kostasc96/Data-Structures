#ifndef __bucketl__
#define __bucketl__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "cdr.h"
#define bucketsize 10


using namespace std;

struct node2
{
    cdr* c;
};

struct bucket2
{
    node2 content[bucketsize];
    bucket2* next;
    int numofcalls;
    bucket2();
    void print();
	void find(char[],char[],char[],char[]);
	void find(char[],char[]);
	void find();
};

class ListBuckets2
{
private:
    bucket2* head;
    bucket2* tail;
    bucket2* prevtail;
    int size_of_list;
public:
    ListBuckets2();
    ~ListBuckets2();
    void insert_cdr(cdr* );
    int get_size_of_list();
    void print();
    cdr* return_last();
    int delete_cdr(char []);
    bucket2* get_head();
    void find(char[],char[],char[],char[]);
    void find(char[],char[]);
    void find();
    char** indist(char[],int*);
	void indist2(char** ,char[],int ,int );
	void topdest();
};

struct node
{
    char number[15];
    ListBuckets2* ptr;
};

struct bucket
{
    node content[bucketsize];
    bucket* next;
    int numofcdr;
    bucket();
    void print();
    int find_num(cdr* ,int );
    int delete_cdr(char []);
};

class ListBuckets
{
private:
    bucket* head;
    bucket* tail;
    bucket* prevtail;
    int option;
    int size_of_list;
public:
    ListBuckets(int opt);
    ~ListBuckets();
    //void insert_cdr(char []);
    void insert_cdr(cdr* );
    void insert_cdr2(cdr* );
    int find_num(cdr* );
    int get_size_of_list();
    void delete_cdr(char [],char num[]);
    void print();
    node return_last();
	void find(char[],char[],char[],char[],char[]);
	void find(char[],char[],char[]);
	void find(char[]);
	char** indist(char[],int*);
	void indist2(char** ,char[],int ,int );
	void topdest(char[]);
};

#endif

