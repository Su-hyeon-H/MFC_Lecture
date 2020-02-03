#include <math.h>
#include <stdio.h>
/*
struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point pos1,pos2;
	double distance;
	fputs("point1 pos: ", stdout);
	scanf("%d %d", &pos1.xpos, &pos1.ypos);

	fputs("point2 pos: ", stdout);
	scanf("%d %d", &pos2.xpos, &pos2.ypos);

	distance=sqrt((double)((pos1.xpos -pos2.xpos) * (pos1.xpos-pos2.xpos)+
		(pos1.ypos-pos2.ypos) * (pos1.ypos-pos2.ypos)));
	printf(" 두점의 거리는 %g 입니다. \n", distance);

	return 0;
}
*/

/*
struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void)
{
	struct person arr[3]={
		{"이승기","010-1212-0001", 21},
		{"정지영","010-1313-0002", 22},
		{"한지수","010-1717-0003", 19}
	};
	int i;
	for (i=0; i<3; i++)
		printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);

	return 0;
}
*/
struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point pos1={1,2};
	struct point pos2={100,200};
	struct point *pptr=&pos1;

	(*pptr).xpos += 4;
	(*pptr).ypos += 5;
	printf("[%d, %d] \n",pptr->xpos, pptr->ypos);

	pptr=&pos2;
	pptr->xpos +=1;
	pptr->ypos +=2;
	printf("[%d, %d] \n",(*pptr).xpos, (*pptr).ypos);
	return 0;
}
