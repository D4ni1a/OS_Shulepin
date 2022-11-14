rm -f -R _ex1.txt
touch _ex1.txt
echo "Danila Shulepin" >> _ex1.txt
rm -f -R _ex1_1.txt
rm -f -R _ex1_2.txt
link _ex1.txt _ex1_1.txt
link _ex1.txt _ex1_2.txt
rm -f -R ex1.txt
touch ex1.txt
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
