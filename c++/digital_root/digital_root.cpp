/*Digital root is the recursive sum of all the digits in a number.

	Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

	Examples
	16  -->  1 + 6 = 7
	942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
	132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
	493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
	*/

#include <cstdio>

int digital_root(int n);

int main(int argc, char *argv[])
{
	int ans = digital_root(23);
	printf("%d\n", ans);
	return 0;
}


//int digital_root(int n) {
//int suma{};
//while ( n >= 10 ) {
//suma += n % 10;
//n /= 10;
//};
//suma += n;
//return (suma < 10) ? suma : digital_root(suma);
//};

int digital_root(int Z) {
	int a = --Z;
	int b = a % 9;
	int c = b + 1;
	int d = 5 % 9;
	printf("a: %d. b: %d. c: %d", a, b, c);
	printf(" d: %d", d);
	return c;
}
