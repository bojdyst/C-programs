#include <stdio.h>
#define max 100

int convert_to_decimal(char rn[max]){
    int IV = 0, IX = 0, IC = 0, ID = 0, IM = 0, XL = 0, XC = 0, XD = 0, XM = 0, CD = 0, CM = 0, M = 0, D = 0, C = 0, L = 0, X = 0, V = 0, I = 0, num, count = 0;
    while ((rn[count])) {
        if(rn[count] == 'I' && rn[count+1] == 'V') {
            IV += 4;
            V -= 5;
            count++;
        }
        if(rn[count] == 'I' && rn[count+1] == 'X') {
            IX += 9;
            X -= 10;
            count++;
        }
        if(rn[count] == 'I' && rn[count+1] == 'C') {
            IC += 99;
            C -= 100;
            count++;
        }
        if(rn[count] == 'I' && rn[count+1] == 'D') {
            ID += 499;
            D -= 500;
            count++;
        }
        if(rn[count] == 'I' && rn[count+1] == 'M') {
            IM += 999;
            M -= 1000;
            count++;
        }
        if(rn[count] == 'X' && rn[count+1] == 'L') {
            XL += 40;
            L -= 50;
            count++;
        }
        if(rn[count] == 'X' && rn[count+1] == 'C') {
            XC += 90;
            C -= 100;
            count++;
        }
        if(rn[count] == 'X' && rn[count+1] == 'D') {
            XD += 490;
            D -= 500;
            count++;
        }
        if(rn[count] == 'X' && rn[count+1] == 'M') {
            XM += 990;
            M -= 1000;
            count++;
        }
        if(rn[count] == 'C' && rn[count+1] == 'D') {
            CD += 400;
            D -= 500;
            count++;
        }
        if(rn[count] == 'C' && rn[count+1] == 'M') {
            CM += 900;
            M -= 1000;
            count++;
        }
        if (rn[count] == 'M'){
            M += 1000;
        if (D != 0 || C != 0 || L != 0 || X != 0 || V != 0 || I != 0)
                break;
        }
        if (rn[count] == 'D') {
            D += 500;
            if (C != 0 || L != 0 || X != 0 || V != 0 || I != 0)
                break;
        }
        if (rn[count] == 'C') {
            C += 100;
            if (L != 0 || X != 0 || V != 0 || I != 0)
                break;
        }
        if (rn[count] == 'L') {
            L += 50;
            if (X != 0 || V != 0 || I != 0)
                break;
        }
        if (rn[count] == 'X') {
            X += 10;
            if (V != 0 || I != 0)
                break;
        }
        if (rn[count] == 'V') {
            V += 5;
            if (I != 0)
                break;
        }
        if (rn[count] == 'I') {
            I += 1;
        }
        count++;
    }

    num = IV + IX + XL + XC + CD + CM + M + D + C + L + X + V + I;
    if (D > 500 || C > 300 || L > 50 || X > 30 || V > 5 || I > 3 || IC > 0 || ID > 0 || IM > 0 || XD > 0 || XM > 0){
        printf("Incorrect roman number - please stick to the rules and start the program again!\n");
        exit(997);
    }
    return num;
}

void convert_to_roman(int num){
    while(num != 0) {
        if(num >= 1000) {
            printf("M");
            num -= 1000;
        }
        else if(num >= 900){
            printf("CM");
            num -= 900;
        }
        else if(num >= 500){
            printf("D");
            num -= 500;
        }
        else if (num >= 400){
            printf("CD");
            num -= 400;
        }
        else if (num >= 100){
            printf("C");
            num -= 100;
        }
        else if (num >= 90){
            printf("XC");
            num -= 90;
        }
        else if (num >= 50){
            printf("L");
            num -= 50;
        }
        else if (num >= 40){
            printf("XL");
            num -= 40;
        }
        else if (num >= 10){
            printf("X");
            num -= 10;
        }
        else if (num >= 9){
            printf("IX");
            num -= 9;
        }
        else if (num >= 5){
            printf("V");
            num -= 5;
        }
        else if (num >= 4){
            printf("IV");
            num -= 4;
        }
        else if (num >= 1){
            printf("I");
            num -= 1;
        }
    }
}

void summing(int a, int b) {
    int result;
    result = a + b;
    printf("The sum of these numbers in Roman is:\n");
    convert_to_roman(result);
    printf("\n");
    printf("The sum of these numbers in decimal is: %d\n", result);
}

int main(void){
    char n1[max], n2[max];
    int number1, number2;
    printf("Enter the first number:\n");
    scanf("%s", n1);
    number1 = convert_to_decimal(n1);
    printf("The first number in decimal is: %d\n", number1);
    printf("\n");
    printf("Enter the second number:\n");
    scanf("%s", n2);
    number2 = convert_to_decimal(n2);
    printf("The second number in decimal: is %d\n", number2);
    printf("\n");
    summing(number1, number2);
    return 0;
}



