#define __banke_process_c__

#include "ban_ke_data.h"
#include "ban_data.h"
#include "ban_ke_process.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "kecheng_data.h"
#include "kecheng_process.h"

//功能描述：根据班级编号ban_bh在屏幕上显示该班要上的课程
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空
//返回值：无
void __disp_ke_ban_bh(char ban_bh[])
{
	struct banke_list all={null,null};
	struct banke_list banke={null,null};
	struct banji_list banji={null,null};
	struct kecheng_list kecheng={null,null};

	if(read_banke(&all)<=0)
	{
		printf("无数据!\r\n");
		return;
	}

	if(read_ban(&banji)<=0)
	{
		printf("无数据!\r\n");
		return;
	}

	if(read_ke(&kecheng)<=0)
	{
		printf("无数据!\r\n");
		return;
	}

	//用班的编号过滤链表
	get_banke_by_bh(&banke,&all,ban_bh);

	disp_banke_list(&banke,&kecheng,&banji);

	empty_ke_list(&kecheng);
	empty_banke_list(&all);
	empty_banke_list(&banke);
	empty_ban_list(&banji);
}

//功能描述：调用相关的数据处理函数实现根据课程编号显示班级信息
//输入参数：参数 ke_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空
//返回值：无
void __disp_ban_ke_bh(char ke_bh[])
{
	struct banke_list all={null,null};
	struct banke_list banke={null,null};
	struct banji_list banji={null,null};
	struct kecheng_list kecheng={null,null};

	if(read_banke(&all)<=0)
	{
		printf("无数据!\r\n");
		return;
	}

	if(read_ban(&banji)<=0)
	{
		printf("无数据!\r\n");
		return;
	}

	if(read_ke(&kecheng)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	
	get_banke_by_kh(&banke,&all,ke_bh);

	disp_banke_list(&banke,&kecheng,&banji);

	empty_ke_list(&kecheng);
	empty_banke_list(&all);
	empty_banke_list(&banke);
	empty_ban_list(&banji);
}


//功能描述：让用户为ban_bh所给出的班级编号所对应的班级增设一门新课程，ke_bh代表所要增设的新课程的编号
//输入参数：参数ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空
//返回值：无
void __zengjia_ban_ke(char ban_bh[])
{
	struct banke_list list={null,null};
	struct __banke *p;
	p=(struct __banke *)malloc(sizeof(struct __banke));
	if(p==null)
	{
		printf("__zengjia_ban_ke报告错误：无法申请内存！\r\n");
		exit(0);
	}
	printf("为%s班增加新课程：\r\n",ban_bh);
	printf("\t请输入开设学期：");
	scanf("%s",p->xueqi);
	strcpy(p->bbianhao,ban_bh);
	printf("请输入课程编号：");
	scanf("%s",p->kbianhao);
	printf("\t请输入教师姓名：");
	scanf("%s",p->jiaoshi);
	read_banke(&list);
	add_banke_to_list(&list,p);
	if(write_banke(&list)>0) printf("保存成功!\r\n");
	empty_banke_list(&list);
}


//功能描述：让用户取消一个班级所开设的一个课程，ban_bh代表班级编号，ke_bh代表课程编号
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空，参数 ke_bh[]的参数类型为字符串数组，该参数用于存放用户输入的课程编号信息，值不可以为空
//返回值：无
void __quxiao_ban_ke(char ban_bh[],char ke_bh[])
{
	


	struct banke_list list={NULL,NULL};
    
    read_banke(&list);
    getout_banke_by_kh(&list,ban_bh,ke_bh);
	write_banke(&list);
}

//功能描述：让用户为给出的课程增设一个班级，ke_bh代表所要增设的新课程的编号
//输入参数：参数 ke_bh[]的参数类型为字符串数组，该参数用于存放用户输入的课程编号信息，值不可以为空
//返回值：无
void __zengjia_ke_ban(char ke_bh[])
{
	struct banke_list list={null,null};
	struct __banke *p;
	p=(struct __banke *)malloc(sizeof(struct __banke));
	if(p==null)
	{
		printf("__zengjia_ban_ke报告错误：无法申请内存！\r\n");
		exit(0);
	}
	printf("为%s课程增加班级：\r\n",ke_bh);
	printf("\t请输入开设学期：");
	scanf("%s",p->xueqi);
	strcpy(p->kbianhao,ke_bh);
	printf("请输入班级编号：");
	scanf("%s",p->bbianhao);
	printf("\t请输入教师姓名：");
	scanf("%s",p->jiaoshi);
	read_banke(&list);
	add_banke_to_list(&list,p);
	if(write_banke(&list)>0) printf("保存成功!\r\n");
	empty_banke_list(&list);
}

