clear
make clean
clear

echo "============================"
echo "Building...   "
echo "============================"
make

echo
echo

echo "============================"
echo "Updating boot media image..."
echo "============================"
sudo sh update_image.sh
echo "Floppy image updated.       "
echo
make clean
exit 0