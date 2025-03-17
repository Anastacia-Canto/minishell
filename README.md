# Minishell

The objective is to create a shell with the same bahavior as Bash, written in C.
To achieve this, we studied the commands to implement, testing not onlly their main funcionalities but also 
the kind of error when the input was different from the expected. 
Deal with the inputs parsing was really a challenge, involving a lot of string manipulation.  
But the heart of the program is the pipeline we had to construct, from receiving a line, parsing it between commands and arguments, chaining the outputs as inputs to next command, 
dealing with simultaneous process to return the correct final result, as Bash does. It can even interact with Bash.

Analyzing the results, I believe it could be very helpful to write unit tests during development. It is a complex program, what make it very easy to create new errors when trying to solve 
a specific problem. And it showed the importance of writing clean and organized code, regarding the complexity and the need for clear communication between group members. 

Some of commands recreated on our shell:
- cd
- echo
- pwd
- env
- exit
- export
- unset
- Heredoc and redirections
- pipe
