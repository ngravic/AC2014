/*	| s |		16		|			18			| <- Bits
	| s |		e		|			f			|
	|   |	e - 30000	|						| 
	| 0 |65535 - 30000	|0.111111111111111111111| <- Mayor num representable
	| 1 |	0 - 30000	|0.000000000000000000001| <- Menor num representable
*/

struct
{	
	// __LITTLE_ENDIAN
		unsigned f:18;
		unsigned e:16;
		unsigned s:1;	
	
} myFloat;

#define max(a,b)	a<b?b:a
/*myFloat sum(myFloat a, myFloat b) {

}*/