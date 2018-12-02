%{
	#include<stdio.h>
	#include<string.h>
	#include"105.tab.h"
	#include<stdlib.h>
	char str[100];
	char multichar[100][100];
	int i,cnt=0;
	int yyparse();
%}


/* C Declarations */
DIGIT [0-9]

/*----------------------RE and Action------------------------------------*/

%%

"_INTEGER_"		{ return INT; }
"_FLOAT_"		{ return FLOAT; }
"_CHARACTER_"		{ return CHAR; }

{DIGIT}+		{ 
			yylval = atoi(yytext);
			return NUM;
			}

"("			{ return LP; }
")"			{ return RP; }
"{"			{ return LB; }
"}"			{ return RB; }
","			{ return CM; }
";"			{ return SM; }
":"			{ return COLON; }
"_THEN_"		{ return THEN; }
"_ADD_"			{ return PLUS; }
"_SUB_"			{ return MINUS; }
"_MULT_"		{ return MULT; }
"_DIV_"			{ return DIV; }
"_POW_"			{ return POW; }
"_EQUAL_"		{ return ASSIGN; }
"_GRT_"			{ return GT; }
"_LST_"			{ return LT; }
"_GEQ_"			{ return GE; }
"_LEQ_"			{ return LE; }
"_EQEQ_"		{ return EE; }
"_INC_"			{ return AA; }
"_DEC_"			{ return LL; }
"_FOR_"			{ return FOR; }
"_PRINT_"		{ return PRNT; }
"_SWITCH_" 		{ return SWITCH; }
"_CASE_"		{ return CASE; }
"_DEFAULT_" 		{ return DEFAULT; }
"_BREAK_"		{ return BREAK; }

"\""[a-zA-Z]([ a-z]+|[A-Z]+|[!]+)+"\"" {
				for(i=0; i<yyleng-2; i++) str[i] = yytext[i+1];
				return STR;
			}
[a-z]		{
				yylval = *yytext - 'a';
				return	VAR;
			}

[a-z][a-z]+ {
				strcpy(multichar[cnt],yytext);
				cnt++;
				return VAR1;
			}			

"_IF_"			{ return IF; }
"_ELSE_"		{ return ELSE; }

"_MAIN_"		{ return MAIN; }

[ \t\n]*	;

"//"(.)*"\n" { printf("This is a comment!\n");}

.	{
		
	}
%%

/* user subroutines */

int main()
{	
	yyin = freopen("input.txt","r",stdin);
	yyout = freopen("output.txt","w",stdout);
	printf("____________________INDRONIL's COMPILER!!!____________________\n\n");
	yyparse();
}

