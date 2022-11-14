rm -f -R _ex3.txt
touch _ex3.txt
rm -f -R ex3.txt
touch ex3.txt
echo "Shulepin Danila" >> _ex3.txt
chmod -x _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt
echo "660: 6 -> 110 <=> ++- permissions for owner" >> ex3.txt
echo "     6 -> 110 <=> ++- permissions for group" >> ex3.txt
echo "     0 -> 000 <=> --- permissions for others" >> ex3.txt
echo "775: 7 -> 111 <=> +++ permissions for owner" >> ex3.txt
echo "     7 -> 111 <=> +++ permissions for group" >> ex3.txt
echo "     5 -> 101 <=> +-+ permissions for others" >> ex3.txt
echo "777: 7 -> 110 <=> +++ permissions for owner" >> ex3.txt
echo "     7 -> 110 <=> +++ permissions for group" >> ex3.txt
echo "     7 -> 000 <=> +++ permissions for others" >> ex3.txt
