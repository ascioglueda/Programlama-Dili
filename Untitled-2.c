#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int reverse_search(const char* str, char c, int len) {
int i;
for (i = len - 1; i >= 0; i--) {
if (str[i] == c) {
return i;
}
}
return -1;
}int is_identifier(const char* str) {
int i;
if (!isalpha(str[0]) && str[0] != '') {
return 0;
}
for (i = 1; str[i] != '\0'; i++) {
if (!isalnum(str[i]) && str[i] != '') {
return 0;
}
}
return 1;
}har* bracketer(const char* str, char left, char right, int len) {
int i, j, count = 0;
char* result = (char*)malloc(sizeof(char) * (len + 1));
for (i = 0; i < len; i++) {
if (str[i] == left) {
count++;
}
else if (str[i] == right) {
count--;
}
if (count < 0) {
free(result);
return NULL;
}
result[i] = str[i];
}
result[len] = '\0';
if (count != 0) {
free(result);
return NULL;
}
return result;
}int is_keyword(const char* str) {
const char* keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
int i, num_keywords = sizeof(keywords) / sizeof(keywords[0]);
for (i = 0; i < num_keywords; i++) {
if (strcmp(str, keywords[i]) == 0) {
return 1;
}
}
return 0;
}int is_operator(const char* str) {
const char* operators[] = {"+", "-", "", "/", "%", "&", "|", "^", "~", "<<", ">>", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "=", "+=", "-=", "=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "++", "--"};
int i, num_operators = sizeof(operators) / sizeof(operators[0]);
for (i = 0; i < num_operators; i++) {
if (strcmp(str, operators[i]) == 0) {
return 1;
}
}
return 0;
}

int combine_and_check_for_operator(char c1, char c2) {
char op[3];
op[0] = c1;
op[1] = c2;
op[2] = '\0';
return is_operator(op);
}const char* get_bracket_name(char c) {
switch (c) {
case '(':
return "leftparenthesis";
case ')':
return "right parenthesis";
case '{':
return "left brace";
case '}':
return "right brace";
case '[':
return "left bracket";
case ']':
return "right bracket";
default:
return "unknown bracket";
}
}

char fpeek(FILE* fp) {
char c = fgetc(fp);
ungetc(c, fp);
return c;
}

char* char_to_str(char c) {
char* str = (char*)malloc(sizeof(char) * 2);
str[0] = c;
str[1] = '\0';
return str;
}

char* two_char_to_str(char c1, char c2) {
char* str = (char*)malloc(sizeof(char) * 3);
str[0] = c1;
str[1] = c2;
str[2] = '\0';
return str;
}