#include <stdio.h>
#include <stdlib.h>

int compare(const void *value1, const void *value2)
{
	size_t v1 = *(size_t*)value1;
	size_t v2 = *(size_t*)value2;

	if (v1 > v2)
		return (1);
	else if (v1 < v2)
		return (-1);
	else
		return (0);
}

int main()
{
	FILE *input = fopen("input.txt","r");

	char	line[50];
	size_t	max_calories = 0;
	size_t	current_calories = 0;
	size_t	top_calories[3] = {0, 0, 0};

	while (fgets(line, sizeof(line), input))
	{
		if (line[0] == '\n')
		{
			if (current_calories > max_calories)
				max_calories = current_calories;
			
			size_t values[4] = {top_calories[0], top_calories[1], top_calories[2], current_calories};
			qsort((void*)values, 4, sizeof(size_t), &compare);

			for (size_t i = 0; i < 3; i++)
				top_calories[i] = values[3-i];
			
			current_calories = 0;
		}
		else
			current_calories += atoi(line);
	}

	printf("Part one: [%lu] calories\n",max_calories);
	printf("Part two: [%lu] calories\n",top_calories[0] + top_calories[1] + top_calories[2]);
	fclose(input);
}