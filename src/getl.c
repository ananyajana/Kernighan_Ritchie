int getl(char s[], int lim)
{
	int c, i;
	i = 0;
	for(i = 0; i < lim - 1 && (c = getchar()) != '@' && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}