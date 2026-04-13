## Reflektion - skillnader mellan C och Python

Att skapa samma program i både C och Python visade tydliga skillnader mellan språken.

Det första som kändes svårare i C var hanteringen av input. I Python behövde jag inte tänka lika mycket på datatyper, eftersom input() alltid returnerar en sträng och kan hanteras flexibelt. I C behövde jag däremot lägga ner mer tid och noggrannhet med datatyper och hur input läses in, till exempel om det är ett heltal eller en sträng. 
När jag använde scanf (i C) så uppstod flera problem om input inte matchade det programmet förväntade sig, vilket ledde till felaktiga beteenden eller att programmet fastnade i en loop.

För att lösa detta gick jag över till att använda fgets istället. Fgets gör att hela raden läses in som text, inklusive mellanslag, vilket gör programmet mer robust. Jag kunde sedan själv kontrollera och validera inputen med hjälp av fler rader. Detta liknar hur Python fungerar, där man kan läsa in in input som en sträng och sedan arbeta igenom den.

I Python använde jag input().strip() för att ta bort mellanslag i början och slutet av inputen. I C behövde jag implementera samma funktion manuellt genom att använda fgets, ta bort newline-tecknet och skriva en egen funktion (remove_whitespace) för att fixa till strängen. Detta moment visar att C kräver mer manuell hantering av strängar jämfört med Python där mycket funktioner är inbyggt redan.

Skillnaderna visade sig även i hur loggen hanterades. I Python kunde man använda en lista (log = [ ] ) och enkelt lägga till nya element med append(). I C behövde jag istället definiera en array med fast storlek och manuellt hålla reda på hur många loggrader som har lagrats. Detta visar hur Python tillhandahåller dynamiska datastrukter och hur C kräver att man planerar minnesanvändningen i förväg.

Python var snabbare att skriva i, eftersom språket är mer hög nivå och kräver inte kompilering på samma sätt. Koden kan köras direkt och felkod kan upptäckas snabbt. C krävde mer arbete, mer planering och struktur, men gav samtidigt mer kontroll över hur programmet fungerar. Till exempel behövde jag manuellt hantera strängar, konverteringar och funktioner, vilket gjorde det tydligare vad som faktiskt sker “behind the scenes”. Det gav mig en större förståelse för vad som skiljer ett låg nivå och ett hög nivå språk åt.

En annan viktig skillnad jag lärde mig i C är att strängar är arrayer av tecken som måste ha en bestämd storlek för att det ska kunna lagras någonstans. Det innebär att man själv måste ha koll på att det finns tillräckligt med minne och att strängen avslutas korrekt med en null-terminator (‘\0’). I Python hanteras detta automatiskt.

Jag lärde mig också att funktioner i C måste deklareras innan de används. Därför behövde jag skriva void remove_whitespace(char str[]); högt uppe i filen för att programmet skulle kunna använda funktionen i menu_choice funktionen (som ju var skriven innan remove_whitespace funktionen). Detta visar än en gång hur C kräver mer planering och struktur, medan Python tillåter mer flexibilitet. 
En annan skillnad är hur datatyper hanteras i C, där jag behövde konvertera tecken till heltal manuellt, till exempel med: input[0] - ‘0’; . Detta fungerar för att tecken lagras i ASCII-värden. I Python sker samma typ av konvertering automatiskt med int(). 

Min slutsats är att Python var lättare och snabbare att använda för denna uppgift, men jag tycker C gav mer kontroll och en djupare förståelse för hur program faktiskt fungerar på en lägre nivå.



