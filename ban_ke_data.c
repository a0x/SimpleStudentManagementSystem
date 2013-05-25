#define __banke_c__
#include "main.h"
#include "ban_ke_data.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ban_data.h"
#include "kecheng_data.h"
//功能描述：从ban_ke.txt文件中读出所有班级，并保存到list所指的链表中
//输入参数：参数list类型为struct banke_list *，指向一个链表，值不能为null
//返回值：整型，当函数运行成功时，返回从ban_ke.txt读取到的班级授课信息数量，当函数运行不成功时，返回-1
int read_banke(struct banke_list *list)
{
	int count=0;
	struct __banke *p;
	FILE *fp;
	if(list==null)
	{
		printf("read_banke报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen("c:\\ban_ke.txt","r");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	
	while(feof(fp)==0)
	{
		p=(struct __banke *)malloc(sizeof(struct __banke));
		if(p==null)
		{
			printf("read_banke报告错误：无法申请内存");
			fclose(fp);
			exit(0);
		}
		if(!fscanf(fp,"%s%s%s%s"
							,p->xueqi	//班级编号
							,p->bbianhao	//专业
							,p->kbianhao	//年级
							,p->jiaoshi))//班号
		{
			printf("read_banke报告错误：banke.txt文件中数据被破坏！");
			free(p);
			fclose(fp);
			exit(0);
		}
		add_banke_to_list(list,p);
		count++;
	}
	fclose(fp);
	return count;
}



//功能描述：向班课列表尾部增加一个班课
//输入参数：参数list代表将要增加班课的链表，参数banke指向一个待增加的班课
//返回值：当函数成功时，本函数返回list指针，当函数运行不成功，本函数返回null。

struct banke_list * add_banke_to_list(struct banke_list *list,struct __banke *banke)
{
	struct banke_list_node *p;
	
	if(list==null) return null;
	if(banke==null) return null;

	p=(struct banke_list_node *)malloc(sizeof(struct banke_list_node));
	if(p==null)
	{
		printf("add_banke_to_list报告错误：无法申请新的内存！\r\n");
		exit(0);
	}

	p->banke=banke;

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

//功能描述：将list所指的链表中的班级授课信息都覆盖式地存放到ban_ke.txt文件中
//输入参数：参数list类型为struct banke_list *，指向一个链表，值不能为null
//返回值：整型 ，当写文件成功时，返回所写入的班级的数量，当写文件不成功时，返回-1
int write_banke(struct banke_list *list)
{
	struct banke_list_node * p;
	
	int count=0;

	FILE *fp;

	if(list==null)
	{
		printf("read_banke报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen("c:\\ban_ke.txt","w");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	for(p=list->header;p!=null;p=p->next)
	{
		if(fprintf(fp,"%s\t%s\t%s\t%s"
			,p->banke->xueqi
			,p->banke->bbianhao
			,p->banke->kbianhao
			,p->banke->jiaoshi)<0)
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

//功能描述：释放链表中的节点，清空链表
//输入参数：参数list指向struct banke_list
//返回值：如果成功则返释放的节点数目，如果不成功则返回-1
int empty_banke_list(struct banke_list *list)
{
	int count=0;
	struct banke_list_node *p,*t;
	if((p=list->header)==null) return 0;
	do
	{
		t=p->next;
		free(p->banke);
		free(p);
		count++;
	}while((p=t)!=null);
	list->header=list->tail=null;
	return count;
}
//功能描述：根据bianhao中所存储的班级编号，在list所指向的链表中查找课程
//输入参数：dest_list代表符合信息的班课信息列表，值为空 ，src_list 代表包含全部班课信息的列表，值不能为空,bianhao 指向待查找的班级编号
//返回值：当函数成功时，本函数返回dest_list指针。当函数运行不成功，本函数返回null
struct banke_list * get_banke_by_bh(struct banke_list *dest_list,struct banke_list *src_list,char *bianhao)
{
	struct banke_list_node * p;
	struct __banke *q;


	
	if(src_list==null) 
	{
		printf("banke_list报告错误:list参数为空！\r\n");
		exit(0);
	}

	if(bianhao==null)
	{
		printf("bianhao报告错误:list参数为空！\r\n");
		exit(0);
	}
	else if(strlen(bianhao)<=0)
	{
		printf("bianhao报告错误:bianhao字符串的长度为0！\r\n");
	}
	

	for(p=src_list->header;p!=null;p=p->next)
	{
		if(strcmp(p->banke->bbianhao,bianhao)==0)
		{
			q=(struct __banke*)malloc(sizeof(struct __banke));
			memcpy(q,p->banke,sizeof(struct __banke));
			add_banke_to_list(dest_list,q);
		}
	}

	return dest_list;
}

//功能描述：根据bianhao中所存储的课程编号，在list所指向的链表中查找课程
//输入参数：dest_list代表符合信息的班课信息列表，值为空 ，src_list 代表包含全部班课信息的列表，值不能为空.ke_bh指向待查找的课程编号.
//返回值：当函数成功时，本函数返回dest_list指针。当函数运行不成功，本函数返回null
struct banke_list * get_banke_by_kh(struct banke_list *dest_list,struct banke_list *src_list,char *ke_bh)
{
	struct banke_list_node * p;
	struct __banke *q;


	if(dest_list==null) 
	{
		printf("get_banke_by_kh报告错误:dest_list参数为空！\r\n");
		exit(0);
	}
	
	if(src_list==null) 
	{
		printf("get_banke_by_kh报告错误:src_list参数为空！\r\n");
		exit(0);
	}

	if(ke_bh==null)
	{
		printf("get_banke_by_kh报告错误:ke_bh参数为空！\r\n");
		exit(0);
	}
	else if(strlen(ke_bh)<=0)
	{
		printf("get_banke_by_kh报告错误:ke_bh字符串的长度为0！\r\n");
	}
	

	for(p=src_list->header;p!=null;p=p->next)
	{
		if(strcmp(p->banke->kbianhao,ke_bh)==0)
		{
			q=(struct __banke*)malloc(sizeof(struct __banke));
			memcpy(q,p->banke,sizeof(struct __banke));
			add_banke_to_list(dest_list,q);
		}
	}

	return dest_list;
}


//功能描述：在屏幕上显示链表中班级课程信息
//输入参数：参数banke类型为struct __banke *，指向一个班级授课信息，值不能为空 参数banji类型为struct __banji *，指向一个班级信息，值不能为空。参数kecheng类型为struct  kecheng_list *,指向一个课程信息，值不能为空
//返回值：无
int disp_banke_list(struct banke_list *banke,struct kecheng_list *kecheng,struct banji_list *banji)
{
	int count=0;
	struct banke_list_node *p;
	struct __banji *b;
	struct __kecheng *k;
	printf("序号 学期\t\t教师\t课程编号\t课程名称\t班级编号\t专业\t年级\t班号\r\n");
	for(p=banke->header;p!=null;p=p->next)
	{
		count++;
		b=get_ban_by_bh(banji,p->banke->bbianhao);
		k=get_ke_by_bh(kecheng,p->banke->kbianhao);
		printf("%-5.0d",count);
		printf("%s\t",p->banke->xueqi);
		printf("%s\t",p->banke->jiaoshi);
		printf("%s\t",k->bianhao);
		printf("%s\t",k->mingcheng);
		printf("%s\t",b->bianhao);
		printf("%s\t",b->zhuanye);
		printf("%s\t",b->nianji);
		printf("%s",b->banhao);
		printf("\r\n");
	}
	return 0;
}

//功能描述：取消一个班级所开设的一个课程
//输入参数：list代表班课信息列表，值不能为空，bianhao代表待删除的课程编号
//返回值：当查找成功时，返回该班课信息的指针，当查找不成功时，返回null
struct __banke * getout_banke_by_bh(struct banke_list *list,char *bianhao)
{

	struct banke_list_node *p,*t;
	struct __banke *banke=null;

	if (list==null) return null;
	if (bianhao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->banke->bbianhao,bianhao)==0)
		{
			if(list->header==p)
			{
				list->header=p->next;
			}
			else
			{
				t->next=p->next;
			}
			banke=p->banke;
			free(p);
			return banke;
		}
		t=p;
	}
	return null;
}
//功能描述：根据班级编号和课程编号，在list所指向的链表中查找上课信息，并移除链表中该节点，同时释放节点内存，
//输入参数：list，代表所有的上课信息，ban_bh代表班级编号，ke_bh代表课程编号
//返回值：当查找成功时，返回该班级信息的指针，当查找不成功，返回null

struct __banke * getout_banke_by_kh(struct banke_list *list,char *ban_bh,char *ke_bh)
{
    
	struct banke_list_node *p,*t;
	struct __banke *banke=null;

	if(list==null) 
	{
		printf("getout_banke_by_kh报告错误：参数list为空！\r\n");
		exit(0);
	}
	if(ban_bh==null)
	{
		printf("getout_banke_by_kh报告错误：参数ban_bh为空！\r\n");
		exit(0);
	}
	else if(strlen(ban_bh)==0)
	{
		printf("getout_banke_by_kh报告错误：参数ban_bh长度为0！\r\n");
		exit(0);
	}
	if(ke_bh==null) 
	{
		printf("getout_banke_by_kh报告错误：参数ke_bh为空！\r\n");
		exit(0);
	}
	else if(strlen(ke_bh)==0)
	{
		printf("getout_banke_by_kh报告错误：参数ke_bh长度为0！\r\n");
		exit(0);
	}

	for(p=list->header;p!=null;p=p->next)

	{	
		if(strcmp (p->banke->bbianhao,ban_bh)==0 &&strcmp(p->banke->kbianhao,ke_bh)==0)
		{	 
			if(list->header==p)
			{
				list->header=p->next;
			}	
			else
			{
				t->next=p->next;		
			}
			banke=p->banke;
			free(p);
			return banke;
		}
		t=p;
	}
  return null;
}
