#ifndef __xuesheng_procss_h__
#define __xuesheng_procss_h__
	#ifdef  __xuesheng_procss_c__

		#define null 0
		//根据班级编号在屏幕上显示该班所有学生
		void __disp_xs_ban_bh(char bianhao[]);
		//让用户完成在ban_bh所对应的班级中增加一个学生信息的操作
		void __zengjia_ban_xs(char ban_bh[]);
		//让用户完成删除一个班的一个学生的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
		void __shanchu_ban_xs(char ban_bh[],char xs_bh[]);
		//让用户完成修改一个班的一个学生信息的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
		void __xiugai_ban_xs(char ban_bh[],char xs_bh[]);
	#else
		//根据班级编号在屏幕上显示该班所有学生
		extern void __disp_xs_ban_bh(char bianhao[]);
		//让用户完成在ban_bh所对应的班级中增加一个学生信息的操作
		extern void __zengjia_ban_xs(char ban_bh[]);
		//让用户完成删除一个班的一个学生的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
		extern void __shanchu_ban_xs(char ban_bh[],char xs_bh[]);
		//让用户完成修改一个班的一个学生信息的操作，其中ban_bh代表班级编号，xs_bh代表学生学号
		extern void __xiugai_ban_xs(char ban_bh[],char xs_bh[]);
	#endif
#endif
