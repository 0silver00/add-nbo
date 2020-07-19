#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

/*
uint32_t add-nbo(uint32_t *n){
	return (n & 0xFF000000) >> 24 | (n & 0x00FF0000) >> 8 | (n & 0x0000FF00) << 8 | (n & 0x000000FF) <<24;
}
*/
int main(int argc, char* argv[]){

	FILE *one, *two;
	uint32_t tmp, tmp2, sum;

	one = fopen(argv[1], "r");
	two = fopen(argv[2], "r");

	fread(&tmp, 1, sizeof(uint32_t), one);
	fread(&tmp2, 1, sizeof(uint32_t), two);

	int ht_tmp = htonl(tmp);
	int ht_tmp2 = htonl(tmp2);

	sum = ht_tmp + ht_tmp2;

	printf("%d(0x%2x) + %d(0x%2x) = %d(0x%2x)\n", ht_tmp, ht_tmp, ht_tmp2, ht_tmp2, sum, sum);

	fclose(one);
	fclose(two);


	return 0;
}
