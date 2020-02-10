#include <cstdlib>
#include <fstream>
#include <sstream>
#include <math.h>
#include "hashtable.h"
#include "cdr.h"
#include "bucketlist.h"
#include "structure.h"

using namespace std;

int sizeh = 5;


int main(int argc, char *argv[])
{
   char Operations[50];
   int j;
   char array1[4][9];
   char array2[4][9];
   int buckets;
   int sizeh1;
   int sizeh2;
   char buffer[1024];
   char line[1024];
   for(j=0; j<argc; j++)
   {
		char* a=argv[j];
			if(!strcmp(a,"-o"))
        	{
            		strcpy(Operations,argv[j+1]);
        	}
        	if(!strcmp(a,"-h1"))
        	{
            		sizeh1 = atoi(argv[j+1]);
        	}
			if(!strcmp(a,"-h2"))
        	{
            		sizeh2 = atoi(argv[j+1]);
        	}
        	if(!strcmp(a,"-s"))
        	{
            		buckets = atoi(argv[j+1]);
        	}
   }
   structure s(sizeh1,sizeh2,buckets);
   std::ifstream ifs;
   ifs.open(Operations);
   while(ifs.getline (buffer,1024))
   {
	stringstream iss;
	iss << buffer;
        iss.getline(buffer,1024, ' ');
		if(!strcmp(buffer,"insert"))
		{
			iss.getline(buffer, 1024, ';');
			char id[11];
			strcpy(id,buffer);
			iss.getline(buffer, 1024, ';');
			char originator[15];
			strcpy(originator,buffer);
			iss.getline(buffer, 1024, ';');
			char destination[15];
			strcpy(destination,buffer);
			iss.getline(buffer, 1024, ';');
			char date[9];
			strcpy(date,buffer);
			iss.getline(buffer, 1024, ';');
			char time[6];
			strcpy(time,buffer);
			iss.getline(buffer, 1024, ';');
			int duration = atoi(buffer);
			iss.getline(buffer, 1024, ';');
			char type;
			type = buffer[0];
			iss.getline(buffer, 1024, ';');
			char tarrif;
			tarrif = buffer[0];
			iss.getline(buffer, 1024, ' ');
			int fault_condition = atoi(buffer);
			cout<<endl;
			cout<<"insert "<<id<<endl;
			s.insertcdr(id,originator,destination,date,time,duration,type,tarrif,fault_condition);
		}
		if(!strcmp(buffer,"print"))
		{
			iss.getline(buffer, 1024, ' ');
			if(!strcmp(buffer,"hashtable1"))
			{
				cout<<endl;
				cout<<"print Hashtable1"<<endl;
				s.print1();
			}
			if(!strcmp(buffer,"hashtable2"))
			{
				cout<<endl;
				cout<<"print Hashtable2"<<endl;
				s.print2();
			}
		}
		if(!strcmp(buffer,"find"))
		{
			iss.getline(buffer, 1024, ' ');
			char originator1[15];
			int counter = 0;
			strcpy(originator1,buffer);
			while(iss.getline(buffer, 1024, ' '))
			{
				strcpy(array1[counter],buffer);
				counter++;
			}
			if(counter == 0)
			{
				cout<<endl;
				cout<<"find"<<" "<<originator1<<endl;
				s.find(originator1);
			}
			if(counter == 2)
			{
				cout<<endl;
				cout<<"find"<<" "<<originator1<<" "<<array1[0]<<" "<<array1[1]<<endl;
				s.find(originator1,array1[0],array1[1]);
			}
			if(counter == 4)
			{
				cout<<endl;
				cout<<"find"<<" "<<originator1<<" "<<array1[0]<<" "<<array1[1]<<" "<<array1[2]<<" "<<array1[3]<<endl;
				s.find(originator1,array1[0],array1[1],array1[2],array1[3]);
			}
		}
		if(!strcmp(buffer,"lookup"))
		{
			iss.getline(buffer, 1024, ' ');
			char originator2[15];
			int counter2 = 0;
			strcpy(originator2,buffer);
			while(iss.getline(buffer, 1024, ' '))
			{
				strcpy(array2[counter2],buffer);
				counter2++;
			}
			if(counter2 == 0)
			{
				cout<<endl;
				cout<<"lookup"<<" "<<originator2<<endl;
				s.lookup(originator2);
			}
			if(counter2 == 2)
			{
				cout<<endl;
				cout<<"lookup"<<" "<<originator2<<" "<<array2[0]<<" "<<array2[1]<<endl;
				s.lookup(originator2,array2[0],array2[1]);
			}
			if(counter2 == 4)
			{
				cout<<endl;
				cout<<"lookup"<<" "<<originator2<<" "<<array2[0]<<" "<<array2[1]<<" "<<array2[2]<<" "<<array2[3]<<endl;
				s.lookup(originator2,array2[0],array2[1],array2[2],array2[3]);
			}
		}  
		if(!strcmp(buffer,"indist"))
		{
			iss.getline(buffer, 1024, ' ');
			char caller1[15];
			strcpy(caller1,buffer);
			iss.getline(buffer, 1024, ' ');
			char caller2[15];
			strcpy(caller2,buffer);
			cout<<endl;
			cout<<"indist"<<caller1<<" "<<caller2<<endl;
			s.indist(caller1,caller2);
		}
		if(!strcmp(buffer,"topdest"))
		{
			iss.getline(buffer, 1024, ' ');
			char caller[15];
			strcpy(caller,buffer);
			cout<<endl;
			cout<<"topdest"<<" "<<caller<<endl;
			s.topdest(caller);
		}     
		if(!strcmp(buffer,"delete"))
		{
			char id[11];
			char caller[15];
			iss.getline(buffer, 1024,' ');
			strcpy(caller,buffer);
			iss.getline(buffer, 1024);
			strcpy(id,buffer);
			cout<<endl;
			cout<<"delete"<<" "<<id<<" "<<caller<<endl;
			s.delete_cdr(caller,id);
		}
		if(!strcmp(buffer,"bye"))
		{
			cout<<"bye"<<endl;
			break;
		}  
   }



    return 0;
}
