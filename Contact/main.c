#include "contactor.h"

void menu();

int main() {
    int input;
    //����ͨѶ¼
    struct Contactor conn;
    //��ʼ��ͨѶ¼
    InitContactor(&conn);

    do {
        menu();
        printf("��ѡ�񣺡�");
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
                printf("�˳�ͨѶ¼\n");
                break;
            default:
                printf("ѡ�����\n");
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
