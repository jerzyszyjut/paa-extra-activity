# TSQRL - Pierwiastki równania kwadratowego

Dla podanych całkowitych współczynników a b c (z zakresu od -1000000 do 1000000 ) równania kwadratowego w postaci kanonicznej a * x2 + b * x + c = 0 wyznacz przybliżone rozwiązania rzeczywiste x'1 oraz x'2 podanego równania (jeżeli istnieją) takie, że |x1 - x'1| <= 10-k oraz |x2 - x'2| <= 10-k, gdzie x1 oraz x2 są rozwiązaniami dokładnymi.

Dane wejściowe składają się z 10 zestawów testowych, podzielonych na dwie grupy:

    testy 1-5: 1 <= k <= 2,

    testy 6-10: 1 <= k <= 100.

## Wejście

W pierwszej linii podana została liczba zestawów testowych t <= 10. W każdej kolejnej z t linii podana została czwórka liczb całkowitych a b c k.
Wyjście

Dla każdej czwórki liczb a b c k wyznacz pierwiastki rzeczywiste równania kwadratowego a * x^2 + b * x + c = 0 z dokładnością do 10-k. Wypisz liczbę różnych pierwiastków rzeczywistych równania. Jeżeli rozwiązania rzeczywiste istnieją, po spacji wypisz pierwiastki w porządku rosnącym (oddzielone spacją). Liczba miejsc po przecinku nie jest ograniczona.
## Przykład

```
Wejście:
5
1 0 1 1
1 2 1 1
1 -2 1 1
1 0 -1 2
1 0 -2 2

Wyjście:
0
1 -1
1 1 [może być: 1 0.9 lub 1 1.1]
2 -1 1
2 -1.41 1.42 [może być: -1.423 1.4142]
```
