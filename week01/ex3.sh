mkdir ~/week01/root_folder
date
sleep 3
mkdir ~/week01/home_folder
date
sleep 3
touch ~/week01/root_folder/root.txt
date
sleep 3
touch ~/week01/home_folder/home.txt

ls -tr / > ~/week01/root_folder/root.txt
ls -tr ~/ > ~/week01/home_folder/home.txt

cat ~/week01/root_folder/root.txt
cat ~/week01/home_folder/home.txt
ls ~/week01/root_folder
ls ~/week01/home_folder
