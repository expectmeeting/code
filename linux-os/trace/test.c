/*************************************************************************
    > File Name: test.c
    > Author: DHD
    > Mail: 
    > Created Time: 2020年10月29日 星期四 23时27分15秒
 ************************************************************************/

#include<stdio.h>


#define TP(args...) printf("%s",##args)
#define Tx(args...) printf("%s",args)

#define ARG(args...) args
#define PAR(args...) args

#define funca(proto) \
	void test(proto);

#define func(proto) funca(PAR(proto))
#define fund(proto) funca(proto)
#define DOGS { C(JACK_RUSSELL), C(BULL_TERRIER), C(ITALIAN_GREYHOUND)  }
#undef C
#define C(a) ENUM_##a
#undef C
#define C(a) #a

enum dog_enums DOGS;
char *dog_strings[] = DOGS;
char *dog_to_string(enum dog_enums dog)
{
	       return dog_strings[dog];
		   
}
int main()
{
	func(ARG(int a,int b))
	PAR(ARG(int a,int b));
	funca(ARG(int a,int b))
	TP(int i,char j);
TP(x,y);
Tx(x,y);
    ##TP(int i,char j);
    Tx(int i,char j);
	return 0;
}
