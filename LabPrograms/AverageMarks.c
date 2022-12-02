#include<stdio.h>
#include<stdlib.h>

int n, size;

struct student{
	int roll;
	char name[20];
	int marks[3];
	float avg;
};

void read(struct student *ptr){
	printf("Enter number of students \n");
	scanf("%d", &n);
	if(n!=size){
		//reallocate the memory
		ptr = (struct student *)realloc(ptr, n * sizeof(struct student));
	}
	for(int i = 0; i<n ; i++){
		printf("Enter Reg.No., Name of Student (%d)", i+1);
		scanf("%d", &(ptr+i)->roll);
		scanf("%s", (ptr+i)->name);
		printf("Enter marks of 3 tests: \n");
		for(int j = 0; j<3; j++){
			scanf("%d", &(ptr+i)->marks[j]);
		}
	}
}

void display(struct student *ptr){
	for(int i = 0; i<n ; i++){
		printf("Details of %d student\n", i+1);
		printf("Name: %d\n", (ptr+i)->roll);
		printf("Name: %s\n", (ptr+i)->name);
		for(int j = 0; j<3; j++){
			printf("%d\t", (ptr+i)->marks[j]);
			printf("\n");
		}
	}
}

void average(struct student *ptr){
	for(int i = 0; i<n; i++){
		if((ptr+i)->marks[0]<=(ptr+i)->marks[1]&&(ptr+i)->marks[0]<=(ptr+i)->marks[1]){
			(ptr+i)->avg = ((ptr+i)->marks[1]+(ptr+i)->marks[2])/2.0;
		}
		else if((ptr+i)->marks[1]<=(ptr+i)->marks[2]&&(ptr+i)->marks[1]<=(ptr+i)->marks[0]){
			(ptr+i)->avg = ((ptr+i)->marks[0]+(ptr+i)->marks[2])/2.0;
		}
		else{
			(ptr+i)->avg = ((ptr+i)->marks[0]+(ptr+i)->marks[1])/2.0;
		}
		printf("%f\n", (ptr+i)->avg);
	}
}


void main(){
	struct student *s;
	printf("Enter size \n");
	scanf("%d", &size);

	s = (struct student *)malloc(size*sizeof(struct student));

	int choice;

	while(1<2){
		printf("Enter your choice \n 1.Read\n 2.Display\n 3.Average\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				read(s);
				break;
			case 2: 
				display(s);
				break;
			case 3: 
				average(s);
				break;
			default:
				printf("Invalid Choice");
				free(s);
				exit(0);
		}
	}
}