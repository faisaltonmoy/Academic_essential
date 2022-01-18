parent('manjur','sohel'). parent('manjur','tufel').
parent('manjur','jerin'). parent('manjur','najnin').
parent('tufel','rifat'). parent('jerin','raaj').

grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
findGp :- write('Grandchildren: '), read(X), write('Grandparent: '),
	grandparent(Gp, X), write(Gp), tab(5), fail.
findGp.
