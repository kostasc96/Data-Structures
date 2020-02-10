#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include "bucketlist.h"


using namespace std;


bucket2::bucket2()
{
    numofcalls = 0;
}

void bucket2::print()
{
    int i;
    for(i=0;i<numofcalls;i++)
    {
        cout<<"cdr id: "<<content[i].c->get_cdr_uniq_id()<<endl;
        cout<<"originator number: "<<content[i].c->get_originator()<<endl;
        cout<<"destination number: "<<content[i].c->get_destination_number()<<endl;
        cout<<"date: "<<content[i].c->get_date()<<endl;
        cout<<"init time: "<<content[i].c->get_init_time()<<endl;
        cout<<"duration: "<<content[i].c->get_duration()<<endl;
        cout<<"type: "<<content[i].c->get_type()<<endl;
        cout<<"tarrif: "<<content[i].c->get_tarrif()<<endl;
        cout<<"fault condition: "<<content[i].c->get_fault_condition()<<endl;
	cout<<endl;
    }
}

void bucket2::find(char a[6],char b[9],char c[6],char d[9])
{
	char hour_cdr[3];
	char min_cdr[3];
	char year_cdr[5];
	char time_cdr[6];
	char date_cdr[9];
	int minutes_cdr,h_cdr,y_cdr,t_cdr;
	int i,h1,h2,min1,min2,y1,y2;
	char hour1[3];
	char hour2[3];
	char minutes1[3];
	char minutes2[3];
	char year1[5];
	char year2[5];
	hour1[0] = a[0];
	hour1[1] = a[1];
	hour1[3] = '\0';
	hour2[0] = c[0];
	hour2[1] = c[1];
	hour2[3] = '\0';
	minutes1[0] = a[3];
	minutes1[1] = a[4];
	minutes1[2] = '\0';
	minutes2[0] = c[3];
	minutes2[1] = c[4];
	minutes2[2] = '\0';
	year1[0] = b[4];
	year1[1] = b[5];
	year1[2] = b[6];
	year1[3] = b[7];
	year1[4] = '\0';
	year2[0] = d[4];
	year2[1] = d[5];
	year2[2] = d[6];
	year2[3] = d[7];
	year2[4] = '\0';
	h1 = atoi(hour1);
	h2 = atoi(hour2);
	min1 = atoi(minutes1);
	min2 = atoi(minutes2);
	y1 = atoi(year1);
	y2 = atoi(year2);
	int time1 = h1*100 + min1;
	int time2 = h2*100 + min2;
	
	for(i=0;i<numofcalls;i++)
	{
		strcpy(time_cdr,content[i].c->get_init_time());
		strcpy(date_cdr,content[i].c->get_date());
		hour_cdr[0] = time_cdr[0];
		hour_cdr[1] = time_cdr[1];
		hour_cdr[3] = '\0';
		min_cdr[0] = time_cdr[3];
		min_cdr[1] = time_cdr[4];
		min_cdr[2] = '\0';
		year_cdr[0] = date_cdr[4];
		year_cdr[1] = date_cdr[5];
		year_cdr[2] = date_cdr[6];
		year_cdr[3] = date_cdr[7];
		year_cdr[4] = '\0';
		minutes_cdr = atoi(min_cdr);
		h_cdr = atoi(hour_cdr);
		y_cdr = atoi(year_cdr);
		t_cdr = h_cdr*100 + minutes_cdr;
		if((time1<=t_cdr)&&(t_cdr<=time2)&&(y1<=y_cdr)&&(y_cdr<=y2))
		{
			cout<<"cdr id: "<<content[i].c->get_cdr_uniq_id()<<endl;
			cout<<"originator number: "<<content[i].c->get_originator()<<endl;
			cout<<"destination number: "<<content[i].c->get_destination_number()<<endl;
			cout<<"date: "<<content[i].c->get_date()<<endl;
			cout<<"init time: "<<content[i].c->get_init_time()<<endl;
			cout<<"duration: "<<content[i].c->get_duration()<<endl;
			cout<<"type: "<<content[i].c->get_type()<<endl;
			cout<<"tarrif: "<<content[i].c->get_tarrif()<<endl;
			cout<<"fault condition: "<<content[i].c->get_fault_condition()<<endl;
			cout<<endl;
		}
	}
}

void bucket2::find(char a[6],char b[6])
{
	char hour_cdr[3];
	char min_cdr[3];
	char time_cdr[6];
	int minutes_cdr,h_cdr,t_cdr;
	int i,h1,h2,min1,min2;
	char hour1[3];
	char hour2[3];
	char minutes1[3];
	char minutes2[3];
	hour1[0] = a[0];
	hour1[1] = a[1];
	hour1[3] = '\0';
	hour2[0] = b[0];
	hour2[1] = b[1];
	hour2[3] = '\0';
	minutes1[0] = a[3];
	minutes1[1] = a[4];
	minutes1[2] = '\0';
	minutes2[0] = b[3];
	minutes2[1] = b[4];
	minutes2[2] = '\0';
	h1 = atoi(hour1);
	h2 = atoi(hour2);
	min1 = atoi(minutes1);
	min2 = atoi(minutes2);
	int time1 = h1*100 + min1;
	int time2 = h2*100 + min2;
	for(i=0;i<numofcalls;i++)
	{
		strcpy(time_cdr,content[i].c->get_init_time());
		hour_cdr[0] = time_cdr[0];
		hour_cdr[1] = time_cdr[1];
		hour_cdr[3] = '\0';
		min_cdr[0] = time_cdr[3];
		min_cdr[1] = time_cdr[4];
		min_cdr[2] = '\0';
		minutes_cdr = atoi(min_cdr);
		h_cdr = atoi(hour_cdr);
		t_cdr = h_cdr*100 + minutes_cdr;
		if((time1<=t_cdr)&&(t_cdr<=time2))
		{
			cout<<"cdr id: "<<content[i].c->get_cdr_uniq_id()<<endl;
			cout<<"originator number: "<<content[i].c->get_originator()<<endl;
			cout<<"destination number: "<<content[i].c->get_destination_number()<<endl;
			cout<<"date: "<<content[i].c->get_date()<<endl;
			cout<<"init time: "<<content[i].c->get_init_time()<<endl;
			cout<<"duration: "<<content[i].c->get_duration()<<endl;
			cout<<"type: "<<content[i].c->get_type()<<endl;
			cout<<"tarrif: "<<content[i].c->get_tarrif()<<endl;
			cout<<"fault condition: "<<content[i].c->get_fault_condition()<<endl;
			cout<<endl;
		}
	}
}

void bucket2::find()
{
	int i;
    for(i=0;i<numofcalls;i++)
    {
        cout<<"cdr id: "<<content[i].c->get_cdr_uniq_id()<<endl;
        cout<<"originator number: "<<content[i].c->get_originator()<<endl;
        cout<<"destination number: "<<content[i].c->get_destination_number()<<endl;
        cout<<"date: "<<content[i].c->get_date()<<endl;
        cout<<"init time: "<<content[i].c->get_init_time()<<endl;
        cout<<"duration: "<<content[i].c->get_duration()<<endl;
        cout<<"type: "<<content[i].c->get_type()<<endl;
        cout<<"tarrif: "<<content[i].c->get_tarrif()<<endl;
        cout<<"fault condition: "<<content[i].c->get_fault_condition()<<endl;
		cout<<endl;
    }
}

ListBuckets2::ListBuckets2()
{
    head = NULL;
    tail = NULL;
    prevtail = NULL;
    size_of_list = 0;
}

ListBuckets2::~ListBuckets2()
{
   bucket2* temp = head;
    bucket2* temp1;
    while(temp!=NULL)
    {
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    delete temp;
}

int ListBuckets2::get_size_of_list()
{
    return size_of_list;
}

void ListBuckets2::print()
{
    bucket2* temp = head;
    while(temp!=NULL)
    {
        temp->print();
        temp = temp->next;
    }
}

void ListBuckets2::insert_cdr(cdr* a)
{

    if(head == NULL)
    {
        head = new bucket2();
        head->next = NULL;
        head->content[head->numofcalls].c = a;
        tail = head;
        head->numofcalls++;
        size_of_list++;
    }
    else
    {
        if((tail->numofcalls) < bucketsize)
        {
            tail->content[tail->numofcalls].c = a;
            tail->numofcalls++;
        }
        else
        {
            prevtail = tail;
            bucket2* temp = new bucket2();
            temp->content[temp->numofcalls].c = a;
            temp->numofcalls++;
            tail->next = temp;
            tail = temp;
            size_of_list++;
        }
    }
}

cdr* ListBuckets2::return_last()
{
    return tail->content[tail->numofcalls-1].c;
}

bucket2* ListBuckets2::get_head()
{
    return head;
}

int ListBuckets2::delete_cdr(char id[11])
{

    if((size_of_list == 1)&&(head->numofcalls == 1)&&(!strcmp(head->content[head->numofcalls-1].c->get_cdr_uniq_id(),id)))
    {
        return 0;
    }


    cdr* last = return_last();
    int i;
    bucket2* temp = head;
    bucket2* temp2 = head;
    while(temp!=NULL)
    {
        if(temp->numofcalls > 1)
        {
            for(i=0;i<temp->numofcalls;i++)
            {
                if(!strcmp(temp->content[i].c->get_cdr_uniq_id(),id))
                {
                    temp->content[i].c = NULL;
                    temp->content[i].c = last;
                    tail->content[tail->numofcalls-1].c = NULL;
                    tail->numofcalls--;
                    if(tail->numofcalls == 0)
                    {
                        prevtail->next = NULL;
                        tail = prevtail;
                    }
                }
            }
        }


        if(temp->numofcalls == 1)
        {
            if(!strcmp(temp->content[temp->numofcalls-1].c->get_cdr_uniq_id(),id))
            {
				temp2->next = temp->next;
				delete temp;
				size_of_list--;
            }
        }
		temp2 = temp;
        temp = temp->next;
    }
    return 1;
}

void ListBuckets2::find(char a[6],char b[9],char c[6],char d[9])
{
	bucket2* temp = head;
    while(temp!=NULL)
    {
        temp->find(a,b,c,d);
        temp = temp->next;
    }
}

void ListBuckets2::find(char a[6],char b[6])
{
	bucket2* temp = head;
    while(temp!=NULL)
    {
        temp->find(a,b);
        temp = temp->next;
    }
}


void ListBuckets2::find()
{
	bucket2* temp = head;
    while(temp!=NULL)
    {
        temp->find();
        temp = temp->next;
    }
}


char** ListBuckets2::indist(char a[15],int* b)
{
	//(*b) = 0;
	bucket2* temp = head;
	int i;
	char** return_array;
	return_array = (char**)malloc(sizeof(char*));
    while(temp!=NULL)
    {
        for(i=0;i<temp->numofcalls;i++)
		{
			return_array = (char**)realloc(return_array,((*b)+1)*sizeof(char*));
			if(!strcmp(temp->content[i].c->get_originator(),a))
			{
				return_array[*b] = strdup(temp->content[i].c->get_destination_number());
				(*b)++;
			}
			else
			{
				return_array[*b] = strdup(temp->content[i].c->get_originator());
				(*b)++;
			}
		}
        temp = temp->next;
    }
	return return_array;
}


void ListBuckets2::indist2(char** a,char b[15],int c,int d)
{
	bucket2* temp = head;
	int i,j;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcalls;i++)
		{
			for(j=0;i<c;j++)
			{
				if((d!=j)&&(!strcmp(a[j],temp->content[i].c->get_destination_number())||(!strcmp(a[j],temp->content[i].c->get_originator()))))
				{
					return;
				}
			}
		}
		temp = temp->next;
	}
	cout<<a[d]<<endl;
}


void ListBuckets2::topdest()
{
	bucket2* temp = head;
	int i,j;
	int flag=0;
	char** array_c = NULL;
	//array_c = (char**)malloc(sizeof(char*));
	int* counter_p = NULL;
	//counter_p = (int*)malloc(sizeof(int));
	int counter = 0;
	char buffer[4];
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcalls;i++)
		{
			strncpy(buffer,temp->content[i].c->get_destination_number(),3);
			buffer[3] = '\0';
			for(j=0;j<counter;j++)
			{
				if(!strcmp(array_c[j],buffer))
				{
					counter_p[j]++;
					flag = 1;
				}
			}
			if(flag == 0)
			{
				array_c = (char**)realloc(array_c,(counter+1)*sizeof(char*));
				counter_p = (int*)realloc(counter_p,(counter+1)*sizeof(int));
				array_c[counter] = strdup(buffer);
				counter_p[counter] = 1;
				counter++;
			}
			flag = 0;  
		}
		temp = temp->next;
	}
	
	int temp_max = 0;
	int max_pos = 0;
	for(i=0;i<counter;i++)
	{
		if(counter_p[i]>temp_max)
		{
			temp_max = counter_p[i];
			max_pos = i;
		}
	}
	
	
	cout<<array_c[max_pos]<<" "<<counter_p[max_pos]<<endl;
	
	for(i=0;i<counter;i++)
	{
			free(array_c[i]);
	}
	free(array_c);
	
	free(counter_p);
}

bucket::bucket()
{
    numofcdr = 0;
}

void bucket::print()
{
    int i;
    for(i=0;i<numofcdr;i++)
    {
     cout<<"-----------------------------"<<endl;
     cout<<"Caller or Callee number: "<<content[i].number<<endl;
     cout<<"-----------------------------"<<endl;
     content[i].ptr->print();
    }
}

int bucket::find_num(cdr* a,int b)
{
    int i;
    for(i=0;i<numofcdr;i++)
    {
        if(b == 1)
        {
            if(!strcmp(content[i].number,a->get_originator()))
            {
                content[i].ptr->insert_cdr(a);
                return 1;
            }
        }
        if(b == 0)
        {
            if(!strcmp(content[i].number,a->get_destination_number()))
            {
                content[i].ptr->insert_cdr(a);
                return 1;
            }
        }
    }
    return 0;
}

int bucket::delete_cdr(char id[11])
{
    int i;
    int flag;
    for(i=0;i<numofcdr;i++)
    {
        if(content[i].ptr != NULL)
        {
            flag = content[i].ptr->delete_cdr(id);
            if(flag == 0)
            {
                ListBuckets2* temp1 = content[i].ptr;
                delete temp1;
				temp1 = NULL;
                return 0;
            }
        }
    }
    return 1;
}

int ListBuckets::get_size_of_list()
{
    return size_of_list;
}

void ListBuckets::print()
{
    bucket* temp = head;
    while(temp!=NULL)
    {
        temp->print();
        temp = temp->next;
    }
}

ListBuckets::ListBuckets(int opt):option(opt)
{
    head = NULL;
    tail = NULL;
    prevtail = NULL;
    size_of_list = 0;
}

ListBuckets::~ListBuckets()
{
    bucket* temp = head;
    bucket* temp1;
    while(temp!=NULL)
    {
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    delete temp;
}

int ListBuckets::find_num(cdr* a)
{
    int flag = 0;
    bucket* temp = head;
    while(temp!=NULL)
    {
        flag = temp->find_num(a,option);
        temp = temp->next;
    }

    return flag;
}

void ListBuckets::insert_cdr(cdr* a)
{
    int flag = 0;
    flag = find_num(a);

    if(flag == 1)
    {
        return;
    }

    if(head == NULL)
    {
        head = new bucket();
        head->next = NULL;
        strcpy((head->content[head->numofcdr].number),a->get_originator());
        head->content[head->numofcdr].ptr = new ListBuckets2();
        head->content[head->numofcdr].ptr->insert_cdr(a);
        tail = head;
        head->numofcdr++;
        size_of_list++;
    }
    else
    {
        if((tail->numofcdr) < bucketsize)
        {
            strcpy((tail->content[tail->numofcdr].number),a->get_originator());
            tail->content[tail->numofcdr].ptr = new ListBuckets2();
            tail->content[tail->numofcdr].ptr->insert_cdr(a);
            tail->numofcdr++;
        }
        else
        {
            bucket* temp = new bucket();
            strcpy((temp->content[temp->numofcdr].number),a->get_originator());
            temp->content[temp->numofcdr].ptr = new ListBuckets2();
            temp->content[temp->numofcdr].ptr->insert_cdr(a);
            temp->numofcdr++;
            tail->next = temp;
            tail = temp;
            size_of_list++;
        }
    }
}

void ListBuckets::insert_cdr2(cdr* a)
{
    int flag = 0;
    flag = find_num(a);

    if(flag == 1)
    {
        return;
    }

    if(head == NULL)
    {
        head = new bucket();
        head->next = NULL;
        strcpy((head->content[head->numofcdr].number),a->get_destination_number());
        head->content[head->numofcdr].ptr = new ListBuckets2();
        head->content[head->numofcdr].ptr->insert_cdr(a);
        tail = head;
        head->numofcdr++;
        size_of_list++;
    }
    else
    {
        if((tail->numofcdr) < bucketsize)
        {
            //strcpy((tail->number[tail->numofcdr]),num);
            strcpy((tail->content[tail->numofcdr].number),a->get_destination_number());
            tail->content[tail->numofcdr].ptr = new ListBuckets2();
            tail->content[tail->numofcdr].ptr->insert_cdr(a);
            tail->numofcdr++;
        }
        else
        {
            prevtail = tail;
            bucket* temp = new bucket();
            strcpy((temp->content[temp->numofcdr].number),a->get_destination_number());
            temp->content[temp->numofcdr].ptr = new ListBuckets2();
            temp->content[temp->numofcdr].ptr->insert_cdr(a);
            temp->numofcdr++;
            tail->next = temp;
            tail = temp;
            size_of_list++;
        }
    }
}


node ListBuckets::return_last()
{
    return tail->content[tail->numofcdr-1];
}


void ListBuckets::delete_cdr(char id[11],char num[15])
{
    bucket* temp = head;
    int flag;
	int i;
    while(temp!=NULL)
    {
        flag = temp->delete_cdr(id);
		if(flag == 0)
		{
			if(temp->numofcdr > 1)
			{
				for(i=0;i<temp->numofcdr;i++)
				{
					if(!strcmp(temp->content[i].number,num))
					{
						strcpy(temp->content[i].number,tail->content[tail->numofcdr-1].number);
						temp->content[i].ptr = tail->content[tail->numofcdr-1].ptr;
						tail->content[tail->numofcdr-1].ptr = NULL;
						tail->numofcdr--;
					}
				}
			}
		}
        temp = temp->next;
    }
}

void ListBuckets::find(char a[15],char b[6],char c[9],char d[6],char e[9])
{
	bucket* temp = head;
	int i;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(a,temp->content[i].number))
			{
				temp->content[i].ptr->find(b,c,d,e);
			}
		}
		temp = temp->next;
	}
}

void ListBuckets::find(char a[15],char b[6],char c[6])
{
	bucket* temp = head;
	int i;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(a,temp->content[i].number))
			{
				temp->content[i].ptr->find(b,c);
			}
		}
		temp = temp->next;
	}
}

void ListBuckets::find(char a[15])
{
	bucket* temp = head;
	int i;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(a,temp->content[i].number))
			{
				temp->content[i].ptr->find();
			}
		}
		temp = temp->next;
	}
}


char** ListBuckets::indist(char a[15],int* b)
{
	bucket* temp = head;
	int i;
	char** return_array;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(a,temp->content[i].number))
			{
				return_array = temp->content[i].ptr->indist(a,b);
				return return_array;
			}
		}
		temp = temp->next;
	}
	return NULL;
}


void ListBuckets::indist2(char** a,char b[15],int c,int d)
{
	bucket* temp = head;
	int i;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(b,temp->content[i].number))
			{
				temp->content[i].ptr->indist2(a,b,c,d);
			}
		}
		temp = temp->next;
	}
}


void ListBuckets::topdest(char a[15])
{
	bucket* temp = head;
	int i;
	while(temp!=NULL)
	{
		for(i=0;i<temp->numofcdr;i++)
		{
			if(!strcmp(a,temp->content[i].number))
			{
				temp->content[i].ptr->topdest();
			}
		}
		temp = temp->next;
	}
}