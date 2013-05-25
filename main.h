//防止头文件重复包含
#ifndef __main_h__ 
#define __main_h__

//定义界面状态，界面状态的控制与切换见word文档《人机交互控制.doc》


#define WELCOME			0
#define KECHENG			1
#define BANJI			2
#define KECHENGXINXI	3
#define BANJIXINXI		4
#define CHENGJI			5
#define XUESHENG		6
#define XUESHENG_CHENGJI 7
#define JIESHU			-1

#define null 0
//定义Example宏
#define Example(funcname) printf("调用教师演示代码：%s\r\n",#funcname)

//自定义的操作上下文结构体，用于记录用户在操作
//过程中所关心的“课程编号”、“班级编号”，“学生编号”
struct __context
{
	char kecheng_bh[32];
	char banji_bh[32];
	char xuesheng_bh[32];
};

//如果是main.c文件包含main.h的情况
#ifdef __main_c__

	struct __context context;	//在main.c中定义一个全局变量context，用于记录用户在使用软件
								//时所关心的“课程编号”、“班级编号”，“学生编号”
	//函数原型
	int welcome();
	int kecheng();
	int banji();
	int kechengxinxi();
	int banjixinxi();
	int chengji();
	int xuesheng();
	int xuesheng_chengji();
//如果是其他源程序包含main.h的情况
#else
	extern struct __context context; //其他源文件中使用context全局变量
#endif

//防止头文件重复包含结束
#endif 