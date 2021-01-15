#include "contactor.h"

void InitContactor(struct Contactor *ps) {
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}

void AddContactor(struct Contactor *ps) {
    if (ps->size == MAX) {
        printf("通讯录已满，不能再添加信息");
    } else {
        printf("请输入姓名：》");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄：》");
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入性别：》");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话：》");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址：》");
        scanf("%s", ps->data[ps->size].adder);
        ps->size++;
        printf("添加成功\n");
    }
}

void ShowContactor(const struct Contactor *ps) {
    if (ps->size == 0) {
        printf("通讯录为空\n");
    } else {
        printf("%-10s\t%-8s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
    printf("请输入要删除的人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("你要删除的人不存在\n");
    } else {
        //删除第pos位的元素
        for (int i = pos + 1; i < ps->size; ++i) {
            ps->data[i - 1] = ps->data[i];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

//查询通讯信息
void SearchContactor(const struct Contactor *ps) {
    char name[MAX];
    printf("请输入要查找的人的姓名:》");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("你要查找的人不存在\n");
    } else {
        printf("%-8s\t%-8s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-8s\t%-8d\t%-5s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].adder);
    }

}

//修改指定通讯录的信息
void ModifyContactor(struct Contactor *ps) {
    char name[MAX];
    printf("请输入要修改的人的姓名:》");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1) {
        printf("要修改的人不存在");
    } else {
        printf("请输入姓名：》");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄：》");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别：》");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话：》");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址：》");
        scanf("%s", ps->data[pos].adder);

        printf("修改成功\n");
    }

}

//按照通讯录姓名进行
void *compare_By_Name(void *e1, void *e2) {
    struct PeoInfo *elem1 = (struct PeoInfo *) e1;
    struct PeoInfo *elem2 = (struct PeoInfo *) e2;
    return strcmp(elem1->name, elem2->name);

}

void SortContactor(struct Contactor *ps) {
    qsort(ps->data, ps->size, sizeof(struct PeoInfo), compare_By_Name);
    printf("排序成功");
}
