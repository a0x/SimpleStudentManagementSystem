#define __ban_c__

#include "main.h"
#include "ban_data.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//功能描述：从ban.txt文件中读出所有班级，并保存到list所指的链表中
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null
//返回值：整型，当读取成功时返回读到的班级数量，当读取不成功时，返回-1
int read_ban(struct banji_list *list)
{
	
	int count=0;

	struct __banji *p;
	FILE *fp;



	if(list==null)
	{
		printf("read_ban报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen("c:\\ban.txt","r");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	
	while(feof(fp)==0)
	{
		p=(struct __banji *)malloc(sizeof(struct __banji));
		if(p==null)
		{
			printf("read_ban报告错误：无法申请内存");
			fclose(fp);
			exit(0);
		}
		if(fscanf(fp,"%s%s%s%s"
							,p->bianhao	//班级编号
							,p->zhuanye	//专业
							,p->nianji	//年级
							,p->banhao)!=4)//班号
		{
			printf("read_ban报告错误：ban.txt文件中数据被破坏！\r\n");
			free(p);
			break;
		}
		add_ban_to_list(list,p);
		count++;
	}
	fclose(fp);
	return count;
}

//功能描述：将list所指的链表中的班级信息都覆盖式地存放到ban.txt文件中
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了需要写入文件的班级信息
//返回值：整型，当写文件成功时，返回所写入的班级的数量,当写文件不成功时，返回-1
int write_ban(struct banji_list *list)
{

	struct banji_list_node * p;
	
	int count=0;

	FILE *fp;

	

	if(list==null)
	{
		printf("read_ban报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen("c:\\ban.txt","w");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	for(p=list->header;p!=null;p=p->next)
	{
		if(fprintf(fp,"%s\t%s\t%s\t%s"
			,p->banji->bianhao
			,p->banji->zhuanye
			,p->banji->nianji
			,p->banji->banhao)<0)
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

//功能描述：按照班级编号对链表中的元素予以排序
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的班级信息
//返回值：整型，当排序成功时，返回按班级编号所排序的班级的数量，当排序不成功时，返回-1
int sort_ban_bh(struct banji_list *list)
{

	int count;
	struct banji_list_node *i,*j;
	struct __banji *t;



	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->banji->bianhao,i->banji->bianhao)<0)
			{
				t=i->banji;
				i->banji=j->banji;
				j->banji=t;
			}
		}
		count++;
	}

	return count;
}

//功能描述：按照班级专业对链表中的元素予以排序
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的班级信息
//返回值：整型，当排序成功时，返回按班级编号所排序的班级的数量，当排序不成功时，返回-1。
int sort_ban_zy(struct banji_list *list)
{
	
	int count;
	struct banji_list_node *i,*j;
	struct __banji *t;



	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->banji->zhuanye,i->banji->zhuanye)<0)
			{
				t=i->banji;
				i->banji=j->banji;
				j->banji=t;
			}
		}
		count++;
	}

	return count;
}

//功能描述：按照班级年级对链表中的元素予以排序
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的班级信息
//返回值：整型，当排序成功时，返回按班级编号所排序的班级的数量，当排序不成功时，返回-1
int sort_ban_nj(struct banji_list *list)
{
	
	int count;
	struct banji_list_node *i,*j;
	struct __banji *t;



	count=0;
	
	if(list==null) return -1;
	
	for(i=list->header;i!=null;i=i->next)
	{
		for(j=i->next;j!=null;j=j->next)
		{
			if(strcmp(j->banji->nianji,i->banji->nianji)<0)
			{
				t=i->banji;
				i->banji=j->banji;
				j->banji=t;
			}
		}
		count++;
	}

	return count;
}

//功能描述：向班级列表尾部增加一个班级
//输入参数：参数list代表将要增加班级的链表，参数banji指向一个待增加的班级
//返回值：整型，当函数成功时，本函数返回list指针,当函数运行不成功，本函数返回null。
struct banji_list * add_ban_to_list(struct banji_list *list,struct __banji *banji)
{
	
	struct banji_list_node *p;
	


	if(list==null) return null;
	if(banji==null) return null;

	p=(struct banji_list_node *)malloc(sizeof(struct banji_list_node));
	if(p==null)
	{
		printf("add_ban_to_list报告错误：无法申请新的内存！\r\n");
		exit(0);
	}

	p->banji=banji;

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
//输入参数：参数list指向struct banji_list
//返回值：如果成功则返释放的节点数目,如果不成功则返回-1
int empty_ban_list(struct banji_list *list)
{

	int count=0;
	struct banji_list_node *p,*t;



	if((p=list->header)==null) return 0;
	do
	{
		t=p->next;
		free(p->banji);
		free(p);
		count++;
	}while((p=t)!=null);
	list->header=list->tail=null;
	return count;
}

//功能描述：在屏幕上显示链表中班级信息
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了需要显示的班级信息
//返回值：显示成功时返回所显示的班级信息的个数，否则返回-1
int disp_ban_list(struct banji_list *list)
{
	int count=0;
	struct banji_list_node *p;

	printf("序号\t编号\t\t专业\t\t年级\t班号\r\n");
	for(p=list->header;p!=null;p=p->next)
	{
		count++;
		printf("%d\t",count);
		disp_ban(p->banji);
		printf("\r\n");

	}
	
	return 0;
}

//功能描述：根据bianhao中所存储的班级编号，在list所指向的链表中查找班级信息
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，且链表中应该存放了班级信息；参数bianhao类型为cha *，指向一个字符串，代表待查找的班级编号
//返回值：当查找成功时，返回该班级信息的指针,当查找不成共识，返回null
struct __banji * get_ban_by_bh(struct banji_list *list,char *bianhao)
{
	struct banji_list_node *p;

	if (list==null) return null;
	if (bianhao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->banji->bianhao,bianhao)==0) return p->banji;
	}

	return null;
}

//功能描述：根据bianhao中所存储的班级编号，在list所指向的链表中查找班级信息，并移除链表中该节点，同时释放节点内存，
//输入参数：参数list类型为struct banji_list *，指向一个链表，值不能为null，代表将要增加班级的链表。参数banji类型为struct __banji *，指向一个待增加的班级，值不能为null
//返回值：当查找成功时，返回该班级信息的指针,当查找不成共识，返回null
struct __banji * getout_ban_by_bh(struct banji_list *list,char *bianhao)
{

	struct banji_list_node *p,*t;
	struct __banji *banji=null;

	if (list==null) return null;
	if (bianhao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->banji->bianhao,bianhao)==0)
		{
			if(list->header==p)
			{
				list->header=p->next;
			}
			else
			{
				t->next=p->next;
			}
			banji=p->banji;
			free(p);
			return banji;
		}
		t=p;
	}
	return null;
}

//功能描述：在屏幕上显示指针p所指向的班级信息
//输入参数：参数p类型为struct __banji *，指向一个班级信息，值不能为空
//返回值：无
void disp_ban(struct __banji * p)
{
		printf("%s\t%s\t%s\t%s"
			,p->bianhao
			,p->zhuanye
			,p->nianji
			,p->banhao);
}
