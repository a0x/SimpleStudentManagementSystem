#ifndef __ke_h__
#define __ke_h__

//自定义结构体：代表课程
struct __kecheng 
{
	char bianhao[32];	//课程编号
	char mingcheng[32];	//课程名称
	char xuefen[32];	//学分
	char jianjie[32];	//简介
};

//课程链表中的节点
struct kecheng_list_node
{
	struct __kecheng * kecheng;			//节点数据部分，存储一个指向课程的指针
	struct kecheng_list_node * next;	//指向下一个节点
};

//课程链表
struct kecheng_list
{
	struct kecheng_list_node * header,* tail;//指向链表的第一个元素和最后一个元素。
};

#ifdef __ke_c__
	int read_ke(struct kecheng_list *list);
	int write_ke(struct kecheng_list *list);
	int sort_ke_bh(struct kecheng_list *list);
	int sort_ke_xuefen(struct kecheng_list *list);
	int sort_ke_mingcheng(struct kecheng_list *list);
	int disp_ke_list(struct kecheng_list *list);
	struct __kecheng * get_ke_by_bh(struct kecheng_list *list,char *bianhao);
	void disp_ke(struct __kecheng * p);
	struct kecheng_list * add_ke_to_list(struct kecheng_list *list,struct __kecheng *kecheng);
	int empty_ke_list(struct kecheng_list *list);
	struct __kecheng * getout_ke_by_bh(struct kecheng_list *list,char *bianhao);
#else
	extern int read_ke(struct kecheng_list *list);
	extern int write_ke(struct kecheng_list *list);
	extern int sort_ke_bh(struct kecheng_list *list);
    extern int sort_ke_mingcheng(struct kecheng_list *list);
	extern int sort_ke_xuefen(struct kecheng_list *list);
	extern int disp_ke_list(struct kecheng_list *list);
	extern struct __kecheng * get_ke_by_bh(struct kecheng_list *list,char *bianhao);
	extern void disp_ke(struct __kecheng * p);
	extern struct kecheng_list * add_ke_to_list(struct kecheng_list *list,struct __kecheng *kecheng);
	extern int empty_ke_list(struct kecheng_list *list);
	extern struct __kecheng * getout_ke_by_bh(struct kecheng_list *list,char *bianhao);
#endif

#endif
