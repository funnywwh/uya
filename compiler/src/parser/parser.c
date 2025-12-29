#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

Parser *parser_new(Lexer *lexer) {
    Parser *parser = malloc(sizeof(Parser));
    if (!parser) {
        return NULL;
    }
    
    parser->lexer = lexer;
    parser->current_token = lexer_next_token(lexer);
    
    return parser;
}

void parser_free(Parser *parser) {
    if (parser) {
        if (parser->current_token) {
            token_free(parser->current_token);
        }
        free(parser);
    }
}

ASTNode *parser_parse(Parser *parser) {
    // 简单的解析器实现，只返回一个程序节点
    ASTNode *program = ast_new_node(AST_PROGRAM, 0, 0, "unknown");
    if (!program) {
        return NULL;
    }
    
    // 这里应该实现完整的解析逻辑
    // 为了演示，我们只创建一个简单的程序结构
    
    // 临时创建一些测试节点
    ASTNode *main_fn = ast_new_node(AST_FN_DECL, 0, 0, "unknown");
    if (main_fn) {
        main_fn->data.fn_decl.name = malloc(5);
        strcpy(main_fn->data.fn_decl.name, "main");
        main_fn->data.fn_decl.return_type = ast_new_node(AST_TYPE_NAMED, 0, 0, "unknown");
        if (main_fn->data.fn_decl.return_type) {
            main_fn->data.fn_decl.return_type->data.type_named.name = malloc(4);
            strcpy(main_fn->data.fn_decl.return_type->data.type_named.name, "i32");
        }
        
        // 创建一个简单的返回语句
        ASTNode *return_stmt = ast_new_node(AST_RETURN_STMT, 0, 0, "unknown");
        if (return_stmt) {
            return_stmt->data.return_stmt.expr = ast_new_node(AST_NUMBER, 0, 0, "unknown");
            if (return_stmt->data.return_stmt.expr) {
                return_stmt->data.return_stmt.expr->data.number.value = malloc(2);
                strcpy(return_stmt->data.return_stmt.expr->data.number.value, "0");
            }
            
            // 创建函数体块
            main_fn->data.fn_decl.body = ast_new_node(AST_BLOCK, 0, 0, "unknown");
            if (main_fn->data.fn_decl.body) {
                main_fn->data.fn_decl.body->data.block.stmts = malloc(sizeof(ASTNode*));
                if (main_fn->data.fn_decl.body->data.block.stmts) {
                    main_fn->data.fn_decl.body->data.block.stmts[0] = return_stmt;
                    main_fn->data.fn_decl.body->data.block.stmt_count = 1;
                }
            }
        }
        
        program->data.program.decls = malloc(sizeof(ASTNode*));
        if (program->data.program.decls) {
            program->data.program.decls[0] = main_fn;
            program->data.program.decl_count = 1;
        }
    }
    
    return program;
}