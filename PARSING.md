#Parsing

BluScript will use three (yes, i know there are 4 items in the list) main steps/components in its parsing process:

* Tokenizer

* Parser

* ASTNode

* ASTCompiler

Below i will try to explain these steps.


###Tokenizer

The Tokenizer is the first step in parsing a BluScript component.  
It simply breaks up the input source code into its lowest common denominators - "Tokens".  
In essence, there are 3 types of tokens (currently):

* WHITESPACE: Any kind of whitespace

* WORD - really, anything that starts with a letter will get a token type of word

* NUMBER - any sequence of characters that contains only a number

* SYMBOL - any special symbols, like "()", "{}" etc, etc  

Then there is a "PostChecker", that may further categorize these Tokens, such as  
the KeywordChecker, which checks if a Token of the type word is any of these keywords:

* bool, int, float, string - it will change the token type to KEYWORD
* return, new - it will change to the token type to KEYWORDf