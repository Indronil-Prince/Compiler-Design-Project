/* C Declarations */

%{
	#include<stdio.h>
	#include <string.h>
	#include <math.h>
	int sym[26], store[26], p;
	int forswitchcase=5;
	int forifelse = 1, str_flagd=0, val_flagd=0;
	int fvalue, val_flag=0, str_flag=0, val_prior=0, str_prior=0, prior=0;
	int switchstack[100], check[100], check2[100], checkstr[100], ll=0, l=0, flag=1, val, i, j, count=0;
	char switchstackstr[100][100], finsidestr[100];
	char str[100];
	char multichar[100][100];
	int m=0, multi_flag=0, ind=0, t=1, single=0, multi=0;
	int cnt;
  	
	int yyerror(char* );
    int yylex();
	
	void clear_str(){
		for(i=0;str[i]!='\0';i++)
		str[i]='\0';
	}
	
	void clear_multichar(int cnt)
	{
		for(p=0; multichar[cnt-1][p]!='\0'; p++) 
		multichar[cnt-1][p] = '\0';
	}
	
	void re_dec(int cnt)
	{
		for(i=0; i<cnt-1; i++)  //when cnt > 1
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				printf("variable '%s' is redeclared\n",multichar[i]);
				t=0;
				clear_multichar(cnt);
				cnt--;
			}
		}
	}
	
	int un_dec()
	{	
		multi_flag=0;
		for(i=0; i<cnt-1; i++)
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				multi_flag = 1;
			}
		}

		if(!multi_flag)
		{
			printf("variable '%s' undeclared!\n",multichar[cnt-1]);
			
			clear_multichar(cnt);
			cnt=cnt-1;
			return 1;
		}
		
		return 0;
	}

	int check_index(int cnt){
		for(i=0; i<cnt-1; i++)
		{	
			if(!strcmp(multichar[cnt-1],multichar[i]))
			{
				return i;
			}
		}
	}
	
	void print_single(int str_flag, int val_flag, int str_prior, int val_prior){
		if(str_flag && val_flag && str_prior < val_prior)
		{
			printf("Printing statement : %s\n",finsidestr);
			printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
		}
		else if(str_flag && val_flag && str_prior > val_prior)
		{
			printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
			printf("Printing statement : %s\n",finsidestr);
		}
		else{
			if(val_flag)printf("Printing value     : %c = %d\n",fvalue+'a',sym[fvalue]);
			if(str_flag)printf("Printing statement : %s\n",finsidestr);
		}
	}
	
	void print_multi(int str_flag, int val_flag, int str_prior, int val_prior){
		if(str_flag && val_flag && str_prior < val_prior)
		{
			printf("Printing statement : %s\n",finsidestr);
			printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
		}
		else if(str_flag && val_flag && str_prior > val_prior)
		{
			printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
			printf("Printing statement : %s\n",finsidestr);
		}
		else{
			if(val_flag) printf("Printing value     : %s = %d\n",multichar[check_index(cnt)],multichar[check_index(cnt)][99]);
			if(str_flag) printf("Printing statement : %s\n",finsidestr);
		}
	}
	
%}

/* BISON Declarations */

%token NUM AA LL FOR VAR VAR1 COLON BREAK DEFAULT CASE THEN IF ELSE SWITCH MAIN RET INT STR FLOAT CHAR LP RP LB RB CM SM PRNT PLUS MINUS MULT DIV POW ASSIGN GT LT GE LE EE
%nonassoc IFX
%nonassoc ELSE
%left LT GT
%left VAR

	
/* Simple grammar rules */

%%

program		: 	MAIN LP RP LB cstatement RB { printf("\nSuccessfully compiled!!!\n"); }
			;

cstatement	: 	/* empty */
			| cstatement statement
			| cstatement cdeclaration
			| cstatement structure
			;
	
cdeclaration: TYPE varlist SM			{ printf("valid declaration\n\n"); }
			;
			
TYPE 		: INT | FLOAT | CHAR ;
				
varlist 	: vassign CM varlist | vassign ;
			
vassign		: VAR					{
										if(store[$1] == 1) printf("variable '%c' redeclared!!!\n",$1+'a');
										else
										{
											store[$1]=1;
											printf("%c declared!\n",$1+'a');
										}	
									}
									
			| VAR1					{	
										int v = 1;
										for(i=0; i<cnt-1; i++)
										{	
											if(!strcmp(multichar[cnt-1],multichar[i]))
											{
												printf("variable '%s' redeclared!!!\n",multichar[i]);
												clear_multichar(cnt);
												cnt--;
												v=0;
											}
										}
										if(v)printf("%s declared!\n",multichar[cnt-1]);
									}
									
			| VAR1 ASSIGN NUM 		{
										t=1;
										
										if(cnt<2)             //when cnt == 1
										{
											char c = (char) $3;
											multichar[cnt-1][99]=c;
											int i = (int) c;
											
										}
										
										re_dec(cnt);
								
										if(t&&cnt>1)
										{
										
											char c = (char) $3;
											multichar[cnt-1][99]=c;
											int i = (int) c;
										
										}
									
										if(t)printf("%s = %d declared & assigned!\n",multichar[cnt-1],multichar[cnt-1][99]);
										
									}						
									
									
			| VAR ASSIGN NUM 		{ 	
										if(store[$1] == 1) printf("variable '%c' redeclared!!!\n",$1+'a');
										else store[$1]=1;
										sym[$1] = $3; 
										printf("%c = %d declared & assigned!\n",$1+'a',$3);
									}
			;
			
structure  	: IF VAR operator NUM THEN COLON LB finsidelist RB	{	
													if(store[$2]!=1)printf("Undeclared character : %c\n",$2+'a');
													printf("\nIf Block\n");
													if( sym[$2] > $4)
													{
														printf("Condition True!\n");
																		
														if(single)print_single(str_flag,val_flag,str_prior,val_prior);
														if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
														forifelse = 0;
													}
													else
													{
														printf("Your 'IF' condition is false!\n");
													}
														single=multi=0;
									  }

			| IF VAR operator VAR THEN COLON LB finsidelist RB	{	
													if(store[$2]!=1)printf("Undeclared character : %c\n",$2+'a');
													if(store[$4]!=1)printf("Undeclared character : %c\n",$4+'a');
													printf("\nIf Block\n");
													if( sym[$2] > sym[$4])
													{
														printf("Condition True!\n");
																		
														if(single)print_single(str_flag,val_flag,str_prior,val_prior);
														if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
														forifelse = 0;
													}
													else
													{
														printf("Your 'IF' condition is false!\n");
													}
														single=multi=0;
									  }
																
			| IF VAR1 operator NUM THEN COLON LB finsidelist RB {
																
																	un_dec();
																	ind = check_index(cnt);
																	printf("\nIf Block\n");
																	if( multichar[ind][99] > $4)
																	{
																		printf("Condition True!\n");
																		
																		if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																		if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
																		forifelse = 0;
																	}
																	else
																	{
																		printf("Your 'IF' condition is false!\n");
																	}
																	single=multi=0;
																	
																	printf("Deleting %s\n",multichar[cnt-1]);
																	clear_multichar(cnt);
																	cnt--;
																
																}
												
			| IF VAR1 operator VAR THEN COLON LB finsidelist RB {
																
																	un_dec();
																	ind = check_index(cnt);
																	printf("\nIf Block\n");
																	if( multichar[ind][99] > sym[$4])
																	{
																		printf("IF condition True!\n");
																		
																		if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																		if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																		
																		forifelse = 0;
																	}
																	else
																	{
																		printf("IF condition false!\n");
																	}
																	single=multi=0;
																	clear_multichar(cnt);
																	cnt--;
																	}
			
			| ELSE LB finsidelist RB 	{ 	printf("\nElse Block\n");
											if(forifelse)
											{
												print_single(str_flag, val_flag, str_prior, val_prior);
											}
										}
										
			| FOR LP VAR ASSIGN NUM CM VAR LE NUM CM VAR AA RP LB finsidelist RB 	{   
															printf("\nFor Loop!!\n");
															if(store[$3]!=1)
															{
																printf("Undeclared variable : %c\n",$3+'a');
															}
																						
															else
															{
																for( sym[$3]=$5; sym[$3] <= $9; sym[$3]++)
																{
																	if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																	if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																}
															}
															str_flag=val_flag=0;
															single=multi=0;
												}

			| FOR LP VAR ASSIGN NUM CM VAR GE NUM CM VAR LL RP LB finsidelist RB 	{   
															printf("\nFor Loop!!\n");
															if(store[$3]!=1)
															{
																printf("Undeclared variable : %c\n",$3+'a');
															}
																						
															else
															{
																for( sym[$3]=$5; sym[$3] >= $9; sym[$3]--)
																{
																	if(single)print_single(str_flag,val_flag,str_prior,val_prior);
																	if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																}
															}
															str_flag=val_flag=0;
															single=multi=0;
												}
																					
			| FOR LP VAR1 ASSIGN NUM CM VAR1 LE NUM CM VAR1 AA RP LB finsidelist RB {
															if(un_dec()==0){
																							
															ind = check_index(cnt);
															printf("\nFor Loop!!\n");
															int temp = multichar[ind][99];
															for( temp=$5; temp<=$9; temp++)
															{
																multichar[ind][99]=temp;
																if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																if(single)print_single(str_flag,val_flag,str_prior,val_prior);
															}
															str_flag=val_flag=0;
													}
															clear_multichar(cnt-1);
															clear_multichar(cnt-2);
															cnt = cnt - 3;
																						
															
															single=multi=0;
													 }

			| FOR LP VAR1 ASSIGN NUM CM VAR1 GE NUM CM VAR1 LL RP LB finsidelist RB {
															if(un_dec()==0){
																							
															ind = check_index(cnt);
															printf("\nFor Loop!!\n");
															int temp = multichar[ind][99];
															for( temp=$5; temp>=$9; temp--)
															{
																multichar[ind][99]=temp;
																if(multi)print_multi(str_flag,val_flag,str_prior,val_prior);
																if(single)print_single(str_flag,val_flag,str_prior,val_prior);
															}
															str_flag=val_flag=0;
													}
															clear_multichar(cnt-1);
															clear_multichar(cnt-2);
															cnt = cnt - 3;
																						
															
															single=multi=0;
													 }
			
			| SWITCH LP VAR RP LB sblock RB 		{ 
														printf("\nSwitch case\n"); 
														forswitchcase=sym[$3]; 
														if(val_flag)
															for( i=0; i<l; i++){
																if(check[i]==forswitchcase){
																	printf("Case %d: Value of %c = %d\n", forswitchcase, switchstack[check[i]]+'a', sym[switchstack[check[i]]]);
																	flag=0;
																	break;
																}
															}
														l=0;
														if(str_flag)
															for( i=0; i<ll; i++){
																if(checkstr[i]==forswitchcase){
																	printf("Case %d: Your statement is = %s\n", forswitchcase, switchstackstr[check[i]]);
																	flag=0;
																	break;
																}
															}
														
														if(flag&&str_flagd)printf("Default: Your statement = %s\n",switchstackstr[ll]);
														if(flag&&val_flagd)printf("Default: value of %c = %d\n",val+'a',sym[val]);
														ll=0;
													}	
			
			;
			
sblock 		: caselist | caselist defaultstatement ;

caselist	: casestatement | casestatement caselist ;

casestatement		: CASE NUM COLON PRNT VAR SM BREAK SM		{ 	
														switchstack[$2]=$5;
														check[l]=$2;
														l++;
														val_flag = 1;
													}
													
			| CASE NUM COLON PRNT STR SM BREAK SM		{
														checkstr[ll]=$2;
														for(i=0;str[i]!='\0';i++)
														{
															switchstackstr[ll][i]=str[i];
														}
														
														ll++;
														str_flag = 1;
														clear_str();
													}
			;
			
defaultstatement	: DEFAULT COLON PRNT VAR SM 				{
														//printf("Default \n");
														val=$4;
														val_flagd=1;
													}
			| DEFAULT COLON PRNT  STR   SM 			{
														
														//printf("Default\n");
														str_flagd=1;
										
														for(i=0;str[i]!='\0';i++)
														{	
															switchstackstr[ll][i]=str[i];
															printf("%c ",switchstackstr[ll][i]);
														}
														printf("%s\n",switchstackstr[ll]);
														clear_str();
													}	
			;
			
operator	: GT | LT | EE | LE | GE ;
			
finsidelist : | structure finsidelist | finside finsidelist ;

finside		: PRNT VAR SM								{ 	
														fvalue=$2; 
														val_flag=1;
														val_prior=++prior;
														single=1;
													}
			| PRNT VAR1 SM 							{ 	
														printf("This var = %s\n",multichar[cnt-1]);
														un_dec();
														
														fvalue = multichar[check_index(cnt)][99];
														printf("%s = %d\n",multichar[check_index(cnt)],fvalue);
														
														val_flag=1;
														val_prior=++prior;
														multi=1;
														
													}
													
			| PRNT  STR  SM 							{
														str_flag=1;
														for(i=0;str[i]!='\0';i++)finsidestr[i]=str[i];
														str_prior=++prior;
														clear_str();
													}
			;
			
statement	: SM
			| expr SM 				{ printf("\nvalue of expression: %d\n", $1); }
			| VAR ASSIGN expr SM 	{
										sym[$1] = $3; 
										if(store[$1]!=1)printf("'%c' is Undeclared",$1+'a');
										printf("%c = %d assigned!\n",$1+'a',$3);
									}
			| VAR1 ASSIGN expr SM 	{
										multi_flag = 0;
										
										un_dec();

										for(i=0;i<cnt-1;i++)
										{
											if(!strcmp(multichar[cnt-1],multichar[i]))
											{
												multichar[i][99] =(char)$3;
												printf("%s = %d assigned!\n",multichar[i],multichar[i][99]);
											}
										}
										
									}
			| printlist
			;
			
printlist 	: printone | printone printlist;

printone	: PRNT STR SM 				{
										printf("Prininting statement : %s\n",str);
										clear_str();
							}
			| PRNT VAR SM			{			
										printf("Prininting value : %c = %d\n",$1+'a',sym[$1]);
							}
			| PRNT VAR1 SM 			{
										ind = check_index(cnt);
										printf("Prininting value : %s = %d\n",multichar[ind],multichar[ind][99]);
							}
			;
	
expr 		: VAR						{ $$ = sym[$1]; } 
			| VAR1 						{ $$ = multichar[check_index(cnt)][99]; clear_multichar(cnt); cnt--; }
			| expr PLUS term			{ $$ = $1 + $3; }
			| expr MINUS term			{ $$ = $1 - $3; }
			| term
			 ;
			 
term 		: term MULT power		{ $$ = $1 * $3; }
			| term DIV power		{ 
										if($3) 
										{
												$$ = $1 / $3;
										}
										else
										{
											$$ = 0;
											printf("\ndivision by zero\t");
										}
									}
			| power 
			;
			
power		: power POW factor		{ $$ = pow($1 , $3); }
			| factor
			;

factor 		: digit					{ $$ = $1; }
			| LP expr RP			{ $$ = $2; }
			;
			
digit 		: NUM	    			{ $$ = $1; }
			;
			
			
%%

int yywrap()
{
	return 1;
}

int yyerror(char *s){
	printf( "%s\n", s);
	return 1;
}