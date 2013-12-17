#include <stdio.h>
#include <string.h>

int main() {
	int max = 0;
	for(int i0=999; i0 > 99; --i0) {
		for(int i1=999; i1 > 99; --i1) {
			int mult = i0*i1;
			char a[7], arev[7] = {};
			sprintf(a, "%d", mult);
			for(int i = strlen(a); i >= 0; --i) {
				sprintf(arev, "%s%c", arev, a[i]);
			}
			if(strcmp(a, arev) == 0 && mult > max) {
				max = mult;
				printf("%s\n", a);
			}
		}
	}
	return 0;
}
