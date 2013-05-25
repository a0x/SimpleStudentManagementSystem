#define __xuesheng_procss_c__

#include "xuesheng_data.h"
#include "xuesheng_process.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

//----------处理班级中的学生信息----------
//功能描述：根据班级编号在屏幕上显示该班所有学生
//输入参数：参数char bianhao[] 类型为char,用于处理班级编号
//返回值：无
void __disp_xs_ban_bh(char bianhao[])
{
	struct xuesheng_list list={0,0};
	read_xuesheng(&list,bianhao);
	disp_xuesheng_list(&list);
	empty_xuesheng_list(&list);
}

//功能描述：根据班级编号和学生编号在屏幕上显示学生
//输入参数：参数ban_bh[]是字符串数组参数ban_bh[]：里面存储班级的编号信息，指向一个链表，值不能为null。参数xs_bh[]：是一个字符串，里面存储学号信息，指向一个链表，值不能为null
//返回值：如果函数运行成功，则ban_bh[]里面存储着生成的文件名，返回ban_bh[]，否则返回null

void __disp_xs(char ban_bh[],char xs_bh[])
{
	struct xuesheng_list list={0,0};
	struct __xuesheng *xs;
	read_xuesheng(&list,ban_bh);
	xs=get_xuesheng_by_bh(&list,xs_bh);
	if(xs!=null)
	{
		printf("学号\t姓名\t性别\t机关\t联系方式\r\n");
		disp_xuesheng(xs);
		printf("\r\n");
	}
	empty_xuesheng_list(&list);
}

//功能描述：让用户完成在ban_bh所对应的班级中增加一个学生信息的操作
//输入参数：参数：char ban_bh[] 类型： char用于为增加学生信息提供班级编号信息
//返回值：无
void __zengjia_ban_xs(char ban_bh[])
{
	struct xuesheng_list list={0,0};	
	struct __xuesheng *p=(struct __xuesheng *)malloc(sizeof(struct __xuesheng));
	if(!p)
	{
		printf("__zengjia_ban_xs报告错误：无法申请内存！\r\n");
		exit(0);
	}
	printf("增加学生：\r\n");
	printf("\t请输入学生学号：");
	scanf("%s",p->xuehao);
	printf("\t请输入学生姓名：");
	scanf("%s",p->xingming);
	printf("\t请输入学生性别：");
	scanf("%s",p->xingbie);
	printf("\t请输入学生籍贯：");
	scanf("%s",p->jiguan);
	printf("\t请输入学生联系方式：");
	scanf("%s",p->lianxifangshi);
	read_xuesheng(&list,ban_bh);
	add_xuesheng_to_list(&list,p);
	if(write_xuesheng(&list,ban_bh)>0) printf("保存成功!\r\n");
	empty_xuesheng_list(&list);
}

//功能描述：让用户完成删除一个班的一个学生的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
//输入参数：参数char ban_bh[] ，char xs_bh[]用于存放班级编号及学生编号
//返回值：无
void __shanchu_ban_xs(char ban_bh[],char xs_bh[])
{
	char cmd[1024];
	struct xuesheng_list list={0,0};
	struct __xuesheng *p;

	if(!ban_bh) 
	{
		printf("__shanchu_ban_xs报告错误：班级为空\r\n");
		exit(0);
	}

	if(!xs_bh) 
	{
		printf("__shanchu_ban_xs报告错误：学生学号为空\r\n");
		exit(0);
	}


	if(read_xuesheng(&list,ban_bh)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((p=getout_xuesheng_by_bh(&list,xs_bh)) == 0)
	{
		printf("找不到编号为%s的班级!\r\n",ban_bh);
		empty_xuesheng_list(&list);
		return;
	}
	
	printf("序号\t学号\t\t姓名\t\t性别\t\t籍贯\t联系方式\r\n");
	printf("1\t");
	disp_xuesheng(p);
	printf("\r\n");
	
	printf("是否确认删除该班（Y/N）：");
	scanf("%s",cmd);
	if(strcmp(cmd,"y") ==0 || strcmp(cmd,"yes")==0)
		write_xuesheng(&list,ban_bh);
	
	empty_xuesheng_list(&list);

}


//功能描述：让用户完成修改一个班的一个学生信息的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
//输入参数：参数：char ban_bh[],char xs_bh[] 用于存放班级编号及学生编号信息
//返回值：无
void __xiugai_ban_xs(char ban_bh[],char xs_bh[])
{
	struct xuesheng_list list={0,0};
	struct __xuesheng *pjian;
	struct __xuesheng *pzeng=(struct __xuesheng *)malloc(sizeof(struct __xuesheng));

	if(!ban_bh) 
	{
		printf("__shanchu_ban_xs报告错误：班级为空\r\n");
		exit(0);
	}

	if(!xs_bh) 
	{
		printf("__shanchu_ban_xs报告错误：学生学号为空\r\n");
		exit(0);
	}


	if(read_xuesheng(&list,ban_bh)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((pjian=get_xuesheng_by_bh(&list,xs_bh)) == 0)
	{
		printf("找不到编号为%s的班级!\r\n",ban_bh);
		empty_xuesheng_list(&list);
		return;
	}
	
	printf("序号\t学号\t\t姓名\t\t性别\t\t籍贯\t联系方式\r\n");
	printf("1\t");
	disp_xuesheng(pjian);
	printf("\r\n");
	
	printf("修改学生：\r\n");

	printf("\t请输入学生学号：");
	scanf("%s",pjian->xuehao);
	printf("\t请输入学生姓名：");
	scanf("%s",pjian->xingming);
	printf("\t请输入学生性别：");
	scanf("%s",pjian->xingbie);
	printf("\t请输入学生籍贯：");
	scanf("%s",pjian->jiguan);
	printf("\t请输入学生联系方式：");
	scanf("%s",pjian->lianxifangshi);


	if(write_xuesheng(&list,ban_bh)>0)
		printf("保存成功！\r\n");
	else
		printf("保存不成功！\r\n");

	
	empty_xuesheng_list(&list);

 }
