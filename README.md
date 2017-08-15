# Seperate-Sentence
In the repository you will nd a program called args.cc, which demonstrates how to access
command line arguments from a C++ program. Use that program as an example to help you
solve this problem. In this problem, you will write a program called wordWrap, whose purpose
is conne text to a given width. wordWrap takes a single argument on the command line, a
positive integer denoting the width of the line. If no argument is supplied on the command
line, the width is 25. wordWrap takes a sequence of words on stdin and echoes them to stdout,
such that the width of the output is no wider than the provided command-line argument. For
example, if the width is 25 and the text is as seen below:
Friends Romans countrymen lend me your ears I come to bury Caesar not
to praise him
then the output would be
Friends Romans countrymen
lend me your ears I come
to bury Caesar not to
praise him
If a word is too long to t on what remains of the line, put it on the next line. Do not break
a word unless it is longer than the entire allowed width. For example, the same text with a
width of 8 becomes
Friends
Romans
countrym
en lend
me your
ears I
come to
bury
Caesar
not to
praise
him
When outputting words, separate them by a single whitespace character, either a single space
or a single newline, regardless of how they are spaced in the input. For example, if the input
contained words separated by two spaces, they would still be separated by one whitespace
character in the output.
