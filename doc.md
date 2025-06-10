## Opis ogólny:
Interfejs programistyczny umożliwiający prostą i modularną implementację automatów komórkowych w środowisku GUI oraz TUI.

## Komponenty

### App:
#### Opis:
Klasa koordynująca działanie programu, składa się z dwuch komponentów:
`Display` oraz `Simulation`.

Konstruowanie `App` w `main.c` decyduje, o interfejsie, oraz rodzaju symulacji.

`App`, jest również odpowiedzialna za komunikacje swoich modułów między sobą, na przykład przekazywanie informacji o obecnym kroku (generacji) symulacja do panelu, który tą informacje wyświetla.

`App` jest odpowidzialna za główną pętle programu.

---
### Simulation:
#### Opis:
Klasa bazowa reprezentująca automat komórkowy.

Dziedzicząc z `Simulation`, programista za pomocą polimorfizmu może zainicjować `App` w interesującej go konfiguracji.
Szczegóły implemetacji konkretnego automatu komórkowego, jego zawiłość i komponenty są zupełnie nie związane z `App` oraz `Display`, poza funkcjami nażuconymi przez klase główną.

```c
  void update();
  void start();
  void step();
  void stop();
  void restart();
  void quit();
```

Metody te reprezentują podstawowe działania które symulacja musi spełniać, żeby być symulacją. Dodatkowo, nażuciłem kontrolki _start, step, stop, restart_, które zmuszają do implementacji reakcji symulacji na udostępnione użytkownikowi akcje.

---
### Display:
#### Opis:
Klasa bazowa reprezentująca komponenty niezbędne do wizualizacji symulacji.

Wirtualne metody i pola są skonstruowane tak, by aplikacja za równo GUI(Graphical User Interface) jak i TUI (Terminal User Interface) odbywała się za pomocą tego samego interfejcu programistycznego (dzięki polimorfizmowi).
`DisplayTUI` oraz `DisplayGUI` dziedzicząc z klasy bazowej będą adekwatnie implementować z góry nałożone elementy interfejsu, takie jak: _nómer generacji_, _informacje o kontrolkach_ oraz oczywiście _główne okno, z "planszą" gry_, oraz operacje niezbędne do poprawnego wyświetlania: zahowanie przy zmienianiu wielkości okna itp.  
