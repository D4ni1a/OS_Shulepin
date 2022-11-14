rm -R tmp
mkdir tmp
touch tmp/file1
touch tmp/file2
link tmp/file1 tmp/link1
rm -f ex4.txt
touch ex4.txt
gcc -w ex4.c -o ex4
./ex4>ex4.txt
