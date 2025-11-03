


 #include <stdio.h>
 char	*ft_strcpy(char *dst, const char *src)
{
	int size;

	size = 0;
	while (src[size] != '\0')
	{
		dst[size] = src[size];
		size++;
	}
	dst[size] = '\0';
	return (dst);
}
 int ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
 char *solvecode(char *code, int key)
 {
	int upper;
	int i;
	int keyi;


	
		i = 0;
		while (code[i] != '\0')
		{
			keyi = 0;
			upper =0;
			if ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z'))
			{
				if (code[i] >= 'A' && code[i] <= 'Z')
				{
					code[i] += 32;
					upper = 32;
				}
				while (keyi < key)
				{
				keyi++;
				code[i] += 1;
				if (code[i] > 'z') 
					code[i] -= 26;
				if (code[i] < 'a') 
					code[i] += 26;
				}
				code[i] -= upper;
			}
		i ++;
	}
	return(code);
	
 }
 char *findkey(char *code, int key, int leng)
 {
	int upper;
	int i;
	int keyi;
	i = 0;
	while (code[i] != '\0' && leng > 0)
	{
		keyi = 0;
		upper =0;
		if ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z'))
		{
			if (code[i] >= 'A' && code[i] <= 'Z')
			{
				code[i] += 32;
				upper = 32;
			}
			while (keyi < key)
				{
				keyi++;
				code[i] += 1;
				if (code[i] > 'z') 
					code[i] -= 26;
				if (code[i] < 'a') 
					code[i] += 26;
				}
			code[i] -= upper;
		}
		i ++;
		leng--;
	}
	code[i] = '\0';
	return(code);
 }

int main()
{
	char code[100000];
	char tmpcode[100000];
	char answer[100000] = "1";
	int key;
	int leng;



	leng =0;
	key = 0;
	
	printf("input the code.\n");
	scanf("%[^\n]%*c", code);
	printf("do you know the key?\n y/n\n");
	scanf("%s", answer);
	ft_strcpy(tmpcode, code);
	if (answer[0] == 'y')
	{
		printf("good, please enter the key\n");
		scanf("%d", &key);
		printf("%s", solvecode(code, key));
	}
	else if (answer[0] == 'n')
	{
		printf("Let's try to break it.\n\
I will give you the first X characters of it, and then yoh project in the 42 Commou can say if it is good.\n\
Please select X\n");
		scanf("%d", &leng);
		while ((answer[0] != 'q' && answer[0] != 'f' && answer[0] != 'y' )&& key < 26)
		{
			key++;
			
			printf("%s\nis that good?\n input. q to stop, f or y for found, and anything for no\n",findkey(tmpcode,1, leng));
			scanf("%s", answer);
		}
		if (answer[0] == 'f' || answer[0] == 'y')
			printf("Great! the key is %d\nThe code is:\n%s\n", key, solvecode(code, key));
		
	}
	
}

//Rnpu cebwrpg va gur 42 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, jvgu n svany cevmr sbe bar fghqrag. Fgnss zrzoref znl cnegvpvcngr ohg ner abg ryvtvoyr sbe n cevmr. Ner lbh nzbat gur irel svefg gb fbyir n pvepyr? Fraq gur uvagf jvgu rkcynangvbaf gb by@42.se gb or nqqrq gb gur yrnqreobneq. Gur uvag sbe guvf svefg cebwrpg, juvpu znl pbagnva nantenzzrq jbeqf, vf: Jbys bs ntragvir cnegvpyrf gung qvfcebir terral gb lbhe ubzrf qan gung cebjfr lbhe fgbby