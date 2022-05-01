/*** ------------------------ DEFINITION SECTION ------------------------ ***/
/*** In order to run this code, have to follow below steps:
 1. Open the terminal
 2. Run: cd/<file_path>
 3. Run: lex <filename.l> or <filename.lex>
 4. Run: gcc lex.yy.c
 5. Run: ./a.out ***/

%{
    int count1;
    int count2;
    int count3;
    int count4;
    int count5;
    int count6;
    int count7;
    int count8;
    int count9;
    int count10;
    int count11;
    int count12;
    int count13;
    int count14;
%}

/*** ------------------------ RULE SECTION ------------------------ ***/

%%

"\t"	{return 0;}
" "	      {printf("'%s' Anagnoristike o kenos xaraktiras \n", yytext); count12++;}
";"	      {printf("'%s' Anagnoristike o xaraktiras \n", yytext); count4++;}
","           {printf("'%s' Anagnoristike o diaxwristikos xaraktiras \n",yytext); count5++;}
":"           {printf("'%s' Anagnoristike o xaraktiras \n",yytext); count6++;}
"\n"           {printf("'%s' It is a break line \n",yytext); count13++;}
"int"		{printf("'%s'Dilwsi Intiger variable \n",yytext); count14++;}
"var"         {printf("'%s' Anagnoristike i dilosi metavlitis \n",yytext); count7++;}
"integer"     {printf("'%s' Anagnoristike i desmevmeni leksi \n",yytext); count8++;}
"real"        {printf("'%s' Anagnoristike i desmevmeni leksi \n",yytext); count9++;}
"boolean"     {printf("'%s' Anagnoristike i desmevmeni leksi \n",yytext); count10++;}
"char"        {printf("'%s' Anagnoristike i desmevmeni leksi \n",yytext); count11++;}
[0-9]+        {printf("'%s' is integer\n", yytext); count1++;}
[a-zA-Z]*[0-9]+       {printf("'%s' is variable\n", yytext); count2++;}
.	      {printf("'%s' is other lexeme\n", yytext); count3++;}
%%

/*** ------------------------ USER CODE SECTION ------------------------ ***/

int yywrap(){return 1;}
int main(){
    yylex();
    printf("Integers are: %d, Characters are: %d, Other Lexemes are: %d, Integers are: %d, Characters are: %d, Other Lexemes are: %d, Integers are: %d, Characters are: %d, Other Lexemes are: %d\n",  count14, count11, count3, count6, count7, count8, count9, count10, count11);
    return 0;
}
