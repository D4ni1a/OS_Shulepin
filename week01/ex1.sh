cd ~
mkdir week01
cd week01/
find /usr/bin -name "*gcc*" 2>/dev/null | sort -r | tail -n 5 > ex1.txt
