#ifndef __kecheng_process_h__

	#define __kecheng_process_h__
	#ifdef __kecheng_process_c__
	
		#define null 0

		//----------课程基本信息的处理------------
		//显示所有课程
		void __disp_all_ke();
		//显示一门课程详细情况
		void __disp_ke_bh();
		//根据课程编号删除一门课
		void __shanchu_ke_bh(char ke_bh[]);
		//让用户完成增加一门课程的操作
		void __zengjia_ke();
		//根据课程编号排序
		void __paixu_ke_bh();
		//根据课程名称排序
		void __paixu_ke_mc();
		//根据课程学分排序
		void __paixu_ke_xf();
		void __disp_xs(char ban_bh[],char xs_bh[]);
	#else

		//----------课程基本信息的处理------------
		//显示所有课程
		extern void __disp_all_ke();
		//显示一门课程详细情况
		extern void __disp_ke_bh();
		//根据课程编号删除一门课
		extern void __shanchu_ke_bh(char ke_bh[]);
		//让用户完成增加一门课程的操作
		extern void __zengjia_ke();
		//根据课程编号排序
		extern void __paixu_ke_bh();
		//根据课程名称排序
		extern void __paixu_ke_mc();
		//根据课程学分排序
		extern void __paixu_ke_xf();
		extern void __disp_xs(char ban_bh[],char xs_bh[]);
	#endif
#endif 
