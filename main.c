#define __main_c__

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "..\\main.h"
#include "..\\ban_ke_process.h"
#include "..\\ban_process.h"
#include "..\\kecheng_process.h"
#include "..\\xuesheng_process.h"
#include "..\\chengji_process.h"
/*
	main函数主要任务是处理用户操作，根据用户操作切换程序状态、调用
	不同的函数完成特定的任务
*/
void main()
{
	
	int ui_state;//存储界面所处于的状态

	//欢迎用户
	ui_state=welcome();


	while(ui_state!=JIESHU)
	{
		switch(ui_state)
		{
		case WELCOME:
			ui_state=welcome();
			break;
		case KECHENG:
			ui_state=kecheng();
			break;
		case BANJI:
			ui_state=banji(); 
			break;
		case KECHENGXINXI:
			ui_state=kechengxinxi();
			break;
		case BANJIXINXI:
			ui_state=banjixinxi();
			break;
		case CHENGJI:
			ui_state=chengji();
			break;
		case XUESHENG:
			ui_state=xuesheng();
			break;
		case XUESHENG_CHENGJI:
			ui_state=xuesheng_chengji();
			break;
		default:
			ui_state=JIESHU;
		}
	}

	//打印结束信息
	printf("感谢您的使用，再见！\r\n");
	
}
//进入欢迎界面
int welcome()
{
	char cmd[1024];//存储用户输入的命令
	//在屏幕上给出欢迎信息
	printf("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
	printf("              -------------------------------------------------\r\n");
	printf("              |                                               |\r\n");
	printf("              |           欢迎访问学生成绩管理系统            |\r\n");
	printf("              |     作者：张三；班级：Java01；学号：00000     |\r\n");
	printf("              |                                               |\r\n");
	printf("              -------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入kecheng进入课程管理界面，输入banji进入班级管理界面，输入jieshu退出应用程序。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"kecheng")==0) 
		{
			return KECHENG;
		}
		else if(strcmp(cmd,"banji")==0)
		{
			return BANJI;
		}
		else if(strcmp(cmd,"jieshu")==0)
		{
			return JIESHU;
		}
		return WELCOME;
	}while(1);
}

//进入课程列表界面
int kecheng()
{
	char cmd[1024],paixu[1024];
	printf("------------------------所有课程列表-------------------------\r\n");
	//按照序号 课程编号 课程名称 学分 课程简介 的方式列出
	__disp_all_ke();
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia添加课程，");
		printf("输入shanchu删除课程，");
		printf("输入paixu进行排序，");
		printf("输入kechengxinxi查看课程详细信息。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{
			//调用增加课程的函数
			__zengjia_ke();
		}
		else if(strcmp(cmd,"shanchu")==0)
		{
			//调用删除课程的函数
			printf("请输入要删除的课程号：");
			scanf("%s",context.kecheng_bh);
			__shanchu_ke_bh(context.kecheng_bh);
		}
		else if(strcmp(cmd,"paixu")==0)
		{
		  do
			{
				printf("操作提示：输入bh按照课程编号排序，输入xf按照专业排序，输入mc按照年级排序，输入后请按回车键：");
				scanf("%s",paixu);
				if(strcmp(paixu,"bh")==0)
				{
					__paixu_ke_bh();
					break;
				}
				else if(strcmp(paixu,"xf")==0)
				{
					__paixu_ke_xf();
					break;
				}
				else if(strcmp(paixu,"mc")==0)
				{
					__paixu_ke_mc();
					break;
				}
				
			}while(1);
			//调用排序课程的函数
		}
		else if(strcmp(cmd,"kechengxinxi")==0)
		{
			return KECHENGXINXI;
		}
		return KECHENG;
		
	}while(1);
}
//进入班级列表界面
int banji()
{
	char cmd[1024],paixu[1024];
	printf("------------------------所有班级列表-------------------------\r\n");
	//按 序号 班级编号 专业 年级 班号 的方式列出班级
	__disp_all_ban();
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia增加班级，");
		printf("输入shanchu删除班级，");
		printf("输入paixu对班级列表进行排序，");
		printf("输入banjixinxi查看班级详细信息。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{
			__zengjia_ban();
			return BANJI;
		}
		else if(strcmp(cmd,"shanchu")==0)
		{
			printf("请输入班级编号：");
			scanf("%s",context.banji_bh);
			__shanchu_ban_bh(context.banji_bh);
		}
		else if(strcmp(cmd,"paixu")==0)
		{
			do
			{
				printf("操作提示：输入bh按照班级编号排序，输入zy按照专业排序，输入nj按照年级排序，输入后请按回车键：");
				scanf("%s",paixu);
				if(strcmp(paixu,"bh")==0)
				{
					__paixu_ban_bh();
					break;
				}
				else if(strcmp(paixu,"zy")==0)
				{
					__paixu_ban_zy();
					break;
				}
				else if(strcmp(paixu,"nj")==0)
				{
					__paixu_ban_nj();
					break;
				}
				
			}while(1);
		}
		else if(strcmp(cmd,"banjixinxi")==0)
		{
			
     		printf("请输入班级编号:");
    		scanf("%s",context.banji_bh);
			return BANJIXINXI;//查看班级详细信息
		}
		return BANJI;
	}while(1);
}
//进入课程信息界面
int kechengxinxi()
{
	char cmd[1024];
	if(strlen(context.kecheng_bh)==0)
	{
		printf("输入课程编号：");
		scanf("%s",context.kecheng_bh);
	}
	context.banji_bh[0]='\0';
    
	printf("------------------------课程信息列表-------------------------\r\n");
	//按 序号 课程号 课程名称 学分 的方式列出课程

	__disp_ke_bh(context.kecheng_bh);

	printf("------------------------上-课--班-级-------------------------\r\n");
	//printf("序号\t学期\t\t教师\t班级编号\t专业\t\t年级\t班号\r\n");
	__disp_ban_ke_bh(context.kecheng_bh);
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia增加授课班级，");
		printf("输入shanchu删除授课班级，");
		printf("输入chengji查看课程成绩表。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{

           __zengjia_ke_ban(context.kecheng_bh);
		   return KECHENGXINXI;
		
		}
		else if(strcmp(cmd,"shancu")==0)
		{
			
			printf("请输入班号:\r\n");
			scanf("%s",context.banji_bh);
			__quxiao_ban_ke(context.banji_bh,context.kecheng_bh);
			return KECHENGXINXI;

		}


		else if(strcmp(cmd,"chengji")==0)
		{
			return CHENGJI;//查看一个班某个课程的成绩单
		}
		return KECHENGXINXI;	
	}while(1);
}
//进入班级信息界面
int banjixinxi()
{
	char cmd[1024];
	//检查参数是否足够
	if(strlen(context.banji_bh)==0)
	{
		printf("请输入班级编号：");
		scanf("%s",context.banji_bh);
	}
	context.kecheng_bh[0]='\0';

	printf("------------------------班级详细信息-------------------------\r\n");
	__disp_ban_bh(context.banji_bh);
	printf("------------------------开-设--课-程-------------------------\r\n");
    __disp_ke_ban_bh(context.banji_bh);
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia增开课程，");
		printf("输入quxiao删除课程，");
		printf("输入chengji处理课程成绩，");
		printf("输入xuesheng处理学生信息。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{
			__zengjia_ban_ke(context.banji_bh);
		}
		else if(strcmp(cmd,"quxiao")==0)
		{
			//取消课程
			//检查参数是否足够
			if(strlen(context.kecheng_bh )==0)
			{
				printf("请输入课程编号：");
				scanf("%s",context.kecheng_bh);
			}
			__quxiao_ban_ke(context.banji_bh,context.kecheng_bh);
			
		}
		else if(strcmp(cmd,"chengji")==0)
		{
			return CHENGJI;//进入班级某课程成绩表
		}
		else if(strcmp(cmd,"xuesheng")==0)
		{
			return XUESHENG;//进入学生管理界面
		}
		return BANJIXINXI;
	}while(1);
}

//进入班级某课程成绩界面
int chengji()
{
	char cmd[1024];


	if(strlen(context.banji_bh)==0)
	{
		printf("请输入班级编号：");
		scanf("%s",context.banji_bh);
	}
	if(strlen(context.kecheng_bh )==0)
	{
		printf("请输入课程编号：");
		scanf("%s",context.kecheng_bh);
	}
	
	printf("------------------------班级详细信息-------------------------\r\n");
	__disp_ban_bh(context.banji_bh);
	printf("------------------------课程信息列表-------------------------\r\n");
	__disp_ke_bh(context.kecheng_bh);
	printf("-------------------------全班成绩表--------------------------\r\n");
	__disp_ban_ke_cj(context.banji_bh,context.kecheng_bh);
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia增加成绩，");
		printf("输入xiugai修改成绩，");
		printf("输入paixu进行排序，");
		printf("输入xuesheng查看学生其他课程成绩。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{
			__zengjia_ban_ke_cj(context.banji_bh,context.kecheng_bh);
		}
		else if(strcmp(cmd,"xiugai")==0)
		{
			printf("请输入学号：");
			scanf("%s",&context.xuesheng_bh);

		    __xiugai_ban_ke_cj(context.banji_bh,context.kecheng_bh,context.xuesheng_bh);
        
		}


		else if(strcmp(cmd,"paixu")==0)
		{
			printf("暂未实现");
		}
		else if(strcmp(cmd,"xuesheng")==0)
		{
			return XUESHENG_CHENGJI;
		}
		return CHENGJI;
	}while(1);
}

//进入学生列表界面
int xuesheng()
{
	char cmd[1024];
	
	printf("-----------------------全班的学生列表--------------------\r\n");
	//按 序号 班级编号 专业 年级 班号 的方式列出班级
	__disp_xs_ban_bh(context.banji_bh);

	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("输入zengjia添加学生信息，");
		printf("输入shanchu删除学生信息，");
		printf("输入xiugai修改学生信息，");
		printf("输入chengji显示一个学生的成绩单，");
		printf("输入suoyou显示全班学生的成绩单。\r\n");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		else if(strcmp(cmd,"zengjia")==0)
		{
			//增加学生
			__zengjia_ban_xs(context.banji_bh);
		}
		else if(strcmp(cmd,"shanchu")==0)
		{
			//删除学生记录
			printf("请输入要删除的学生学号：");
			scanf("%s",context.xuesheng_bh);
			__shanchu_ban_xs(context.banji_bh,context.xuesheng_bh);
		}
		else if(strcmp(cmd,"xiugai")==0)
		{
			printf("请输入要修改的学生学号：");
			scanf("%s",context.xuesheng_bh);
			__xiugai_ban_xs(context.banji_bh,context.xuesheng_bh);
		}
		else if(strcmp(cmd,"chengji")==0)
		{
			return XUESHENG_CHENGJI;
		}
		else if(strcmp(cmd,"suoyou")==0)
		{
			return CHENGJI;
		}
		return XUESHENG;
	}while(1);
}
//进入学生成绩界面
int xuesheng_chengji()
{
	char cmd[1024];
	printf("请输入学生学号：");
	scanf("%s",context.xuesheng_bh);
	printf("------------------------学生详细信息-------------------------\r\n");
	__disp_xs(context.banji_bh,context.xuesheng_bh);
	printf("------------------------成绩详细信息-------------------------\r\n");
	__disp_ban_xs_cj(context.banji_bh,context.xuesheng_bh);
	printf("-------------------------------------------------------------\r\n");
	do
	{
		printf("操作提示：输入welcome回到欢迎界面，");
		printf("请输入命令后按回车键：");
		scanf("%s",cmd);
		if(strcmp(cmd,"welcome")==0)
		{
			return WELCOME;
		}
		return XUESHENG_CHENGJI;
	}while(1);
}