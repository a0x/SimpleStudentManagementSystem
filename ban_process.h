#ifndef __ban_process_h__

	#define __ban_process_h__
	#ifdef __ban_process_c__
	
		#define null 0
		//显示所有班级信息
		void __disp_all_ban();
		//根据班级编号显示该班的信息
		void __disp_ban_bh(char ban_bh[]);
		//让用户在屏幕上输入信息，增加一个班
		void __zengjia_ban();
		//根据班级号删除指定班级的信息
		void __shanchu_ban_bh(char ban_bh[]);
		//根据编号对班级进行排序
		void __paixu_ban_bh();
		//根据专业对班级进行排序
		void __paixu_ban_zy();
		//根据年级对班级进行排序
		void __paixu_ban_nj();

	#else

		//显示所有班级信息
		extern void __disp_all_ban();
		//根据班级编号显示该班的信息
		extern void __disp_ban_bh(char ban_bh[]);
		//让用户在屏幕上输入信息，增加一个班
		extern void __zengjia_ban();
		//根据班级号删除指定班级的信息
		extern void __shanchu_ban_bh(char ban_bh[]);
		//根据编号对班级进行排序
		extern void __paixu_ban_bh();
		//根据专业对班级进行排序
		extern void __paixu_ban_zy();
		//根据年级对班级进行排序
		extern void __paixu_ban_nj();

	#endif
#endif 
