#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Contact {
    int id, status;
    char name[50], phone[12], address[50];
};

void printfMenu() {
    printf("**********MENU***********\n");
    printf("1.In toan bo danh sach contact o trong mang contactList tren cung 1 hang\n");
    printf("2.Thuc hien chuc nang them moi vao vi tri cuoi cung cua contactList\n");
    printf("3.Chinh sua thong tin trong contactList\n");
    printf("4.Xoa thong tin trong contactList\n");
    printf("5.Sap xep va in ra danh sach contact da duoc sap xep\n");
    printf("6.Tim kiem nhi phan va in ra thong tin cua contact tren cung mot hang\n");
    printf("7.Tim kiem tuyen tinh va in ra thong tin cua contact\n");
    printf("8.Thoat\n");
    printf("Lua chon cua ban la: ");
}

void printContact(struct Contact arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d\t", arr[i].id);
        printf("Ho va Ten: %s\t", arr[i].name);
        printf("So Dien Thoai: %s\t", arr[i].phone);
        printf("Dia chi: %s\t", arr[i].address);
        printf("Trang Thai: %d\n", arr[i].status);
        printf("-----------------------\n");
    }
}

int main() {
    char searchName[50];
    int foundIndex;
    int searchStatus,found;
    int left,right,middle;
    struct Contact ct1 = {1, 1, "Nguyen The Minh", "095852985", "Ha Noi"};
    struct Contact ct2 = {2, 2, "Nguyen Nam Son", "047358472", "Ha Noi"};
    struct Contact ct3 = {3, 1, "Le Dien Tien", "047847525", "Thai Nguyen"};
    struct Contact ct4 = {4, 2, "Nguyen Minh Hien", "0486745156", "Soc Son"};
    struct Contact ct5 = {5, 1, "Luong Minh Vy", "0785676558", "Thanh Hoa"};
    struct Contact contactList[] = {ct1, ct2, ct3, ct4, ct5};
    int contactCount = 5;

    do {
        printfMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printContact(contactList, contactCount);
                break;
            case 2:
            	getchar();
			    printf("Nhap ten muon them: ");
			    gets(contactList[contactCount].name);
			    printf("Nhap so dien thoai: ");
			    gets(contactList[contactCount].phone);
			    printf("Nhap dia chi: ");
			    gets(contactList[contactCount].address);
			    printf("Nhap trang thai: ");
			    getchar();
			    scanf("%d",&contactList[contactCount].status);
			    contactList[contactCount].id = contactCount + 1;
			    contactCount++;
			    printf("Contact da duoc them.\n");
                break;
            case 3:
            	getchar();
                printf("Nhap ten contact muon chinh sua: ");
                gets(searchName);                
                foundIndex = -1;
                for (int i = 0; i < contactCount; i++) {
                    if (strcmp(contactList[i].name, searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {               	
                    printf("Nhap ten moi: ");
                    gets(contactList[foundIndex].name);
                    printf("Nhap so dien thoai moi: ");
                    gets(contactList[foundIndex].phone);
                    printf("Nhap dia chi moi: ");
                    gets(contactList[foundIndex].address);
                    printf("Nhap trang thai moi: ");
                    scanf("%d",&contactList[foundIndex].status);
                    printf("Contact da duoc cap nhat.\n");
                } else {
                    printf("Khong tim thay contact.\n");
                }
                break;
            case 4:
            	getchar();
                printf("Nhap ten contact muon xoa: ");
                gets(searchName);
                foundIndex = -1;
                for (int i = 0; i < contactCount; i++) {
                    if (strcmp(contactList[i].name, searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {
                    for (int i = foundIndex; i < contactCount - 1; i++) {
                        contactList[i] = contactList[i + 1];
                    }
                    contactCount--;
                    printf("Contact da duoc xoa.\n");
                } else {
                    printf("Khong tim thay contact.\n");
                }
                break;
            case 5:
                for (int i = 0; i < contactCount - 1; i++) {
                    for (int j = i + 1; j < contactCount; j++) {
                        if (strcmp(contactList[i].name, contactList[j].name) > 0) {
                            struct Contact temp = contactList[i];
                            contactList[i] = contactList[j];
                            contactList[j] = temp;
                        }
                    }
                }
                printContact(contactList, contactCount);
                break;
            case 6:
            	getchar();
                printf("Nhap ten contact muon tim kiem: ");
                gets(searchName);
                left = 0;
                right = contactCount - 1;
                foundIndex = -1;
                while (left <= right) {
                    middle = (left + right) / 2;
                    if (strcmp(contactList[middle].name, searchName) == 0) {
                        foundIndex = middle;
                        break;
                    } else if (strcmp(contactList[middle].name, searchName) < 0) {
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                if (foundIndex != -1) {
                    printf("ID: %d\t", contactList[foundIndex].id);
                    printf("Ho va Ten: %s\t", contactList[foundIndex].name);
                    printf("So Dien Thoai: %s\t", contactList[foundIndex].phone);
                    printf("Dia chi: %s\t", contactList[foundIndex].address);
                    printf("Trang Thai: %d\n", contactList[foundIndex].status);
                } else {
                    printf("Khong tim thay contact.\n");
                }
                break;
            case 7:
            	getchar();
                printf("Nhap trang thai contact muon tim kiem: ");
                scanf("%d",&searchStatus);
                found = 0;
                for (int i = 0; i < contactCount; i++) {
                    if (contactList[i].status == searchStatus) {
                        printf("ID: %d\t", contactList[i].id);
                        printf("Ho va Ten: %s\t", contactList[i].name);
                        printf("So Dien Thoai: %s\t", contactList[i].phone);
                        printf("Dia chi: %s\t", contactList[i].address);
                        printf("Trang Thai: %d\n", contactList[i].status);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay contact.\n");
                }
                break;
            case 8:
            	printf("Ket thuc chuong trinh\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (1==1);
}
