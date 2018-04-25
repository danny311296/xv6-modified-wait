# XV6 MODIFIED

A modified version of xv6 to support status parameter in wait system call

### Prerequisites

* gcc version 6.3.0 or higher
* qemu x86

### Installing

First install pre-requisites by: (Only for Ubuntu users):

```
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install gcc-multilib
sudo apt-get install qemu
sudo apt-get install git
```

Download it to local system by:

```
git clone https://github.com/DarkFate13/xv6-modified-wait.git
```

Then compile the project and load the image in your local system by:

```
export QEMU=:qemu-system-x86_64
make
make qemu
```
For testing if it works, see Running tests below

## Running Tests

For automated tests, run:

``` 
usertests

# NOTE: Make sure ls shows usertests executable inside xv6
```

For manual tests, run:

* Copy source code say usertests.c into xv6/ folder
* Modify make file and add line:
```
UPROGS=\
    _cat\
    _echo\ ...
	_usertests\
```
* Then make and load image and run executable


## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - The main back-end used

## Authors

* **Daniel I** - [danny311296](https://github.com/danny311296)
* **Ganesh K.** - [DarkFate13](https://github.com/DarkFate13)

## Acknowledgments

* This is developed as a Hackathon project for Unix System Programing Course.
* We would like to thank our professors, Prof. Nitin V Pujari and Prof. Nypunya Devraj for giving us this opportunity and their valuable advice.
