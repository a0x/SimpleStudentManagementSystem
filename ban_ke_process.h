#ifndef __ban_ke_process_h__

	#define __ban_ke_process_h__
	#ifdef __banke_process_c__
	
		#define null 0
		//根据班级编号ban_bh在屏幕上显示该班要上的课程
		void __disp_ke_ban_bh(char ban_bh[]);
		//根据课程编号ke_bh在屏幕上显示要上该课程的班
		void __disp_ban_ke_bh(char ke_bh[]);
		//让用户为ban_bh所给出的班级编号所对应的班级增设一门新课程
		void __zengjia_ban_ke(char ban_bh[]);
		//让用户取消一个班级所开设的一个课程，ban_bh代表班级编号，ke_bh代表课程编号
		void __quxiao_ban_ke(char ban_bh[],char ke_bh[]);
		//让用户为给出的课程增设一个班级，ke_bh代表所要增设的新课程的编
		void __zengjia_ke_ban(char ke_bh[]);
	#else
		extern void __disp_ke_ban_bh(char ban_bh[]);
		extern void __disp_ban_ke_bh(char ke_bh[]);
		extern void __zengjia_ban_ke(char ban_bh[]);
		extern void __quxiao_ban_ke(char ban_bh[],char ke_bh[]);
		extern void __zengjia_ke_ban(char ke_bh[]);
	#endif
#endif 
