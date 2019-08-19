/*Programming language*/

Some text comes in and behavior comes out
Text -> Lexer -> Tokens -> Parser -> Syntax tree -> Evaluator -> Behavior 

Assembler:
1: Lexical Analysis (lexer)
	1.1: Read champion file
	1.2: Tokenize each word (separated by a space, recognize commas, .name and .comment)
	1.3: Tokenization is done by reading letter by letter until it recognizes the next tokend if token then respond to Syntax Analyzer/Parser 
   	//If token is parentheses, ',', or ':' then it is represented as an integer code?
	1.4: Valid tokens for us will be the opcodes

2: Parser
	2.1: Sends a request to the LA, 
3:

Lexical analysis:
Tokenizes the code, eliminates whitespaces and tabs and newline
tokens are defined by reg-ex which are understood by lexical analyzer
Reg-exp: the notations for describing a set of character strings
If any invalid tokens generate a warning
Receives a Get-next-token command by parser
"Removes" comments and whitespace
tokens: single logical unit
	a: Identifiers: variable name, function name, etc. (MUST DIFFER IN CASE and SPELLING FROM KEYWORDS) In C they must only consist of digits, underscore or letters, no whitespace, no longer than 31 chars
	b: keywords: for, while, if, auto, break, return, static, short, unsigned, etc
	c: operators: +, ++, -, <<, sizeof, etc (Arithmetic, Relational, Logical, Assignment, Conditional, Bitwise)
	d: special symbol: #, &, =, *, {}, [] etc
		Arithmetic, punctuation, assignment, special assignment, comparison, preprocessor, logical, shift operators
	e: constant

A token is formed with individual characters and referring to the reg-ex that can be compared to a dictionary (op-code mnemonic basically)
non-tokens: Comments, preprocessor directive, macros, blanks, tabs, newline/spaces, etc.

Pattern: Rule to descibe set of strings associated to token  
Lexeme: sequence ok characters are matched by a pattern for token i n t = int? // (matched by the reg-ex)

Language theory:
	empty string->Epsilon

Example:
	a = b + c * 10
	<id, pointer to the symbol for a>
	<op, '='>
	<id, pointer to the symbol for b>
	<op, '+'>
	<id, pointer to the symbol for c>
	<op, '*'>
	<const, integer value 10>

Lexer: a program that performs lexical analysis, if it encounters an error it throws an error and stops the scanning

Once the token is produced and it has a grammar error, a syntax error gets thrown

Syntax analyzer/Parser: Generate a syntax tree

Cell: //lexer
	scans through every char and returns what type of token/regex it is

Object file: 
    Header: Index, other software can use it to go into specific segments
	Text segment: Set of instructions
	Data segment: Whatever data you use
	Relocation information: (initial part of RAM is dedicated to OS) 
	Symbol table: Every symbol contained in your program (identifiers)
	Debugging information: How a variable is changing
	Object code:

COMPILING:

High level -> Pre-processor - Pure HLL -> Compiler - Assembly language -> Assembler - Relocatable Machine Code -> Loader/Linker -> Absolute Machine Code

High level language: #define or include i.e. '#' symbol is a preprocessor directive, it directs the pre-processor about what to do
Pre-processor: Removes all '#' directives, by including the files and all the #define directives using macro expansion. File inclusion, augmentation, macro-processing, etc
Assembly language: Intermediate state, machine instructions and useful data for execution
Assembler: Non-universal, every platform i.e. "Hardware + OS" its output is called object file
Interpreter: Converts high-level into low-level, translates the program one statement at a time, like compilers, usually slower
Relocatable Machine code: Can be loaded at any point in the RAM? and can be run.
Loader/Linker: Converts the relocatable code into absolute code and tries to run the program. Linker loads a variety of objects files into a single file then loader loads it 
			in memory and executes it.
	

