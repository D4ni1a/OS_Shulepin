gcc -w ex3.c -o ex3
./ex3 3 &
sleep 2
pstree $$
sleep 7
pstree $$
sleep 5
pstree $$
sleep 5
./ex3 5 &
sleep 22
pstree $$