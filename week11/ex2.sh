sh ex1.sh

sudo chown "$USER":"$USER" lofsdisk

echo "Danila" > lofsdisk/file1
echo "Shulepin" > lofsdisk/file2

gcc -w ex2.c -static -static-libgcc -static-libstdc++ -o ex2.out

cp ex2.out lofsdisk/
mkdir lofsdisk/bin
cp /bin/bash lofsdisk/bin
cp /bin/cat lofsdisk/bin
cp /bin/echo lofsdisk/bin
cp /bin/ls lofsdisk/bin

rm -f ex2.txt
touch ex2.txt

echo "Content of new root (lofsdisk):" >> ex2.txt
sudo chroot ./lofsdisk/ /ex2.out >> ex2.txt
echo "" >> ex2.txt

echo "Content of real root (/):" >> ex2.txt
./ex2.out >> ex2.txt

rm -R ./ex2.out
