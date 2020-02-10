#ifndef __struct__
#define __struct__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "cdr.h"
#include "bucketlist.h"
#include "hashtable.h"

using namespace std;


class structure
{
	private:
		hashtable hashtable1;
		hashtable hashtable2;
		int size_h1;
		int size_h2;
		int size_bucket;
	public:
		structure(int sizeh1,int sizeh2,int sizebucket);
		void insertcdr(char [],char [],char [],char [] ,char [],int ,char ,char ,int );
		void delete_cdr(char[],char[]);
		void print1();
		void print2();
		void find(char[],char[],char[],char[],char[]);
		void find(char[],char[],char[]);
		void find(char[]);
		void lookup(char[],char[],char[],char[],char[]);
		void lookup(char[],char[],char[]);
		void lookup(char[]);
		void indist(char[],char[]);
		void topdest(char[]);
};


#endif


