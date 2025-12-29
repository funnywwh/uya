#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "../lexer/lexer.h"

// 语法分析器结构
typedef struct Parser {
    Lexer *lexer;
    Token *current_token;
} Parser;

// 语法分析器函数
Parser *parser_new(Lexer *lexer);
void parser_free(Parser *parser);
ASTNode *parser_parse(Parser *parser);

#endif