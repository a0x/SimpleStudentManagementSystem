#ifndef __chengji_data_h__
#define __chengji_data_h__



//自定义结构体：代表班级
struct __chengji 
{    
	char xuehao[32];	//学号
	char name[32];	//姓名
	char pingshi[32];	//平时分
	char kaoshi[32];	//考试分
	char zonghe[32];	//综合成绩
};

//班级链表中的节点
struct chengji_list_node
{
	struct __chengji * chengji;			//节点数据部分，存储一个指向班级的指针
	struct chengji_list_node * next;	//指向下一个节点
};

//班级链表
struct chengji_list
{
	struct chengji_list_node * header,* tail;//指向链表的第一个元素和最后一个元素。
};

#ifdef __chengji_data_c__
	#define null 0
	int read_chengji(struct chengji_list *list,char ke_bh[],char ban_bh[]);
	int write_chengji(struct chengji_list *list,char ke_bh[],char ban_bh[]);
	int sort_chengji_xh(struct chengji_list *list);
	int sort_chengji_zhcj(struct chengji_list *list);
	int disp_chengji_list(struct chengji_list *list);
	struct __chengji * get_chengji_by_bh(struct chengji_list *list,char *xuehao);
	struct __chengji * get_chengji_by_xh(struct chengji_list *list,char *xuehao);
	void disp_chengji(struct __chengji * p);
	struct chengji_list * add_chengji_to_list(struct chengji_list *list,struct __chengji *chengji);
	int empty_chengji_list(struct chengji_list *list);
	char *get_ke_ban_filename(char *filename,char *ke_bh,char *ban_bh);
#else
	extern int read_chengji(struct chengji_list *list,char ke_bh[],char ban_bh[]);
	extern int write_chengji(struct chengji_list *list,char ke_bh[],char ban_bh[]);
	extern int sort_chengji_bh(struct chengji_list *list);
	extern int sort_chengji_zy(struct chengji_list *list);
	extern int disp_chengji_list(struct chengji_list *list);
	extern struct __chengji * get_ban_by_bh(struct chengji_list *list,char *bianhao);
	extern struct __chengji * get_chengji_by_xh(struct chengji_list *list,char *xuehao);
	extern void disp_chengji(struct __chengji * p);
	extern struct chengji_list * add_chengji_to_list(struct chengji_list *list,struct __chengji *banji);
	extern int empty_chengji_list(struct chengji_list *list);
	extern char *get_ke_ban_filename(char *filename,char *ke_bh,char *ban_bh);
#endif

#endif
