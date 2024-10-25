#include<stdio.h>
#include<string.h>
int counter(int);
void getDigitsInArray(int*, int num, int len);
void getResult(int, int, char[][6], int*);
int tenToNineteen(int);

int main(){
    int num, no_of_digits;
    scanf("%d",&num);
    if(num == 100000){
        printf("One Lakh\n");
        return 0;
    }
    char ones[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    no_of_digits = counter(num);
    int digitsArr[no_of_digits];
    getDigitsInArray(digitsArr, num, no_of_digits);
    getResult(no_of_digits, num, ones, digitsArr);
    return 0;
}

int counter(int num){
    int count = 0;
    while(num){
        ++count;
        num /= 10;
    }
    return count;
}

void getDigitsInArray(int arr[], int num, int len){
    for(int i = len-1; i >=0; --i){
        arr[i] = num % 10;
        num /= 10;
    }
}

void getResult(int len, int num, char ones[][6], int digitsArr[]){
    int temp = num, i = 0;
    char tens[9][8] = {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    switch (len){
        case 1:
            printf("%s\n",ones[num]);
            break;
        case 2:
            if(tenToNineteen(num)){
                printf("\n");
                break;
            }
            if(digitsArr[i] != 0 && i == 0) printf("%s ",tens[digitsArr[i++]-1]);
            if(digitsArr[i] != 0 && i == 1) printf("%s\n",ones[digitsArr[i]]);
            else printf("\n");
            break;
        case 3:
            if(digitsArr[i] != 0 && i == 0) printf("%s %s ",ones[digitsArr[i++]],"hundred");
            if(digitsArr[i] != 0 && i == 1){
                if(digitsArr[i] == 1){
                    int temp = digitsArr[i] * 10 + digitsArr[i+1];
                    tenToNineteen(temp);
                    printf("\n");
                    break;
                }else{
                    printf("%s ",tens[digitsArr[i]-1]);
                }
            }
            if(digitsArr[++i] != 0 && i == 2) printf("%s\n",ones[digitsArr[i]]);
            else printf("\n");
            break;
        case 4:
            if(digitsArr[i] != 0 && i == 0) printf("%s %s ",ones[digitsArr[i++]],"thousand");
            if(digitsArr[i] != 0 && i == 1) printf("%s %s ",ones[digitsArr[i]],"hundred");
            if(digitsArr[++i] != 0 && i == 2){
                if(digitsArr[i] == 1){
                    int temp = digitsArr[i] * 10 + digitsArr[i+1];
                    tenToNineteen(temp);
                    printf("\n");
                    break;
                }else{
                    printf("%s ",tens[digitsArr[i]-1]);
                }
            }
            if(digitsArr[++i] != 0 && i == 3) printf("%s\n",ones[digitsArr[i]]);
            else printf("\n");
            break;
        case 5:
            if(digitsArr[i] != 0 && i == 0){
                if(digitsArr[i] == 1){
                    int temp = digitsArr[i] * 10 + digitsArr[i+1];
                    tenToNineteen(temp);
                    printf(" thousand ");
                    ++i;
                }else{
                    printf("%s ",tens[digitsArr[i++]-1]);
                    if(digitsArr[i] != 0) printf("%s %s ",ones[digitsArr[i]],"thousand");
                    else printf("thousand "); 
                }
            }
            if(digitsArr[++i] != 0 && i == 2){
                printf("%s %s ",ones[digitsArr[i]],"hundred");
            }
            if(digitsArr[++i] != 0 && i == 3){
                if(digitsArr[i] == 1){
                    int temp = digitsArr[i] * 10 + digitsArr[i+1];
                    tenToNineteen(temp);
                    printf("\n");
                    break;
                }else{
                    printf("%s ",tens[digitsArr[i]-1]);
                }
            }
            if(digitsArr[++i] != 0 && i == 4) printf("%s\n",ones[digitsArr[i]]);
            else printf("\n");
            break;
        default:
            printf("input should be less than 100000\n");
    }
}

int tenToNineteen(int num){
    if(num == 10) {
        printf("ten");
        return 1;
    }
    if(num == 11){
        printf("eleven");
        return 1;
    } 
    if(num == 12) {
        printf("twelve");
        return 1;
    }
    if(num == 13) {
        printf("thirteen");
        return 1;
    }
    if(num == 14) {
        printf("fourteen");
        return 1;
    }
    if(num == 15) {
        printf("fifteen");
        return 1;
    }
    if(num == 16) {
        printf("sixteen");
        return 1;
    }
    if(num == 17) {
        printf("seventeen");
        return 1;
    }
    if(num == 18) {
        printf("eighteen");
        return 1;
    }
    if(num == 19) {
        printf("nineteen");
        return 1;
    }
    return 0;
}