
// java -jar .\external\antlr-4.7.2-complete.jar -no-listener -visitor -Dlanguage=Cpp .\src\lisp.g -o .\src\generated\

grammar lisp;

program
    : toplevel* EOF;

toplevel
    : (defun|define|defstruct)
    ;

defun
    : '(' 'defun' IDENTIFIER '(' typedParameter* ')' typeName expression* ')'
    ;

define
    : '(' 'define' IDENTIFIER expression ')'
    ;

defstruct
    : '(' 'defstruct' IDENTIFIER structMember+ ')'
    ;

structMember
    : '[' IDENTIFIER typeName expression? ']'
    ;

expression
    : constant
    | callable
    | lambda
    | let
    | cond
    | loop
    | binary
    ;

constant
    : symbolReference | FLOAT_LITERAL | INTEGER_LITERAL | STRING_LITERAL
    ;

symbolReference
    : IDENTIFIER ('.' IDENTIFIER)*
    ;

callable
    : '(' expression parameter* ')'
    ;

parameter
    : expression
    ;

lambda
    : '(' 'lambda' '(' typedParameter* ')' typeName expression* ')'
    ;

typedParameter
    : '[' IDENTIFIER typeName ']'
    | typeName
    ;

let
    : '(' 'let' '(' typedValueBinding* ')' expression* ')'
    ;

typedValueBinding
    : '[' IDENTIFIER typeName? expression ']'
    ;

typeName
    : POINTER_PREFIX? IDENTIFIER
    ;

cond
    : '(' 'cond' condValue* ')'
    ;

condCondition
    : expression
    ;

condValue
    : '[' condCondition expression+ ']'
    | '[' 'else' expression+ ']'
    ;

loop
    : '(' 'loop' '(' loopBindingExpression* ')' 'do' expression* ')'
    ;

loopBindingExpression
    : '[' IDENTIFIER typeName? expression expression expression ']'
    ;

binary
    : '(' binaryOperator expression expression ')'
    ;

binaryOperator
    : '+'|'-'|'*'|'/'
    | '='|'>'|'<'
    | '~='|'>='|'<='
    ;

WHITESPACE
    : [ \t\u000C\r\n]+ -> skip
    ;

POINTER_PREFIX
    : '&'
    ;

IDENTIFIER
    : IdSymbol (Digit|IdSymbol)*
    ;

FLOAT_LITERAL
    : ('+'|'-')? Digit+ '.' Digit+
    ;

INTEGER_LITERAL
    : ('+'|'-')? Digit+
    ;

STRING_LITERAL
    : '"' (~('"' | '\\' | '\r' | '\n') | '\\' ('"' | '\\'))* '"'
    ;

LINE_COMMENT
    : ';' ~('\r'|'\n')* -> channel(HIDDEN)
    ;

fragment Digit
    : [0-9]
    ;

fragment Nondigit
    : [a-zA-Z]
    ;

fragment IdSymbol
    : Nondigit('-'|'+'|'*'|'/'|'_'|Nondigit)*
    ;
