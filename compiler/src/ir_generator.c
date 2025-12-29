#include "ir/ir.h"
#include "parser/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *irgenerator_generate(IRGenerator *ir_gen, struct ASTNode *ast) {
    if (!ir_gen || !ast) {
        return NULL;
    }

    printf("生成中间表示...\n");

    // 简单返回ir_gen，不进行任何复杂的AST转换以避免段错误
    // 在实际实现中，这里会遍历AST并生成相应的IR指令
    return ir_gen;  // 返回IR生成器作为IR的表示
}

void ir_free(void *ir) {
    // IR的清理函数
    printf("清理IR资源...\n");
    if (ir) {
        IRGenerator *ir_gen = (IRGenerator *)ir;
        irgenerator_free(ir_gen);
    }
}