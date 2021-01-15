#include "contactor.h"

void InitContactor(struct Contactor *ps) {
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}

void AddContactor(struct Contactor *ps) {
    if (ps->size == MAX) {
        printf("ͨѶ¼�����������������Ϣ");
    } else {
        printf("��������������");
        scanf("%s", ps->data[ps->size].name);
        printf("���������䣺��");
        scanf("%d", &(ps->data[ps->size].age));
        printf("�������Ա𣺡�");
        scanf("%s", ps->data[ps->size].sex);
        printf("������绰����");
        scanf("%s", ps->data[ps->size].tele);
        printf("�������ַ����");
        scanf("%s", ps->data[ps->size].adder);
        ps->size++;
        printf("��ӳɹ�\n");
    }
}

void ShowContactor(const struct Contactor *ps) {
    if (ps->size == 0) {
        printf("ͨѶ¼Ϊ��\n");
    } else {
        printf("%-10s\t%-8s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        for (int i = 0; i < ps->size; ++i) {
            printf("%-8s\t%-8d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].adder);
        }
    }
}

int FindByName(const struct Contactor *ps, char name[]) {
    for (int i = 0; i < ps->size; ++i) {
        if (0 == strcmp(ps->data[i].name, name)) {
            return i;
        }
    }
    return -1;
}

void DelContactor(struct Contactor *ps) {
    char name[MAX_NAME];
    printf("������Ҫɾ�����˵�����:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("��Ҫɾ�����˲�����\n");
    } else {
        //ɾ����posλ��Ԫ��
        for (int i = pos + 1; i < ps->size; ++i) {
            ps->data[i - 1] = ps->data[i];
        }
        ps->size--;
        printf("ɾ���ɹ�\n");
    }
}

//��ѯͨѶ��Ϣ
void SearchContactor(const struct Contactor *ps) {
    char name[MAX];
    printf("������Ҫ���ҵ��˵�����:��");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("��Ҫ���ҵ��˲�����\n");
    } else {
        printf("%-8s\t%-8s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        printf("%-8s\t%-8d\t%-5s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].adder);
    }

}

//�޸�ָ��ͨѶ¼����Ϣ
void ModifyContactor(struct Contactor *ps) {
    char name[MAX];
    printf("������Ҫ�޸ĵ��˵�����:��");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("Ҫ�޸ĵ��˲�����");
    } else {
        printf("��������������");
        scanf("%s", ps->data[pos].name);
        printf("���������䣺��");
        scanf("%d", &(ps->data[pos].age));
        printf("�������Ա𣺡�");
        scanf("%s", ps->data[pos].sex);
        printf("������绰����");
        scanf("%s", ps->data[pos].tele);
        printf("�������ַ����");
        scanf("%s", ps->data[pos].adder);

        printf("�޸ĳɹ�\n");
    }

}

//����ͨѶ¼��������
void *compare_By_Name(void *e1, void *e2) {
    struct PeoInfo *elem1 = (struct PeoInfo *) e1;
    struct PeoInfo *elem2 = (struct PeoInfo *) e2;
    return strcmp(elem1->name, elem2->name);

}

void SortContactor(struct Contactor *ps) {
    qsort(ps->data, ps->size, sizeof(struct PeoInfo), compare_By_Name);
    printf("����ɹ�");
}
