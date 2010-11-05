#!/bin/bash
#
# This build script is adapted from the build script for
# MikeOS.
#
# http://mikeos.berlios.de/

# initialization
OSNAME=BFOS
FLOPPY_IMG_NAME=floppy.img
CDROM_IMG_NAME=bfos.iso
KERNEL_NAME=kernel

OUTPUT_DIR=bin
FLOPPY_IMG_PATH=$OUTPUT_DIR/$FLOPPY_IMG_NAME
CDROM_IMG_PATH=$OUTPUT_DIR/$CDROM_IMG_NAME
KERNEL_PATH=$OUTPUT_DIR/$KERNEL_NAME

# Make sure the user has root permission
clear
echo ">>> Checking for root permissions..."
if test "`whoami`" != "root"
then
	echo "You must be logged in as root to build (for loopback mounting)"
	echo "Enter 'su' or 'sudo bash' to switch to root"
	exit
fi

echo ">>> Cleaning project..."
make clean

echo ">>> Building..."
make -silent|| exit

# Ensure the output floppy image exists
if [ ! -e $FLOPPY_IMG_PATH ]
then
    echo ">>> Could not locate the required floppy image: '$FLOPPY_IMG_PATH'"
	exit
else
    echo ">>> Updating floppy image at '$FLOPPY_IMG_PATH'..."
fi

# Copy the binary images to the install media
sudo losetup /dev/loop0 $FLOPPY_IMG_PATH
sudo mount /dev/loop0 /mnt
sudo cp $KERNEL_PATH /mnt/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
echo ">>> Floppy image updated."

# Create an ISO also
echo ">>> Creating CD-ROM ISO image..."
rm -f $CDROM_IMG_PATH
mkisofs -quiet -V '$OSNAME' -input-charset iso8859-1 -o $CDROM_IMG_PATH -b $FLOPPY_IMG_NAME $OUTPUT_DIR || exit

# cleanup
make clean
echo '>>> Done!'
exit 0
