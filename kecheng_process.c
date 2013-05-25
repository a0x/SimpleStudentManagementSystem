#define  __kecheng_process_c__

#include "kecheng_data.h"
#include "kecheng_process.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//----------课程基本信息的处理------------

//功能描述：将kecheng.txt文件中的所有课程显示在界面上
//输入参数：无参数
//返回值：无
void __disp_all_ke()
{
	struct kecheng_list list={null,null};
	read_ke(&list);
	disp_ke_list(&list);
	empty_ke_list(&list);
}

//功能描述：显示一门课程详细情况
//输入参数：无参数
//返回值：无
void __disp_ke_bh(char kecheng_bh[])
{
	struct kecheng_list list={null,null};
	struct __kecheng *p;
	if(kecheng_bh==null)
	{
		printf("错误：课程号为空！\r\n");
		return;
	}
	if(read_ke(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((p=get_ke_by_bh(&list,kecheng_bh))==null)
	{
		printf("找不到编号为%s的班级!\r\n",kecheng_bh);
	}

	printf("序号\t课程编号\t\t课程名称\t\t学分\t简介\r\n");
	printf("1\t");
	disp_ke(p);
	printf("\r\n");
	empty_ke_list(&list);

}

//功能描述：根据课程编号删除一门课
//输入参数：字符数组（即课程编号），用户界面上输入要删除的课程编号
//返回值：无
void __shanchu_ke_bh(char ke_bh[])
{
    char cmd[1024];
	struct kecheng_list list={null,null};
	struct __kecheng *p;

	if(ke_bh==null) 
	{
		printf("__shanchu_ke_bh报告错误：课程编号为空\r\n");
		exit(0);
	}


	if(read_ke(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	if((p=getout_ke_by_bh(&list,ke_bh))==null)
	{
		printf("找不到编号为%s的课程!\r\n",ke_bh);
		empty_ke_list(&list);
		return;
	}
	
	printf("序号\t课程编号\t\t课程名称\t\t学分\t简介\r\n");
	printf("1\t");
	disp_ke(p);
	printf("\r\n");
	
	printf("是否确认删除该门课程（Y/N）：");
	scanf("%s",cmd);
	if(strcmp(cmd,"y") ==0||strcmp(cmd,"yes")==0)
		write_ke(&list);
	
	empty_ke_list(&list);

}
//功能描述：让用户完成增加一门课程的操作
//输入参数：无参数
//返回值：无

void __zengjia_ke()
{
   struct kecheng_list list={null,null};

   struct __kecheng *p=(struct __kecheng *)malloc(sizeof(struct __kecheng));
	if(p==null)
	{
		printf("__zengjia_ke报告错误：无法申请内存！\r\n");
		exit(0);
	}

	printf("增加课程：\r\n");
	printf("\t请输入课程编号：");
	scanf("%s",p->bianhao);
	printf("\t请输入课程名称：");
	scanf("%s",p->mingcheng);
	printf("\t请输入学分：");
	scanf("%s",p->xuefen);
	printf("\t请输入简介：");
	scanf("%s",p->jianjie);

	read_ke(&list);
	add_ke_to_list(&list,p);
	if(write_ke(&list)>0) printf("保存成功!\r\n");
	empty_ke_list(&list);
}

//功能描述：根据课程编号排序
//输入参数：无参数
//返回值：无
void __paixu_ke_bh()
{
    struct kecheng_list list={null,null};
	if(read_ke(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ke_bh(&list);
	write_ke(&list);
	empty_ke_list(&list);		
}
//功能描述：根据课程名称排序
//输入参数：无参数
//返回值：无
void __paixu_ke_mc()
{
    struct kecheng_list list={null,null};
	if(read_ke(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ke_mingcheng(&list);
	write_ke(&list);
	empty_ke_list(&list);	
}
//功能描述：根据课程学分排序
//输入参数：无参数
//返回值：无
void __paixu_ke_xf()
{   
	struct kecheng_list list={null,null};
	if(read_ke(&list)<=0)
	{
		printf("无数据!\r\n");
		return;
	}
	sort_ke_xuefen(&list);
	write_ke(&list);
	empty_ke_list(&list);
}



