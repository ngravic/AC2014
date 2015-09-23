myFloat sum(myFloat a, myFloat b) {
	myFloat toRet, may, min;
	may_exp = a.e >= b.e ? a : b;
	men_exp = a.e >= b.e ? b : a;
	int rot_qty = may_exp.e - men_exp.e;
	toRet.m = men_exp.m >> rot_qty; // VER LO DEL SHIFT QUE RELLENA CON 1
	
	if( may_exp.s == men_exp.s ) {
		toRet.s = a.s;
		toRet.m += may_exp.m;
	}
	else {
		
		if (may_exp.e != men_exp.e){
			toRet.s = may_exp.s == 1 ? 1 : 0 ;
		}
		else {
			toRet.s = may_exp.m > men_exp.m ? 1 : 0 ;
		}
		toRet.m -= may_exp.m;;
	}
	toRet.e = may_exp.e;
	if (toRet.m >> 15 == 1){    // VER LO DEL SHIFT QUE RELLENA CON 1, si empieza con 1 siempre va a dar true esto, y va a rotarlo igual. El while iba a explotar
		toRet.m = toRet.m >> 1;
		toRet.e++;
	}

	return toRet;
}

myFloat sum(myFloat a, myFloat b) {
	myFloat toRet;
	toRet.e = a.e + b.e - 30000; // Esto es porque cada exponente es 30000+exponente. Si sumas 2 exponentes tenes e1 + e2 + 30000 + 30000. Queremos e1+e2+30000
	toRet.m = a.m * b.m ; // No se como decirle que redondee a 18 cifras este número
	// Capaz se pueda rotar a la derecha rellenando con 0, 18 lugares y después volverlos, no se
	toRet.s = a.s == b.s ? 1 : 0 ;
	return toRet;
}
