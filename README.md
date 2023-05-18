# Tema2PA

## Implementare

* problema1/
    * in/
    * ref/
    * cycleDetection.c
    * cycleDetection.h
    * mainPB1.c
    * Makefile
* problema2/
    * in/
    * ref/
    * distances.c
    * distances.h
    * mainPB2.c
    * Makefile
* problema3/
    * in/
    * ref/
    * mainPB3.c
    * Makefile
    * smecheria.c
    * smecheria.h

## Problema 1

init_graph: Inițializează graful G. Inițializează vectorii adj, visited și recursion_stack cu valorile implicite.

add_edge: Adaugă o muchie între nodurile u și v în graf. Crează un nou nod și îl adaugă în lista de adiacență a nodului u.

is_cyclic_util: Funcția recursivă utilizată pentru a verifica dacă există un ciclu în graf, pornind de la nodul u. Marchează nodul u ca vizitat și îl adaugă în stiva de recursivitate. Apoi, pentru fiecare nod adiacent v nevizitat, se verifică dacă acesta este parte a unui ciclu recursiv apelând funcția is_cyclic_util pentru v. Dacă se găsește un ciclu în oricare dintre aceste apeluri recursive, se returnează true. De asemenea, se verifică dacă v se află deja în stiva de recursivitate, caz în care se returnează true. La finalul iterației, se elimină nodul u din stiva de recursivitate și se returnează false.

is_cyclic: Funcția principală pentru detectarea ciclurilor în graf. Inițializează vectorii visited și recursion_stack și apoi parcurge fiecare nod nevizitat al grafului. Pentru fiecare nod nevizitat, se apelează is_cyclic_util pentru a verifica dacă există un ciclu pornind de la acel nod. Dacă se găsește un ciclu, se returnează true. În final, se returnează false dacă nu se găsește niciun ciclu în graf.

## Problema 2

dfs : Funcție auxiliară utilizată în sortarea topologică. Aceasta parcurge în adâncime graful începând de la un nod dat și marchează nodurile vizitate. Odată ce toate nodurile adiacente unui nod au fost vizitate, nodul respectiv este adăugat în vectorul topo în ordinea inversă a parcugerii în adâncime. Astfel, vectorul topo va conține nodurile sortate topologic.

topological_sort : Realizează sortarea topologică pentru graful dat. Parcurge fiecare nod nevizitat și apelează funcția dfs pentru a obține ordinea sortată în vectorul topo. Apoi, inițializează distanțele minime în vectorul dist, unde dist[i] reprezintă distanța minimă de la sursa s la nodul i. Inițial, toate distanțele sunt setate la o valoare infinită (INF), cu excepția nodului sursă s care este setat la 0.

calculate_distances : Calculează distanțele minime de la sursa s către toate celelalte noduri folosind sortarea topologică. Parcurge nodurile din vectorul topo în ordinea inversă și actualizează distanțele minime pentru fiecare nod adiacent nevizitat. Distanța minimă către un nod v este actualizată dacă există o cale mai scurtă prin nodul u, adică dist[u] + adj[u][v] < dist[v].

## Problema 3

allocate_arrays: Această funcție este responsabilă de alocarea memoriei pentru matricea de noduri (graph) și pentru vectorul de distanțe (dist). De asemenea, inițializează valorile de capacitate și număr de muchii pentru fiecare nod, și alocă spațiu pentru muchiile fiecărui nod.

free_arrays: Eliberează memoria alocată pentru matricea de noduri și vectorul de distanțe. Înainte de a elibera memoria pentru fiecare nod, este necesar să se elibereze și memoria alocată pentru muchiile respective.

add_edge: Adaugă o muchie între nodurile u și v cu o anumită greutate w în graf. Verifică dacă greutatea este mai mică sau egală cu o valoare maximă (MAX_COST) și, în caz afirmativ, adaugă muchia la nodul u și incrementează numărul de muchii ale nodului u. Dacă capacitatea nodului u este depășită, aceasta este dublată și spațiul alocat pentru muchii este realocat în consecință.

dijkstra: Implementează algoritmul Dijkstra pentru găsirea celor mai scurte căi în graf, pornind de la nodul sursă specificat prin parametrul source. Inițializează distanțele către toate celelalte noduri cu o valoare infinită (INF), iar distanța către nodul sursă este setată la 0. Folosește un vector auxiliar visited pentru a marca nodurile vizitate. Pentru fiecare iterație, alege nodul nevizitat cu distanța minimă și îl marchează ca vizitat. Apoi, actualizează distanțele minime către toate nodurile adiacente nevizitate, dacă există o cale mai scurtă prin nodul curent.

## Testare
cd problemaID
make run input=in/testID.in

Se verifică manual fișierul de output (date.out) cu fișierul de ref (ref/testID.out).
