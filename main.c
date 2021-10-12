#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int i, row = 0, line = 0;
char test[1000];  //test�ļ��е��ַ�
int number[100];	//������
char mark[100][5];   //��ʶ����

//�ʷ�����
int wordanalysis() {
    int y=0;
    //��ʶ���ͱ�����
    if ((test[i] >= 'A'&&test[i] <= 'Z')||(test[i]>='a'&&test[i]<='z')) {
        char word[10];
        //�����ֱ�
        char pro[100][100] = {  "If","Else","While","Break","Continue", "Return","if","else","while","break","continue","return"};
        int n = 0;
        word[n++] = test[i++];
        while ((test[i] >= 'A'&&test[i] <= 'Z') || (test[i] >= '0' && test[i] <= '9')||(test[i]>='a'&&test[i]<='z')) {
            word[n++] = test[i++];
        }
        word[n] = '\0';
        i--;
        //�жϸñ�ʶ���Ƿ�Ϊ������
        for (n = 0; n < 100; n++) {
            if (strcmp(word, pro[n]) == 0) {
                if(n>=6) {
                    printf("%s\n", pro[n-6]);
                    return 3;
                } else {
                    printf("Ident(%s)\n",pro[n]);
                    return 3;
                }
            }
        }
        //�жϸñ�ʶ���Ƿ��ڱ�ʶ������
        if (line != 0) {
            int q = 0;
            while (q<line) {
                if (strcmp(word, mark[q++]) == 0) {
                    printf("Ident(%s)\n",word);
                    return 3;
                }
            }

        }
        //���ñ�ʶ�����浽��ʶ������
        strcpy(mark[line], word);
        printf("Ident(%s)\n",word);
        line++;
        return 3;

    }
    //����
    else if (test[i] >= '0' && test[i] <= '9') {
        char x[100];
        int n = 0;
        x[n++] = test[i++];
        while (test[i] >= '0' && test[i] <= '9') {
            x[n++] = test[i++];
        }
        x[n] = '\0';
        i--;
        int num = atoi(x); //���ַ���ת����int��
        //�жϸó����Ƿ�����ڳ�������
        if (row != 0) {
            for(y=0; y<row; y++) {
                if(number[y]==num) {
                    printf("Number(%d)\n", num);
                    return 3;
                }
            }
        }
        //���ó������浽��ʶ������
        number[row]=num;
        printf("Number(%d)\n", num);
        row++;
        return 3;
    }
    //���ַ���
    else
        switch (test[i]) {
        case ' ':
        case '\n':
            return -1;
        case '=':
            if (test[i+1] == '=') {
                i++;
                printf("Eq\n");
                return 3;
            }
            printf("Assign\n");
            return 3;
        case '<':
            i++;
            if (test[i] == '=') {
                return 3;
            } else if (test[i] == '>') {
                return 3;
            } else {
                i--;
                printf("Lt\n");
                return 3;
            }
        case '>':
            i++;
            if (test[i] == '=') {
                return 3;
            } else {
                i--;
                printf("Gt\n");
                return 3;
            }
        case '+':
            printf("Plus\n");
            return 3;
        case '*':
            printf("Mult\n");
            return 3;
        case ';':
            printf("Semicolon\n");
            return 3;
        case '(':
            printf("Lpar\n");
            return 3;
        case ')':
            printf("Rpar\n");
            return 3;
        case '{':
            printf("LBrace\n");
            return 3;
        case '}':
            printf("RBrace\n");
            return 3;
        case EOF:
            return 0;
        default:
            printf("Err\n");
            return -2;
        }
    return 0;
}

int main() {
    int c = 0;
    int m;
    i = 0;
    FILE *fp;
    fp=fopen("test.txt","r");
    if (fp == NULL) {
        printf("can't open file!\n");
        exit(0);
    }
    while (!feof(fp)) {
        test[c++] = fgetc(fp);
    }
    test[c] = '#';
    do {
        m = wordanalysis();
        switch (m) {
        case -2:
            i++;
            break;
        case -1:
            i++;
            break;
        case 0:
            i++;
            break;
        case 3:
            i++;
            break;
        }
    } while (m != -2 && m != 0);
    return 0;
}
