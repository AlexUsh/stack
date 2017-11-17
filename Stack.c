#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = -1;
double stack[100];

void push(double elem)
{
	count++;
	stack[count] = elem;
}

double pop()
{
	double elem = stack[count];
	count--;
	return elem;
}

int main(int argc, char *argv[]) {
    char in[10];
	while(strcmp(in,"=")!=0)
	{
		printf("Enter operand or operator:");
		gets(in);
		char* ends;
        strtol(in, &ends, 10);
		if (ends == strchr(in, '\0') && strcmp(in, "")!=0) {
  			push(atof(in));
		}
		else if (strcmp(in, "=")!=0)
        {
            double b=pop();
            double a=pop();
            double c=0;
            if (strcmp(in, "+")==0)
            {
                c=a+b;
            }
            else if (strcmp(in, "-")==0)
            {
                c=a-b;
            }
            else if (strcmp(in, "*")==0)
            {
                c=a*b;
            }
            else if (strcmp(in, "/")==0)
            {
               c=a/b;
            }
            push(c);
        }
	}
	double y=pop();
	printf("%g", y);
	return 0;
}
