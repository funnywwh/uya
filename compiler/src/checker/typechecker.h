#ifndef TYPECHECKER_H
#define TYPECHECKER_H

#include "../parser/ast.h"

// 类型检查器结构
typedef struct TypeChecker {
    // 类型检查器状态
} TypeChecker;

// 类型检查器函数
TypeChecker *typechecker_new();
void typechecker_free(TypeChecker *checker);
int typechecker_check(TypeChecker *checker, ASTNode *ast);

#endif