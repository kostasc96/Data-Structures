#include <iostream>
#include <cstring>
#include <cstdlib>
#include "hashtable.h"
#include "structure.h"

using namespace std;


structure::structure(int sizeh1,int sizeh2,int sizebucket):size_h1(sizeh1),size_h2(sizeh1),size_bucket(sizebucket),hashtable1(sizeh1,sizebucket,1),hashtable2(sizeh2,sizebucket,0)
{
		
}

void structure::insertcdr(char a[11],char b[15],char c[15],char d[9],char e[6],int f,char g,char h,int i)
{
	cdr* k = new cdr(a,b,c,d,e,f,g,h,i);
	hashtable1.insertcdr(k);
	hashtable2.insertcdr(k);
}

void structure::delete_cdr(char caller[15],char id[11])
{
	hashtable1.delete_cdr(caller,id);
}

void structure::print1()
{
	hashtable1.print();
}

void structure::print2()
{
	hashtable2.print();
}

void structure::find(char a[15],char b[6],char c[9],char d[6],char e[9])
{
	hashtable1.find(a,b,c,d,e);
}

void structure::find(char a[15],char b[6],char c[6])
{
	hashtable1.find(a,b,c);
}

void structure::find(char a[15])
{
	hashtable1.find(a);
}

void structure::lookup(char a[15],char b[6],char c[9],char d[6],char e[9])
{
	hashtable2.find(a,b,c,d,e);
}

void structure::lookup(char a[15],char b[6],char c[6])
{
	hashtable2.find(a,b,c);
}

void structure::lookup(char a[15])
{
	hashtable2.find(a);
}

void structure::indist(char a[15],char b[15])
{
	char** ret1;
	char** ret2;
	char** ret3;
	char** ret4;
	char** final1;
	final1 = (char**)malloc(sizeof(char*));
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;
	int size4 = 0;
	int size_f1 = 0;
	int size_f2 = 0;
	ret1 = hashtable1.indist(a,&size1);
	ret2 = hashtable2.indist(a,&size2);
	ret3 = hashtable1.indist(b,&size3);
	ret4 = hashtable2.indist(b,&size4);
	if(((ret1 == NULL)||(ret2==NULL))&&((ret3 == NULL)||(ret4 == NULL)))
	{
		return;
	}
	int i,j,k;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size3;j++)
		{
			final1 = (char**)realloc(final1,(size_f1+1)*sizeof(char*));
			if((!strcmp(ret1[i],ret3[j]))&&(strcmp(ret1[i],b))&&(strcmp(ret1[i],a)))
			{
				final1[size_f1] = strdup(ret3[j]);
				size_f1++;
			}
		}
		for(k=0;k<size4;k++)
		{
			final1 = (char**)realloc(final1,(size_f1+1)*sizeof(char*));
			if((!strcmp(ret1[i],ret4[k]))&&(strcmp(ret1[i],b))&&(strcmp(ret1[i],a)))
			{
				final1[size_f1] = strdup(ret4[k]);
				size_f1++;
			}
		}
	}
	
	for(i=0;i<size2;i++)
	{
		for(j=0;j<size3;j++)
		{
			final1 = (char**)realloc(final1,(size_f1+1)*sizeof(char*));
			if((!strcmp(ret2[i],ret3[j]))&&(!strcmp(ret2[i],b)))
			{
				final1[size_f1] = strdup(ret3[j]);
				size_f1++;
			}
		}
		for(k=0;k<size4;k++)
		{
			final1 = (char**)realloc(final1,(size_f1+1)*sizeof(char*));
			if((!strcmp(ret2[i],ret4[k]))&&(!strcmp(ret2[i],b)))
			{
				final1[size_f1] = strdup(ret4[k]);
				size_f1++;
			}
		}
	}
	
	hashtable1.indist2(final1,size_f1);
	hashtable2.indist2(final1,size_f1);
	
	for(i=0;i<size1;i++)
	{
			free(ret1[i]);
	}
	free(ret1);
	
	for(i=0;i<size2;i++)
	{
			free(ret2[i]);
	}
	free(ret2);
	
	for(i=0;i<size3;i++)
	{
			free(ret3[i]);
	}
	free(ret3);
	
	for(i=0;i<size4;i++)
	{
			free(ret4[i]);
	}
	free(ret4);
	
	for(i=0;i<size_f1;i++)
	{
			free(final1[i]);		
	}
	free(final1);
}



void structure::topdest(char a[15])
{
	hashtable1.topdest(a);
}