int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;
	return n1;
}

int abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
