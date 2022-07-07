#include <string>
#include <cstdio>

int solve(const std::string& eq) {
	size_t size = eq.length();
	printf("tamaño ecuación: %d\n", size);
	size_t found = eq.find_first_of("x=", 0);
	if (eq[found] == 'x') {
		printf("izq: %c\n", eq[found]);
	}
	else {
		printf("der: %c\n", eq[found]);
	};

	//while (found != std::string::npos) {
		//str[found]='*';
		//found = std::str.find_first_of("",found+1);
	//}

	return 0;
}

int main(int argc, char *argv[])
{
	int ans = solve("x = 1 + 2");
	printf("ans: %d\n", ans);
	return 0;
}
