#ifndef __banke_h__
#define __banke_h__

//自定义结构体：代表班级
struct __banke 
{
	char xueqi[32];	//学期
	char bbianhao[32];	//班级编号
	char kbianhao[32];	//课程编号
	char jiaoshi[32];	//教师
};

//班课链表中的节点
struct banke_list_node
{
	struct __banke * banke;			//节点数据部分，存储一个指向班级的指针
	struct banke_list_node * next;	//指向下一个节点
};

//班级链表
struct banke_list
{
	struct banke_list_node * header,* tail;//指向链表的第一个元素和最后一个元素。
};

#ifdef __banke_c__
	int read_banke(struct banke_list *list);
	struct banke_list * add_banke_to_list(struct banke_list *list,struct __banke *banke);
	int write_banke(struct banke_list *list);
	int empty_banke_list(struct banke_list *list);
	struct banke_list * get_banke_by_bh(struct banke_list *dest_list,struct banke_list *src_list,char *bianhao);
	struct banke_list * get_banke_by_kh(struct banke_list *dest_list,struct banke_list *src_list,char *ke_bh);
	int disp_banke_list(struct banke_list *banke,struct kecheng_list *kecheng,struct banji_list *banji);
	struct __banke * getout_banke_by_kh(struct banke_list *list,char *ban_bh,char *ke_bh);
#else
	extern int read_banke(struct banke_list *list);
	extern struct banke_list * add_banke_to_list(struct banke_list *list,struct __banke *banke);
	extern int write_banke(struct banke_list *list);
	extern int empty_banke_list(struct banke_list *list);
	extern struct banke_list * get_banke_by_bh(struct banke_list *dest_list,struct banke_list *src_list,char *bianhao);
	extern struct banke_list * get_banke_by_kh(struct banke_list *dest_list,struct banke_list *src_list,char *ke_bh);
	extern int disp_banke_list(struct banke_list *banke,struct kecheng_list *kecheng,struct banji_list *banji);
	extern struct __banke * getout_banke_by_kh(struct banke_list *list,char *ban_bh,char *ke_bh);

#endif

#endif
