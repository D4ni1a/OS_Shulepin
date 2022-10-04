gcc -w -pthread ex4.c -o ex4
time=`date +%s`
./ex4 10000000 1 > ex4.txt
echo 1 thread runs $(expr `date +%s` - $time)s >> ex4.txt

time=`date +%s`
./ex4 10000000 2 >> ex4.txt
echo 2 threads run $(expr `date +%s` - $time)s >> ex4.txt

time=`date +%s`
./ex4 10000000 4 >> ex4.txt
echo 4 threads run $(expr `date +%s` - $time)s >> ex4.txt

time=`date +%s`
./ex4 10000000 10 >> ex4.txt
echo 10 threads run $(expr `date +%s` - $time)s >> ex4.txt

time=`date +%s`
./ex4 10000000 100 >> ex4.txt
echo 100 threads run $(expr `date +%s` - $time)s >> ex4.txt