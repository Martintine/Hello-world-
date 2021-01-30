#include"graphics.h"
struct _color/*vs只支持这种结构体定义形式*/
{
	int red;
	int green;
	int blue;
};
struct _fillcolor
{
	int red;
	int green;
	int blue;
};
_color color;
_fillcolor fillcolor;
void savecolor(char c, int i)/*i为0则保存颜色，为1则保存填充颜色*/
{
	if (c == 'r' && i == 0)
	{
		color.red = 0xFF;
		color.green = 0x0;
		color.blue = 0x0;
	}
	if (c == 'g' && i == 0)
	{
		color.red = 0x0;
		color.green = 0xFF;
		color.blue = 0x0;
	}
	if (c == 'b' && i == 0)
	{
		color.red = 0x0;
		color.green = 0x0;
		color.blue = 0xFF;
	}
	if (c == 'r' && i == 1)
	{
		fillcolor.red = 0xFF;
		fillcolor.green = 0x0;
		fillcolor.blue = 0x0;
	}
	if (c == 'g' && i == 1)
	{
		fillcolor.red = 0x0;
		fillcolor.green = 0xFF;
		fillcolor.blue = 0x0;
	}
	if (c == 'b' && i == 1)
	{
		fillcolor.red = 0x0;
		fillcolor.green = 0x0;
		fillcolor.blue = 0xFF;
	}
}
int main()
{
	initgraph(1024, 768);
	setfont(27, 0, "微软雅黑");
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));
	setcolor(EGERGB(0x0, 0x0, 0x0));
	for (int i = 0; i == 0;)
	{
		xyprintf(10, 10, "请选择你想要画的颜色:");
		xyprintf(250, 10, "1,红色");
		xyprintf(330, 10, "2,绿色");
		xyprintf(410, 10, "3,蓝色");
		char cv3;
		cv3 = getch();
		switch (cv3)
		{
		case'1':
		{
			savecolor('r', 0);
			i = 1;
			break;
		}
		case'2': {
			savecolor('g', 0);
			i = 1;
			break;
		}
		case'3': {
			savecolor('b', 0);
			i = 1;
			break;
		}
		default: xyprintf(490, 10, "请输入正确的数字");
		}
	}
	for (int i = 0; i == 0;)
	{
		xyprintf(10, 40, "请选择你想填充的颜色:");
		xyprintf(250, 40, "1,红色");
		xyprintf(330, 40, "2,绿色");
		xyprintf(410, 40, "3,蓝色");
		char cv4;
		cv4 = getch();
		switch (cv4)
		{
		case'1':
		{
			savecolor('r', 1);
			i = 1;
			break;
		}
		case'2': {
			savecolor('g', 1);
			i = 1;
			break;
		}
		case'3': {
			savecolor('b', 1);
			i = 1;
			break;
		}
		default: xyprintf(490, 40, "请输入正确的数字");
		}
	}
	char points[100],width[5];
	int coord[100], w;
	inputbox_getline("画多边形", "请输入线宽", width, 5);
	inputbox_getline("画多边形", "请输入多边形各顶点的坐标", points, 100);
	char* tokenPtr = strtok(points, ",");
	int i = 0;
	while (tokenPtr != NULL)
	{
		coord[i++] = atoi(tokenPtr);
		tokenPtr = strtok(NULL, ",");
	}
	setcolor(EGERGB(color.red, color.green, color.blue));
	setfillcolor(EGERGB(fillcolor.red, fillcolor.green, fillcolor.blue));
	fillpoly((i + 1) / 2, coord);
	getch();
	getch();
	closegraph();
	return 0;
}