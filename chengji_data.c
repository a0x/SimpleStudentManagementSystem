#define __chengji_data_c__

#include "main.h"
#include "chengji_data.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//功能描述：从chengji_班级编号_课程编号.txt 文件中读出所有	成绩，并保存到list所指的链表中
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null
//返回值：整型，当函数运行成功时，返回从chengji_班级编号_课程编号.txt读取到的成绩信息数量，当函数运行不成功时，返回-1
int read_chengji(struct chengji_list *list,char ban_bh[],char ke_bh[]){
	int count=0;

	struct __chengji *p;
	FILE *fp;

	char filename[1024];
     
	if(list==null)
	{
		printf("read_chengji报告错误：传入参数为空！");
		return 0;
	}
    
	fp=fopen(get_ke_ban_filename(filename,ban_bh,ke_bh),"r");

	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	while(feof(fp)==0)
	{
		p=(struct __chengji *)malloc(sizeof(struct __chengji));
		if(p==null)
		{
			printf("read_chengji报告错误：无法申请内存");
			fclose(fp);
			exit(0);
		}
		if(!fscanf(fp,"%s%s%s%s%s"
							,p->xuehao	//学号
							,p->name	//姓名
							,p->pingshi	//平时分
							,p->kaoshi	//考试分
							,p->zonghe))//综合成绩
		{
			printf("read_chengji报告错误：chengji_BJ20120101_KC201201.txt文件中数据被破坏！");
			free(p);
			fclose(fp);
			exit(0);
		}
		add_chengji_to_list(list,p);
		count++;
	}
	fclose(fp);
	return count;
}



//功能描述：将list所指链表中包含的成绩信息都覆盖式地存放到chengji_班级编号_课程编号.txt文件中，chengji_班级编号_课程编号.txt原有的内容都将被改写为list中所指链表中包含的成绩信息
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null，且链表中应该存放了需要写入文件的成绩信息
//返回值：当写文件成功时，返回所写入的成绩的数量，当写文件不成功时，返回-1
int write_chengji(struct chengji_list *list,char ban_bh[],char ke_bh[])
{
	char filename[1024];
	struct chengji_list_node * p;
	
	int count=0;

	FILE *fp;

	//Example(write_chengji);

	if(list==null)
	{
		printf("read_chengji报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen(get_ke_ban_filename(filename,ban_bh,ke_bh),"w");

	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	for(p=list->header;p!=null;p=p->next)
	{
		if(fprintf(fp,"%s\t%s\t%s\t%s\t%s"
			,p->chengji->xuehao
			,p->chengji->name
			,p->chengji->pingshi
			,p->chengji->kaoshi
			,p->chengji->zonghe)<0)
		{
			printf("无法写入文件！\r\n");
			break;
		}
		if(p->next!=null) fprintf(fp,"\r\n");
		count++;
	}
	fclose(fp);
	return count;
}





//功能描述：释放链表中的所有节点，清空链表
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null
//返回值：如果成功则返释放的节点数目，如果不成功则返回-1
int empty_chengji_list(struct chengji_list *list)
{
	struct chengji_list_node *p,*t;

	if((p=list->header)==null) return 0;
	do
	{
		t=p->next;
		free(p->chengji);
		free(p);
	}while((p=t)!=null);
	list->header=list->tail=null;
	return 0;
}




//功能描述：向成绩列表尾部增加一个成绩
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null，代表将要增加成绩的链表。参数chengji类型为struct __chengji *，指向一个待增加的成绩，值不能为null
//返回值：当函数成功时，本函数返回所传入的list指针，当函数运行不成功，本函数返回null
struct chengji_list * add_chengji_to_list(struct chengji_list *list,struct __chengji *chengji)
{
	struct chengji_list_node *p;
	
	if(list==null) return null;
	if(chengji==null) return null;

	p=(struct chengji_list_node *)malloc(sizeof(struct chengji_list_node));
	if(p==null)
	{
		printf("add_chengji_BJ20120101_KC201201_to_list报告错误：无法申请新的内存！\r\n");
		exit(0);
	}

	p->chengji=chengji;

	if(list->header==null) 
	{
		list->header=list->tail=p;
	}
	else
	{
		list->tail->next=p;
		list->tail=p;
	}
	p->next=null;
	return list;
}


//功能描述：通过学号查找到此人的成绩信息
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null，且链表中应该存放了成绩信息；参数xuehao类型为char *，指向一个字符串，代表待查找的学号
//返回值：类型为struct __chengji *类型，当查找成功时返回一个指针，指向查到的成绩信息。当查找不成功时，返回null
struct __chengji * get_chengji_by_xh(struct chengji_list *list,char *xuehao)
{
	struct chengji_list_node *p;

	if (list==null) return null;
	if (xuehao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->chengji->xuehao,xuehao)==0) return p->chengji;
	}

	return null;
}
//功能描述：在屏幕上显示链表中成绩信息
//输入参数：参数list类型为struct chengji_list *，指向一个链表，值不能为null，且链表中应该存放了需要显示的成绩信息
//返回值：无
int disp_chengji_list(struct chengji_list *list)
{
	int count=0;
	struct chengji_list_node *p;
	printf("序号\t学号\t\t姓名\t平时分\t考试分\t综合成绩\r\n");
	for(p=list->header;p!=null;p=p->next)
	{
		count++;
		printf("%d\t",count);
		disp_chengji(p->chengji);
		printf("\r\n");

	}
	
	return 0;
}

//功能描述：在屏幕上显示指针p所指向的班级信息
//输入参数：参数p类型为struct __chengji *，指向一个成绩信息，值不能为空
//返回值：无
void disp_chengji(struct __chengji * p)
{
		printf("%s\t%s\t%s\t%s\t%s"
			,p->xuehao
			,p->name
			,p->pingshi
			,p->kaoshi
			,p->zonghe);
}

/*
struct __chengji * getout_chengji_by_xh(struct chengji_list *list,char *xuehao)
{


	struct chengji_list_node *p,*t;
	struct __chengji *chengji=null;
	Example(getout_chengji_by_xh);
	if (list==null) return null;
	if (xuehao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->chengji->xuehao,xuehao)==0)
		{
			if(list->header==p)
			{
				list->header=p->next;
			}
			else
			{
				t->next=p->next;
			}
			chengji=p->chengji;
			free(p);
			return chengji;
		}
		t=p;
	}
	return null;
}
*/

//功能描述：根据课程编号和班级编号，获取存储该班级学生名单的那个文件的文件名
//输入参数：参数filename：必须是一个足够长的字符串缓冲区，防止溢出，参数ke_bh：是一个字符串，里面存储课程的编号信息，参数ban_bh：是一个字符串，里面存储班级的编号信息
//返回值：如果函数运行成功，则filename里面存储着生成的文件名，返回filename，否则返回null。
char *get_ke_ban_filename(char *filename,char *ban_bh,char *ke_bh)
{
	if(filename==null || ban_bh==null) return null;
	//清除filename中的字符串
	filename[0]='\0';

	strcpy(filename,"c:\\chengji_");
	strcat(filename,ban_bh);
	strcat(filename,"_");
	strcat(filename,ke_bh);
	strcat(filename,".txt");

	return filename;

}