#include<stdio.h>
#include<string.h>
struct Student{
	int id;
	char name[50];
	char birthday[50];
	char address[50];
	int status;
};


void displayStudent(struct Student arr[],int size){
	for(int i=0;i<size;i++){
		printf("id:%d\n",arr[i].id);
		printf("Name: %s\n",arr[i].name);
		printf("Birthday: %s\n",arr[i].birthday);
		printf("Address: %s\n",arr[i].address);
		printf("Status: %d\n",arr[i].status);
	}
}

int searchStudent(struct Student arr[],int size,char answer[50]){
	int index = -1;
	for(int i=0; i<size;i++){
		if(strcmp(arr[i].name,answer)==0){
			index = i;
			
		}
	}
	return index;
}
  int binarySearch(struct Student arr[], int left, int right, char answer[50]) {
                if (right >= left) {
                   int mid = left + (right - left) / 2;
                if (strcmp(arr[mid].name, answer) == 0) {
                    return mid;
                }
                if (strcmp(arr[mid].name, answer) > 0) {
                    return binarySearch(arr, left, mid - 1, answer);
                }
                    return binarySearch(arr, mid + 1, right, answer);
                }
                 return -1;
    }
void searchByStatus(struct Student arr[], int size, int status) {
    printf("Danh sach sinh vien theo status %d:\n", status);
    for (int i = 0; i < size; i++) {
        if (arr[i].status == status) {
            displayStudent(&arr[i], 1);
        }
}
}
int main(){
	struct Student student1 = {1,"Nguyen Van A","17/07/2005","Ha Noi",0};
	struct Student student2 = {2,"Nguyen Van B","05/08/2006","Thanh Hoa",1};
	struct Student studentList[100]={student1,student2};
	int currentSize = 2;
	int choice;
	do{
		printf("*********Menu*********\n");
		printf("1.in ra toan bo sach\n ");
		printf("2.Thuc hien chuc nang them moi sinh vien\n");
		printf("3.Thuc hien chuc nang cap nhat thong tin cua sinh vien\n");
		printf("4.Thuc hien chuc nang xoa mot sinh vien\n");
		printf("5.Thuc hien chuc nang sap xep va in ra danh sach da sap xep\n");
		printf("6.Thuc hien chuc nang tim kiem theo ten va in ra \n");
		printf("7.Thuc hien chuc nang tim kiem theo status va in ra\n");
		printf("8.Thoat chuong trinh\n");
		printf("Lua chon cua ban\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				displayStudent(studentList,currentSize);
				break;
			case 2:
				struct Student newStudent;
				printf("Nhap vao id cua sinh vien\n");
				scanf("%d",&newStudent.id);
				fflush(stdin);
				printf("Nhap vao ten cua sinh vien\n");
				gets(newStudent.name);
				printf("nhap vao sinh nhat cua sinh vien\n");
				scanf("%s",&newStudent.birthday);
				fflush(stdin);
				printf("Nhap vao dia chi cua sinh vien\n");
				gets(newStudent.address);
				printf("Nhap vao status cua sinh vien\n");
				scanf("%d",&newStudent.status);
				fflush(stdin);
				studentList[currentSize]=newStudent;
				currentSize ++;
				displayStudent(studentList,currentSize);
				break;
			case 3:{
				char answer[100];
                printf("Cap nhat thong tin cua sinh vien: ");
                scanf("%s", answer);
                int updateIndex = searchStudent(studentList, currentSize, answer);
                if (updateIndex != -1) {
                    printf("Nhap vao ten cap nhat cua sinh vien: ");
                    scanf("%s", studentList[updateIndex].name);
                    printf("Nhap vao ngay sinh moi cua sinh vien: ");
                    scanf("%s", studentList[updateIndex].birthday);
                    printf("Nhap vao dia chi moi cua sinh vien: ");
                    scanf("%s", studentList[updateIndex].address);
                    printf("Nhap vao status moi cua sinh vien: ");
                    scanf("%d", &studentList[updateIndex].status);
                    fflush(stdin);
                    displayStudent(studentList, currentSize);
                }
				break;
			}
			case 4:{
				char answer[100];
                printf("Nhap vao sinh vien ban muon xoa: \n");
                gets(answer);
                int deleteIndex = searchStudent(studentList, currentSize, answer);
                if (deleteIndex != -1)
                {
                    for (int i = deleteIndex; i < currentSize; i++)
                    {
                        studentList[i] = studentList[i + 1];
                    }
                    currentSize--;
                    displayStudent(studentList, currentSize);
                }
				break;
			}
			
			case 5:{
				char answer[50];
				gets(answer);
				int arrange= searchStudent(studentList,currentSize,answer);
				for (int i = 0; i < currentSize - 1; i++) {
                    for (int j = 0; j < currentSize - i - 1; j++) {
                        if (studentList[j].id > studentList[j + 1].id) {
                            struct Student temp = studentList[j];
                            studentList[j] = studentList[j + 1];
                            studentList[j + 1] = temp;
                        }
                    }
                    printf("Danh sach sinh vien sau khi sap xep\n ");
                    displayStudent(studentList,currentSize);
                }
				break;
	     	}
			   
            case 6: {
                char answer[50];
                printf("Nhap vao ten sinh vien can tim: ");
                scanf("%s", answer);
                displayStudent(studentList, currentSize);
                int index = binarySearch(studentList, 0, currentSize - 1, answer);
                if (index != -1) {
                    printf("Thong tin sinh vien tim kiem theo ten:\n");
                    displayStudent(&studentList[index], 1);
                } else {
                    printf("Khong tim thay sinh vien co ten nay.\n");
                }
                 break;
            }
            case 7: {
                int status;
                printf("Nhap vao status can tim: ");
                scanf("%d", &status);
                searchByStatus(studentList, currentSize, status);
                break;
            }
			case 8:
				printf("Thoat chuong trinh\n");
				break;
			default:
				printf("lua chon khong hop le\n");
				
		}
	} while(choice!=8);
}
