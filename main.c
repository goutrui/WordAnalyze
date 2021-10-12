#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int i, row = 0, line = 0;
char test[1000];  //test文件中的字符
int number[100];	//常数表
char mark[100][5];   //标识符表

//词法分析
int wordanalysis() {
    int y=0;
    //标识符和保留字
    if ((test[i] >= 'A'&&test[i] <= 'Z')||(test[i]>='a'&&test[i]<='z')) {
        char word[10];
        //保留字表
        char pro[100][100] = {  "If","Else","While","Break","Continue", "Return","if","else","while","break","continue","return"};
        int n = 0;
        word[n++] = test[i++];
        while ((test[i] >= 'A'&&test[i] <= 'Z') || (test[i] >= '0' && test[i] <= '9')||(test[i]>='a'&&test[i]<='z')) {
            word[n++] = test[i++];
        }
        word[n] = '\0';
        i--;
        //判断该标识符是否为保留字
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
        //判断该标识符是否在标识符表中
        if (line != 0) {
            int q = 0;
            while (q<line) {
                if (strcmp(word, mark[q++]) == 0) {
                    printf("Ident(%s)\n",word);
                    return 3;
                }
            }

        }
        //将该标识符保存到标识符表中
        strcpy(mark[line], word);
        printf("Ident(%s)\n",word);
        line++;
        return 3;

    }
    //数字
        else if (test[i] >= '0' && test[i] <= '9') {
        printf("Number(");
        while (test[i] >= '0' && test[i] <= '9') {
            printf("%c",test[i]);
            i++;
        }
        i--;
        printf(")\n");
        return 3;
    }
    //各种符号
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
            printf("LPar\n");
            return 3;
        case ')':
            printf("RPar\n");
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

int main(int argc, char *argv[]) {
    int c = 0;
    int m;
    i = 0;
    FILE *fp;
    fp=fopen(argv[1],"r");
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
