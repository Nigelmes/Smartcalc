# Smartcalc_v1.0

Smart calculator to solve math problems, build functions and count credit

Backend written on C, GUI - qt5+, C++;

Calcutator get a string, after clic to '=' send this string to validator, if expression is correct, it'll parsed by lexemes, and push them to stack.
Then make correct order of lexemes (to reverse polish notation) only then get an answer and send it to GUI

Also here are unit-testes, that make me sure, that calculator work correct, even with complex expressions.

If expression  uncorrect you'll get a warning


To start smart calculator you should dounload it, then write in terminal 'make install' and app will installed in 'smartcalc' folder.
And with command 'make open' you can open it and use.
