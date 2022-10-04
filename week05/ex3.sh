gcc -w -pthread ex3.c -o ex3
time=`date +%s`
./ex3 10000000 1 > ex3.txt
echo 1 thread runs $(expr `date +%s` - $time)s >> ex3.txt

time=`date +%s`
./ex3 10000000 2 >> ex3.txt
echo 2 threads run $(expr `date +%s` - $time)s >> ex3.txt

time=`date +%s`
./ex3 10000000 4 >> ex3.txt
echo 4 threads run $(expr `date +%s` - $time)s >> ex3.txt

time=`date +%s`
./ex3 10000000 10 >> ex3.txt
echo 10 threads run $(expr `date +%s` - $time)s >> ex3.txt

time=`date +%s`
./ex3 10000000 100 >> ex3.txt
echo 100 threads run $(expr `date +%s` - $time)s >> ex3.txt