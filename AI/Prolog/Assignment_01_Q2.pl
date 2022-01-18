parent('manjur','sohel'). parent('manjur','tufel').
parent('manjur','jerin'). parent('manjur','najnin').
parent('tufel','rifat'). parent('jerin','raaj').

male('manjur'). male('sohel').
male('tufel').  male('rifat'). male('raaj').

female('jerin'). female('najnin').

brother(X,Y):-parent(Z,X), parent(Z,Y), male(X), not(X=Y).
findBr :- write(' Sibling: '), read(X), write('brother: '),
	brother(Br, X), write(Br), tab(5), fail.
findBr.

sister(X,Y):-parent(Z,X), parent(Z,Y),female(X), not(X=Y).
findSr :- write(' sibling: '), read(X), write('sister: '),
	sister(Sr, X), write(Sr), tab(5), fail.
findSr.

aunt(X,Y):-parent(Z,Y), sister(X,Z).
findAt :- write(' Nephew: '), read(X), write('aunt: '),
	aunt(At,X), write(At), tab(5), fail.
findAt.


uncle(X,Y):-parent(Z,Y), brother(X,Z).
findUl :- write(' Nephew: '), read(X), write('uncle: '),
	uncle(Ul,X), write(Ul), tab(5), fail.
findUl.

