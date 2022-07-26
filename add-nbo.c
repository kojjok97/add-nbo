#include <stdio.h>
#include <stdint.h>


uint32_t my_converter(char* number){
	uint32_t num1 = number[0];
	uint32_t num2 = number[1];
	uint32_t num3 = number[2];
	uint32_t num4 = number[3];
	
	return (num1 << 24) + (num2 << 16) + (num3 << 8) + (num4 & 0x000000ff); 
	
	
}


uint32_t main(uint32_t argc, char **argv)
{
	char number1[6];
	char number2[6];
	FILE* file1 = fopen(argv[1],"rb");
	if(file1 == NULL)
	{
		printf("No File");
		return 0;

	}
	
	fread(number1, sizeof(char),6, file1);
	fclose(file1);

	FILE* file2 = fopen(argv[2],"rb");
	if(file2 == NULL)
	{
		printf("No File");
		return 0;
	}
	fread(number2,sizeof(char),6,file2);
	echo
	fclose(file2);

	
	printf("\n\n\n");	


	uint32_t num1 = my_converter(number1);
	uint32_t num2 = my_converter(number2);
	
	printf("%d(1x%x) + %d(0x%x) = %d(0x%x)",num1,num1,num2,num2,(num1+num2),(num1+num2));	
	
	return 0;

}
