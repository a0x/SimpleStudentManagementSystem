#ifndef __chengji_process_h__

	#define __chengji_process_h__
 
   #ifdef __chengji_process_c__
	#define null 0
	//在屏幕上显示该班所有学生的一门课程的成绩
	void __disp_ban_ke_cj(char ban_bh[],char ke_bh[]);
	//让用户完成一次成绩录入
	void __zengjia_ban_ke_cj(char ban_bh[],char ke_bh[]);
	//让用户修改成绩
	void __xiugai_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_bh[]);
	//让用户删除成绩
	void __shanchu_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_bh[]);
	//在屏幕上显示某班某学生的详细成绩信息
	void __disp_ban_xs_cj(char ban_bh[],char xs_bh[]);
  #else
    //在屏幕上显示该班所有学生的一门课程的成绩
	extern void __disp_ban_ke_cj(char ban_bh[],char ke_bh[]);
	//让用户完成一次成绩录入
	extern void __zengjia_ban_ke_cj(char ban_bh[],char ke_bh[]);
	//让用户修改成绩
	extern void __xiugai_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_bh[]);
	//让用户删除成绩
	extern void __shanchu_ban_ke_cj(char ban_bh[],char ke_bh[],char xs_bh[]);
	//在屏幕上显示某班某学生的详细成绩信息
	extern void __disp_ban_xs_cj(char ban_bh[],char xs_bh[]);
  #endif
#endif
