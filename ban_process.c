#define __ban_process_c__

#include "ban_data.h"
#include "ban_process.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//----------班级基本信息的处理------------


//功能描述：调用相关的数据处理函数实现显示ban.txt中所有班级信息
//输入参数：本函数无参数
//返回值：无
void __disp_all_ban()
{
	struct banji_list list={null,null};
	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	disp_ban_list(&list);
	empty_ban_list(&list);
}

//功能描述：根据班级编号显示该班的信息
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空
//返回值：无
void __disp_ban_bh(char ban_bh[])
{
	struct banji_list list={null,null};
	struct __banji *p;
	if(ban_bh==null)
	{
		printf("错误：班号为空！\r\n");
		return;
	}
	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((p=get_ban_by_bh(&list,ban_bh))==null)
	{
		printf("找不到编号为%s的班级!\r\n",ban_bh);
	}
	else
	{
		printf("序号\t编号\t\t专业\t\t年级\t班号\r\n");
		printf("1\t");
		disp_ban(p);
		printf("\r\n");
	}
	empty_ban_list(&list);
}

//功能描述：让用户在屏幕上输入信息，增加一个班
//输入参数：本函数无参数
//返回值：无
void __zengjia_ban()
{
	struct banji_list list={null,null};
	
	struct __banji *p=(struct __banji *)malloc(sizeof(struct __banji));
	if(p==null)
	{
		printf("__zengjia_ban报告错误：无法申请内存！\r\n");
		exit(0);
	}

	printf("增加班级：\r\n");
	printf("\t请输入班级编号：");
	scanf("%s",p->bianhao);
	printf("\t请输入班级专业：");
	scanf("%s",p->zhuanye);
	printf("\t请输入班级年级：");
	scanf("%s",p->nianji);
	printf("\t请输入班级号：");
	scanf("%s",p->banhao);

	read_ban(&list);
	add_ban_to_list(&list,p);
	if(write_ban(&list)>0) printf("保存成功!\r\n");
	empty_ban_list(&list);
}

//功能描述：根据班级号删除指定班级的信息
//输入参数：参数 ban_bh[]的参数类型为字符串数组，该参数用于存放用户输入的班级编号信息，值不可以为空
//返回值：无
void __shanchu_ban_bh(char ban_bh[])
{
	char cmd[1024];
	struct banji_list list={null,null};
	struct __banji *p;

	if(ban_bh==null) 
	{
		printf("__shanchu_ban_bh报告错误：班级编号为空\r\n");
		exit(0);
	}


	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((p=getout_ban_by_bh(&list,ban_bh))==null)
	{
		printf("找不到编号为%s的班级!\r\n",ban_bh);
		empty_ban_list(&list);
		return;
	}

	
	printf("是否确认删除该班（Y/N）：");
	scanf("%s",cmd);
	if(strcmp(cmd,"y") ==0||strcmp(cmd,"yes")==0)
		write_ban(&list);
	
	empty_ban_list(&list);

}
//功能描述：根据编号对班级进行排序
//输入参数：本函数无参数
//返回值：无
void __paixu_ban_bh()
{
	struct banji_list list={null,null};
	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ban_bh(&list);
	write_ban(&list);
	empty_ban_list(&list);
}
//功能描述：根据专业对班级进行排序
//输入参数：本函数无参数
//返回值：无
void __paixu_ban_zy()
{
	struct banji_list list={null,null};
	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ban_zy(&list);
	write_ban(&list);
	empty_ban_list(&list);
}
//功能描述：根据年级对班级进行排序
//输入参数：本函数无参数
//返回值：无
void __paixu_ban_nj()
{
	struct banji_list list={null,null};
	if(read_ban(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ban_nj(&list);
	write_ban(&list);
	empty_ban_list(&list);
}
