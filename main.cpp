/*
 * 代码说明
 * 代码由 筱锋xiao_lfeng 编写
 * 其开发者由此互联网ICP备案作者编写：粤ICP备2022014822号
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct {
    int no; //8位学号
    char name[20]; //姓名
    int score; //成绩
} Student;

typedef struct Node {
    Student data; //数据域
    struct Node *next; //指针域
} LNode;

//初始化一个学生信息链表，根据指定学生个数，逐个输入学生信息
void CreatStuList(LNode *&list) {
    LNode *p, *temp;
    int intUser;
    printf("[INFO] 需要添加多少用户：");
    scanf_s("%d", &intUser);
    getchar();
    p = new LNode;
    list = p;
    for (int i = 0; i < intUser; ++i) {
        temp = new LNode;
        printf("[INSERT] 正在添加第 %d 个用户：\n", i + 1);
        printf("\t[INFO] 请输入学号：");
        scanf_s("%d",&temp->data.no);
        getchar();
        printf("\t[INFO] 请输入姓名：");
        fgets(temp->data.name, 20, stdin);
        printf("\t[INFO] 请输入分数：");
        scanf_s("%d", &temp->data.score);
        getchar();
        temp->next = nullptr;
        p->next = temp;
        p = p->next;
    }
    printf("\n");
}

//逐个显示学生表中所有学生的相关信息
void show(LNode *list) {
    int i;
    printf("[SELECT] 输出链表中所有用户信息：\n");
    for (i = 0; list->next != nullptr; i++) {
        list = list->next;
        printf("\t[INFO] 第 %d 个用户：\n", i+1);
        printf("\t\t学号：%d\n",list->data.no);
        printf("\t\t姓名：%s",list->data.name);
        printf("\t\t分数：%d\n",list->data.score);
    }
    printf("\n");
}

//根据姓名进行查找，若存在则输出此学生的信息，并返回逻辑序号，否则输出“无此人”并返回0；
int findByName(LNode *list, char name[]) {
    printf("[SELECT] 正在查找用户\n");
    for (int i = 0; list->next != nullptr; i++) {
        list = list->next;
        if (strcmp(list->data.name,name) == 0) {
            return i+1;
        }
    }
    return 0;
}

//输出逻辑序号pos相应的学生信息（学号，姓名，成绩）
int Position(LNode *list, int pos) {
    printf("[SELECT] 正在查询下标为 %d 的用户：\n", pos);
    for (int i = 0; i <= pos; ++i) {
        if (list->next == nullptr) {
            printf("[FAIL] 查询失败，没有对应下标用户");
            return 0;
        }
        if (i == pos) {
            printf("\t[SUCCESS] 查询成功：\n");
            printf("\t\t学号：%d\n",list->data.no);
            printf("\t\t姓名：%s",list->data.name);
            printf("\t\t分数：%d\n",list->data.score);
        }
        list = list->next;
    }
    return 1;
}

//给定一个学生信息，插入到表中指定的位置
int PInsert(LNode *&list, int pos) {
    LNode *temp,*p;
    p = list;
    for (int i = 0; i < pos; ++i) {
        if (p->next == nullptr) return 0;
        p = p->next;
    }
    temp = new LNode;
    printf("[INSERT] 正在添加用户：\n");
    printf("\t[INFO] 请输入学号：");
    scanf_s("%d",&temp->data.no);
    getchar();
    printf("\t[INFO] 请输入姓名：");
    fgets(temp->data.name, 20, stdin);
    printf("\t[INFO] 请输入分数：");
    scanf_s("%d", &temp->data.score);
    getchar();
    temp->next = p->next;
    p->next = temp;
    return 1;
}

// 删除指定位置的学生记录
int Delete(LNode *&list, int pos) {
    printf("[DELETE] 正在删除下标为 %d 的用户：\n", pos);
    LNode *p,*temp;
    p = list;
    for (int i = 0; i < pos-1; ++i) {
        if (p->next == nullptr) {
            printf("[FAIL] 删除失败，没有对应下标用户");
            return 0;
        }
        p = p->next;
    }
    temp = p->next;
    p->next = temp->next;
    free(temp);
    printf("[SUCCESS] 删除成功\n");
    return 1;
}

//统计表中学生人数
int Count(LNode *list) {
    int i;
    for (i = 0; list->next != nullptr; ++i) {
        list = list->next;
    }
    return i;
}

//释放链表
void DestroyList(LNode *&list) {
    LNode *temp,*p;
    temp = list;
    while (temp->next != nullptr) {
        p = temp->next;
        free(temp);
        temp = p;
    }
    free(temp);
}


int main() {
    // 创建链表节点
    char name[20];
    LNode *lNode;

    CreatStuList(lNode);

    printf("[SELECT] 请输入需要查询用户名：");
    fgets(name,20,stdin);
    int intName = findByName(lNode, name);
    if (intName > 0)
        printf("\t[SUCCESS] 查询成功（下标）：%d\n", intName);
    else
        printf("\t[FAIL] 没有对应用户\n");
    printf("\n");

    show(lNode);

    PInsert(lNode,2);
    printf("\n");

    show(lNode);

    printf("[SELECT] 总计学生人数 %d 人\n", Count(lNode));
    printf("\n");

    Position(lNode,2);
    printf("\n");

    Delete(lNode,3);
    printf("\n");

    show(lNode);

    DestroyList(lNode);
    system("pause");
}