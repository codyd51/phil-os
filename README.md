phil-os - learning to run code on the (virtual) metal
=====================================================

This is basically me running through JamesM's [OS development tutorial](http://www.jamesmolloy.co.uk/tutorial_html/), so very little original code here.

So far - all of the stuff from the tutorial:

* It boots!
* Basic console I/O.
* Kernel heap and dynamic memory alloc/free.
* VFS and initrd
* Multitasking
* Syscalls and user mode.

I think 'exec' will probably come next - this means understanding the ELF binary format.

Some notes on the development environment
-----------------------------------------

I gave up trying to use OSX as a development environment pretty early on, basically because (a) I don't understand the Mach-O binary format well enough, and (b) I don't know how to use the OSX linker to build a binary with a Multiboot header. I'm therefore using Ubuntu with a more familiar GNU toolchain to develop. Although I'm using a 64 bit platform, I'm forcing everything to build 32 bit binaries for simplicity - that's the '-m' flags in the Makefile.

I'm running the OS itself inside VirtualBox, which is super easy - you just need to make a GRUB floppy image and mount it as the boot device.

Pro-tip: VirtualBox has debugging tools built in - you just need to add --debug to the command line when you start the VM host. Once you have that you can access register state, dump memory and inspect the stack.
