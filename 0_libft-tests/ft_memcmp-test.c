#include "../0_libft/inc/libft.h"

void	test_ft_memcmp(bool testmode, const void *s1, const void *s2, size_t n)
{
	int ret;
	printf("Comparing %zu chars of s1 and s2, where:\n", n);
	printf("- s1 is: \"%s\"\n", s1);
	printf("- s2 is: \"%s\"\n", s2);
	if (testmode)
		ret = memcmp(s1, s2, n);
	else
		ret = ft_memcmp(s1, s2, n);
	if(ret > 0)
		printf("RESULT: ft_memcpy returns %i, meaning s2 is less than s1", ret);
	else if(ret < 0)
		printf("RESULT: ft_memcpy returns %i, meaning s1 is less than s2", ret);
	else
		printf("RESULT: ft_memcpy returns %i, meaning s1 is equal to s2", ret);
	printf("\n\n");
}

void	tests_ft_memcmp(bool testmode)
{
	test_ft_memcmp(testmode, "123456", "789101", 6);
	test_ft_memcmp(testmode, "ABCDEF", "ABCDEF", 6);
	test_ft_memcmp(testmode, "zooble", "zoomle", 6);
	test_ft_memcmp(testmode, "a thing with spaces", "a thing with faces", 6);
	test_ft_memcmp(testmode, "a thing with spaces", "a thing with faces", 19);	
	test_ft_memcmp(testmode, "aabbccddeeff", "aabbccddeegg", 10);
	test_ft_memcmp(testmode, "aabbccddeeff", "aabbccddeegg", 12);		
}

int   main(int argc, char **argv)
{
   (void)argc;
   if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
   {
      printf("--- RUNNING %s [original]\n", argv[0] + 5);
      tests_ft_memcmp(true);
   }
   else
   {
      printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
      tests_ft_memcmp(false);
   }
   return 0;
}