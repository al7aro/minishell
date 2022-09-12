# minishell

	### ~Reader


Heredocs
	substitute for STDIN
	send input to command
	if using between pipes
		input is added to that comming from pipe
	it can be implemented 
	heredoc input is proccessed
		FROM RIGHT TO LEFT
			and
		BEFORE NON HEREDOCED INPUT

		<stdinput fileinput stdoutput fileoutput stderror> could be a token

```
cat < README.md | grep h << MORE_INPUT | cat
```

```
cat < README.md | grep h << MORE_INPUT | cat | grep not << EVEN_MORE_INPUT
T(h)is is going to be cated since goes to first GREP (h) and the to second (not)
tis is not
MORE_INPUT
this is n_ot goint to be cated since goes to second grep (n_ot)
this is not not going to be cated since goes to second grep (not)
EVEN_MORE_INPUT
```

LOL=10
echo $LOL -> 10
echo "$LOL" -> 10
echo '$LOL' -> $LOL
