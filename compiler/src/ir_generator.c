#include "ir/ir.h"
#include "parser/ast.h"
#include <stdio.h>
#include <stdlib.h>

void *irgenerator_generate(IRGenerator *ir_gen, struct ASTNode *ast) {
    if (!ir_gen || !ast) {
        return NULL;
    }

    printf("生成中间表示...\n");

    // 这里应该实现从AST到IR的转换
    // 为了演示，我们创建一个简单的IR

    // 为演示目的，创建一个简单的main函数
    IRInst *main_func = irinst_new(IR_FUNC_DEF);
    if (main_func) {
        main_func->data.func.name = malloc(5);
        if (main_func->data.func.name) {
            strcpy(main_func->data.func.name, "main");
            main_func->data.func.return_type = IR_TYPE_I32;
            main_func->data.func.param_count = 0;
            main_func->data.func.is_extern = 0;

            // 创建返回0的语句
            IRInst *ret_stmt = irinst_new(IR_RETURN);
            if (ret_stmt) {
                // 这里应该创建一个表示数字0的IR指令
                // 为了简化，我们直接使用一个临时的IR指令
            }

            main_func->data.func.body = malloc(sizeof(IRInst*));
            if (main_func->data.func.body) {
                main_func->data.func.body[0] = ret_stmt;
                main_func->data.func.body_count = 1;
            }

            // 将函数添加到IR生成器
            if (ir_gen->inst_count >= ir_gen->inst_capacity) {
                ir_gen->inst_capacity *= 2;
                ir_gen->instructions = realloc(ir_gen->instructions,
                                              ir_gen->inst_capacity * sizeof(IRInst*));
            }

            if (ir_gen->instructions) {
                ir_gen->instructions[ir_gen->inst_count] = main_func;
                ir_gen->inst_count++;
                return ir_gen;  // 返回IR生成器作为IR的表示
            }
        }
    }

    return NULL;
}

void ir_free(void *ir) {
    // IR的清理函数
    // 这里应该清理IR相关资源
    printf("清理IR资源...\n");
}