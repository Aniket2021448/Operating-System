The first step is to add the syscall to the syscall table (syscall 64.tbl). This line should go after the common kernel 2d memcpy numbers 450 and 451. sys kernel 2d memcpy.

And in the sys.c file, which is located at /new kernel/linux-5.19.9/kernel/sys.c, we need to include the additional syscall that is defined by:
SYSCALL DEFINE4(kernel 2d memcpy,float *,arr1,float *,arr2,int,n,int,m).

I utilised the copy from user and copy to user functions in the SYSCALL DEFINE4 to copy the data from the matrix or array. The three arguments for the aforementioned function are an array, new array adders, and the size of the new array.

Using the command, build/compile the syscall

SUFFIX="linux_aniket"

set -e

make -j2

make modules_install

cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux$SUFFIX

sed s/linux/linux$SUFFIX/g \
    </etc/mkinitcpio.d/linux.preset \
    >/etc/mkinitcpio.d/linux$SUFFIX.preset
mkinitcpio -p linux$SUFFIX

grub-mkconfig -o /boot/grub/grub.cfg