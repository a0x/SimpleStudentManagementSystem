#ifndef __xuesheng_h__
#define __xuesheng_h__

//自定义结构体：代表学生
struct __xuesheng 
{
	char xuehao[32];	//学号
	char xingming[32];	//姓名
	char xingbie[32];	//性别
	char jiguan[32];   //籍贯
	char lianxifangshi[32];	//联系方式
};

//学生链表中的节点
struct xuesheng_list_node
{
	struct __xuesheng * xuesheng;			//节点数据部分，存储一个指向学生的指针
	struct xuesheng_list_node * next;	//指向下一个节点
};

//学生链表
struct xuesheng_list
{
	//指向链表的第一个元素和最后一个元素。
	struct xuesheng_list_node * header,* tail;	
};

#ifdef __xuesheng_c__
	int read_xuesheng(struct xuesheng_list *list,char bianhao[]);
	int write_xuesheng(struct xuesheng_list *list,char ban_bh[]);
	int sort_xuesheng_bh(struct xuesheng_list *list);
	int sort_xuesheng_zy(struct xuesheng_list *list);
	int disp_xuesheng_list(struct xuesheng_list *list);
	struct __xuesheng * get_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao);
	struct __xuesheng * getout_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao);
	void disp_xuesheng(struct __xuesheng * p);
	struct xuesheng_list * add_xuesheng_to_list(struct xuesheng_list *list,struct __xuesheng *xuesheng);
	int empty_xuesheng_list(struct xuesheng_list *list);
	char *get_xs_filename(char *filename,char *ban_bh);

#else
	extern int read_xuesheng(struct xuesheng_list *list,char bianhao[]);
	extern int write_xuesheng(struct xuesheng_list *list,char ban_bh[]);
	extern int sort_xuesheng_bh(struct xuesheng_list *list);
	extern int sort_xuesheng_zy(struct xuesheng_list *list);
	extern int disp_xuesheng_list(struct xuesheng_list *list);
	extern struct __xuesheng * get_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao);
	extern struct __xuesheng * getout_xuesheng_by_bh(struct xuesheng_list *list,char *xuehao);
	extern void disp_xuesheng(struct __xuesheng * p);
	extern struct xuesheng_list * add_xuesheng_to_list(struct xuesheng_list *list,struct __xuesheng *xuesheng);
	extern int empty_xuesheng_list(struct xuesheng_list *list);
	extern char *get_xs_filename(char *filename,char *ban_bh);

#endif

#endif
