/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amori <amori@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:02:37 by amori             #+#    #+#             */
/*   Updated: 2023/09/19 19:04:17 by amori            ###   ########.fr       */
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

size_t	ft_strlen(const char *str);
size_t	ft_write(int fd, const char *str, size_t size);
size_t	ft_read(int fd, const char *str, size_t size);
char	*ft_strcpy(const char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_func)());
void	ft_list_sort(t_list **begin_list, int (*cmp)());

int		cmp_sort(void *data1, void *data2) { return ((void *)data1 > (void *)data2); }
int		list_sort_tester()
{
	int	out = 0;

	printf("\n☆ ft_list_sort\n");

	t_list *elem1 = malloc(sizeof(t_list));
	t_list *elem2 = malloc(sizeof(t_list));
	t_list *elem3 = malloc(sizeof(t_list));

	elem1->data = (void *)1;
	elem1->next = elem2;
	elem2->data = (void *)2;
	elem2->next = elem3;
	elem3->data = (void *)3;
	elem3->next = NULL;
	ft_list_sort(&elem1, cmp_sort);
	printf("Yours : %p -> %p -> %p | Real : %p -> %p -> %p | %s", elem1->data, elem1->next->data, elem1->next->next->data, (void *)1, (void *)2, (void *)3, (elem1->data == (void *)1 && elem1->next->data == (void *)2 && elem1->next->next->data == (void *)3) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	if (elem1->data != (void *)1 || elem1->next->data != (void *)2 || elem1->next->next->data != (void *)3)
		out = 1;

	elem1->data = (void *)42;
	elem2->data = (void *)36;
	elem3->data = (void *)12;
	ft_list_sort(&elem1, cmp_sort);
	printf("Yours : %p -> %p -> %p | Real : %p -> %p -> %p | %s", elem1->data, elem1->next->data, elem1->next->next->data, (void *)12, (void *)36, (void *)42, (elem1->data == (void *)12 && elem1->next->data == (void *)36 && elem1->next->next->data == (void *)42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	if (elem1->data != (void *)12|| elem1->next->data != (void *)36 || elem1->next->next->data != (void *)42)
		out = 1;

	elem1->next = NULL;
	ft_list_sort(&elem1, cmp_sort);
	printf("Yours : %p | Real : %p | %s", elem1->data, (void *)12, (elem1->data == (void *)12) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	if (elem1->data != (void *)12)
		out = 1;

	elem1 = NULL;
	ft_list_sort(&elem1, cmp_sort);
	printf("Yours : %p | Real : %p | %s", elem1, NULL, "\x1B[32mNo Segfault OK\x1B[0m\n");

	free(elem1);
	free(elem2);
	free(elem3);

	t_list *elem = malloc(sizeof(t_list));
	elem->data = (void *)42;
	elem->next = NULL;
	ft_list_sort(&elem1, NULL);
	printf("NULL comparison | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");
	ft_list_sort(NULL, cmp_sort);
	printf("NULL element | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");

	free(elem);
	return (out);
}

int		cmp(void *data, void *data_ref) { return (data == data_ref); }
void	free_func(void *elem) { free(elem); }
int	list_remove_if_tester()
{
	int out = 0;

	printf("\n☆ ft_list_remove_if\n");

	t_list *elem1 = malloc(sizeof(t_list));
	t_list *elem2 = malloc(sizeof(t_list));
	t_list *elem3 = malloc(sizeof(t_list));

	elem1->data = (void *)42;
	elem1->next = elem2;
	elem2->data = (void *)21;
	elem2->next = elem3;
	elem3->data = (void *)99;
	elem3->next = NULL;

	ft_list_remove_if(&elem1, (void *)21, cmp, free_func);
	if (elem1 && elem1->next)
	{
		printf("Yours : %p -> %p | Real : %p -> %p | %s", elem1->data, elem1->next->data, (void *)42, (void *)99, (elem1->data == (void *)42 && elem1->next->data == (void *)99) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
		if (elem1->data != (void *)42 || elem1->next->data != (void *)99)
			out = 1;
	}
	else
	{
		printf("Your list is empty or half empty | %s", "\x1B[31mKO\x1B[0m\n");
		out = 1;
	}

	ft_list_remove_if(&elem1, (void *)42, cmp, free_func);
	if (elem1)
	{
		printf("Yours : %p | Real : %p | %s", elem1->data, (void *)99, (elem1->data == (void *)99) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
		if (elem1->data != (void *)99)
			out = 1;
	} else
	{
		printf("Your list is empty or half empty | %s", "\x1B[31mKO\x1B[0m\n");
		out = 1;
	}

	ft_list_remove_if(&elem1, (void *)99, cmp, free_func);
	printf("Yours : %p | Real : %p | %s", elem1, NULL, (elem1 == NULL) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	if (elem1 != NULL)
		out = 1;


	t_list *elem = malloc(sizeof(t_list));
	elem->data = (void *)42;
	elem->next = NULL;
	ft_list_remove_if(NULL, (void *)99, cmp, free_func);
	printf("NULL element | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");
	ft_list_remove_if(&elem, (void *)99, NULL, free_func);
	printf("NULL comparison | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");
	ft_list_remove_if(&elem, (void *)99, cmp, NULL);
	printf("NULL free | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");

	free(elem);
	return (out);
}

int	list_size_tester()
{
	int	out = 0;

	t_list *elem1 = malloc(sizeof(t_list));
	t_list *elem2 = malloc(sizeof(t_list));

	char *data = malloc(sizeof(char) * 6);
	char *data2 = malloc(sizeof(char) * 6);

	strcpy(data, "Hello");
	strcpy(data2, "Heyyy");

	elem1->data = data;
	elem1->next = elem2;
	elem2->data = data2;
	elem2->next = NULL;

	printf("\n☆ ft_list_size\n");

	int size = ft_list_size(elem1);
	int sizeNull = ft_list_size(NULL);

	printf("Yours : %d | Real : %d | %s", size, 2, (size == 2) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Yours : %d | Real : %d | %s", sizeNull, 0, (sizeNull == 0) ? "\x1B[32mNo Segfault OK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (size != 2 || sizeNull != 0)
		out = 1;

	free(elem1);
	free(elem2);
	free(data);
	free(data2);

	return (out);
}

int	list_push_front_tester()
{
	int out = 0;

	printf("\n☆ ft_list_push_front\n");

	t_list *list = NULL;
	char *data = malloc(sizeof(char) * 6);
	char *data2 = malloc(sizeof(char) * 11);
	strcpy(data, "Eater");
	strcpy(data2, "Spaghettis");

	ft_list_push_front(&list, data);
	if (list)
	{
		printf("Yours list : %s | Real list : %s | %s", (char *)list->data, "Eater", (strcmp((char *)list->data, "Eater") == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
		if (strcmp((char *)list->data, "Eater") != 0)
			out = 1;
	}
printf("%p\n", list);
	ft_list_push_front(&list, data2);
// printf("%p|%p\n", list, list->next);
	if (list && list->next)
	{
		printf("Yours list : %s -> %s | Real list : %s -> %s | %s", (char *)list->data, (char *)list->next->data, "Spaghettis", "Eater", (strcmp((char *)list->data, "Spaghettis") == 0 && strcmp((char *)list->next->data, "Eater") == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
		if (strcmp((char *)list->data, "Spaghettis") != 0 || strcmp((char *)list->next->data, "Eater") != 0)
			out = 1;
	}
	else
	{
		printf("Your list is empty or half empty | %s", "\x1B[31mKO\x1B[0m\n");
		out = 1;
	}

	while (list)
	{
		t_list *tmp = list->next;
		free(list);
		list = tmp;
	}
	free(data);
	free(data2);

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

	printf("42 b10 | Yours : %d | Real : %d | %s", nbA, 42, (nbA == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("-42 b10 | Yours : %d | Real : %d | %s", nbB, -42, (nbB == -42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("2A b16 | Yours (2A bas 16) : %d | Real : %d | %s", nbC, 42, (nbC == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("pei bPoneyvif | Yours : %d | Real : %d | %s", nbF, 30, (nbF == 30) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("12a34 b10 | Yours : %d | Real : %d | %s", nbD, 12, (nbD == 12) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("\\r\\n\\t\\f\\v-37 b10 | Yours : %d | Real : %d | %s", nbE, -37, (nbE == -37) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("+42 b10 | Yours : %d | Real : %d | %s", nbG, 42, (nbG == 42) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("42 (invalid base) | Yours : %d | Real : %d | %s", nbH, 0, (nbH == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	ft_atoi_base(NULL, "0123456789");
	printf("NULL number | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");
	ft_atoi_base("42", NULL);
	printf("NULL base | %s", "\x1B[32mNo Segfault OK\x1B[0m\n");

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

	printf("Yours : %s | Real : %s | %s", str_2, str_3, (strcmp(str_2, str_3) == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(str_2, str_3) != 0)
		out = 1;

	free(str_2);
	free(str_3);

	char *str_4 = ft_strdup("");
	char *str_5 = strdup("");

	printf("Yours : %s | Real : %s | %s", str_4, str_5, (strcmp(str_4, str_5) == 0) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

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

	int fd = open("help.c", O_RDONLY);
	int fd2 = open("help.c", O_RDONLY);

	char *str_1 = calloc(sizeof(char), 19);
	char *str_2 = calloc(sizeof(char), 19);

	int sizeA = ft_read(fd, str_1, 19);
	int sizeB = read(fd2, str_2, 19);

	printf("Yours : %d \"%s\" | Real : %d \"%s\" | %s", sizeA, str_1, sizeB, str_2, (strcmp(str_1, str_2) == 0 && sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(str_1, str_2) != 0)
		out = 1;

	sizeA = ft_read(-1, str_1, 0);
	int erreurA = errno;

	sizeB = read(-1, str_2, 0);
	int erreurB = errno;

	printf("Yours : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Yours errno : %d | Real errno : %d | %s", erreurA, erreurB, (erreurA == erreurB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

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

	printf("Yours : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (cmpA != cmpB)
		out = 1;

	cmpA = ft_strcmp(str_2, str_1);
	cmpB = strcmp(str_2, str_1);

	printf("Yours : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (cmpA != cmpB)
		out = 1;

	cmpA = ft_strcmp(str_1, str_1);
	cmpB = strcmp(str_1, str_1);

	printf("Yours : %d | Real : %d | %s", cmpA, cmpB, (cmpA == cmpB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

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

	printf("Yours : %s | Real : %s | %s", strA, strB, (strcmp(str_1, str_2) == 0 && strA == str_2 && strB == str_3) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (strcmp(strA, strB) != 0)
		out = 1;

	free(str_2);
	free(str_3);

	char *str_4 = "";
	char *str_5 = calloc(sizeof(char), 1);
	char *str_6 = calloc(sizeof(char), 1);

	strA = ft_strcpy(str_5, str_4);
	strB = strcpy(str_6, str_4);

	printf("Yours : %s | Real : %s | %s", strA, strB, (strcmp(str_4, str_5) == 0 && strA == str_5 && strB == str_6) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

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

	printf("Yours : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB)
		out = 1;

	sizeA = ft_write(1, "Hello World!\n", 0);
	sizeB = write(1, "Hello World!\n", 0);

	printf("Yours : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB)
		out = 1;

	sizeA = ft_write(-1, "Hello World!\n", 13);
	int erreurA = errno;
	sizeB = write(-1, "Hello World!\n", 13);
	int erreurB = errno;

	printf("Yours : %d | Real : %d | %s", sizeA, sizeB, (sizeA == sizeB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Yours errno : %d | Real errno : %d | %s", erreurA, erreurB, (erreurA == erreurB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	if (sizeA != sizeB || erreurA != erreurB)
		out = 1;

	return (out);
}

int	strlen_tester()
{
	char	*str_1 = "Hello World!";

	int		lenA = ft_strlen(str_1);
	int		lenB = strlen(str_1);
	int		lenC = ft_strlen("");
	int		lenD = strlen("");

	printf("\n☆ ft_strlen\n");

	printf("Yours : %d | Real : %d | %s", lenA, lenB, (lenA == lenB) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");
	printf("Yours : %d | Real : %d | %s", lenC, lenD, (lenC == lenD) ? "\x1B[32mOK\x1B[0m\n" : "\x1B[31mKO\x1B[0m\n");

	return (lenA == lenB) ? 0 : 1;
}

int ft_atoi_base_recursive(char *s, char *c);

int	main()
{
	printf("\n \e[1;34mLibasm Basic Tests\e[0m\n");

	int ok = 0;

	ok += strlen_tester();
	ok += write_tester();
	ok += strcpy_tester();
	ok += strcmp_tester();
	ok += read_tester();
	ok += strdup_tester();
	printf("\n \e[1;34mLibasm Bonus Tests\e[0m\n");
	ok += atoi_base_tester();
	ok += list_push_front_tester();
	ok += list_size_tester();
	ok += list_remove_if_tester();
	ok += list_sort_tester();

	if (ok == 0)
		printf("\x1B[32m\n ✔ Obviously, all tests passed ✔\x1B[0m\n\n");
	else
		printf("\x1B[31m\n ❌ Uh... Some tests failed ❌\x1B[0m\n\n");
}
