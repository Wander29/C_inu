#include <stdio.h>

int main(){
	int s, m, h;
	scanf("%d",&s);
	if ( s<0 )
	{
		printf("invalid input");
	} else {
		h = (int) s/3600;
		if( h>0 )
			s -= h*3600;
		m = (int) s/60;
		if( m>0 )
			s -= m*60;
		printf("%d h %d min %d s", h, m, s);
	}
	return 0;
}

/* METODO 2 monoRow
#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    printf("%d h %d min %d s", x/3600, (x%3600/60), ((x%3600)%60) );
    return 0;
}
*/