# Savarankiskas darbas - SD1_Audrius_Ivko_PIT-21-NT-I

## Programa skirta studentu iverciu skaiciavimui. Atliakamaas namu darbu ir egzaminu rezulatatu skaiciavimas pagal vidurki ir pagal mediana. Galimi skaiciavimu variantai. Matuojama programos greitoveika kuriant duomenu failus, skaidant duomanu failus, rusiuojant duomenu failus. Naudojami skirtingu tipu duomenu saugojimo <T> tipo konteineriai. Pateikiami graitoveikos matavimai
1. Namu darbu vidutinis ivertinimas
2. Namu darbu medianas vertinimu
3. Namu darbu ir egzamino vidutinis ivertinimas
4. Namu darbu ir egzamino medianos ivertinimu
5. Duomenu nuskaitymas is failo
6. Duomenu ivedimas rankiniu budu
7. Atsitiktiniu duomenu generavimas. Pasirenkant studentu kieki ir namu darbu kieki.
8. Ivestu, nuskaitytu is failo ir sugeneruotu duomenu apjungimo galimybe.
10. Duomenu rykiavimas pagal pozymius (varda ir vidutini galutini vertinima)
10. Duomenu trinimas is duomenu failo

  ## Greitoveikos matavimas duomenu skaidymas
Matuojama atskirai kiekvieno <T> tipo konteinerio greitoveika.
1. Kuriamas atsitiktiniu duomenu sarasas, kuriamai objektai ir atliekami skaiciavimai;
2. Saras <T> Vector konteineris skaidomas i dvi dalis pagal pozimi, 5 balu vidurkio ir virs 5 balu vidurkio
duomenys talpinami i sesis <T> tipo konteinerius. Vector, Deque ir List, kiekvieno po du;
3. Rusiavimas <T> tipo Vector, Deque ir List konteineriu pagal balo vidurki;
4. Kiekvienas tipas irasys duomenis i fala, greitoveika matuojama tik Vector tipo konteinerio;
5. Generuojamas atsitiktinis studento: Vardas, Pavarde
6. Generuojamas atsitiktinis egzamino balas
7. Studentu kieki - pasirenka vartotojas
8. Namu darbu kieki: - pasirenka vartotojas

  ### Matavimo rezultatais su skirtingu duomenu kiekiu:

  #### Vector tipo objektu failo generavimas
1. Vector tipo objektu failo generavimas, is 1000 eiluciu ir 33 stulpeliu laikas: 0.0987275 s/n
2. Vector tipo objektu failo generavimas, is 10000 eiluciu ir 18 stulpeliu laikas: 0.790674 s/n
3. Vector tipo objektu failo generavimas, is 1000000 eiluciu ir 23 stulpeliu laikas: 87.7151 s/n

  #### Vector tipo failo rusiavimas:
1. Vector tipo failo rusiavimas, is 1000 objektu 0.0319004 s/n
2. Vector tipo failo rusiavimas, is 10000 objektu 0.365863 s/n
3. Vector tipo failo rusiavimas, is 1000000 objektu 27.1117 s/n

  #### Vector tipo failo dalinimas pagal pozimy:
1. Vectort tipo duomenu konteinerio dalinimas pagal pozimi, is 1000 objektu trukme: 0.017874 s/n
2. Vectort tipo duomenu konteinerio dalinimas pagal pozimi, is 10000 objektu trukme: 0.14974 s/n
3. Vectort tipo duomenu konteinerio dalinimas pagal pozimi, is 1000000 objektu trukme: 18.6625 s/n
  
  #### Deque tipo failo dalinimas pagal pozimy:
1. Deque tipo duomenu konteinerio dalinimas pagal pozimi, is 1000 objektu trukme: 0.00398871 s/n
2. Deque tipo duomenu konteinerio dalinimas pagal pozimi, is 10000 objektu trukme: 0.0398127 s/n
3. Deque tipo duomenu konteinerio dalinimas pagal pozimi, is 1000000 objektu trukme: 4.33691 s/n
  
  #### List tipo failo dalinimas pagal pozimy:
1. List tipo duomenu konteinerio dalinimas pagal pozimi, is 1000 objektu trukme: 0.00373546 s/n
2. List tipo duomenu konteinerio dalinimas pagal pozimi, is 10000 objektu trukme: 0.0375128 s/n
3. List tipo duomenu konteinerio dalinimas pagal pozimi, is 1000000 objektu trukme: 4.44062 s/n
  
  #### Vectort tipo duomenu konteinerio rusiavimas pagal pozimy:
1. Vectort tipo duomenu konteinerio rusiavimas pagal pozimy, is 1000 objektu trukme: 0.00932929 s/n
2. Vectort tipo duomenu konteinerio rusiavimas pagal pozimy, is 10000 objektu trukme: 0.0938672 s/n
3. Vectort tipo duomenu konteinerio rusiavimas pagal pozimy, is 1000000 objektu trukme: 3.22944 s/n
  
  #### Deque tipo duomenu konteinerio rusiavimas pagal pozimy:
1. Deque tipo duomenu konteinerio rusiavimas pagal pozimy, is 1000 objektu trukme: 0.00958662 s/n
2. Deque tipo duomenu konteinerio rusiavimas pagal pozimy, is 10000 objektu trukme: 0.104002 s/n
3. Deque tipo duomenu konteinerio rusiavimas pagal pozimy, is 1000000 objektu trukme: 4.33147 s/n

  #### List tipo duomenu konteinerio rusiavimas pagal pozimy:
1. List tipo duomenu konteinerio rusiavimas pagal pozimy atliktas Vector konteineryje, is 1000 objektu trukme: 0.0319004 s/n
2. List tipo duomenu konteinerio rusiavimas pagal pozimy atliktas Vector konteineryje, is 10000 objektu trukme: 0.365863 s/n
3. List tipo duomenu konteinerio rusiavimas pagal pozimy atliktas Vector konteineryje, is 1000000 objektu trukme: 27.1117 s/n

  #### Vector tipo duo menu irasymas i faila:
1. Vector tipo duo menu irasymas i faila is 1000 objektu trukme: 0.0181975 s/n
2. Vector tipo duo menu irasymas i faila is 10000 objektu trukme: 0.16294 s/n
3. Vector tipo duo menu irasymas i faila is 1000000 objektu trukme: 16.2968 s/n






