#define __xuesheng_c__

#include "main.h"
#include "xuesheng_data.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//功能描述：从xuesheng.txt文件中读出所有学生，并保存到list所指的链表中
//输入参数：参数list类型为struct  xuesheng_list *，指向一个链表，值不能为null
//返回值：当读取成功时返回读到的班级数量,当读取不成功时，返回-1
int read_xuesheng(struct xuesheng_list *list,char bianhao[])
{
	int count=0;

	char filename[1024];	

	struct __xuesheng *p;
	FILE *fp;

	if(bianhao == null )
	{
		printf("read_xuesheng出现错误：传入班级编号参数为空。\r\n");
		exit(0);
	}
//	printf("%s\r\n",get_xs_filename(filename,bianhao));
	if(get_xs_filename(filename,bianhao)==null)
	{
		printf("read_xuesheng出现错误：无法拼合文件名。\r\n");
		exit(0);
	}
	

	if(list==null)
	{
		printf("read_xuesheng报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen(get_xs_filename(filename,bianhao),"r");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	
	while(feof(fp)==0)
	{
		p=(struct __xuesheng *)malloc(sizeof(struct __xuesheng));
		if(p==null)
		{
			printf("read_xuesheng报告错误：无法申请内存");
			fclose(fp);
			exit(0);
		}
		if(!fscanf(fp,"%s%s%s%s%s"
		
							,p->xuehao	    //学号
							,p->xingming	//姓名
							,p->xingbie	    //性别
							,p->jiguan      //籍贯
							,p->lianxifangshi))//联系方式
		{
			printf("read_xuesheng报告错误：xuesheng.txt文件中数据被破坏！");
			free(p);
			fclose(fp);
			exit(0);
		}
		add_xuesheng_to_list(list,p);
		count++;
	}
	fclose(fp);
	return count;
}



//功能描述：将list所指的链表中的班级信息都覆盖式地存放到xuesheng_班级编号.txt文件中
//输入参数：参数list类型为struct xuesheng_list，指向一个链表，值不能为null，且链表中应该存放了需要写入文件的学生信息
//返回值：当写文件成功时，返回所写入的学生的数量,当写文件不成功时，返回-1
int write_xuesheng(struct xuesheng_list *list,char ban_bh[])
{
	char filename[1024];

	struct xuesheng_list_node * p;
	
	int count=0;

	FILE *fp;


	if(list==null)
	{
		printf("read_xuesheng报告错误：传入参数为空！");
		return 0;
	}

	fp=fopen(get_xs_filename(filename,ban_bh),"w");
	if(fp==null)
	{
		printf("目前没有数据!\r\n");
		return 0;
	}

	for(p=list->header;p!=null;p=p->next)//学号 姓名 性别 籍贯 联系方式
	{
		if(fprintf(fp,"%s\t%s\t%s\t%s\t%s"
			,p->xuesheng->xuehao
			,p->xuesheng->xingming
			,p->xuesheng->xingbie
			,p->xuesheng->jiguan
			,p->xuesheng->lianxifangshi)<0)
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
//输入参数：参数list类型为struct xuesheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的班级信息
//返回值：当排序成功时，返回按学生学号所排序的学生的数量，当排序不成功时，返回-1
int sort_xuesheng_bh(struct xuesheng_list *list)
{
	return 0;
}

//功能描述：按照班级专业对链表中的元素予以排序
//输入参数：参数list类型为struct xuesheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要排序的班级信息
//返回值：当排序成功时，返回按班级编号所排序的班级的数量，当排序不成功时，返回-1
int sort_xuesheng_zy(struct xuesheng_list *list)
{
	return 0;
}

//功能描述：向班级列表尾部增加一个班级
//输入参数：参数list代表将要增加班级的链表，参数banji指向一个待增加的班级
//返回值：当函数成功时，本函数返回list指针,当函数运行不成功，本函数返回null
struct xuesheng_list * add_xuesheng_to_list(struct xuesheng_list *list,struct __xuesheng *xuesheng)
{
	struct xuesheng_list_node *p;
	
	if(list==null) return null;
	if(xuesheng==null) return null;

	p=(struct xuesheng_list_node *)malloc(sizeof(struct xuesheng_list_node));
	if(p==null)
	{
		printf("add_xuesheng_to_list报告错误：无法申请新的内存！\r\n");
		exit(0);
	}

	p->xuesheng=xuesheng;

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
int empty_xuesheng_list(struct xuesheng_list *list)
{
	int count = 0;
	struct xuesheng_list_node *p,*t;

	if(list == null)
	{
		return -1;
	}

	if((p=list->header)==null) return 0;
	do
	{
		t=p->next;
		free(p->xuesheng);
		free(p);
		count++;
	}while((p=t)!=null);
	list->header=list->tail=null;
	return count;
}

//功能描述：在屏幕上显示链表中班级信息
//输入参数：参数list类型为struct xuesheng_list *，指向一个链表，值不能为null，且链表中应该存放了需要显示的学生信息
//返回值：显示成功时返回所显示的学生信息的个数，否则返回-1
int disp_xuesheng_list(struct xuesheng_list *list)
{
	int count=0;
	struct xuesheng_list_node *p;//序号\t学号\t\t姓名\t性别\t籍贯\t联系方式\r
	printf("序号\t学号\t姓名\t性别\t籍贯\t联系方式\r\n");
	for(p=list->header;p!=null;p=p->next)
	{
		count++;
		printf("%d\t",count);
		disp_xuesheng(p->xuesheng);
		printf("\r\n");
	}
	
	return 0;
}

//功能描述：根据xuehao中所存储的学生学号，在list所指向的链表中查找学生信息
//输入参数：参数list类型为struct xuesheng_list *，指向一个链表，值不能为null，且链表中应该存放了学生信息；参数xuehao类型为char *，指向一个字符串，代表待查找的学生学号
//返回值：当查找成功时，返回该学生信息的指针,当查找不成共识，返回null
struct __xuesheng * get_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao)
{
	struct xuesheng_list_node *p;
	if (list==null) return null;
	if (xuehao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->xuesheng->xuehao,xuehao)==0) return p->xuesheng;
	}

	return null;
}

//功能描述：根据xuehao中所存储的学生学号，在list所指向的链表中查找学生信息
//输入参数：参数list类型为struct xuesheng_list *，指向一个链表，值不能为null，且链表中应该存放了学生信息；参数xuehao类型为char*，指向一个字符串，代表待查找的学生学号
//返回值：当查找成功时，返回该学生的指针,当查找不成共识，返回null
struct __xuesheng * getout_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao)
{
	struct xuesheng_list_node *p,*t;
	struct __xuesheng *xuesheng=null;
	if (list==null) return null;
	if (xuehao==null) return null;
	
	for(p=list->header;p!=null;p=p->next)
	{
		if(strcmp(p->xuesheng->xuehao,xuehao)==0)
		{
			if(list->header==p)
			{
				list->header=p->next;
			}
			else
			{
				t->next=p->next;
			}
			xuesheng=p->xuesheng;
			free(p);
			return xuesheng;
		}
		t=p;
	}
	return null;
}

//功能描述：在屏幕上显示指针p所指向的学生信息
//输入参数：参数p类型为struct __xuesheng *，指向一个学生信息，值不能为空
//返回值：无
void disp_xuesheng(struct __xuesheng * p)
{
		printf("%s\t%s\t%s\t%s\t%s"
			,p->xuehao
			,p->xingming
			,p->xingbie
			,p->jiguan
			,p->lianxifangshi);
}

//功能描述：根据班级编号，获取存储该班级学生名单的那个文件的文件名
//输入参数：参数filename：必须是一个足够长的字符串缓冲区，防止溢出,参数ban_bn：是一个字符串，里面存储班级的编号信息
//返回值：如果函数运行成功，则filename里面存储着生成的文件名，返回filename,否则返回null。
char *get_xs_filename(char *filename,char *ban_bh)
{
	if(filename==null || ban_bh==null) return null;
	//清除filename中的字符串
	filename[0]='\0';

	strcpy(filename,"c:\\xuesheng_");
	strcat(filename,ban_bh);
	strcat(filename,".txt");

	return filename;

}