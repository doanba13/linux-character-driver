#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include <linux/jiffies.h>


#define DRIVER_AUTHOR "linh"
#define DRIVER_DESC "Dg driver"
#define VERSION "3.0"
#define MEM_SIZE 1024

static struct cdev *lab51_cdev;
unsigned open_cnt = 0;

char *buf_tmp;
int32_t *kernel_buf;

char fromBase[10], toBase[10], data[20];


static int vchar_driver_open(struct inode *inode, struct file *flip);
static int vchar_driver_release(struct inode *inode, struct file *filp);
static ssize_t vchar_driver_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off);
static ssize_t vchar_driver_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off);

static void DecToBinary(int n);
static void DecToHex(int n);
static void DecToOct(int n);
static int BinToDec(int bin_num);
static int OctalToDec(int n);
static int HexToDec(char *hex);
static int PowerNumberCal(int n, int exp);

static int finalBaseLen;
static int decimal;


static struct file_operations fops = 
{
    .owner      = THIS_MODULE,
    .read       = vchar_driver_read,
    .write      = vchar_driver_write,
    .open       = vchar_driver_open,
    .release    = vchar_driver_release,
};

struct vchar_drv{
	dev_t dev_num;				
	struct class *dev_class;	
	struct device *dev;
}vchar_drv;



static int vchar_driver_open(struct inode *inode, struct file *flip)
{
    open_cnt++;
    printk("Handle opened event %u times\n", open_cnt);
	return 0;
}


static int vchar_driver_release(struct inode *inode, struct file *filp)
{
    printk("Handle closed event %u times\n", open_cnt);
    return 0;
}
 

static ssize_t vchar_driver_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off)
{
	copy_to_user(user_buf, kernel_buf, MEM_SIZE);
	printk("Read\n");
	return finalBaseLen;
}


static ssize_t vchar_driver_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off)
{
	printk(KERN_INFO "JUMP TO WRITE\n");
	copy_from_user(buf_tmp, user_buf, len);

	printk(KERN_INFO "%s", *buf_tmp);
	sscanf(*buf_tmp, "%s,%s,%s", data, fromBase, toBase);

	printk(KERN_INFO "data = %s, from %s to %s\n", data, fromBase, toBase);

	if (strcmp(fromBase,"Binary") == 0 && strcmp(toBase,"Octal")) {
		decimal = BinToDec((int)data);
		DecToOct(decimal);
	} else if (strcmp(fromBase,"Binary") == 0 && strcmp(toBase,"Heximal")){
		decimal = BinToDec((int)data);
		DecToHex(decimal);
	} else if (strcmp(fromBase,"Octal") == 0 && strcmp(toBase,"Binary")){
		decimal = OctalToDec((int)data);
		DecToBinary(decimal);
	} else if (strcmp(fromBase,"Octal") == 0 && strcmp(toBase,"Heximal")){
		decimal = OctalToDec((int)data);
		DecToHex(decimal);
	} else if (strcmp(fromBase,"Heximal") == 0 && strcmp(toBase,"Binary")){
		decimal = HexToDec(data);
		DecToBinary(decimal);
	} else if (strcmp(fromBase,"Heximal") == 0 && strcmp(toBase,"Octal")){
		decimal = HexToDec(data);
		DecToOct(decimal);
	}

	printk(KERN_INFO "Write\n");
	return len;
}

int PowerNumberCal(int n, int exp)
{
    int value = 1;
    while (exp != 0)
    {
        value *= n;
        --exp;
    }
    return value;
}

// 10->2
void DecToBinary(int n)
{
    int arr[100];
    int i = 0;
    int j = 0;
    while (n > 0)
    {
        arr[i] = n % 2;
        n = n / 2;
        i++;
    }
    finalBaseLen = 0;
    for (i = i - 1; i >= 0; i--)
    {
        kernel_buf[j] = arr[i];
        j++;
        finalBaseLen++;
    }
}
// 10->16
void DecToHex(int n)
{
    int arr[100];
    int i = 0;
    int j = 0;
    int k = 0;
    while (n > 0)
    {
        arr[i] = n % 16;
        n = n / 16;
        i++;
    }
    finalBaseLen = 0;
    for (j = i - 1; j >= 0; j--)
    {
        kernel_buf[k] = arr[j];
        k++;
        finalBaseLen++;
    }
}

// 10->8
void DecToOct(int n)
{
    int arr[100];
    int i = 0;
    int j = 0;
    while (n > 0)
    {
        arr[i] = n % 8;
        n = n / 8;
        i++;
    }
    finalBaseLen = 0;
    for (i = i - 1; i >= 0; i--)
    {
        kernel_buf[j] = arr[i];
        j++;
        finalBaseLen++;
    }
}

// 2->10
int BinToDec(int bin_num)
{
    // declaration of variables
    int decimal_num = 0, temp = 0, rem;
    while (bin_num != 0)
    {
        rem = bin_num % 10;
        bin_num = bin_num / 10;
        decimal_num = decimal_num + rem * PowerNumberCal(2, temp);
        temp++;
    }
    return decimal_num;
}

// 8->10

int OctalToDec(int n)
{
    int p = 0, decimal = 0, r;

    while (n > 0)
    {
        // retrieving the right-most digit of n
        r = n % 10;

        // dividing n by 10 to remove the
        // right-most digits since it is already
        // scanned in previous step
        n = n / 10;

        decimal = decimal + r * PowerNumberCal(8, p);
        ++p;
    }

    return decimal;
}

// 16->10
int HexToDec(char *hex)
{
    int p = 0;
    int decimal = 0;
    int r, i;

    // instead of reading charcacters from Right-To-Left
    // we can also read character from Left-To-Right
    // we just have to initialize p with strlen(c) - 1
    // and decrement p in each iteration
    for (i = strlen(hex) - 1; i >= 0; --i)
    {

        // converting c[i] to appropriate decimal form
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            r = hex[i] - '0';
        }
        else
        {
            r = hex[i] - 'A' + 10;
        }

        decimal = decimal + r * PowerNumberCal(16, p);
        ++p;
    }

    return decimal;
}
// Khoi tao driver
static int __init char_driver_init(void)
{
	int ret = 0;
	vchar_drv.dev_num = 0;

    
    ret = alloc_chrdev_region(&vchar_drv.dev_num, 0, 1, "lab51");
	if(ret < 0) {
		printk("Can't allocate character driver\n");
		goto failed_register_devnum;
	}
    printk("Insert character driver successfully. major(%d), minor(%d)\n", MAJOR(vchar_drv.dev_num), MINOR(vchar_drv.dev_num));

	
    vchar_drv.dev_class = class_create(THIS_MODULE, "lab51");
	if(IS_ERR(vchar_drv.dev_class)) {
		printk("Can't create class\n");
		goto failed_create_class;
	}

	vchar_drv.dev = device_create(vchar_drv.dev_class, NULL, vchar_drv.dev_num, NULL,"lab51");
	if(IS_ERR(vchar_drv.dev)) {
		printk("Can't create device file\n");
		goto failed_create_device;
	}
    
	
	kernel_buf 		= kmalloc(MEM_SIZE, GFP_KERNEL);
	buf_tmp			= kmalloc(MEM_SIZE, GFP_KERNEL);

    lab51_cdev = cdev_alloc();				
	cdev_init(lab51_cdev, &fops); 			
	cdev_add(lab51_cdev, vchar_drv.dev_num, 1); 	

    return 0;

failed_create_device:
	class_destroy(vchar_drv.dev_class);
failed_create_class:
	unregister_chrdev_region(vchar_drv.dev_num, 1);
failed_register_devnum:
	return ret;
}

static void __exit char_driver_exit(void) 
{
    cdev_del(lab51_cdev);
	kfree(kernel_buf);
	kfree(buf_tmp);

	device_destroy(vchar_drv.dev_class, vchar_drv.dev_num);
	class_destroy(vchar_drv.dev_class);
	unregister_chrdev_region(vchar_drv.dev_num, 1);
	printk("Remove character driver successfully.\n");
}

module_init(char_driver_init);
module_exit(char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(VERSION);
