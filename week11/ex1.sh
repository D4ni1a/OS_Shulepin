dir="lofsdisk"

if [ -d "$dir" ]
then
    if mountpoint -q "$dir";
    then
         sudo umount -d "$dir"
    fi
    rm -R "$dir"
fi

rm -f lofs.img

fallocate -l 100M lofs.img
mkdir lofsdisk

freeloop=$(sudo losetup -f)
sudo losetup $freeloop lofs.img
sudo mkfs.ext4 $freeloop
sudo mount --types ext4 $freeloop lofsdisk
