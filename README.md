# WasteOfSpace

# `waste` is a simple command line tool that helps you waste space on your disk efficiently and conveniently.

# Installation
-  clone the repository:
```bash
git clone <repository-url>
```
-  navigate to the project directory:
```bash
cd wasteofspace
```
- install the dependencies:
```bash
sudo apt install make gcc
```
- build the project:
```bash
./configure && make
```
- install the tool:
```bash
sudo make install
```
# Usage
-  run the tool:
```bash
waste 100
```
-  specify the unit of space to waste (default is MB): 
```bash
waste 100 --unit GB
```
