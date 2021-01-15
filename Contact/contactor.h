//
// Created by Individual on 2021/1/15.
//

#ifndef CONTACT_CONTACTOR_H
#define CONTACT_CONTACTOR_H

#define MAX (1000)
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDER 30

#include "stdio.h"
#include "string.h"
#include <stdlib.h>



enum option {
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT,
    SHOW

};
struct PeoInfo {
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char adder[MAX_ADDER];
};
struct Contactor {
    struct PeoInfo data[MAX];//存放1000个数据
    int size;
};



//申明函数

//初始化一个通讯录
void InitContactor(struct Contactor *ps);

//增加一个信息到通讯录
void AddContactor(struct Contactor *ps);

//显示通讯录的信息
void ShowContactor(const struct Contactor *ps);

//从通讯录中删除一个信息
void DelContactor(struct Contactor *ps);

//查找指定的通讯录的信息
void SearchContactor(const struct Contactor *ps);

//修改指定通讯录的信息
void ModifyContactor(struct Contactor *ps);

//按照通讯录姓名进行
void SortContactor(struct Contactor *ps);

#endif //CONTACT_CONTACTOR_H