rm -f -R week01
mkdir week01
rm -f -R week10
mkdir week10
touch week01/file.txt
echo "Shulepin Danila" >> week01/file.txt
rm -f -R ex2.txt
touch ex2.txt
link week01/file.txt week10/_ex2.txt >> ex2.txt
find ./ -inum `stat -c '%i' week01/file.txt` >> ex2.txt
find ./ -inum `stat -c '%i' week01/file.txt` -exec rm {} \; >> ex2.txt
