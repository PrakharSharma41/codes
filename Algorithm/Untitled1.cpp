#include <stdio.h>
#include <stdlib.h>
#define mem_size 1024
int memory[mem_size] = {0};

void show_memory()
{
	int i;
	for ( i = 0; i < mem_size; i++)
	{
		printf("%d | ", memory[i]);
	}

	printf("\n\n\n\n\n");
}

void allocate(int process_no, int st, int en)
{
	int i;
	for ( i = st; i < en; i++)
	{
		memory[i] = process_no;
	}
}

void first_fit(int process_no, int size)
{
	int i,st = -1, en = -1, flag = 0, flag1 = 0;
	for ( i = 0; i < mem_size; i++)
	{
		if (memory[i] == 0)
		{
			if (flag1 == 0)
			{
				st = i;
				flag = 1;
				flag1 = 1;
			}
		}
		else
		{
			if (flag == 1)
			{
				en = i;
				if (en - st >= size)
				{
					break;
				}
				else
				{
					st = -1;
					en = -1;
					flag = 0;
					flag1 = 0;
				}
			}
		}
	}

	if (st != -1 && en == -1)
	{
		en = mem_size;
	}

	if (st != -1 && en != -1 && en - st >= size)
	{
		allocate(process_no, st, en);
		show_memory();
	}
	else
	{
		printf("Cannot allocate\n\n");
	}
}

void best_fit(int process_no, int size)
{
	int i,st = -1, en = -1, flag = 0, flag1 = 0, smallest = mem_size, final_st = -1, final_en = -1;
	for ( i = 0; i < mem_size; i++)
	{
		if (memory[i] == 0)
		{
			if (flag1 == 0)
			{
				st = i;
				flag = 1;
				flag1 = 1;
			}
		}
		else
		{
			if (flag == 1)
			{
				en = i;
				if ((en - st) >= size && (en - st) < smallest)
				{
					smallest = (en - st);
					final_st = st;
					final_en = en;
				}
				st = -1;
				en = -1;
				flag = 0;
				flag1 = 0;
			}
		}
	}

	if (final_st != -1 && final_en == -1)
	{
		final_en = mem_size;
	}

	if ((final_st != -1) && (final_en != -1) && ((final_en - final_st) >= size))
	{
		allocate(process_no, final_st, final_en);
		show_memory();
	}
	else
	{
		printf("Cannot allocate\n\n");
	}
}

void worst_fit(int process_no, int size)
{
	int i,st = -1, en = -1, flag = 0, flag1 = 0, largest = 0, final_st = -1, final_en = -1;
	for ( i = 0; i < mem_size; i++)
	{
		if (memory[i] == 0)
		{
			if (flag1 == 0)
			{
				st = i;
				flag = 1;
				flag1 = 1;
			}
		}
		else
		{
			if (flag == 1)
			{
				en = i;

				if ((en - st) > largest)
				{
					largest = (en - st);
					final_st = st;
					final_en = en;
				}

				st = -1;
				en = -1;
				flag = 0;
				flag1 = 0;
			}
		}
	}

	if (final_st != -1 && final_en == -1)
	{
		final_en = mem_size;
	}

	if ((final_st != -1) && (final_en != -1) && ((final_en - final_st) >= size))
	{
		allocate(process_no, final_st, final_en);
		show_memory();
	}
	else
	{
		printf("Cannot allocate this process\n\n");
	}
}

int main()
{
	int upper = 20;
	int lower = 1;
	int st = 0;
	int i, j = 0;
	printf("Adsad\n");
	for (i = 0; i < 10; i++)
	{
		int size = (rand() % (upper - lower + 1)) + lower;
		printf("size is %d\n",size);
		int en = st + size;
		for (j = st; j < en; j++)
		{
			memory[j] = i + 1;
		}

		st = (rand() % (100 - 1 + 1)) + 1 + j;
		printf("start is %d\n",st);
	}

	show_memory();

	char cont = 'y';
	int process_no = 10;

	while (cont == 'y')
	{
		process_no++;
		int size;
		printf("Please enter a size for the process between 1 to 50 : ");
		scanf("%d", &size);
		int option;
		printf("Choose any one option:\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			first_fit(process_no, size);
			break;
		case 2:
			best_fit(process_no, size);
			break;
		case 3:
			worst_fit(process_no, size);
			break;
		}

		printf("\n\nDo you want to continue(y/n) : ");
		scanf(" %c", &cont);
	}
	return 0;
}
