# WasteOfSpace

# `waste` is a simple command line tool that helps you waste space on your disk efficiently and conveniently.

# Installation
## Debian
```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://zs-247.github.io/wasteofarepo/repo.asc | sudo gpg --dearmor -o /etc/apt/keyrings/wasteofarepo.gpg
# add repository
echo "deb [signed-by=/etc/apt/keyrings/wasteofarepo.gpg] https://zs-247.github.io/wasteofarepo bookworm main" | sudo tee /etc/apt/sources.list.d/wasteofarepo.list
```
```bash
sudo apt update
sudo apt install waste
```
## From source:
-  clone the repository:
```bash
git clone https://github.com/ZS-247/wasteofspace.git
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
