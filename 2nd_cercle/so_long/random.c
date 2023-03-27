void	main()
{
	void	*a = malloc(1);
	int res = (int)a % 17;
	if (res < 0)
		res *= -1;
	printf("%d | %d\n", res, res % 4);
	free(a);
}