/*
 * ����˵��
 * ������ ���xiao_lfeng ��д
 * �俪�����ɴ˻�����ICP�������߱�д����ICP��2022014822��
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct {
    int no; //8λѧ��
    char name[20]; //����
    int score; //�ɼ�
} Student;

typedef struct Node {
    Student data; //������
    struct Node *next; //ָ����
} LNode;

//��ʼ��һ��ѧ����Ϣ��������ָ��ѧ���������������ѧ����Ϣ
void CreatStuList(LNode *&list) {
    LNode *p, *temp;
    int intUser;
    printf("[INFO] ��Ҫ��Ӷ����û���");
    scanf_s("%d", &intUser);
    getchar();
    p = new LNode;
    list = p;
    for (int i = 0; i < intUser; ++i) {
        temp = new LNode;
        printf("[INSERT] ������ӵ� %d ���û���\n", i + 1);
        printf("\t[INFO] ������ѧ�ţ�");
        scanf_s("%d",&temp->data.no);
        getchar();
        printf("\t[INFO] ������������");
        fgets(temp->data.name, 20, stdin);
        printf("\t[INFO] �����������");
        scanf_s("%d", &temp->data.score);
        getchar();
        temp->next = nullptr;
        p->next = temp;
        p = p->next;
    }
    printf("\n");
}

//�����ʾѧ����������ѧ���������Ϣ
void show(LNode *list) {
    int i;
    printf("[SELECT] ��������������û���Ϣ��\n");
    for (i = 0; list->next != nullptr; i++) {
        list = list->next;
        printf("\t[INFO] �� %d ���û���\n", i+1);
        printf("\t\tѧ�ţ�%d\n",list->data.no);
        printf("\t\t������%s",list->data.name);
        printf("\t\t������%d\n",list->data.score);
    }
    printf("\n");
}

//�����������в��ң��������������ѧ������Ϣ���������߼���ţ�����������޴��ˡ�������0��
int findByName(LNode *list, char name[]) {
    printf("[SELECT] ���ڲ����û�\n");
    for (int i = 0; list->next != nullptr; i++) {
        list = list->next;
        if (strcmp(list->data.name,name) == 0) {
            return i+1;
        }
    }
    return 0;
}

//����߼����pos��Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ���
int Position(LNode *list, int pos) {
    printf("[SELECT] ���ڲ�ѯ�±�Ϊ %d ���û���\n", pos);
    for (int i = 0; i <= pos; ++i) {
        if (list->next == nullptr) {
            printf("[FAIL] ��ѯʧ�ܣ�û�ж�Ӧ�±��û�");
            return 0;
        }
        if (i == pos) {
            printf("\t[SUCCESS] ��ѯ�ɹ���\n");
            printf("\t\tѧ�ţ�%d\n",list->data.no);
            printf("\t\t������%s",list->data.name);
            printf("\t\t������%d\n",list->data.score);
        }
        list = list->next;
    }
    return 1;
}

//����һ��ѧ����Ϣ�����뵽����ָ����λ��
int PInsert(LNode *&list, int pos) {
    LNode *temp,*p;
    p = list;
    for (int i = 0; i < pos; ++i) {
        if (p->next == nullptr) return 0;
        p = p->next;
    }
    temp = new LNode;
    printf("[INSERT] ��������û���\n");
    printf("\t[INFO] ������ѧ�ţ�");
    scanf_s("%d",&temp->data.no);
    getchar();
    printf("\t[INFO] ������������");
    fgets(temp->data.name, 20, stdin);
    printf("\t[INFO] �����������");
    scanf_s("%d", &temp->data.score);
    getchar();
    temp->next = p->next;
    p->next = temp;
    return 1;
}

// ɾ��ָ��λ�õ�ѧ����¼
int Delete(LNode *&list, int pos) {
    printf("[DELETE] ����ɾ���±�Ϊ %d ���û���\n", pos);
    LNode *p,*temp;
    p = list;
    for (int i = 0; i < pos-1; ++i) {
        if (p->next == nullptr) {
            printf("[FAIL] ɾ��ʧ�ܣ�û�ж�Ӧ�±��û�");
            return 0;
        }
        p = p->next;
    }
    temp = p->next;
    p->next = temp->next;
    free(temp);
    printf("[SUCCESS] ɾ���ɹ�\n");
    return 1;
}

//ͳ�Ʊ���ѧ������
int Count(LNode *list) {
    int i;
    for (i = 0; list->next != nullptr; ++i) {
        list = list->next;
    }
    return i;
}

//�ͷ�����
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
    // ��������ڵ�
    char name[20];
    LNode *lNode;

    CreatStuList(lNode);

    printf("[SELECT] ��������Ҫ��ѯ�û�����");
    fgets(name,20,stdin);
    int intName = findByName(lNode, name);
    if (intName > 0)
        printf("\t[SUCCESS] ��ѯ�ɹ����±꣩��%d\n", intName);
    else
        printf("\t[FAIL] û�ж�Ӧ�û�\n");
    printf("\n");

    show(lNode);

    PInsert(lNode,2);
    printf("\n");

    show(lNode);

    printf("[SELECT] �ܼ�ѧ������ %d ��\n", Count(lNode));
    printf("\n");

    Position(lNode,2);
    printf("\n");

    Delete(lNode,3);
    printf("\n");

    show(lNode);

    DestroyList(lNode);
    system("pause");
}