
/********************************************/
/* Author       : ARUN.V                    */
/* Date         : 3-3-2023                  */
/* Filename     :                           */
/* Description  : Kernel Compilation steps  */
/********************************************/

Prerequisites:
	Account: sudo/root user
	Space  : minimum 5GB space required
	check current Kernel level


step 1 : Download source Code
           step 1.1 : https://www.kernel.org/
           
step 2 : Extract source Code
	   step 2.1 : tar xvf linux-6.0.7.tar.xz (which Kernel required)
	   
step 3 : Install Required Package to compile Linux Kernel
	   step 3.1 : sudo apt-get install build-essential 
	   step 3.2 : sudo apt-get install libelf-dev
	   step 3.3 : sudo apt-get install ncurses-dev
	   step 3.4 : sudo apt-get install libssl-dev
	   step 3.5 : sudo apt-get install byzanz
	   step 3.6 : sudo apt-get install flex 
	   step 3.7 : sudo apt-get install bison
	   

step 4 : Configure Kernel
	   step 4.1 : change current directory to extracted directory
	   step 4.2 : make menuconfig

step 5 : Build the Kernel
	   step 5.1 : make -j(core)   //core 2/4
	   step 5.2 : sudo make modules
	   step 5.3 : sudo make install
	   step 5.4 : sudo make modules_install
	   step 5.5 : sudo make install

step 6 : Update the Bootloader
	   step 6.1 : sudo update-initramfs -c -k 6.0.7 (put latest )
	   step 6.2 : sudo update-grub
	   

step 7 : Reboot and Verify kernel Version
	   ste  7.1 : Reboot
	   step 7.2 : uname -mrs




