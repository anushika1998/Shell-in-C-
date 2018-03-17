# Shell-in-C

This is  a simple shell that can handle five, internal commands
– ‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’. These commands
would be handled directly by the shell. Your shell should also be able to handle
five external commands – ‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’.
<br/>
For each external command there is a different program and internal commands are written inside the main class. 
For each external command there are 2 other options available. 
<br/>
<br/>

___INTERNAL COMMANDS___

1. _CD_
cd dir_name or cd dir/dir/name or cd ..
	You will me able to traverse through directories with this command. It is able to take multiple directories at once. 
cd 
	Not putting any arguments will take us to the root folder. 

2. _ECHO_
echo hello
	It will print the rest of the string as it is 
echo 
	It will print a new line 
echo -n 
	It will not end it with a new line 

3. _ HSTORY_
history 
	it will print the history for the past 10 commands if any 

4. _PWD_
pwd 
	it will print the current firectory path

5. _EXIT_
exit 
	it will exit the shell


___EXTERNAL COMMANDS___

1. _LS_
ls
	it lists all the files in the current directory.

ls -m 
	fill width with a comma separated list of entries

ls -1
	 list one file per line. 


2. _RM_
rm filename
	this will delete the file with that name if it exists else gives an error.

rm -i filename
	this will promt a question before deleting the file.

rm -v filename
	this will delete the file the give a missege if it is deleted or not.


3. _MKDIR_
mkdir filename
	this will create a new directory and give an error if not possible.

mkdir -v filename 
	this will create a new file directory and give a messege on completion.

mkdir -m mode filename
	this will create a file directory with the particular mode.


4. _DATE_
date
	Display the current time in the given FORMAT, or set the system date.

date -I
	output date/time in ISO 8601 format.
	Example:2006-08-14T02:34:56-0600

date -R
	output date/time in ISO 8601 format. 
	Example:2006-08-14T02:34:56-0600


5. _CAT_
cat filename
	it will print the file on the shell window

cat -n filename 
	number all output lines

cat -E filename
	display $ at end of each line
