#ifndef __hash__
#define __hash__

#include "cdr.h"
#include "bucketlist.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int hash(char *str);

class hashtable
{
	private:
		ListBuckets** hash_table;
		int size_hashtable;
		int sizebucket;
		int option;
	public:
        hashtable(int s,int s1,int opt);
        ~hashtable();
        void insertcdr(cdr* a);
        void delete_cdr(char[],char[]);
        void print();
		void find(char[],char[],char[],char[],char[]);
		void find(char[],char[],char[]);
		void find(char[]);
		char** indist(char[],int* );
		void indist2(char** ,int );
		void topdest(char[]);
};



#endif
