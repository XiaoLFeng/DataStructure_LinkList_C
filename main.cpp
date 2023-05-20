/*
 * 代码说明
 * 代码由 筱锋xiao_lfeng 编写
 * 其开发者由此互联网ICP备案作者编写：粤ICP备2022014822号
 */

#include <cstdio>

typedef struct {
    char no[8]; //8位学号
    char name[20]; //姓名
    int score; //成绩
} Student;

typedef struct Node {
    Student data; //数据域
    struct Node *next; //指针域
} LNode;

//初始化一个学生信息链表，根据指定学生个数，逐个输入学生信息
void CreatStuList(LNode *&list) {
    list = new LNode;
}

//逐个显示学生表中所有学生的相关信息
void show(LNode *&list);

//根据姓名进行查找，若存在则输出此学生的信息，并返回逻辑序号，否则输出“无此人”并返回0；
int findByName(LNode *&list, char name[]);

//输出逻辑序号pos相应的学生信息（学号，姓名，成绩）
int Position(int pos, LNode *&list);

//给定一个学生信息，插入到表中指定的位置
int PInsert(int pos, LNode *&list, Student student);

// 删除指定位置的学生记录
int Delete(int pos, LNode *&list);

//统计表中学生人数
int Count(LNode *&list);

//释放链表
void DestroyList(LNode *&list);


int main() {
    // 创建链表节点
    LNode *lNode;
    CreatStuList(lNode);

}