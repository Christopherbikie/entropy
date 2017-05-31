#!/bin/sh

set -e
. ./build.sh
 
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cp sysroot/boot/entropy.kernel isodir/boot/entropy.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "entropy" {
	multiboot /boot/entropy.kernel
}
EOF
grub-mkrescue -o entropy.iso isodir

