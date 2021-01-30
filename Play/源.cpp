#include <stdio.h>
#include"graphics.h"
#include"标头.h"
record picture[20];
Array array[50];
int main()
{
	initgraph(1024, 768);
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));
	setcolor(EGERGB(0x0, 0x0, 0x0));
	setfont(30, 0, "微软雅黑");
	int num;
	char a0[50],arr[50];
	char a1[50], a2[50], a3[50],name1[50],a4[50], a5[50], a6[50],a7[50],a8[50],a9[50];
	text = fopen("records.txt", "r+");
	rewind(text);
	if (text != NULL)
	{
		fscanf(text, "%s", a0);
		num = atoi(strtok(a0, "图形个数："));
		for (int i = 0; i <= num - 1; i++)
		{
			fscanf(text, "%s", a1);
			strcpy(picture[i].name, strtok(a1, "（"));
			fscanf(text, "%s%s%s", a2, a3, a4);
			strcpy(a4, strtok(a4, "（"));
			picture[i].colors[1] = atoi(a2);
			picture[i].colors[2] = atoi(a3);
			picture[i].colors[3] = atoi(a4);
			fscanf(text, "%s%s%s", a5, a6, a7);
			strcpy(a7, strtok(a7, "（"));
			picture[i].fillcolors[1] = atoi(a5);
			picture[i].fillcolors[2] = atoi(a6);
			picture[i].fillcolors[3] = atoi(a7);
			fscanf(text, "%s", a8);
			picture[i]._sides = atoi(strtok(a8, "（"));
			fscanf(text, "%s", a9);
			picture[i]._radius = atoi(strtok(a9, "（"));
			for (int k = 0; k <= 49; k++)
			{
				fscanf(text, "%s", array[k].array);
				if (strlen(array[k].array) >= 5)
					strcpy(array[k].array, strtok(array[k].array, "（"));
				picture[i]._coord[k] = atoi(array[k].array);
			}
		}
		xyprintf(10,10,"%s",a3);
	}
	getch();
	closegraph();
    return 0;
}