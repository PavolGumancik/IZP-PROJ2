
FIT 	
home
	
studia
	
předměty
	
termíny
	
registrace
	
hesla
	
ostatní
	
odhlásit
	 english 
Login xguman01, Gumančík Pavol, 2. ročník BIT, prezenční, FIT
Ak. rok 2019/2020 studium č. 1: řádný zápis

	Zpět na termíny 
[[IZP Home]]

Navigace

    Hlavní stránka
    Poslední změny
    Nápověda

Stránka

Nástroje

    Odkazuje sem
    Nahrát soubor
    Seznam souborů
    Seznam stránek
    Historie stránky

	

    StránkaZdrojSledovat 

Projekt 2 - Iterační výpočty
Obsah
1	Popis projektu
2	Detailní specifikace
 	2.1	Překlad a odevzdání zdrojového souboru
 	2.2	Spuštění a výstup programu
 	2.3	Nápověda a vzorce
 	2.4	1. podúkol
 	2.5	2. podúkol
 	2.6	3. podúkol
3	Hodnocení
4	Reference
Popis projektu

Najděte pracovní bod diody.

Mějme jednoduché sériové zapojení diody a rezistoru. Známe Shockleyovu rovnici a jeho konstanty. Napište funkci, která pro dané vstupní napětí U_0 a odpor rezistoru R najde pracovní napětí diody odpovídající zadané přesnosti. Dále napište program, který na základě těchto vstupních parametrů na výstup vytiskne pracovní bod diody, tedy napětí a proud.
Detailní specifikace
Překlad a odevzdání zdrojového souboru

Odevzdání: Program implementujte ve zdrojovém souboru proj2.c. Zdrojový soubor odevzdejte prostřednictvím informačního systému.

Překlad: Program překládejte s následujícími argumenty:

$ gcc -std=c99 -Wall -Wextra -Werror proj2.c -lm -o proj2

Spuštění a výstup programu

Vstupní data programu budou zadány jako jeho argumenty:

$ ./proj2 U0 R EPS
Up=XXXX V
Ip=YYYY A

kde:

    U0 je hodnota vstupního napětí ve Voltech,
    R je odpor rezistoru v Ohmech a
    EPS je absolutní chyba/přestnost/odchylka (epsilon),
    XXXX je hodnota napětí pracovního bodu diody a
    YYYY je hodnota proudu pracovního bodu diody.

Formát číselného výstupu XXXX a YYYY odpovídá formátovací značce %g.
Nápověda a vzorce

Voltampérová charakteristika diody v sériovém zapojení s rezistorem:

Proud v rezistoru:

Napětí na rezistoru:

Proud v diodě (Shockleyhova rovnice):

Přičemž uvažujme, že závěrný saturační proud a tepelné napětí mají tyto hodnoty:

Protože je obvod uzavřený, platí 1. Kirchhoffův zákon:

1. podúkol

Vyjádřete poslední rovnici pomocí napětí U_p, U_0 a R.
2. podúkol

Implementujte algoritmické schema pro výpočet posloupnosti využívající metodu půlení intervalu. Ukončující podmínka bude odpovídat absolutní požadované přesnosti výsledku (epsilon).
3. podúkol

Napište funkci diode, která pomocí schematu z 2. podúkolu a vzorce z 1. podúkolu hledá hodnotu napětí U_p. Počáteční interval napětí bude od 0 do U_0.

double diode(double u0, double r, double eps);

Ve funkci je u0 hodnota vstupního napětí, r je odpor rezistoru a eps je absolutní přesnost (maximální požadovaná odchylka). Funkce v návratové hodnotě vrací nalezené napětí U_p.
Hodnocení

Na výsledném hodnocení mají hlavní vliv následující faktory:

    implementace algoritmického schematu pro iterační výpočet,
    implementace metody půlení intervalu a výpočet pracovního bodu,
    ošetření neočekávaných stavů.

Reference

    Peringer, P.: Přednáška o polovodičích, 2019, Předmět IEL, VUT v Brně.
    Metoda půlení intervalu: Studijní opory IZP, Numerické výpočty, strana 4.
    Bečvář, J., Lineární algebra, matfyzpress, Praha, 2005.
    Funkce exp(3).

Nahoru
Id stránky: 156, verze: 11728, dne: 2019-11-17 20:10:18 uložil: smrcka
©Fakulta informačních technologií VUT v Brně, Božetěchova 2, 612 66 Brno
Připomínky zasílejte na adresu lampa@fit.vut.cz
