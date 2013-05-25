#define __ke_c__
#define __main_c__
#include "main.h"
#include "kecheng_data.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//功能描述：从kecheng.txt文件中读出所有课程，并保存到list所指的链表中
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为空
//返回值：整型，当函数运行成功时，返回从kecheng.txt中读取的课程信息数量，当函数运行不成功时，返回-1
int read_ke(struct kecheng_list *list)
{
	int count=0;

	struct __kecheng *p;
	FILE *fp;

	if(list==null)
	{
		printf("read_ke报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen("c:\\kecheng.txt","r");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	
	while(feof(fp)==0)
	{
		p=(struct __kecheng *)malloc(sizeof(struct __kecheng));
		if(p==null)
		{
			printf("read_ke报告错误：无法申请内存");
			fclose(fp);
			exit(0);
		}
		if(!fscanf(fp,"%s%s%s%s"
							,p->bianhao	//课程编号
							,p->mingcheng	//课程名称
							,p->xuefen	//学分
							,p->jianjie))//简介
		{
			printf("read_ke报告错误：kecheng.txt文件中数据被破坏！");
			free(p);
			fclose(fp);
			exit(0);
		}
		add_ke_to_list(list,p);
		count++;
	}
	fclose(fp);
	return count;
}

//功能描述：将list所指链表中包含的课程信息都覆盖式地存放到kecheng.txt文件中，kecheng.txt原有的内容都将被改写为list中所指链表中包含的课程信息
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要写入文件的课程信息
//返回值：当写文件成功时，返回所写入的课程的数量，当写文件不成功时，返回-1
int write_ke(struct kecheng_list *list)
{
	struct kecheng_list_node * p;
	int count = 0;
	FILE *fp;
	Example(write_ke);
    if(list == null)
	{
		printf("write_ke报告错误：传入参数为空！");
		return 0;
	}
	fp=fopen("c:\\kecheng.txt","w");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	for(p=list->header;p!=null;p=p->next)
	{
		if(fprintf(fp,"%s\t%s\t%s\t%s"
			,p->kecheng->bianhao
			,p->kecheng->mingcheng
			,p->kecheng->xuefen
			,p->kecheng->jianjie)<0)
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


//功能描述：向课程列表尾部增加一个课程
//输入参数：参数list代表将要增加课程的链表，参数banji指向一个待增加的课程
//返回值：当函数成功时，本函数返回list指针，当函数运行不成功，本函数返回null。
struct kecheng_list * add_ke_to_list(struct kecheng_list *list,struct __kecheng *kecheng)
{
	struct kecheng_list_node *p;
	
	if(list==null) return null;
	if(kecheng==null) return null;

	p=(struct kecheng_list_node *)malloc(sizeof(struct kecheng_list_node));
	if(p==null)
	{
		printf("add_ke_to_list报告错误：无法申请新的内存！\r\n");
		exit(0);
	}

	p->kecheng=kecheng;

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
//功能描述：释放链表中的节点，清空链表
//输入参数：参数list指向struct kecheng_list
//返回值：如果成功则返释放的节点数目，如果不成功则返回-1
int empty_ke_list(struct kecheng_list *list)
{
	struct kecheng_list_node *p,*t;
	int count=0;

	if((p=list->header)==null) return 0;
	do
	{
		t=p->next;
		free(p->kecheng);
		free(p);
		count++;
	}while((p=t)!=null);
	list->header=list->tail=null;
	return count;
}

//功能描述：根据bianhao中所存储的课程编号，在list所指向的链表中查找课程信息，并移除链表中该节点，同时释放节点内存
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，不能为空值
//返回值：整型，当函数运行成功时，则返回释放的节点数目，当函数运行不成功时，返回-1
struct __kecheng * getout_ke_by_bh(struct kecheng_list *list,char *bianhao)
{

	struct kecheng_list_node *p,*t;
	struct __kecheng *kecheng=null;
	Example(getout_ke_by_bh);
	if (list==null) return null;
	if (bianhao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->kecheng->bianhao,bianhao)==0)
		{
			if(list->header==p)
			{
				list->header=p->next;
			}
			else
			{
				t->next=p->next;
			}
			kecheng=p->kecheng;
			free(p);
			return kecheng;
		}
		t=p;
	}
	return null;
}


//功能描述：在屏幕上显示链表中课程信息
//输入参数：参数list类型为struct kecheng_list *,指向一个链表，值不能为空
//返回值：整型，当函数运行成功时，返回从kecheng.txt中读取的课程信息数量，当函数运行不成功时，返回-1
int disp_ke_list(struct kecheng_list *list)
{
	int count=0;
	struct kecheng_list_node *p;
	printf("序号\t课程编号\t\t课程名称\t\t学分\t简介\r\n");
	for(p=list->header;p!=null;p=p->next)
	{
		count++;
		printf("%d\t",count);
		disp_ke(p->kecheng);
		printf("\r\n");

	}
	
	return 0;
}

//功能描述：根据bianhao中所存储的课程编号，在list所指向的链表中查找课程信息，并移除链表中该节点，同时释放节点内存
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为空，参数bianhao类型为char *，指向一个课程的编号，值不能为空
//返回值：指向课程信息的指针，当查找成功时返回该课程信息的指针，当查找不成功时返回null
struct __kecheng * get_ke_by_bh(struct kecheng_list *list,char *bianhao)
{
	struct kecheng_list_node *p;
	Example(get_ke_by_bh);
	if (list==null) return null;
	if (bianhao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->kecheng->bianhao,bianhao)==0) return p->kecheng;
	}

	return null;
}

//功能描述：在屏幕上显示指针p所指向的班级信息
//输入参数：参数list类型为struct __kecheng * p
//返回值：无
void disp_ke(struct __kecheng * p)
{
		printf("%s\t%s\t%s\t%s"
			,p->bianhao
			,p->mingcheng
			,p->xuefen
			,p->jianjie);
}
//功能描述：按照课程学分对list所指课程链表中的元素予以排序
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的课程信息
//返回值：当排序成功时，返回按课程学分所排序的课程的数量，当排序不成功时，返回-1
int sort_ke_xuefen(struct kecheng_list *list)
{
	int count;
	struct kecheng_list_node *i,*j;
	struct __kecheng *t;

	Example(sort_ke_xuefen);

	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->kecheng->xuefen,i->kecheng->xuefen)<0)
			{
				t=i->kecheng;
				i->kecheng=j->kecheng;
				j->kecheng=t;
			}
		}
		count++;
	}

	return count;
}
//功能描述：按照课程编号对list所指课程链表中的元素予以排序
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的课程信息
//返回值：当排序成功时，返回按课程编号所排序的课程的数量，当排序不成功时，返回-1
int sort_ke_bh(struct kecheng_list *list)
{
	int count;
	struct kecheng_list_node *i,*j;
	struct __kecheng *t;

	Example(sort_ke_bh);

	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->kecheng->bianhao,i->kecheng->bianhao)<0)
			{
				t=i->kecheng;
				i->kecheng=j->kecheng;
				j->kecheng=t;
			}
		}
		count++;
	}

	return count;
}
//功能描述：按照课程名称对链表中的元素予以排序
//输入参数：参数list类型为struct kecheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的课程信息
//返回值：当排序成功时，返回按课程名字所排序的课程的数量，当排序不成功时，返回-1
int sort_ke_mingcheng(struct kecheng_list *list)
{
   int count;
	struct kecheng_list_node *i,*j;
	struct __kecheng *t;

	Example(sort_ke_xuefen);

	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->kecheng->mingcheng,i->kecheng->mingcheng)<0)
			{
				t=i->kecheng;
				i->kecheng=j->kecheng;
				j->kecheng=t;
			}
		}
		count++;
	}

	return count;
}