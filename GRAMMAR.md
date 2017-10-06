# Grammar used by this implementation

## Terminals (tokens)

These tokens have an associated attributes, which means they have various form

`WORD`

`ASSIGNEMENT_WORD`

`NAME`

`NEWLINE`

`IO_NUMBER`

### Operators

Each of these tokens have a single possible form
They are given with their name first and the corresponding string following

`AND_IF`	`&&`

`OR_IF`		`||`

`DSEMI`		`;;`

`DLESS`		`>>`

`DGREAT`	`<<`

`LESSAND`	`<&`

`GREATAND`	`>&`

`LESSGREAT`	`<>`

`DLESSDASH`	`<<-`

`CLOBBER`	`>|`

`AND`		`&`

`SEMI`		`;`

`GREAT`		`>`

`LESS`		`<`

### Reserved Words

`IF		`if`
`THEN`	`then`
`ELSE`	`else`
`ELIF`	`elif`
`FI`	`fi`
`DO`	`do`
`DONE`	`done`

`CASE`	`case`
`ESAC`	`esac`
`WHILE`	`while`
`UNTIL`	`until`
`FOR`	`for`

`LBRACE`	`{`
`RBRACE`	`}`
`BANG`		`!`
`IN`		`in`

That is the empty string.

`empty`		``


## The Grammar

This is for now a subset of the [POSIX Shell Grammar](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)

### Rules 

1. When TOKEN = reserved_word -> that reseverd word.
Else : WORD token
2. See Redirection
3. Quote Removal applied to the word to determine delimiter
4. ESAC if match, else, WORD
5. When TOKEN meets name requirements, NAME, else, WORD
6. a. case : TOKEN is exactly in -> IN. Else, WORD
   b. for : TOKEN is exactly in or do -> IN or DO. Else, WORD
7. a. First Word : if TOKEN does not have'=', rule 1. Else b.
   b. TOKEN contains unquoted '=' :
	- begins with '=', rule 1.
	- all before '=' == valid name -> ASSIGNEMENT_WORD
	- Unspecified
	Rule 1.
8. NAME in function
TOKEN = exactly a resevered word -> that reserved word. Else, if TOKEN meets name requirements -> NAME.
Else Rule 1.
9. No expansion or assignement.

### Productions

simple_command	: cmd_prefix cmd_word cmd_suffix
				| cmd_prefix cmd_word
				| cmd_prefix
				| cmd_name cmd_suffix
				| cmd_name
cmd_name		: WORD	/* Rule 7a /*
cmd_word		: WORD	/* Rule 7b */
cmd_prefix		: io_redirect
				| cmd_prefix | io_redirect
				| ASSIGNEMENT_WORD
				| cmd_prefix ASSIGNEMENT_WORD
cmd_suffix		: io_redirect
				| cmd_suffix io_redirect
redirect_list	: io_redirect | redirect_list io_redirect
io_redirect		: io_file | IO_NUMBER io_file
				| io_here | IO_NUMBER io_here
io_file			:io_op filename
io_op			:`LESS` | `LESSAND` | `GREAT` | `GREATAND` | `DGREAT` | `LESSGREAT` | `CLOBBER`
filename		:`WORD` /* Apply Rule 2 */
io_here			:`DLESS` here_end | `DLESSDASH` here_end
here_end		:`WORD`	/* Apply Rule 3 */
newline_list	:`NEWLINE` | newline_list `NEWLINE`
linebreak		:newline_list | `empty`
separator_op	:`AND` | `SEMI`
separator		:separator_op linebreak | newline_list
sequential_sep	:`SEMI`	linebreak | newline_list
