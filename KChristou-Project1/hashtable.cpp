#include "hashtable.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int hash(char str[15], int table_size)
{
    unsigned long h = 5381;
    int c;

    while (c = *str++)
        h = ((h << 5) + h) + c;

    return h % table_size;
}


hashtable::hashtable(int s,int s1,int opt):size_hashtable(s),sizebucket(s1),option(opt)
{
    hash_table = new ListBuckets*[s];
    for(int i=0;i<s;i++)
    {
        hash_table[i]=new ListBuckets(opt);
    }
	cout<<"Hashtable created"<<endl;
}

hashtable::~hashtable()
{
    for(int i=0;i<size_hashtable;i++)
    {
       delete hash_table[i];
    }
	delete [] hash_table;
	cout<<"Hashtable Deleted"<<endl;
}


void hashtable::insertcdr(cdr* a)
{
	//int key=hash(a->get_originator(),size_hashtable);  /*se poia thesh tou pinaka tha bei*/
	if(option == 1)
    {
		int key=hash(a->get_originator(),size_hashtable);  /*se poia thesh tou pinaka tha bei*/
        hash_table[key]->insert_cdr(a);
    }
    if(option == 0)
    {
		int key=hash(a->get_destination_number(),size_hashtable);  /*se poia thesh tou pinaka tha bei*/
        hash_table[key]->insert_cdr2(a);
    }
}


void hashtable::print()
{
    int i;
    for(i=0;i<size_hashtable;i++)
    {
        cout<<endl;
        cout<<i<<" position of hashtable"<<endl;
        hash_table[i]->print();
        cout<<"Size of list "<<i<<" is "<<hash_table[i]->get_size_of_list()<<endl;
    }
}

void hashtable::delete_cdr(char caller[15],char id[11])
{
    int key=hash(caller,size_hashtable);
    hash_table[key]->delete_cdr(id,caller);
}


void hashtable::find(char a[15],char b[6],char c[9],char d[6],char e[9])
{
	int i;
	int key=hash(a,size_hashtable);	
	hash_table[key]->find(a,b,c,d,e);
}

void hashtable::find(char a[15],char b[6],char c[6])
{
	int i;
	int key=hash(a,size_hashtable);	
	hash_table[key]->find(a,b,c);
}

void hashtable::find(char a[15])
{
	int i;
	int key=hash(a,size_hashtable);
	hash_table[key]->find(a);	
}


char** hashtable::indist(char a[15],int* c)
{
	char** ret1;
	int key1=hash(a,size_hashtable);
	ret1 = hash_table[key1]->indist(a,c);
	return ret1;
}


void hashtable::indist2(char** a,int b)
{
	int i;
	for(i=0;i<b;i++)
	{
		int key=hash(a[i],size_hashtable);
		hash_table[key]->indist2(a,a[i],b,i);
	}
}

void hashtable::topdest(char a[15])
{
	int key=hash(a,size_hashtable);
	hash_table[key]->topdest(a);
}