/*
* simpleKM.c − The simplest kernel module.
*/
#include <linux/module.h>   // Required by all kernel modules

// This function shall be invoked as soon as this LKM is loaded.
int hello_world_init_module(void){

    printk(KERN_INFO "SimpleKM module loaded Successfully\n");
    /*
     * A non 0 return means init_module failed; module can't be loaded.
     */
    return 0;
}


// This function shall be invoked as soon as this LKM is unloaded.
void hello_world_cleanup_module(void){

    printk(KERN_INFO "SimpleKM module unloaded successfully.\n");
}

// Tell the kernel which are init and cleanup functions for this module. 
// If you do not do this registration, kernel would try to use 'init_module' 
// and 'cleanup_module' instead
module_init(hello_world_init_module);
module_exit(hello_world_cleanup_module);

// Module Information
#define AUTHOR_NAME "Temple Cloud"
#define MODULE_DESC "A simple kernel module"

MODULE_AUTHOR(AUTHOR_NAME);         // Who wrote this module?
MODULE_DESCRIPTION(MODULE_DESC);    // What does this module do?
MODULE_LICENSE("GPL");

