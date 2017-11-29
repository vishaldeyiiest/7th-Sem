{
	int b, c;
	int a = (a-b) + (b-c) + (b-c);
	
	if(a > 100)
		a = c + b * (c+a)/b;
	while(c)
	{
		if(a < c)
			b += b*c + b/(a+c*10);
		else
			c++;
	}
}
