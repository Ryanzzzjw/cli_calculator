/*
 * ============================================================================
 *                         模块15：表达式解析器
 *                    (Expression Parser - Shunting Yard)
 * ============================================================================
 *
 * 【学习目标】
 * 完成本模块后，你将能够：
 * 1. 理解中缀表达式和后缀表达式的区别
 * 2. 实现栈（Stack）数据结构
 * 3. 使用 Shunting Yard 算法将中缀表达式转换为后缀表达式
 * 4. 计算后缀表达式得到最终结果
 *
 * 【预计完成时间】60-90 分钟
 *
 * 【最终效果】
 * 用户可以输入复杂的数学表达式，如：
 *   > 3 + 4 * 2
 *   结果: 11
 *   > (1 + 2) * (3 + 4)
 *   结果: 21
 *
 * ============================================================================
 *                          第一部分：核心概念
 * ============================================================================
 *
 * 【什么是中缀表达式？】
 * 中缀表达式就是我们日常使用的数学表达式写法，运算符在两个操作数中间：
 *   例如：3 + 4、2 * 5、(1 + 2) * 3
 *
 * 【什么是后缀表达式？（逆波兰表示法）】
 * 后缀表达式中，运算符在操作数的后面：
 *   中缀：3 + 4      ->  后缀：3 4 +
 *   中缀：2 * 5      ->  后缀：2 5 *
 *   中缀：3 + 4 * 2  ->  后缀：3 4 2 * +
 *
 * 【为什么需要转换？】
 * 1. 中缀表达式需要考虑运算符优先级和括号，解析复杂
 * 2. 后缀表达式不需要括号，从左到右顺序计算，非常适合计算机处理
 * 3. 后缀表达式可以用简单的栈来计算
 *
 * 【运算符优先级】
 *   优先级 2（高）：* /
 *   优先级 1（低）：+ -
 *   括号不是运算符，但用于改变计算顺序
 *
 * ============================================================================
 *                      第二部分：Shunting Yard 算法
 * ============================================================================
 *
 * 【算法简介】
 * Shunting Yard（调度场）算法由 Edsger Dijkstra 发明，
 * 用于将中缀表达式转换为后缀表达式。
 *
 * 【算法步骤 - 用火车调度场来理解】
 * 想象一个火车调度场：
 * - 输入轨道：中缀表达式的各个元素（数字、运算符、括号）
 * - 输出轨道：后缀表达式
 * - 临时轨道（栈）：暂存运算符
 *
 * 【详细步骤】
 * 从左到右扫描中缀表达式的每个元素：
 *
 * 1. 如果是【数字】：
 *    -> 直接输出到结果
 *
 * 2. 如果是【左括号 '('】：
 *    -> 压入运算符栈
 *
 * 3. 如果是【右括号 ')'】：
 *    -> 弹出栈顶运算符并输出，直到遇到左括号
 *    -> 丢弃这对括号（不输出）
 *
 * 4. 如果是【运算符】：
 *    -> 当栈不为空，且栈顶不是左括号，且栈顶运算符优先级 >= 当前运算符时：
 *       弹出栈顶运算符并输出
 *    -> 将当前运算符压入栈
 *
 * 5. 扫描完成后：
 *    -> 将栈中剩余的运算符全部弹出并输出
 *
 * 【示例：转换 "3 + 4 * 2"】
 *
 * 步骤  | 当前元素 | 动作                    | 输出队列    | 运算符栈
 * ------|----------|-------------------------|-------------|----------
 *   1   |    3     | 数字，直接输出          | 3           | (空)
 *   2   |    +     | 栈空，压入栈            | 3           | +
 *   3   |    4     | 数字，直接输出          | 3 4         | +
 *   4   |    *     | *优先级>+，压入栈       | 3 4         | + *
 *   5   |    2     | 数字，直接输出          | 3 4 2       | + *
 *   6   |  结束    | 弹出所有运算符          | 3 4 2 * +   | (空)
 *
 * 结果：3 4 2 * +
 *
 * 【示例：转换 "(1 + 2) * 3"】
 *
 * 步骤  | 当前元素 | 动作                    | 输出队列    | 运算符栈
 * ------|----------|-------------------------|-------------|----------
 *   1   |    (     | 左括号，压入栈          | (空)        | (
 *   2   |    1     | 数字，直接输出          | 1           | (
 *   3   |    +     | 压入栈                  | 1           | ( +
 *   4   |    2     | 数字，直接输出          | 1 2         | ( +
 *   5   |    )     | 弹出直到(，输出+        | 1 2 +       | (空)
 *   6   |    *     | 栈空，压入栈            | 1 2 +       | *
 *   7   |    3     | 数字，直接输出          | 1 2 + 3     | *
 *   8   |  结束    | 弹出所有运算符          | 1 2 + 3 *   | (空)
 *
 * 结果：1 2 + 3 *
 *
 * ============================================================================
 *                      第三部分：计算后缀表达式
 * ============================================================================
 *
 * 【算法步骤】
 * 从左到右扫描后缀表达式：
 *
 * 1. 如果是【数字】：压入数字栈
 * 2. 如果是【运算符】：
 *    -> 从栈中弹出两个数字（注意顺序！先弹出的是第二个操作数）
 *    -> 执行运算
 *    -> 将结果压入栈
 * 3. 扫描完成后，栈中唯一的元素就是最终结果
 *
 * 【示例：计算 "3 4 2 * +"】
 *
 * 步骤  | 当前元素 | 动作                    | 数字栈
 * ------|----------|-------------------------|-------------
 *   1   |    3     | 压入栈                  | 3
 *   2   |    4     | 压入栈                  | 3, 4
 *   3   |    2     | 压入栈                  | 3, 4, 2
 *   4   |    *     | 弹出4,2，计算4*2=8      | 3, 8
 *   5   |    +     | 弹出3,8，计算3+8=11     | 11
 *
 * 结果：11
 *
 * ============================================================================
 *                      第四部分：数据结构定义
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

/*
 * ----------------------------------------------------------------------------
 *                              栈的实现
 * ----------------------------------------------------------------------------
 * 栈（Stack）是一种后进先出（LIFO）的数据结构。
 * 就像一摞盘子，最后放上去的盘子最先被拿走。
 *
 * 我们需要两种栈：
 * 1. 数字栈（存储 double 类型）- 用于计算后缀表达式
 * 2. 字符栈（存储 char 类型）- 用于存储运算符
 */

#define MAX_STACK_SIZE 100  /* 栈的最大容量 */
#define MAX_EXPR_LEN 256    /* 表达式的最大长度 */

/*
 * 【任务1】定义数字栈结构
 *
 * 提示：栈需要两个成员
 * - 一个数组用于存储数据
 * - 一个整数记录栈顶位置（-1 表示空栈）
 */
typedef struct {
    double data[MAX_STACK_SIZE];  /* 存储数字的数组 */
    int top;                       /* 栈顶索引，-1表示空栈 */
} NumStack;

/*
 * 【任务2】定义字符栈结构（用于存储运算符）
 */
typedef struct {
    char data[MAX_STACK_SIZE];    /* 存储字符的数组 */
    int top;                       /* 栈顶索引，-1表示空栈 */
} CharStack;

/*
 * ============================================================================
 *                      第五部分：栈操作函数
 * ============================================================================
 */

/*
 * 【任务3】初始化数字栈
 * 将栈顶索引设为 -1，表示空栈
 */
void num_stack_init(NumStack *stack) {
    stack->top = -1;
}

/*
 * 【任务4】检查数字栈是否为空
 * 返回：1 表示空，0 表示非空
 */
int num_stack_is_empty(NumStack *stack) {
    return stack->top == -1;
}

/*
 * 【任务5】向数字栈压入一个数字
 *
 * 步骤：
 * 1. 检查栈是否已满（top >= MAX_STACK_SIZE - 1）
 * 2. 如果未满，先将 top 加 1，再将数字存入 data[top]
 */
void num_stack_push(NumStack *stack, double value) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

/*
 * 【任务6】从数字栈弹出一个数字
 *
 * 步骤：
 * 1. 检查栈是否为空
 * 2. 如果非空，返回 data[top]，然后将 top 减 1
 */
double num_stack_pop(NumStack *stack) {
    if (num_stack_is_empty(stack)) {
        printf("Error: Stack is empty, cannot pop!\n");
        return 0;
    }
    return stack->data[stack->top--];
}

/*
 * 【任务7-10】实现字符栈的操作函数
 * 与数字栈类似，请自行实现以下函数：
 */
void char_stack_init(CharStack *stack) {
    stack->top = -1;
}

int char_stack_is_empty(CharStack *stack) {
    return stack->top == -1;
}

void char_stack_push(CharStack *stack, char c) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

char char_stack_pop(CharStack *stack) {
    if (char_stack_is_empty(stack)) {
        printf("Error: Stack is empty, cannot pop!\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

/*
 * 【任务11】查看字符栈顶元素（不弹出）
 * 这个函数在 Shunting Yard 算法中很有用
 */
char char_stack_peek(CharStack *stack) {
    if (char_stack_is_empty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

/*
 * ============================================================================
 *                      第六部分：辅助函数
 * ============================================================================
 */

/*
 * 【任务12】判断字符是否为运算符
 */
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/*
 * 【任务13】获取运算符优先级
 *
 * 优先级规则：
 * - '*' 和 '/' 优先级为 2（高）
 * - '+' 和 '-' 优先级为 1（低）
 * - 其他返回 0
 */
int get_precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

/*
 * 【任务14】执行单次运算
 *
 * 参数：
 * - a: 第一个操作数（左边的数）
 * - b: 第二个操作数（右边的数）
 * - op: 运算符
 *
 * 注意：从栈中弹出时，先弹出的是 b，后弹出的是 a
 */
double apply_operator(double a, double b, char op) {
    switch (op) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            return divide(a, b);
        default:
            printf("Error: Unknown operator'%c'\n", op);
            return 0;
    }
}

/*
 * ============================================================================
 *                  第七部分：中缀转后缀（Shunting Yard）
 * ============================================================================
 *
 * 【任务15】实现中缀表达式转后缀表达式
 *
 * 输入：中缀表达式字符串，如 "3 + 4 * 2"
 * 输出：后缀表达式字符串，如 "3 4 2 * +"
 *
 * 算法伪代码：
 *
 * function infix_to_postfix(infix):
 *     初始化运算符栈
 *     初始化输出字符串
 *
 *     for each token in infix:
 *         if token 是数字:
 *             添加到输出
 *         else if token == '(':
 *             压入栈
 *         else if token == ')':
 *             while 栈顶 != '(':
 *                 弹出并添加到输出
 *             弹出 '('（丢弃）
 *         else if token 是运算符:
 *             while 栈非空 AND 栈顶!='(' AND 栈顶优先级>=当前优先级:
 *                 弹出并添加到输出
 *             压入当前运算符
 *
 *     while 栈非空:
 *         弹出并添加到输出
 *
 *     return 输出字符串
 */
int infix_to_postfix(const char *infix, char *postfix) {
    CharStack op_stack;
    char_stack_init(&op_stack);

    int j = 0;  /* postfix 字符串的索引 */
    int i = 0;  /* infix 字符串的索引 */
    int len = strlen(infix);

    while (i < len) {
        char c = infix[i];

        /* 跳过空格 */
        if (c == ' ') {
            i++;
            continue;
        }

        /* 情况1：数字（包括多位数和小数） */
        if (isdigit(c) || (c == '.' && i + 1 < len && isdigit(infix[i + 1]))) {
            /* 复制整个数字到输出 */
            while (i < len && (isdigit(infix[i]) || infix[i] == '.')) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';  /* 数字之间用空格分隔 */
            continue;
        }

        /* 情况2：左括号 */
        if (c == '(') {
            char_stack_push(&op_stack, c);
            i++;
            continue;
        }

        /* 情况3：右括号 */
        if (c == ')') {
            while (!char_stack_is_empty(&op_stack) &&
                   char_stack_peek(&op_stack) != '(') {
                postfix[j++] = char_stack_pop(&op_stack);
                postfix[j++] = ' ';
            }
            if (char_stack_is_empty(&op_stack)) {
                printf("Error: Mismatched parentheses\n");
                return 0;
            }
            char_stack_pop(&op_stack);  /* 弹出 '(' */
            i++;
            continue;
        }

        /* 情况4：运算符 */
        if (is_operator(c)) {
            while (!char_stack_is_empty(&op_stack) &&
                   char_stack_peek(&op_stack) != '(' &&
                   get_precedence(char_stack_peek(&op_stack)) >= get_precedence(c)) {
                postfix[j++] = char_stack_pop(&op_stack);
                postfix[j++] = ' ';
            }
            char_stack_push(&op_stack, c);
            i++;
            continue;
        }

        /* 未知字符 */
        printf("Error: Unrecognized character '%c'\n", c);
        return 0;
    }

    /* 弹出栈中剩余的运算符 */
    while (!char_stack_is_empty(&op_stack)) {
        char op = char_stack_pop(&op_stack);
        if (op == '(') {
            printf("Error: Mismatched parentheses\n");
            return 0;
        }
        postfix[j++] = op;
        postfix[j++] = ' ';
    }

    /* 去掉末尾多余的空格 */
    if (j > 0 && postfix[j - 1] == ' ') {
        j--;
    }
    postfix[j] = '\0';

    return 1;  /* 成功 */
}

/*
 * ============================================================================
 *                      第八部分：计算后缀表达式
 * ============================================================================
 *
 * 【任务16】实现后缀表达式计算
 *
 * 算法伪代码：
 *
 * function evaluate_postfix(postfix):
 *     初始化数字栈
 *
 *     for each token in postfix:
 *         if token 是数字:
 *             压入栈
 *         else if token 是运算符:
 *             b = 弹出栈顶
 *             a = 弹出栈顶
 *             result = a op b
 *             压入 result
 *
 *     return 栈顶元素（最终结果）
 */
double evaluate_postfix(const char *postfix) {
    NumStack num_stack;
    num_stack_init(&num_stack);

    int i = 0;
    int len = strlen(postfix);

    while (i < len) {
        char c = postfix[i];

        /* 跳过空格 */
        if (c == ' ') {
            i++;
            continue;
        }

        /* 如果是数字 */
        if (isdigit(c) || (c == '.' && i + 1 < len && isdigit(postfix[i + 1]))) {
            /* 解析数字 */
            double num = 0;
            double decimal = 0.1;
            int is_decimal = 0;

            while (i < len && (isdigit(postfix[i]) || postfix[i] == '.')) {
                if (postfix[i] == '.') {
                    is_decimal = 1;
                } else if (is_decimal) {
                    num += (postfix[i] - '0') * decimal;
                    decimal *= 0.1;
                } else {
                    num = num * 10 + (postfix[i] - '0');
                }
                i++;
            }
            num_stack_push(&num_stack, num);
            continue;
        }

        /* 如果是运算符 */
        if (is_operator(c)) {
            if (num_stack.top < 1) {
                printf("Error: Invalid expression format\n");
                return 0;
            }
            double b = num_stack_pop(&num_stack);
            double a = num_stack_pop(&num_stack);
            double result = apply_operator(a, b, c);
            num_stack_push(&num_stack, result);
            i++;
            continue;
        }

        i++;
    }

    if (num_stack.top != 0) {
        printf("错误：表达式格式不正确！\n");
        return 0;
    }

    return num_stack_pop(&num_stack);
}

/*
 * ============================================================================
 *                      第九部分：主函数（表达式计算）
 * ============================================================================
 *
 * 【任务17】实现表达式解析器的入口函数
 *
 * 这个函数将被添加到主菜单中，作为选项12
 */
void expression_calculator(void) {
    char infix[MAX_EXPR_LEN];
    char postfix[MAX_EXPR_LEN];

    printf("\n");
    printf("========================================\n");
    printf("         Expression Calculator\n");
    printf("========================================\n");
    printf("\n");
    printf("Supported operator: + - * /\n");
    printf("support ()\n");
    printf("Examples:3 + 4 * 2, (1 + 2) * 3\n");
    printf("\n");
    printf("Please enter expression:");

    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        printf("Error: loading inputs fails\n");
        return;
    }

    /* 去掉换行符 */
    int len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    if (strlen(infix) == 0) {
        printf("Error: Expression is empty.\n");
        return;
    }

    printf("\n");
    printf("------------------------------------------\n");
    printf("  Expression: %s\n", infix);

    /* 转换为后缀表达式 */
    if (!infix_to_postfix(infix, postfix)) {
        return;
    }
    printf("  Postfix Expression: %s\n", postfix);

    /* 计算结果 */
    double result = evaluate_postfix(postfix);
    printf("  Result:   %.2lf\n", result);
    printf("------------------------------------------\n");
    printf("\n");
}

/*
 * ============================================================================
 *                      第十部分：集成到主程序
 * ============================================================================
 *
 * 【任务18】将表达式计算器添加到主菜单
 *
 * 步骤：
 *
 * 1. 在 calc.h 中添加函数声明：
 *    void expression_calculator(void);
 *
 * 2. 修改 main.c 中的菜单，添加选项12：
 *
 *    printf("|  12. Expression Calculator               |\n");
 *    printf("|  13. Exit                                |\n");
 *
 * 3. 在 main.c 的 switch 语句中添加 case 12：
 *
 *    case 12:
 *        expression_calculator();
 *        continue;
 *
 * 4. 更新退出选项为 13
 *
 * 5. 在 CMakeLists.txt 中添加 module15_expression_parser.c
 *
 * ============================================================================
 *                          恭喜完成！
 * ============================================================================
 *
 * 你已经完成了命令行计算器项目的所有15个模块！
 *
 * 【你学到了什么】
 * - 栈数据结构的实现和应用
 * - Shunting Yard 算法（中缀转后缀）
 * - 后缀表达式的计算
 * - 运算符优先级的处理
 * - 括号匹配的处理
 *
 * 【扩展挑战】
 * 如果你想继续提升，可以尝试：
 * 1. 支持负数（如 -3 + 4）
 * 2. 支持更多运算符（如 ^ 幂运算、% 取模）
 * 3. 支持数学函数（如 sin, cos, sqrt）
 * 4. 添加变量支持（如 x = 5, x + 3）
 * 5. 实现表达式历史记录
 *
 * ============================================================================
 */
