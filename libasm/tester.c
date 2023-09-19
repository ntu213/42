/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amori <amori@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:02:37 by amori             #+#    #+#             */
/*   Updated: 2023/09/19 12:03:15 by amori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

extern size_t	ft_strlen(const char *str);
extern size_t	ft_write(int fd, const char *str, size_t size);
extern size_t	ft_read(int fd, const char *str, size_t size);
extern char		*ft_strcpy(const char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strdup(const char *str);
extern int		ft_atoi_base(char *str, char *base);
extern void		ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin_list);

int	list_tester()
{
	int out = 0;

	printf("\n☆ ft_list_push_front\n");

	t_list *list = NULL;
	char *data = malloc(sizeof(char) * 6);
	char *data2 = malloc(sizeof(char) * 6);
	strcpy(data, "Hello");
	strcpy(data2, "Heyyy");
	ft_list_push_front(&list, data);
	ft_list_push_front(&list, data2);

	if (list && list->next)
	{
		printf("Your list : %s -> %s | Real list : %s -> %s | %s", (char *)list->data, (char *)list->next->data, "Heyyy", "Hello", (strcmp((char *)list->data, "Heyyy") == 0 && strcmp((char *)list->next->data, "Hello") == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
		if (strcmp((char *)list->data, "Heyyy") != 0 || strcmp((char *)list->next->data, "Hello") != 0)
			out = 1;
	}
	else
	{
		printf("Your list is empty or half empty | %s", "\x1B[31mKO\x1B[0m\n");
		out = 1;
	}

	printf("\n☆ ft_list_size\n");

	int size = ft_list_size(list);
	int sizeNull = ft_list_size(NULL);

	printf("Your : %d | Real : %d | %s", size, 2, (size == 2) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Your : %d | Real : %d | %s", sizeNull, 0, (sizeNull == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	while (list)
	{
		t_list *tmp = list->next;
		if (list->data)
			free(list->data);
		free(list);
		list = tmp;
	}

	return (out);
}

int	atoi_base_tester()
{
	int	out = 0;

	printf("\n☆ atoi_base\n");

	int nbA = ft_atoi_base("42", "0123456789");
	int nbB = ft_atoi_base("-42", "0123456789");
	int nbC = ft_atoi_base("2A", "0123456789ABCDEF");
	int nbF = ft_atoi_base("pei", "poneyvif");
	int nbD = ft_atoi_base("12a34", "0123456789");
	int nbE = ft_atoi_base("\r\n\t\f\v-37", "0123456789");
	int nbG = ft_atoi_base("+42", "0123456789");
	int nbH = ft_atoi_base("42", "01+234\r56789-");

	printf("42 b10 | Your : %d | Real : %d | %s", nbA, 42, (nbA == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("-42 b10 | Your : %d | Real : %d | %s", nbB, -42, (nbB == -42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("2A b16 | Your (2A bas 16) : %d | Real : %d | %s", nbC, 42, (nbC == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("pei bPoneyvif | Your : %d | Real : %d | %s", nbF, 30, (nbF == 30) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("12a34 b10 | Your : %d | Real : %d | %s", nbD, 12, (nbD == 12) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("\\r\\n\\t\\f\\v -37 b10 | Your : %d | Real : %d | %s", nbE, -37, (nbE == -37) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("+42 b10 | Your : %d | Real : %d | %s", nbG, 42, (nbG == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("42 (invalid base) | Your : %d | Real : %d | %s", nbH, 0, (nbH == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (nbA != 42 || nbB != -42 || nbC != 42 || nbF != 30 || nbD != 12 || nbE != -37 || nbG != 42 || nbH != 0)
		out = 1;

	return (out);
}

int	strdup_tester()
{
	int out = 0;

	printf("\n☆ strdup\n");

	char *str_1 = "Hello World!";
	char *str_2 = ft_strdup(str_1);
	char *str_3 = strdup(str_1);

	printf("Your : %s | Real : %s | %s", str_2, str_3, (strcmp(str_2, str_3) == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(str_2, str_3) != 0)
		out = 1;

	free(str_2);
	free(str_3);

	char *str_4 = ft_strdup("");
	char *str_5 = strdup("");

	printf("Your : %s | Real : %s | %s", str_4, str_5, (strcmp(str_4, str_5) == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(str_4, str_5) != 0)
		out = 1;

	free(str_4);
	free(str_5);

	return (out);
}

int	read_tester()
{
	int	out = 0;

	printf("\n☆ read\n");

	int fd = open("tester.c", O_RDONLY);
	int fd2 = open("tester.c", O_RDONLY);

	char *str_1 = calloc(sizeof(char), 13);
	char *str_2 = calloc(sizeof(char), 13);

	int sizeA = ft_read(fd, str_1, 13);
	int sizeB = read(fd2, str_2, 13);

	printf("Your : %d %s | Real : %d %s | %s", sizeA, str_1, sizeB, str_2, (strcmp(str_1, str_2) == 0 && sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(str_1, str_2) != 0)
		out = 1;

	sizeA = ft_read(-1, str_1, 0);
	int erreurA = errno;

	sizeB = read(-1, str_2, 0);
	int erreurB = errno;

	printf("Your : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Your errno : %d | Real errno : %d | %s", erreurA, erreurB, (erreurA == erreurB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB || erreurA != erreurB)
		out = 1;

	free(str_1);
	free(str_2);
	close(fd);
	close(fd2);
	return (out);
}

int	strcmp_tester()
{
	int	out = 0;

	printf("\n☆ strcmp\n");

	char *str_1 = "Hello World!";
	char *str_2 = "not Hello World!";

	int cmpA = ft_strcmp(str_1, str_2);
	int cmpB = strcmp(str_1, str_2);

	printf("Your : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (cmpA != cmpB)
		out = 1;

	cmpA = ft_strcmp(str_2, str_1);
	cmpB = strcmp(str_2, str_1);

	printf("Your : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (cmpA != cmpB)
		out = 1;

	cmpA = ft_strcmp(str_1, str_1);
	cmpB = strcmp(str_1, str_1);

	printf("Your : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (cmpA != cmpB)
		out = 1;

	return (out);
}

int	strcpy_tester()
{
	int out = 0;

	printf("\n☆ strcpy\n");

	char *str_1 = "Hello World!";
	char *str_2 = calloc(sizeof(char), 13);
	char *str_3 = calloc(sizeof(char), 13);

	char *strA = ft_strcpy(str_2, str_1);
	char *strB = strcpy(str_3, str_1);

	printf("Your : %s | Real : %s | %s", strA, strB, (strcmp(str_1, str_2) == 0 && strA == str_2 && strB == str_3) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(strA, strB) != 0)
		out = 1;

	free(str_2);
	free(str_3);

	char *str_4 = "";
	char *str_5 = calloc(sizeof(char), 1);
	char *str_6 = calloc(sizeof(char), 1);

	strA = ft_strcpy(str_5, str_4);
	strB = strcpy(str_6, str_4);

	printf("Your : %s | Real : %s | %s", strA, strB, (strcmp(str_4, str_5) == 0 && strA == str_5 && strB == str_6) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(strA, strB) != 0)
		out = 1;

	free(str_5);
	free(str_6);

	return (out);
}

int	write_tester()
{
	int out = 0;

	printf("\n☆ write\n");

	int sizeA = ft_write(1, "Hello World!\n", 13);
	int sizeB = write(1, "Hello World!\n", 13);

	printf("Your : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB)
		out = 1;

	sizeA = ft_write(1, "Hello World!\n", 0);
	sizeB = write(1, "Hello World!\n", 0);

	printf("Your : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB)
		out = 1;

	sizeA = ft_write(-1, "Hello World!\n", 13);
	int erreurA = errno;
	sizeB = write(-1, "Hello World!\n", 13);
	int erreurB = errno;

	printf("Your : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Your errno : %d | Real errno : %d | %s", erreurA, erreurB, (erreurA == erreurB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB || erreurA != erreurB)
		out = 1;

	return (out);
}

int	strlen_tester()
{
	char	*str_1 = "Hello World!";

	int		lenA = ft_strlen(str_1);
	int		lenB = strlen(str_1);

	printf("\n☆ ft_strlen\n");

	printf("Your : %d | Real : %d | %s", lenA, lenB, (lenA == lenB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	return (lenA == lenB) ? 0 : 1;
}

int	main()
{
	printf("✿ Libasm tester ✿\n");

	int ok = 0;

	ok += strlen_tester();
	ok += write_tester();
	ok += strcpy_tester();
	ok += strcmp_tester();
	ok += read_tester();
	ok += strdup_tester();
	printf("\n✿ Libasm Bonus ✿\n");
	ok += atoi_base_tester();
	ok += list_tester();

	if (ok == 0)
		printf("\x1B[32m\nAll tests passed ✔\x1B[0m\n");
	else
		printf("\x1B[31m\nSome tests failed ❌\x1B[0m\n\n");
}
