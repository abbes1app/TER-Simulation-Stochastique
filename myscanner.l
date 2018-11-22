%{
#include "myscanner.h"
%}

%%

"="           return Egal ;
"+"           return PLUS ;
"("           return SepO ;
")"           return SepF ;
":"           return DeuxPoint ;
";"           return PointVirgule ;
","           return Virgule ;
"["         return AccO;
"]"           return AccF;
"molecule"  return molecule ;
"vitesse"   return vitesse;
"diametre"  return diametre ;
"taille"    return taille ;
"pop"       return pop  ;
"->"        return Arrow ;


[a-zA-Z][a-zA-Z0-9]* {

vtoken = yytext;
return Identificateur ;


}
[1-9][0-9]* {
vtoken = yytext;
return INTEGER;


}
[+-]?([0-9]+[.])[0-9]* {
vtoken = yytext;

return FLoat;

}
\/\/(.)*\n      ;
[ \t\n]         ;

%%
int yywrap(void)
{
 return 1;
}
