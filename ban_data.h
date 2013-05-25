#ifndef __ban_h__
#define __ban_h__

//自定义结构体：代表班级
struct __banji 
{
	char bianhao[32];	//班级编号
	char zhuanye[32];	//专业
	char nianji[32];	//年级
	char banhao[32];	//班号
};

//班级链表中的节点
struct banji_list_node
{
	struct __banji * banji;			//节点数据部分，存储一个指向班级的指针
	struct banji_list_node * next;	//指向下一个节点
};

//班级链表
struct banji_list
{
	struct banji_list_node * header,* tail;//指向链表的第一个元素和最后一个元素。
};

#ifdef __ban_c__
	int read_ban(struct banji_list *list);
	int write_ban(struct banji_list *list);
	int sort_ban_bh(struct banji_list *list);
	int sort_ban_zy(struct banji_list *list);
	int sort_ban_nj(struct banji_list *list);
	int disp_ban_list(struct banji_list *list);
	struct __banji * get_ban_by_bh(struct banji_list *list,char *bianhao);
	void disp_ban(struct __banji * p);
	struct banji_list * add_ban_to_list(struct banji_list *list,struct __banji *banji);
	struct __banji * getout_ban_by_bh(struct banji_list *list,char *bianhao);
	int empty_ban_list(struct banji_list *list);
#else
	extern int read_ban(struct banji_list *list);
	extern int write_ban(struct banji_list *list);
	extern int sort_ban_bh(struct banji_list *list);
	extern int sort_ban_zy(struct banji_list *list);
	extern int sort_ban_nj(struct banji_list *list);
	extern int disp_ban_list(struct banji_list *list);
	extern struct __banji * get_ban_by_bh(struct banji_list *list,char *bianhao);
	extern void disp_ban(struct __banji * p);
	extern struct banji_list * add_ban_to_list(struct banji_list *list,struct __banji *banji);
	extern struct __banji * getout_ban_by_bh(struct banji_list *list,char *bianhao);
	extern int empty_ban_list(struct banji_list *list);
#endif

#endif
