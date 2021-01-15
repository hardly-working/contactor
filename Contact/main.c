#include "contactor.h"

void menu();

int main() {
    int input;
    //创建通讯录
    struct Contactor conn;
    //初始化通讯录
    InitContactor(&conn);

    do {
        menu();
        printf("请选择：》");
        scanf("%d",&input);
        switch (input) {
            case ADD:
                AddContactor(&conn);
                break;
            case DEL:
                DelContactor(&conn);
                break;
            case SEARCH:
                SearchContactor(&conn);
                break;
            case MODIFY:
                ModifyContactor(&conn);
                break;
            case SORT:
                SortContactor(&conn);
                break;
            case SHOW:
                ShowContactor(&conn);
                break;
            case EXIT:
                printf("退出通讯录\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }

    } while (input);
    return 0;
}

void menu() {
    printf("**********************************\n");
    printf("***1.add            2.del*********\n");
    printf("***3.search         4.modify******\n");
    printf("***5.sort           6.show********\n");
    printf("***7.exit                         \n");
    printf("**********************************\n");


}
