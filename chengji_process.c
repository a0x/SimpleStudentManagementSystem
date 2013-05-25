#define __chengji_process_c__

#include "chengji_data.h"
#include "chengji_process.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "xuesheng_data.h"
#include "xuesheng_process.h"
#include "ban_ke_data.h"
#include "ban_ke_process.h"
#include "kecheng_data.h"
#include "kecheng_process.h"
//----------处理班级课程成绩-----------

//功能描述：调用相关的数据处理函数实现显示chengji_班级编号_课程编号.txt中所有成绩信息
//输入参数：参数ban_bh类型为字符串数组，指向一个字符串，代表待查找成绩的班级编号
//返回值：无
void __disp_ban_ke_cj(char ban_bh[],char ke_bh[])
{
	struct xuesheng_list xuesheng={null,null};
	struct chengji_list chengji={null,null};
	struct xuesheng_list_node *p;
	struct __chengji *q;
	int count=0;
	read_xuesheng(&xuesheng,ban_bh);
	read_chengji(&chengji,ban_bh,ke_bh);
	printf("序号\t学号\t姓名\t平时分\t考试分\t综合成绩\r\n");
	for(p=xuesheng.header;p!=null;p=p->next)
	{
		count++;
		q=get_chengji_by_xh(&chengji,p->xuesheng->xuehao);
		printf("%d\t%s\t%s\t%s\t%s\t%s\r\n"
			,count
			,p->xuesheng->xuehao
			,p->xuesheng->xingming
			,q==null?"--":q->pingshi
			,q==null?"--":q->kaoshi
			,q==null?"--":q->zonghe);
	}

	empty_chengji_list(&chengji);
	empty_xuesheng_list(&xuesheng);
}

//功能描述：调用相关的数据处理函数实现让用户在屏幕上输入信息，增加一个成绩
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空；参数 ke_bh[]的参数类型为字符串数组，该参数用于存放用户输入的课程编号信息，值不可以为空
//返回值：无
void __zengjia_ban_ke_cj(char ban_bh[],char ke_bh[])
{
	struct chengji_list list={0,0};
	struct __chengji *p=(struct __chengji *)malloc(sizeof(struct __chengji));

	read_chengji(&list,ke_bh,ban_bh);

	if(p==0)
	{
		printf("__zengjia_chengji报告错误：无法申请内存！\r\n");
		exit(0);
	}

	printf("增加班级：\r\n");
	printf("\t请输入学号：");
	scanf("%s",p->xuehao);
	printf("\t请输入姓名：");
	scanf("%s",p->name);
	printf("\t请输入平时成绩：");
	scanf("%s",p->pingshi);
	printf("\t请输入考试成绩：");
	scanf("%s",p->kaoshi);
	printf("\t请输入总成绩：");
	scanf("%s",p->zonghe);

	//disp_chengji_list(&list);
	add_chengji_to_list(&list,p);
	//if(write_chengji(&list)>0) printf("保存成功!\r\n");
	if(write_chengji(&list,ban_bh,ke_bh)>0) printf("保存成功!\r\n");
	empty_chengji_list(&list);

}


//功能描述：调用相关的数据处理函数实现让用户在屏幕上输入信息，修改一个成绩
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空；参数 ke_bh[]的参数类型为字符串数组，该参数用于存放用户输入的课程编号信息，值不可以为空；参数 xs_bh[]的参数类型为字符串数组，该参数用于存放用户输入的学生编号信息，值不可以为空
//返回值：无
void __xiugai_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_bh[])
{    
	char cmd[1024];
    struct chengji_list list={0,0};
    struct __chengji *p;
	
	if(ban_bh==0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的班级编号为空！\r\n");
		exit(0);
	}
	else if(strlen(ban_bh)<0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的班级编号长度为0！\r\n");
		exit(0);
	}

	if(ke_bh==0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的课程编号为空！\r\n");
		exit(0);
	}
	else if(strlen(ke_bh)<0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的课程编号长度为0！\r\n");
		exit(0);
	}

	if(xs_bh==0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的学生编号为空！\r\n");
		exit(0);
	}
	else if(strlen(xs_bh)<0)
	{
		printf("__xiugai_ban_ke_cj报告错误：传入的学生编号长度为0！\r\n");
		exit(0);
	}

	//找到对应的记录
	if(read_chengji(&list,ke_bh,ban_bh)==0)
	{
		printf("无成绩数据，无法修改！\r\n");
		return ;
	}

	//调用函数得到一条学生成绩记录，存放在指针p里面
    p=get_chengji_by_xh(&list,xs_bh);

	//将原有信息显示给用户
	printf("原有成绩信息：\r\n");
	printf("\t学号：%s\r\n",p->xuehao);
	printf("\t姓名：%s\r\n",p->name);
	printf("\t平时成绩：%s\r\n",p->pingshi);
	printf("\t考试成绩：%s\r\n",p->kaoshi);
	printf("\t综合成绩：%s\r\n",p->zonghe);
	//询问用户是否继续修改
	do
	{
		printf("是否修改(Y/N)：");
		scanf("%s",cmd);
		if(strcmp(cmd,"y")==0)
		{
			break;
		}
		else if(strcmp(cmd,"Y")==0)
		{
			break;
		}
		else if(strcmp(cmd,"n")==0)
		{
			return;
		}
		else if(strcmp(cmd,"N")==0)
		{
			return;
		} 
	}while(1);
	
	//用户确认修改，开始交互
	printf("请输入平时成绩：");
	scanf("%s",p->pingshi);
	printf("请输入考试成绩：");
	scanf("%s",p->kaoshi);
	printf("请输入综合成绩：");
	scanf("%s",p->zonghe);

	//保存数据
	write_chengji(&list,ban_bh,ke_bh);
	//write_chengji(&list);
	//释放数据结构
	empty_chengji_list(&list);

}



/*
//让用户删除成绩
void __shanchu_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_xh[])
{
char cmd[1024];
struct chengji_list list={0,0};
struct __chengji *p;

if(ban_bh==0) 
{
printf("__shanchu_ban_ke_cj报告错误：班级不存在哦\r\n");
exit(0);
}

if(ke_bh==0) 
{
printf("__shanchu_ban_ke_cj报告错误：课程不存在哦\r\n");
exit(0);
}

if(xs_bh==0) 
{
printf("__shanchu_ban_ke_cj报告错误：学生不存在哦\r\n");
exit(0);
}


if(read_chengji(&list,"BJ20120101","KC201201")<=0)
{
printf("无数据!\r\n");
return;
}

if((p=getout_chengji_by_xh(&list,xs_xh))==null)
{
printf("找不到学号为%s的学生成绩!\r\n",xs_xh);
empty_chengji_list(&list);
return;
}

printf("学号\t姓名\t\t平时分\t\t考试分\t综合成绩\r\n");
printf("1\t");
disp_chengji(p);
printf("\r\n");

printf("是否确认删除该生成绩（Y/N）：");
scanf("%s",cmd);
if(strcmp(cmd,"y") ==0||strcmp(cmd,"yes")==0)
write_chengji(&list);

empty_chengji_list(&list);

}
*/
//功能描述：在屏幕上显示某班某学生的详细成绩信息
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空；参数 xs_bh[]的参数类型为字符串数组，该参数用于存放用户输入的学生编号信息，值不可以为空
//返回值：无
void __disp_ban_xs_cj(char ban_bh[],char xs_bh[])
{
	struct banke_list banke={null,null};
	struct chengji_list chengji={null,null};
	struct kecheng_list kecheng={null,null};
	struct banke_list_node *p;
	struct chengji_list_node *q;
	struct kecheng_list_node *k;
	int count=0;

	read_banke(&banke);
	read_ke(&kecheng);

	printf("序号\t学期\t科目\t平时分\t考试分\t综合成绩\r\n");
	for(p=banke.header;p!=null;p=p->next)
	{
		read_chengji(&chengji,ban_bh,p->banke->kbianhao);
		for(q=chengji.header;q!=null;q=q->next)
		{
			if(strcmp(q->chengji->xuehao,xs_bh)==0)
			{
				count++;
				for(k=kecheng.header;k!=null;k=k->next)
				{
					if(strcmp(k->kecheng->bianhao,p->banke->kbianhao)==0) 
					{
						printf("%d\t%s\t%s\t%s\t%s\t%s\r\n"
							,count
							,p->banke->xueqi
							,k->kecheng->mingcheng
							,q->chengji->pingshi
							,q->chengji->kaoshi
							,q->chengji->zonghe);
						break;
					}
				}
			}
		}
		empty_chengji_list(&chengji);
	}
	empty_banke_list(&banke);
	empty_ke_list(&kecheng);
	
}
