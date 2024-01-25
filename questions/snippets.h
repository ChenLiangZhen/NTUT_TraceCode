//
// Created by Lightii Chen on 2023/12/8.
//

#include <string>

#ifndef TRACECODE_SNIPPETS_H
#define TRACECODE_SNIPPETS_H

typedef enum {
    dog, cat, lion = 4, tiger, monkey, hippo, giraffe
} animal;

typedef struct linkdata {
    char name[10];
    int data[4][4];
    struct linkdata *next;
} LinkData;

void q108_2_f1(int d[][4]) {
    int k, c, r;
    int a[][3] = {{1, 1, 1},
                  {2, 2, 2},
                  {1, 1, 2}};
    int b[][3] = {{1, 2, 3},
                  {2, 3, 4},
                  {3, 4, 5}};
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            d[c][r] = 0;
            for (int k = 0; k < 3; k++) {
                d[c][r] += a[c][k] * b[k][r];
            }
        }
    }

    printf("%d\n", d[0][0], d[0][1], d[0][2]); //prints out 6, 9, 12
}

void q108_2_f2(LinkData **topp, char * s){
    LinkData *x;
    x = (LinkData *) malloc(sizeof(LinkData));
    strncpy(x->name, s, 10);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            x->data[i][j] = i + j;
        }
    }
    x->next = *topp;
    *topp = x;
}

void q108_1(int a, int b) {
    printf("%d\n", !a && b);
    printf("%d\n", ~a & b);
}

void q108_2() {
    animal a = static_cast<animal>(cat + hippo);
    printf("%d\n", a);
}

void q108_3(int num) {
    int k;
    k = (num > 1 ? (num <= 10 ? 100 : 200) : 300);
    printf("%d\n", ++k);
}

void q108_4(int num) {
    float f = 1.0;
    for (int i = 1; i <= num; i++) {
        f *= i;
    }
    printf("%.2f\n", f);
}

void q108_5(char *s1, char *s2) {
    char str1[80] = "", str2[] = "a";
    int i = 0;
    while (*(s1 + i) <= *(s2 + i) && strlen(str1) < 80) {
        i++;
        strncat(str1, str2, 1);
    }
    printf("%s\n", str1);
}

void q108_6(int x[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        switch ((animal) x[i] + 3) {
            case dog:
                sum += 3;
                break;
            case cat:
                sum += 3;
                break;
            case lion:
                sum += 4;
            case tiger:
                sum += 4;
                break;
            default:
                sum += 1;
                break;
        }
    }
    printf("%d\n", sum);
}

void q108_7(int a[], int p1, int *p2) {
    a[0] = 5;
    p1 = *p2 + 1;
    *p2 = 1;
}

int q108_8(int n) {
    if (n < 2) { return n; }
    return q108_8(n - 1) + q108_8(n - 2);
}

void execute_snippets_108() {

    char s[2][12] = {"problem", "programmer"};
    int a[] = {1, 2, 3, 4};
    char *array[] = {"dog", "lion", "hippo", "giraffe"};
    LinkData a2, *top = nullptr;

    q108_2_f1(a2.data);

    q108_1(16, 8);
    q108_2();
    q108_3(5);
    q108_4(5);
    q108_5(s[0], s[1]);
    q108_6(a, 4);
    q108_7(a, a[0], &a[2]);

    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", q108_8(6));
}

void func() {

    int a = 2, b = 1;
    unsigned int c = 1, d = 6;
    printf("%d\n", a && !b);
    printf("%d\n", c << 2);
    printf("%d\n", c | d);
}

void func2() {

    int num = 5;
    float t = num / 2 * num % 2 + 2 + 1.0 / num;

    printf("%d\n", ~40);
    printf("%3.1f\n", t);
}

int func3() {

    enum direction {
        North, South, East, West
    };
    enum direction d = South;

    printf("%d %d %d\n", North, South, East);
    d = (North + East) / 2 > d ? East : West;

    return d;
}

int func4() {

    int w[4][3] = {{4, 2, 1},
                   {3, 4, 2},
                   {2, 3, 3},
                   {1, 1, 4}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 0) {
                w[0][j] = w[0][j] + w[i][j];
            }
        }
    }

    printf("%d\n", w[0][2]);
    return w[0][2];
}

void func5() {

    int x[5] = {5, 4, 3, 2, 1};
    char s[6] = "";

    for (int i = 0; i < 5; i++) {

        switch (x[i] % 2 + x[i] % 3) {

            case 0:
                strcat(s, "a");
                break;

            case 1:
                strcat(s, "b");
                break;

            case 2:
                strcat(s, "c");
                break;

            case 3:
                strcat(s, "d");

            default:
                strcat(s, "e");
                break;
        }
    }

    printf("%s\n", s);
}

void func6(int a, int *b, int *c) {

    a = 7;
    *b = 5;
    c = &a;

    printf("In Function:%3d%3d%#16X%#16X%#16X\n", a, *b, &a, c, &c);
}

int q110_1(int a, int b) {
    return (a || !b) + (~a & b);
}

float q110_2(int num) {
    float t = (float) num / 2 + num % 2 + 1.0 / num;

    return t;
}

int q110_3() {
    enum FOOD {
        fish = -1, eggs, meat = 3, milk, bean
    };
    return (eggs + milk) / 2 > meat ? fish : bean;
}

int q110_4(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < 3) continue;
        sum += i;
    }

    return sum;
}

int q110_5(char *s) {
    int i = 0, t = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case 's':
                t += 1;
                break;
            case 'c':
                t += 2;
                break;
            case 'e':
                t += 3;
            default:
                t += 1;
                break;
        }
        i++;
    }
    return t;
}

int q110_6(int x[3], int y[3][3]) {
    int t = 0, n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t += x[i] * y[i][j];
        }
    }

    return t;
}

char *q110_7(char s1[], char s2[]) {
    char s[20] = "";
    strncat(s, s1, 4);
    strcat(s, s2);
    strncpy(s1, s, 10);

    return s1;
}

void execute_snippets() {
    int a = 1, b = 2, c = 3;
    func();
    func2();
    func3();
    func4();
    func5();
    func6(a, &b, &c);
}

void execute_snippets_110() {

    int a[3][3] = {{1, 1, 1},
                   {2, 2, 2},
                   {3, 3, 3}};
    int b[3] = {1, 2, 2};

    char s1[] = "Hello", s2[] = "World!";

    printf("%d\n", q110_1(1, 2));
    printf("%3.1f\n", q110_2(5));
    printf("%d\n", q110_3());
    printf("%d\n", q110_4(5));
    printf("%d\n", q110_5("science"));
    printf("%d\n", q110_6(b, a));
    printf("%s\n", q110_7(s1, s2));
}


#endif //TRACECODE_SNIPPETS_H
