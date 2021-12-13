#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
int main()
{  
	printf("Enter PID : ");
	char str[20];
	long pid;
	
	scanf("%[^\n]%*c",str);
	
	pid = atoi(str);
	long temp = syscall(335, pid, ""); 
	if(temp == 0) 
		printf("'sh_task_info' executed successfully\n");

	else 
	{
		if(pid<0 || pid>=32768){
			printf("Error...-1\n");
		}
		else{
			printf("Error...-2\n");
		}
		perror("Error ");
		printf("'sh_task_info' didn't execute with Error No.: %d\n", errno);
	}
	return 0;
}
