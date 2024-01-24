#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }

    int sqrtNum = sqrt(num);
    int i; 
    for ( i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int dem_le_chia_het_5(int **mang, int n, int m) {
    int dem = 0;
    int i; 
    int j; 
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            if (mang[i][j] % 2 != 0 && mang[i][j] % 5 == 0) {
                dem++;
            }
        }
    }
    return dem;
}

int main() {
    int n, m, choice;
    int i, j, temp;
    int sum;
    printf("nhap so hang ");
    scanf("%d", &n);
    printf("nhap so cot ");
    scanf("%d", &m);
    int a[n][m];
    int k; 

    do {
        printf("************************MENU**************************\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu le chia het cho 5 trong mang\n");
        printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren bien, duong cheo chinh, duong cheo phu\n");
        printf("5. Su dung thuat toan sap xep lua chon sap xep cac phan tu giam dan theo dong cua mang\n");
        printf("6. Tinh tong cac so phan tu la so nguyen to trong mang\n");
        printf("7. Su dung thuat toan chen sap xep cac phan tu tren duong cheo phu cua mang tang dan\n");
        printf("8. Nhap gia tri mot mang 1 chieu gom n phan tu va chi so cot muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
        printf("9. Thoat\n");
        printf("nhap lua chon cua ban \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("a[%d][%d]=", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }
                break;
            case 2:
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d  ", a[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            case 3:
                printf("So luong phan tu le chia het cho 5: %d\n", dem_le_chia_het_5(a, n, m));
                break;
            case 4:
                break;
            case 5:
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m - 1; j++) {
                        for ( k = j + 1; k < m; k++) {
                            if (a[i][j] > a[i][k]) {
                                temp = a[i][j];
                                a[i][j] = a[i][k];
                                a[i][k] = temp;
                            }
                        }
                    }
                }
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d  ", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 6:
                sum = 0;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (isPrime(a[i][j]))
                            sum += a[i][j];
                    }
                }
                printf("tong cac phan tu la so nguyen to trong mang la %d \n", sum);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                printf("thoat\n");
                break;
            default:
                printf("khong hop le\n");
        }
    } while (choice != 9);

    return 0;
}

