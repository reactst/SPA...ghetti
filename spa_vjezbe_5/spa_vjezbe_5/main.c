#include "dictionary.h"

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict;
	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}
	dict = create();
	while (readWord(fd, buffer))
	{
		add(dict, buffer);
	}
	fclose(fd);
	print(dict);
	filterDictionary(dict, filter);
	printf("\n\n\n");
	printf("Filtrinaraanranran rjecnik:\n");
	printf("\n\n\n");
	print(dict);
	destroy(dict);

}